#include <LiquidCrystal.h>
 
#define trigger 18
#define echo 19
 
LiquidCrystal lcd(12,11,5,4,3,2);
 
float time=0,distance=0;
float initial=0,diff=0;
int buttonState1 = 0;
const int buttonPin = 7;
 
void setup()
{
 lcd.begin(16,2);
 pinMode(trigger,OUTPUT);
 pinMode(echo,INPUT);
 pinMode(buttonPin, INPUT);
 digitalWrite(buttonPin, HIGH);
}
 
void loop()
{
 lcd.clear();
 buttonState1 = digitalRead(buttonPin);

 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 int duration = pulseIn(echo, HIGH);
//and gere we calculate distance from it
 distance = duration/29.14 / 2;
 if (buttonState1 == LOW ){
     initial=distance;
     diff=0;
 }
 if(distance-initial >diff)
    diff=distance-initial;
 lcd.clear();
 lcd.print("Mesafe:");
 lcd.print(diff);
 lcd.print("cm");
 delay(500);
}
