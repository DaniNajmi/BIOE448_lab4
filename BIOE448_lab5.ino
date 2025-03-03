// Lab 5 Microcontrollers: Bluetooth Communication
// February 19th, 2025
// Daniela Najmias Lang, Matan Blitz, Marc De Guzman

const int trigPin = 11;
const int echoPin = 12;
long duration;
int distanceCm, distanceInch;

const int red = 2; // red LED
const int green = 3; // green LED
const int range = 5; // range for changing from green to red based on distance in cm

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  Serial.begin(9600);

}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH); //record the time
  
  //Uncomment for calculating rate
  // Serial.println(duration);

  distanceCm = duration * 0.017; // from data sheet information
  distanceInch = duration * 0.007; // converted from cm
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.print(" cm/");
  Serial.print(distanceInch);
  Serial.println(" in");
  delay(1000); // delay so you can read the distance (slows refresh rate)


  // this is for turning the red LED on if the distance is more than 5cm, otherwise, it will turn on the green LED
  if (distanceCm < range) {
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
  }
  else {
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
    }

    delayMicroseconds(1000);
}


