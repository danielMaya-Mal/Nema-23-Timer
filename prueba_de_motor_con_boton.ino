#include<TimerOne.h>
#define STEPPIN 12
#define DIRPIN 11
#define ENAPIN 10

#define ACTIONPIN 8

#define Led 7

#include "DFRobot_LCD.h"

  const int colorR = 255;
  const int colorG = 0;
  const int colorB = 0;
  DFRobot_LCD lcd(16,2);  //16 characters and 2 lines of show

volatile int tiempo_t=0;
const int STEPTIME = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(STEPPIN,OUTPUT);
  pinMode(DIRPIN,OUTPUT);
  pinMode(ENAPIN,OUTPUT); 

  pinMode(ACTIONPIN,INPUT);

  pinMode(Led,OUTPUT);
  //digitalWrite(ENAPIN,LOW);
  lcd.init();
  lcd.setRGB(colorR, colorG, colorB);//If the module is a monochrome screen, you need to shield it
  lcd.print("prueba");
  delay(1000);
  lcd.clear();
  //Timer1.initialize(1000000);                      //Configura el timer en 1 segundo 
  //Timer1.attachInterrupt(Temporizador);            //Configura la interrupcion del timer 1
}

void loop() {
  // put your main code here, to run repeatedly:
    lcd.print(tiempo_t);
    lcd.clear();
    if(digitalRead(ACTIONPIN))
    {
      tiempo_t=10;
      Timer1.initialize(1000000);                      //Configura el timer en 1 segundo 
      Timer1.attachInterrupt(Temporizador);            //Configura la interrupcion del timer 1
      digitalWrite(ENAPIN,LOW);
      do{
      forward(200);
      }
      while(tiempo_t>0);
    }
    else
    {
      //detachInterrupt(Temporizador);
      //digitalWrite(ENAPIN,HIGH);
      //tiempo_t=0;
    }
    
}

void Temporizador(void)
{
  digitalWrite(Led, digitalRead(Led)^1);   //invierte el estado del led
  tiempo_t--;

  if(tiempo_t<=0)
  {
    digitalWrite(ENAPIN,HIGH);
    //tiempo_t=5;
  }
  /*if(Start==1)                             //condicional para que se efectue la cuenta regresiva 
  {
   // tiempo_t--;
   // sprintf(Text,"tiempo: %d",tiempo);
   // lcd.print(tiempo);
  /* if(tiempo_t==0)                           //Reinicia los conteos a 0 para volver a empezar
    {
      Start=2;
      seg=0;
      minut=0;
      hora=0;
      digitalWrite(fin,HIGH);
    
    }
  }*/
}


void forward(int steps){
  int i;
 // digitalWrite(ENAPIN,LOW);//ENABLE IS ACTIVE LOW
  digitalWrite(DIRPIN,HIGH);//SET DIRECTION 
  for(i=0;i<steps;i++){
    digitalWrite(STEPPIN,HIGH);
    delay(STEPTIME);
    digitalWrite(STEPPIN,LOW);
    delay(STEPTIME);
  }
 //digitalWrite(ENAPIN,HIGH);//DISABLE STEPPER
}

void reverse(int steps){
  int i;
 // digitalWrite(ENAPIN,LOW);//ENABLE IS ACTIVE LOW
  digitalWrite(DIRPIN,LOW);//SET DIRECTION 
  for(i=0;i<steps;i++){
    digitalWrite(STEPPIN,HIGH);
    delay(STEPTIME);
    digitalWrite(STEPPIN,LOW);
    delay(STEPTIME);
  }
  digitalWrite(ENAPIN,HIGH);//DISABLE STEPPER
}
