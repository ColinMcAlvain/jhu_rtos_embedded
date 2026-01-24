/*****************************************************************************************************
FILENAME:
DESCRIPTION:
COMPILER:

NOTES:

****************************************************************************************************
MODIFICATION HISTORY
****************************************************************************************************
name                date            version             notes
****************************************************************************************************
mcalvain colin      1/20/26         1.0.0               init
mcalvain colin      1/21/26         1.0.0               added major compents and dialed in timing. Working
mcalvain colin      1/21/26         1.0.0               added sentienal command
                                                        restructed code 2x. Once to use setup as loop.
                                                          Then restuctured to provide states.
****************************************************************************************************/
//includes
#include <Arduino.h>

//declarations
void setup();
void loop() ;
bool morseLookup(char c, uint8_t &pattern, uint8_t &len) ;
bool morseElement(uint8_t pattern, uint8_t len, uint8_t index);
void ledOn();
void ledOff();
void blinkDot(uint16_t unitMs) ;
void blinkDash(uint16_t unitMs) ;
void letterGap(uint16_t unitMs) ;
void wordGap(uint16_t unitMs);
void sendMorseChar(char c, uint16_t unitMs);
void sendMorse(const char* msg, uint16_t unitMs);
String readLine();
String upper(String s);

//pin setup
const uint8_t LED_PIN = 5;
const uint16_t UNIT_MS = 132;

//supporting stuctures
enum SystemState { RUN, IDLE };
SystemState state = RUN;

struct MorseCode {
  char ch;
  uint8_t pattern;
  uint8_t len;
};

static const MorseCode MORSE_TABLE[] = {
  {'A', 0b01,   2}, {'B', 0b1000, 4}, {'C', 0b1010, 4}, {'D', 0b100,  3},
  {'E', 0b0,    1}, {'F', 0b0010, 4}, {'G', 0b110,  3}, {'H', 0b0000, 4},
  {'I', 0b00,   2}, {'J', 0b0111, 4}, {'K', 0b101,  3}, {'L', 0b0100, 4},
  {'M', 0b11,   2}, {'N', 0b10,   2}, {'O', 0b111,  3}, {'P', 0b0110, 4},
  {'Q', 0b1101, 4}, {'R', 0b010,  3}, {'S', 0b000,  3}, {'T', 0b1,    1},
  {'U', 0b001,  3}, {'V', 0b0001, 4}, {'W', 0b011,  3}, {'X', 0b1001, 4},
  {'Y', 0b1011, 4}, {'Z', 0b1100, 4},
};

/*****************************************************************************************************
FUNCTION NAME:  Setup()
DESCRIPTION:    sets up the pin modes, and set inital voltages for deterministic start.
INPUT:          none
OUTPUT:         none
NOTES:          TODO: overly done for learning. Will reduce to what is need later 
****************************************************************************************************/
void setup() {
  pinMode(LED_PIN, OUTPUT);
  ledOff();
  Serial.begin(115200);
  Serial.setTimeout(50);
  Serial.println("Type text + Enter to blink Morse. Type EXIT to idle.");
}

/*****************************************************************************************************
FUNCTION NAME:      loop()  
DESCRIPTION:        main logic loop of the program. Will continue until as round robin unitl sentinel 
                    is entered. cntl-z for simplisity 
INPUT:              none
OUTPUT:             none
NOTES:              loop needs to run a morse code led. 
                    1) take in user typed string
                    2) translate string to char
                    3) determine dot/dash order
                    4) activate led
****************************************************************************************************/
void loop() {
  if (!Serial.available()) return;

  String msg = upper(readLine());
  if (msg.length() == 0) return;

  if (state == RUN) {
    if (msg == "EXIT") {
      state = IDLE;
      ledOff();
      Serial.println("IDLE. Type CONTINUE to resume.");
      return;
    }
    sendMorse(msg.c_str(), UNIT_MS);
    return;
  }

  if (state == IDLE) {
    if (msg == "CONTINUE") {
      state = RUN;
      Serial.println("RUN. Type text + Enter to blink Morse. Type EXIT to idle.");
    }
  }
}
/*****************************************************************************************************
FUNCTION NAME:       morseLookup
DESCRIPTION:         finds the morse pattern and length for a given character.
INPUT:               c is the character to translate.
OUTPUT:              pattern and len are updated when the character is found.
NOTES:               supports uppercase and lowercase letters and returns false for unsupported input.
****************************************************************************************************/
bool morseLookup(char c, uint8_t &pattern, uint8_t &len) {
  if (c >= 'a' && c <= 'z') c = char(c - 'a' + 'A');
  for (uint16_t i = 0; i < sizeof(MORSE_TABLE) / sizeof(MORSE_TABLE[0]); i++) {
    if (MORSE_TABLE[i].ch == c) {
      pattern = MORSE_TABLE[i].pattern;
      len = MORSE_TABLE[i].len;
      return true;
    }
  }
  return false;
}

/*****************************************************************************************************
FUNCTION NAME:       morseElement
DESCRIPTION:         returns the dot or dash value at the requested index of a morse pattern.
INPUT:               pattern is the bit encoded morse pattern, len is the element count, index selects the element.
OUTPUT:              returns false for dot and true for dash.
NOTES:               pattern is stored most significant bit first within the length.
****************************************************************************************************/
bool morseElement(uint8_t pattern, uint8_t len, uint8_t index) {
  uint8_t shift = (len - 1) - index;
  return (pattern >> shift) & 1;
}

/*****************************************************************************************************
FUNCTION NAME:       ledOn
DESCRIPTION:         turns the output led on.
INPUT:               none
OUTPUT:              none
NOTES:               uses the configured led pin.
****************************************************************************************************/
void ledOn()  { digitalWrite(LED_PIN, HIGH); }

/*****************************************************************************************************
FUNCTION NAME:       ledOff
DESCRIPTION:         turns the output led off.
INPUT:               none
OUTPUT:              none
NOTES:               uses the configured led pin.
****************************************************************************************************/
void ledOff() { digitalWrite(LED_PIN, LOW);  }

/*****************************************************************************************************
FUNCTION NAME:       blinkDot
DESCRIPTION:         blinks a dot using the morse base unit timing.
INPUT:               unitMs is the base time unit in milliseconds.
OUTPUT:              none
NOTES:               includes the intra character gap after the dot.
****************************************************************************************************/
void blinkDot(uint16_t unitMs) {
  ledOn();  delay(unitMs);
  ledOff(); delay(unitMs);
}

/*****************************************************************************************************
FUNCTION NAME:       blinkDash
DESCRIPTION:         blinks a dash using the morse base unit timing.
INPUT:               unitMs is the base time unit in milliseconds.
OUTPUT:              none
NOTES:               includes the intra character gap after the dash.
****************************************************************************************************/
void blinkDash(uint16_t unitMs) {
  ledOn();  delay(3 * unitMs);
  ledOff(); delay(unitMs);
}

/*****************************************************************************************************
FUNCTION NAME:       letterGap
DESCRIPTION:         delays to create the correct gap between letters.
INPUT:               unitMs is the base time unit in milliseconds.
OUTPUT:              none
NOTES:               adds remaining delay because one unit gap already occurs after the last element.
****************************************************************************************************/
void letterGap(uint16_t unitMs) {
  delay(2 * unitMs);
}

/*****************************************************************************************************
FUNCTION NAME:       wordGap
DESCRIPTION:         delays to create the correct gap between words.
INPUT:               unitMs is the base time unit in milliseconds.
OUTPUT:              none
NOTES:               adds remaining delay because one unit gap already occurs after the last element.
****************************************************************************************************/
void wordGap(uint16_t unitMs) {
  delay(6 * unitMs);
}

/*****************************************************************************************************
FUNCTION NAME:       sendMorseChar
DESCRIPTION:         outputs a single character as morse code on the led.
INPUT:               c is the character to output and unitMs is the base time unit in milliseconds.
OUTPUT:              none
NOTES:               unsupported characters are ignored.
****************************************************************************************************/
void sendMorseChar(char c, uint16_t unitMs) {
  uint8_t pattern = 0, len = 0;
  if (!morseLookup(c, pattern, len)) return;

  for (uint8_t i = 0; i < len; i++) {
    bool dash = morseElement(pattern, len, i);
    if (dash) blinkDash(unitMs);
    else      blinkDot(unitMs);
  }
  letterGap(unitMs);
}

/*****************************************************************************************************
FUNCTION NAME:       sendMorse
DESCRIPTION:         outputs a null terminated string as morse code on the led.
INPUT:               msg is the string to output and unitMs is the base time unit in milliseconds.
OUTPUT:              none
NOTES:               spaces create word gaps and unsupported characters are ignored.
****************************************************************************************************/
void sendMorse(const char* msg, uint16_t unitMs) {
  for (uint16_t i = 0; msg[i] != '\0'; i++) {
    if (msg[i] == ' ') wordGap(unitMs);
    else               sendMorseChar(msg[i], unitMs);
  }
}

/*****************************************************************************************************
FUNCTION NAME:       readLine
DESCRIPTION:         reads a line of text from the serial port.
INPUT:               none
OUTPUT:              returns the trimmed line that was read.
NOTES:               reads up to the newline character.
****************************************************************************************************/
String readLine() {
  String s = Serial.readStringUntil('\n');
  s.trim();
  return s;
}

/*****************************************************************************************************
FUNCTION NAME:       upper
DESCRIPTION:         converts a string to uppercase.
INPUT:               s is the string to convert.
OUTPUT:              returns the uppercase version of the input string.
NOTES:               conversion is performed in place on the local copy of the string.
****************************************************************************************************/
String upper(String s) {
  s.toUpperCase();
  return s;
}
