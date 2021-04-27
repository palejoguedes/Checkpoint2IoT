int buttonPin2 = 2; // nomeia o pino2 do arduino como buttonPin2
int buttonPin3 = 3; // nomeia o pino3 do arduino como buttonPin3
int ledPin = 13;    // nomeia o pino13 do arduino como ledPin 
int pot1 = A0;    //Nomeia o pino A0 como pot1
int pot2 = A1;    //Nomeia o pino A0 como pot2
int buttonStatus2;  // Variavel de estado do buttonPin2
int buttonStatus3;  // Variavel de estado do buttonPin2
int valor_pot1;
int valor_pot2;
void setup() {
  pinMode(ledPin, OUTPUT);            //Pino13 como saida 
  pinMode(buttonPin2, INPUT_PULLUP);  //Pino2 como entrada com resistor de pullup interno
  pinMode(buttonPin3, INPUT_PULLUP);  //Pino3 como entrada com resistor de pullup interno
  pinMode(pot1, INPUT);				//Pino A0 como entrada
  pinMode(pot2, INPUT);	  			//Pino A1 como entrada
  Serial.begin(9600);				   //Inicialica a comunicação serial
}

void loop() {
  buttonStatus2 = digitalRead(buttonPin2);
  buttonStatus3 = digitalRead(buttonPin3);
  valor_pot1 = analogRead(pot1);
  valor_pot2 = analogRead(pot2);
// O botão quando é pressionado: O pino do arduino fica com estado logico "LOW"
// O botão quando não esta pressionado: O pino do arduino fica com estado logico "HIGH"

  if ((buttonStatus2 == LOW)){   // Se botao2 OU(OR) botão3 for pressionado
    digitalWrite(ledPin, HIGH);
	Serial.print("A");
    Serial.print(valor_pot1);
    delay(500);                                            // delay de 0,5 seg.
  }

  if ((buttonStatus3 == LOW)){   // Se botao2 Eaa(AND) botão3 for pressionado
    digitalWrite (ledPin, LOW);                            // Então apaga o led
    Serial.print("B");
	Serial.print(valor_pot2);
    delay(500);                                            // delay de 0,5 seg.
  }

}