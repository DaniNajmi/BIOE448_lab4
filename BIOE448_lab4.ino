// Lab 4 Microcontrollers: Sensors and calibration
// February 12th, 2025
// Daniela Najmias Lang and Daniel Bacuyag 

const int trigPin = 11;
const int echoPin = 12;
long duration;
int distanceCm, distanceInch;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
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


}

