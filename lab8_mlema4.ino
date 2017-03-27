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


//Buttons and pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int buttonPin0 = 8;    // the pin that the pushbutton is attached to
const int buttonPin1 = 9;  
const int rx = 0;
const int tx = 1;
const int ledPin0 = 10;
const int ledPin1 = 11;

// Variables will change:
int buttonPushCounter0 = 0;   // counter for the number of button presses Max 7 Min 0
int buttonPushCounter1 = 0;
int buttonState0 = 0;         // current state of the button
int buttonState1 = 0;
int lastButtonState0 = 0;     // previous state of the button
int lastButtonState1= 0;

void setup() {
  // initialize the button pins as a input:
  pinMode(buttonPin0, INPUT);
  pinMode(buttonPin1, INPUT);
  // initialize the LEDs as an output:
  
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin0, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);
  pinMode(rx, OUTPUT);
  pinMode(tx, INPUT);
  lcd.begin(16, 2);
}

void light (int currentNumber, int led)
{

if ((currentNumber % 2))
  digitalWrite(led,LOW);
else
  digitalWrite(led, HIGH);

lcd.print("A");
}

void loop() {
  // read the pushbutton input pin:
  buttonState0 = digitalRead(buttonPin0);
  buttonState1 = digitalRead(buttonPin1);

  // compare the buttonState to its previous state and check that the decrement button is not being pushed
  if (buttonState0 != lastButtonState0 && buttonState1 != HIGH) {
    // if the state has changed, increment the counter
    if (buttonState0 == HIGH) {
      // if the current state is HIGH then the button went from off to on:
//      if(buttonPushCounter0 != 7) //Keep the counter at 7 
        buttonPushCounter0++;
//      Serial.println("on");
//      Serial.print("number of button pushes:  ");
//      Serial.println(buttonPushCounter);
        Serial.write("A");
    } else {
      // if the current state is LOW then the button
      // wend from on to off:
//      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  
  // save the current state as the last state,
  //for next time through the loop
  lastButtonState0 = buttonState0;

if(Serial.available() > 0)
  light(buttonPushCounter0, ledPin0);

 //Call function
//  light(buttonPushCounter);
}

  
 else if (buttonState1 != lastButtonState1 && buttonState0 != HIGH) {
    // if the state has changed, increment the counter
    if (buttonState1 == HIGH) {
      // if the current state is HIGH then the button went from off to on:
//      if(buttonPushCounter != 0)
        buttonPushCounter1++;
//      Serial.println("on");
//      Serial.print("number of button pushes:  ");
//      Serial.println(buttonPushCounter);
    } else {
      Serial.write("A");
    }
//      // if the current state is LOW then the button
//      // wend from on to off:
//      Serial.println("off");
//    }
    // Delay a little bit to avoid bouncing
    delay(50);
  
  // save the current state as the last state,
  //for next time through the loop
  lastButtonState1 = buttonState1;

//Call function
//  light(buttonPushCounter);
if (Serial.available() >  0)
  light(buttonPushCounter1, ledPin1);
}
}
