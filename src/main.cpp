#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

// Matrixen
const int COLS = 16;
const int ROW = 24;
const int NUM_PIXELS = COLS * ROW;

// PIN + Helligkeit
#define MATRIX_PIN_1 13
#define MATRIX_PIN_2 12
#define BRIGHTNESS 8

// Matrix initialisieren
Adafruit_NeoPixel matrix_1 = Adafruit_NeoPixel(NUM_PIXELS, MATRIX_PIN_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel matrix_2 = Adafruit_NeoPixel(NUM_PIXELS, MATRIX_PIN_2, NEO_GBR + NEO_KHZ800);

int joyX_1 = 0;
int joyX_2 = 0;

void border(int start, int end);
void fullBorder();
void resetMatrix();
void JoystickPosition();

void setup() {
    // Matrix_1 und Matrix_2 Initialisieren
    matrix_1.begin();
    matrix_1.setBrightness(BRIGHTNESS);
    matrix_1.show();

    matrix_2.begin();
    matrix_2.setBrightness(BRIGHTNESS);
    matrix_2.show();

    // Spielfächel intialisieren
    resetMatrix();

    // 8 und 9 auf Input stellen, um die Schalter einlesen zu können
    pinMode(8, INPUT);
    pinMode(9, INPUT);    
}

void loop() {
    
}
 

void border(int start, int end) {
    for (int i = start; i < end; i++) {
      matrix_1.setPixelColor(i, 0, 255, 255);
      matrix_1.show();

      matrix_2.setPixelColor(i, 0, 255, 255);
      matrix_2.show();
    }
}
void fullBorder() {
  int i = 8;
  border(0, 16);
  while (i < 192) {
    border(i, i + 8);
    i = i + 24;
  }
  border(184, 208);
  i = 224;
  while (i < 376) {
    border(i, i + 8);
    i = i + 24;
  }
  border(376,384);
  border(22, 26);
  border(40,42);
  border(54,56);
  border(70, 74);
  border(88, 90);
  border(102, 104);
  border(118, 122);
  border(136, 138);
  border(150, 152);
  border(166, 170);
}
void resetMatrix() {
    matrix_1.clear();
    matrix_2.clear();
    fullBorder();
}
void JoystickPosition() {
  // todo 0 wert ermitteln und dann die Logik programmieren
  joyX_1 = analogRead(A0);
  joyX_2 = analogRead(A1);

}