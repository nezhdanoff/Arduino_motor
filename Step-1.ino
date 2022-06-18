#include <Stepper.h>

// Define stepper motor connections:
#define dirPin 0
#define stepPin 2
#define buttonPin 3     // номер вывода с кнопкой
#define ledPin 13    // номер вывода со светодиодом

volatile int buttonState = 0;         // переменная для чтения состояния кнопки
volatile int rotate = 0;         // переменная для чтения состояния кнопки

void setup() {
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  // Set the spinning direction CW/CCW:
//  digitalWrite(dirPin, HIGH);
  digitalWrite(dirPin, LOW);
{
  // настроить вывод светодиода на выход:
  pinMode(ledPin, OUTPUT);
  // настроить вывод кнопки на вход:
  pinMode(buttonPin, INPUT);
  // прикрепить прерывание к вектору ISR
//  attachInterrupt(0, pin_ISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(buttonPin), pin_ISR, CHANGE);
}
 
}

void loop() {
  // These four lines result in 1 step:
//  digitalWrite(stepPin, HIGH);
//  delayMicroseconds(10000);
//  digitalWrite(stepPin, LOW);
//  delayMicroseconds(10000 );
}

void pin_ISR() 
{
  buttonState = digitalRead(buttonPin);
  rotate = buttonState;
  
  Serial.print("Rotate = ");
  Serial.println(rotate);

  
  digitalWrite(ledPin, buttonState);
  delayMicroseconds(5 );
}
