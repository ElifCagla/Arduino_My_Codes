#include <SPI.h>
#include <RF24.h>
#define GAZ_AYARI A0

RF24 radio(7, 8); // CE, CSN pimlerini belirtin
uint8_t gaz_ayari = 0;
char giden_komut[32]; 

void setup() {
  pinMode(GAZ_AYARI, INPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(0xF0F0F0F0E12E);
  radio.stopListening();
}
void loop() {
  gaz_ayari = map(analogRead(GAZ_AYARI), 0, 1023, 0, 255);
  sprintf(giden_komut,"%d,%d,%d,%d",  180,-230,1,0);
  radio.write(&giden_komut, sizeof(giden_komut));
  Serial.println(giden_komut);
  delay(200);
}