/* const int a = 0;
const int b = 1;
const int c = 2;
const int d = 3;
const int e = 4;
const int f = 5;
const int g = 6;   
 */


#define ZERO  0b01000000
#define ONE   0b11111001
#define TWO   0b10100100
#define THREE 0b10110000
#define FOUR  0b10011001
#define FIVE  0b10010010
#define SIX   0b10000010
#define SEVEN 0b11111000
#define EIGHT 0b00000000
#define NINE  0b10010000
#define A     0b00001000
#define B     0b00000011
#define C     0b01000110
#define D     0b00100001
#define E     0b00000110
#define F     0b00001110

#include <inttypes.h>

const uint8_t arr[16] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, A, B, C, D, E, F};

void setup() {
  // put your setup code here, to run once:
  DDRF = 0xff;
}

void loop() {
  // put your main code here, to run repeatedly:
  for(size_t i = 0; i < 16; i++){
      delay(700);
      PORTF = i[arr];
  }
}
