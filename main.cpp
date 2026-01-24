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

//declarations
void setup();
void loop();
void getString(char*);
void flashLED(); //ratio: signal/letter/word == 1/3/7 == 60ms/180ms/420ms

/**validation function**/
int myFunction(int, int);
void altHigh();
void altLow();
/**validation function**/

//pin setup
const uint8_t PIN_D_0  = 0;
const uint8_t PIN_D_1  = 1;
const uint8_t PIN_D_2  = 2;
const uint8_t PIN_D_3  = 3;
const uint8_t PIN_D_4  = 4;
const uint8_t PIN_D_5  = 5;
const uint8_t PIN_D_6  = 6;
const uint8_t PIN_D_7  = 7;
const uint8_t PIN_D_8  = 8;
const uint8_t PIN_D_9  = 9;
const uint8_t PIN_D_10 = 10;
const uint8_t PIN_D_11 = 11;
const uint8_t PIN_D_12 = 12;
const uint8_t PIN_D_13 = 13;

const uint8_t PIN_A_0 = A0;
const uint8_t PIN_A_1 = A1;
const uint8_t PIN_A_2 = A2;
const uint8_t PIN_A_3 = A3;
const uint8_t PIN_A_4 = A4;
const uint8_t PIN_A_5 = A5;

/*****************************************************************************************************
FUNCTION NAME:  Setup()
DESCRIPTION:    sets up the pin modes, and set inital voltages for deterministic start.
INPUT:          none
OUTPUT:         none
NOTES:          TODO: overly done for learning. Will reduce to what is need later 
****************************************************************************************************/
void setup() {
    Serial.begin(115200);

    pinMode(PIN_D_0, INPUT);
    pinMode(PIN_D_1, INPUT);

    pinMode(PIN_D_2, INPUT_PULLUP);
    pinMode(PIN_D_3, INPUT_PULLUP);
    pinMode(PIN_D_4, INPUT_PULLUP);

    pinMode(PIN_D_5, OUTPUT);
    pinMode(PIN_D_6, OUTPUT);
    pinMode(PIN_D_7, OUTPUT);
    pinMode(PIN_D_8, OUTPUT);
    pinMode(PIN_D_9, OUTPUT);
    pinMode(PIN_D_10, OUTPUT);
    pinMode(PIN_D_11, OUTPUT);
    pinMode(PIN_D_12, OUTPUT);
    pinMode(PIN_D_13, OUTPUT);

    digitalWrite(PIN_D_5, LOW);
    digitalWrite(PIN_D_6, LOW);
    digitalWrite(PIN_D_7, LOW);
    digitalWrite(PIN_D_8, LOW);
    digitalWrite(PIN_D_9, LOW);
    digitalWrite(PIN_D_10, LOW);
    digitalWrite(PIN_D_11, LOW);
    digitalWrite(PIN_D_12, LOW);
    digitalWrite(PIN_D_13, LOW);

    pinMode(PIN_A_0, INPUT);
    pinMode(PIN_A_1, INPUT);
    pinMode(PIN_A_2, INPUT);
    pinMode(PIN_A_3, INPUT);
    pinMode(PIN_A_4, INPUT);
    pinMode(PIN_A_5, INPUT);

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
    digitalWrite(PIN_D_5, HIGH);
    digitalWrite(PIN_D_6, HIGH);
    digitalWrite(PIN_D_7, HIGH);
    digitalWrite(PIN_D_8, HIGH);
    digitalWrite(PIN_D_9, HIGH);
    digitalWrite(PIN_D_10, HIGH);
    digitalWrite(PIN_D_11, HIGH);
    digitalWrite(PIN_D_12, HIGH);
    digitalWrite(PIN_D_13, HIGH);
}
/**validation function**/
/**validation function**/
void altLow(){
    digitalWrite(PIN_D_5, LOW);
    digitalWrite(PIN_D_6, LOW);
    digitalWrite(PIN_D_7, LOW);
    digitalWrite(PIN_D_8, LOW);
    digitalWrite(PIN_D_9, LOW);
    digitalWrite(PIN_D_10, LOW);
    digitalWrite(PIN_D_11, LOW);
    digitalWrite(PIN_D_12, LOW);
    digitalWrite(PIN_D_13, LOW);
}
/**validation function**/