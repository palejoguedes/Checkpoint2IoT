#include <Adafruit_SSD1306.h>
#define OLED_Address 0x3C // 0x3C device address of I2C OLED
Adafruit_SSD1306 oled(128, 64);

int ledPin = 11;    // nomeia o pino11 do arduino como ledPin 
int potenciometro1 = 0;
int potenciometro2 = 0;
int last_potenciometro1 = 0;
int last_potenciometro2 = 0;

void setup() {
  pinMode(ledPin, OUTPUT);            //Pino11 como saida 
  Serial.begin(9600);				   //Inicialica a comunicação serial
  
//inicialização do display oled 
  oled.begin(SSD1306_SWITCHCAPVCC, OLED_Address);
  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setTextColor(WHITE);
}


void loop() {
  char dado;
  oledTempo();							    // Declara dado como variavel local do tipo char
  if(Serial.available() > 0){				// Se tem alguma coisa no buffer da serial
    dado = Serial.read();					// Entao salva em dado
    Serial.print(dado);
  	if(dado == 'A'){
		potenciometro1 = Serial.parseInt();
		oledTempo();
		Serial.println(String("Pot1: ") + potenciometro1);		// Print para mostrar o valor
  		delay(100);                   	
	}    
	if(dado == 'B'){
		potenciometro2 = Serial.parseInt();
		oledTempo();
		Serial.println(String("Pot2: ") + potenciometro2);		// Print para mostrar o valor
  		delay(100);                   	
	}
	
  }//end if Serial.available
  
}//end loop

void oledTempo(){
  oled.setCursor(0,0); 		//seta o cursor no inicio
  oled.setTextColor(BLACK); 	//e apaga o
  oled.print("potenciometro 1:");			// valor da temp.
  oled.print(last_potenciometro1);  	// antigo, o templast

  oled.setCursor(0,0);			// seta o cursor no inicio
  oled.setTextColor(WHITE);	// 
  oled.print("potenciometro 1:");
  oled.print(potenciometro1);
  last_potenciometro1 = potenciometro1;
  oled.display();

  oled.setCursor(0,7); 		//seta o cursor no inicio
  oled.setTextColor(BLACK); 	//e apaga o
  oled.print("potenciometro 2:");			// valor da temp.
  oled.print(last_potenciometro2);  
//oled.print(templast_term);		// antigo, o templast

  oled.setCursor(0,7);			// seta o cursor no inicio
  oled.setTextColor(WHITE);	// 
  oled.print("potenciometro 2:");
  oled.print(potenciometro2);
  last_potenciometro1 = potenciometro2;
  oled.display();

  oled.display();
}