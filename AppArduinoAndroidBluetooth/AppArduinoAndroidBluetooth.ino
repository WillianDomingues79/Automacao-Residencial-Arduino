#include <SoftwareSerial.h>

SoftwareSerial bluetooth(10, 11);

#define led1 3

String comando;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

  pinMode(led1, OUTPUT);
}

void loop() {
  comando = "";

  if(bluetooth.available()){
    while(bluetooth.available()){
      char caracter = bluetooth.read();

      comando += caracter;
      delay(10);
    }
    //Serial.print("Comando: ");
    //Serial.println(comando);

    if(comando.indexOf("led1") >= 0){
      digitalWrite(led1, !digitalRead(led1));
      
      bluetooth.println("Vai Ligar/Desligar led1");
    }

    bluetooth.println("{");
    
    if(digitalRead(led1)) {
      bluetooth.println("l1on");
    }else {
      bluetooth.println("l1of");
    }
    
    bluetooth.println("}");
  }
}
