#include <Servo.h>	//importa a biblioteca do servo motor

int servo1 = 9;  		// cria o objeto meuservo
int servo2 = 11;

int valor1; 
int valor2;   			

void setup() {
  pinMode(servo1, OUTPUT);
  pinMode(servo2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
	char dado;         
  	if(Serial.available() > 0){
    dado = Serial.read(); 
    Serial.print(dado);
    if(dado == 'A'){
      valor1 = Serial.parseInt(); // faz a leitura do potenciometro e salva em valor (valores entre 0-1023)
      Serial.println(valor1);
      servoPos1(servo1, valor1);
      servoPos2(servo2, 15);
      delay(1000);                   // delay para esperar o servo chegar na posição.
    }
      if(dado == 'B'){
      	servoPos1(servo1, 0);
		valor2 = Serial.parseInt(); // faz a leitura do potenciometro e salva em valor (valores entre 0-1023)
	  	Serial.println(valor2);
		if(valor2 > 30){
			Serial.println("Cafe longo");
			servoPos2(servo2, 30);
		}
		if(valor2 < 30){
			Serial.println("Cafe curto");
			servoPos2(servo2, 0);
		}
    } 
  }
}

void servoPos1 (int servo, int valor)
{
  int pos = map(valor, 0, 20, 0, 90);
  int microPulso = map(pos, 0,180,1000,2000);
  digitalWrite(servo, HIGH);
  delayMicroseconds(microPulso);
  digitalWrite(servo, LOW);
  delay(10);                   
}

void servoPos2 (int servo, int valor)
{
  int pos = map(valor, 0, 30, 0, 180);
  int microPulso = map(pos, 0,180,1000,2000);
  digitalWrite(servo, HIGH);
  delayMicroseconds(microPulso);
  digitalWrite(servo, LOW);
  delay(10);                   
}