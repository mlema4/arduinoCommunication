/*
Manuel Lema - 676532040
Lab 2
Description: Using two push buttons and 3 led lights, 
the circuit should implement a binary counter, with an increment
button and a decrement button with the led displaying the current binary value
References: http://www.arduino.cc/en/Tutorial/ButtonStateChange

*/
#include <LiquidCrystal.h>
#include <stdlib.h>
#include <string.h>
#include <SoftwareSerial.h>


//Buttons and pins
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int buttonPin0 = 8;    // the pin that the pushbutton is attached to
//const int buttonPin1 = 9;  
const int rx = 0;
const int tx = 1;
const int ledPin0 = 10;
//const int ledPin1 = 11;

// Variables will change:
int buttonPushCounter0 = 0;   // counter for the number of button presses Max 7 Min 0
//int buttonPushCounter1 = 0;
int buttonState0 = 0;         // current state of the button
//int buttonState1 = 0;
int lastButtonState0 = 0;     // previous state of the button
//int lastButtonState1= 0;
boolean lit = false;

void setup() {
  // initialize the button pins as a input:
  pinMode(buttonPin0, INPUT);
 // pinMode(buttonPin1, INPUT);
  // initialize the LEDs as an output:
  
 // pinMode(ledPin1, OUTPUT);
  pinMode(ledPin0, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);
  pinMode(rx, OUTPUT);
  pinMode(tx, INPUT);
//  lcd.begin(16, 2);
}

void light ()
{
//  lcd.print("A");

if (lit){
  digitalWrite(ledPin0,LOW);
  lit = false;
}

else{
  //lcd.print("ON");
  digitalWrite(ledPin0, HIGH);
  lit = true;
}


}

void loop() {
  // read the pushbutton input pin:
  buttonState0 = digitalRead(buttonPin0);
 // buttonState1 = digitalRead(buttonPin1);

  // compare the buttonState to its previous state and check that the decrement button is not being pushed
  if (buttonState0 != lastButtonState0) {
    // if the state has changed, increment the counter
    if (buttonState0 == HIGH) {
        //buttonPushCounter0++;
        Serial.print("A");
       // lcd.print("1");
    } else {
      // if the current state is LOW then the button
      // wend from on to off:
    }
    // Delay a little bit to avoid bouncing
   //
   delay(50);
  
  // save the current state as the last state,
  //for next time through the loop
  lastButtonState0 = buttonState0;

  }
if(Serial.available()){
//  lcd.clear();
  //lcd.print("CALLING FUNCTION");
 // lcd.clear();
Serial.read();
  light();
  
}
delay(500);
}
