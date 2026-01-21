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
****************************************************************************************************/
//includes
#include <Arduino.h>
#include <cstdint>

//declarations
void setup();
void loop();
void getString(char*);
void flashLED() //ratio: signal/letter/word == 1/3/7 == 60ms/180ms/420ms

/**validation function**/
int myFunction(int, int);
void altHigh();
void altLow();
/**validation function**/

//pin setup
const uint8_t PIN_D0  = 0;
const uint8_t PIN_D1  = 1;
const uint8_t PIN_D2  = 2;
const uint8_t PIN_D3  = 3;
const uint8_t PIN_D4  = 4;
const uint8_t PIN_D5  = 5;
const uint8_t PIN_D6  = 6;
const uint8_t PIN_D7  = 7;
const uint8_t PIN_D8  = 8;
const uint8_t PIN_D9  = 9;
const uint8_t PIN_D10 = 10;
const uint8_t PIN_D11 = 11;
const uint8_t PIN_D12 = 12;
const uint8_t PIN_D13 = 13;

const uint8_t PIN_A0 = A0;
const uint8_t PIN_A1 = A1;
const uint8_t PIN_A2 = A2;
const uint8_t PIN_A3 = A3;
const uint8_t PIN_A4 = A4;
const uint8_t PIN_A5 = A5;

/*****************************************************************************************************
FUNCTION NAME:  Setup()
DESCRIPTION:    sets up the pin modes, and set inital voltages for deterministic start.
INPUT:          none
OUTPUT:         none
NOTES:          TODO: overly done for learning. Will reduce to what is need later 
****************************************************************************************************/
void setup() {
    Serial.begin(115200);

    pinMode(PIN_D0, INPUT);
    pinMode(PIN_D1, INPUT);

    pinMode(PIN_D2, INPUT_PULLUP);
    pinMode(PIN_D3, INPUT_PULLUP);
    pinMode(PIN_D4, INPUT_PULLUP);

    pinMode(PIN_D5, OUTPUT);
    pinMode(PIN_D6, OUTPUT);
    pinMode(PIN_D7, OUTPUT);
    pinMode(PIN_D8, OUTPUT);
    pinMode(PIN_D9, OUTPUT);
    pinMode(PIN_D10, OUTPUT);
    pinMode(PIN_D11, OUTPUT);
    pinMode(PIN_D12, OUTPUT);
    pinMode(PIN_D13, OUTPUT);

    digitalWrite(PIN_D5, LOW);
    digitalWrite(PIN_D6, LOW);
    digitalWrite(PIN_D7, LOW);
    digitalWrite(PIN_D8, LOW);
    digitalWrite(PIN_D9, LOW);
    digitalWrite(PIN_D10, LOW);
    digitalWrite(PIN_D11, LOW);
    digitalWrite(PIN_D12, LOW);
    digitalWrite(PIN_D13, LOW);

    pinMode(PIN_A0, INPUT);
    pinMode(PIN_A1, INPUT);
    pinMode(PIN_A2, INPUT);
    pinMode(PIN_A3, INPUT);
    pinMode(PIN_A4, INPUT);
    pinMode(PIN_A5, INPUT);

    analogReference(DEFAULT);
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
  /**validation function**/
  int result = myFunction(2, 3);
  Serial.println(result);
  delay(1000);
  /**validation function**/

  altHigh();
  delay(1000);
  altLow();
  delay(1000);
}

/**validation function**/
int myFunction(int x, int y) {
  return x + y;
}
/**validation function**/

/**validation function**/
void altHigh(){
    digitalWrite(PIN_D5, HIGH);
    digitalWrite(PIN_D6, HIGH);
    digitalWrite(PIN_D7, HIGH);
    digitalWrite(PIN_D8, HIGH);
    digitalWrite(PIN_D9, HIGH);
    digitalWrite(PIN_D10, HIGH);
    digitalWrite(PIN_D11, HIGH);
    digitalWrite(PIN_D12, HIGH);
    digitalWrite(PIN_D13, HIGH);
}
/**validation function**/
/**validation function**/
void altLow(){
    digitalWrite(PIN_D5, LOW);
    digitalWrite(PIN_D6, LOW);
    digitalWrite(PIN_D7, LOW);
    digitalWrite(PIN_D8, LOW);
    digitalWrite(PIN_D9, LOW);
    digitalWrite(PIN_D10, LOW);
    digitalWrite(PIN_D11, LOW);
    digitalWrite(PIN_D12, LOW);
    digitalWrite(PIN_D13, LOW);
}
/**validation function**/