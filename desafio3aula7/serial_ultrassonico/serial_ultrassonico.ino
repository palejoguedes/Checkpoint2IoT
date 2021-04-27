#include <Ultrasonic.h>

HC_SR04 sensor1(4,5); // (trigger, echo)
HC_SR04 sensor2(12,11); // (trigger, echo)
int btn_capsula = 8; //botao capsula
bool isCopo = false;

void setup() {
  Serial.begin(9600);
  pinMode(btn_capsula, INPUT_PULLUP);
}

void loop(){
  if(sensor1.distance() <= 20 && isCopo == false){
   Serial.print("A");
   Serial.print(sensor1.distance());
   isCopo = true;
   delay(200);
 }

 if(isCopo == true){
  Serial.print("B");
  Serial.print(sensor2.distance());
  delay(5000);
  isCopo = false;
 }
 
}