#include <SPI.h>
#include <RF24.h>
#define pinR1 3
#define pinR2 5
#define pinL1 9
#define pinL2 6

RF24 radio(7, 8);
uint8_t right_speed;
uint8_t left_speed;
char gelen_komut[32];

void setup() {
  Serial.begin(9600);
  radio.begin();
  pinMode(pinR1, OUTPUT);
  pinMode(pinR2, OUTPUT);
  pinMode(pinL1, OUTPUT);
  pinMode(pinL2, OUTPUT);
  radio.openReadingPipe(1, 0xF0F0F0F0E12E);
  radio.startListening();
  all_stop();
}

void turn_right(uint8_t speed){
  right_back(speed);
  left_forward(speed);
}
void turn_left(uint8_t speed){
  right_forward(speed);
  left_back(speed);
}

void right_back(uint8_t speed){
  analogWrite( pinR1 , speed );
  analogWrite( pinR2 , 0 );
}

void right_forward(uint8_t speed){
  analogWrite( pinR1 , 0 );
  analogWrite( pinR2 , speed );
}

void left_back (uint8_t speed){
  analogWrite( pinL1 , 0 );
  analogWrite( pinL2 , speed );
}

void left_forward(uint8_t speed){
  analogWrite( pinL1 , speed );
  analogWrite( pinL2 , 0 );
}

void left_stop(){
  analogWrite( pinL1 , 0 );
  analogWrite( pinL2 , 0 );
}
void right_stop(){
  analogWrite( pinR1 , 0 );
  analogWrite( pinR2 , 0 );
}

void all_stop(){
  right_stop();
  left_stop();  
}
void motor_test(){
  right_forward(255);
  delay(2000);
  right_back(255);
  delay(2000);
  right_stop();

  left_forward(255);
  delay(2000);
  left_back(255);
  delay(2000);
  left_stop();
}

void loop() {
  if(radio.available()){
    radio.read(&gelen_komut, sizeof(gelen_komut));
    //right_speed = atoi(gelen_komut);
    //left_speed = 
    //analogWrite(pinR1, gelen_k)
    Serial.println(gelen_komut);
  }
}#include <SPI.h>
#include <RF24.h>
#define pinR1 3
#define pinR2 5
#define pinL1 9
#define pinL2 6

RF24 radio(7, 8);
uint8_t right_speed;
uint8_t left_speed;
char gelen_komut[32];

void setup() {
  Serial.begin(9600);
  radio.begin();
  pinMode(pinR1, OUTPUT);
  pinMode(pinR2, OUTPUT);
  pinMode(pinL1, OUTPUT);
  pinMode(pinL2, OUTPUT);
  radio.openReadingPipe(1, 0xF0F0F0F0E12E);
  radio.startListening();
  all_stop();
}

void turn_right(uint8_t speed){
  right_back(speed);
  left_forward(speed);
}
void turn_left(uint8_t speed){
  right_forward(speed);
  left_back(speed);
}

void right_back(uint8_t speed){
  analogWrite( pinR1 , speed );
  analogWrite( pinR2 , 0 );
}

void right_forward(uint8_t speed){
  analogWrite( pinR1 , 0 );
  analogWrite( pinR2 , speed );
}

void left_back (uint8_t speed){
  analogWrite( pinL1 , 0 );
  analogWrite( pinL2 , speed );
}

void left_forward(uint8_t speed){
  analogWrite( pinL1 , speed );
  analogWrite( pinL2 , 0 );
}

void left_stop(){
  analogWrite( pinL1 , 0 );
  analogWrite( pinL2 , 0 );
}
void right_stop(){
  analogWrite( pinR1 , 0 );
  analogWrite( pinR2 , 0 );
}

void all_stop(){
  right_stop();
  left_stop();  
}
void motor_test(){
  right_forward(255);
  delay(2000);
  right_back(255);
  delay(2000);
  right_stop();

  left_forward(255);
  delay(2000);
  left_back(255);
  delay(2000);
  left_stop();
}

void loop() {
  if(radio.available()){
    radio.read(&gelen_komut, sizeof(gelen_komut));
    //right_speed = atoi(gelen_komut);
    //left_speed = 
    //analogWrite(pinR1, gelen_k)
    Serial.println(gelen_komut);
  }
}