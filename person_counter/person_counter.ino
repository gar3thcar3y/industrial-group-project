// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;

struct SonicSensor{
  int trigPin;
  int echoPin;
};


// defines variables
long duration;
int distance1;
int distance2;
struct SonicSensor sonicsensor1;
struct SonicSensor sonicsensor2;

char type;
int count;

//include the rgb_lcd library
#include "rgb_lcd.h"

//assign name lcd to rgb_lcd
rgb_lcd lcd;

void setup() {
  sonicsensor1.trigPin = 9;
  sonicsensor1.echoPin = 10;
  sonicsensor2.trigPin = 11;
  sonicsensor2.echoPin = 12;

  type = 'n';
  count = 0;

  pinMode(sonicsensor1.trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(sonicsensor1.echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(sonicsensor2.trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(sonicsensor2.echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication

  lcd.begin(16, 2);
    // Print Hello, World! to the LCD.
  lcd.print("started");
  delay(1000);
}
void loop() {
  // Clears the trigPin
  digitalWrite(sonicsensor1.trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(sonicsensor1.trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sonicsensor1.trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(sonicsensor1.echoPin, HIGH);
  // Calculating the distance
  distance1 = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  if(distance1 < 100){
    if(type == 'n'){
      lcd.setCursor(0, 0);
      lcd.print("welcome");
      type = 'e';
    }
    if(type == 'l'){
      type = 'n';
      lcd.setCursor(0, 0);
      lcd.print("             ");
      Serial.println("type: ");
      Serial.println(type);
      count -= 1;
      delay(500);
    }
    lcd.setCursor(0, 1);
    lcd.print("             ");
    lcd.setCursor(0, 1);
    lcd.print("count: "); lcd.print(count);
  }
  
  digitalWrite(sonicsensor2.trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(sonicsensor2.trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sonicsensor2.trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(sonicsensor2.echoPin, HIGH);
  // Calculating the distance
  distance2 = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  if(distance2 < 100){
    if(type == 'n'){
      lcd.setCursor(0, 0);
      lcd.print("goodbye");
      
      type = 'l';
    }
    if(type == 'e'){
      type = 'n';
      lcd.setCursor(0, 0);
      lcd.print("             ");
      Serial.println("type: ");
      Serial.println(type);
      count += 1;
      delay(500);
    }
    lcd.setCursor(0, 1);
    lcd.print("             ");
    lcd.setCursor(0, 1);
    lcd.print("count: "); lcd.print(count);
    
  }

  Serial.println(distance2);

  
}