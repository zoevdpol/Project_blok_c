// defines variables 
const int echoPin = 4; 
const int trigPin = 3;
long duration; // variable for the duration of sound wave travel 
int distance; // variable for the distance measurement 
int sleepPin = 2;    // select the output pin for enabeling motordriver 
int motorForward1Pin = 5;
int motorReverse1Pin = 6;
int motorForward2Pin = 8;
int motorReverse2Pin = 9;
void setup() { 
// put your setup code here, to run once: 
pinMode(sleepPin, OUTPUT); 
pinMode(motorForward1Pin, OUTPUT); 
pinMode(motorReverse1Pin, OUTPUT); 
pinMode(motorForward2Pin, OUTPUT); 
pinMode(motorReverse2Pin, OUTPUT); 
digitalWrite(sleepPin, HIGH);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
Serial.begin(9600); // Serial Communication is starting with 9600 of
// baudrate speed
Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in 
// Serial Monitor
Serial.println("with Arduino UNO");
}
void go(){
  digitalWrite(sleepPin, HIGH); 
  digitalWrite(motorForward1Pin, LOW);
  digitalWrite(motorReverse1Pin, HIGH);
  digitalWrite(motorForward2Pin, HIGH); 
  digitalWrite(motorReverse2Pin, LOW);
  delay(6);
  }

void reverse(){
  digitalWrite(sleepPin, HIGH); 
  digitalWrite(motorForward1Pin, HIGH);
  digitalWrite(motorReverse1Pin, LOW);
  digitalWrite(motorForward2Pin, LOW); 
  digitalWrite(motorReverse2Pin, HIGH);
  delay(5000);
  }
void stop(){
  digitalWrite(sleepPin, HIGH); 
  digitalWrite(motorForward1Pin, LOW);
  digitalWrite(motorReverse1Pin, LOW);
  digitalWrite(motorForward2Pin, LOW); 
  digitalWrite(motorReverse2Pin, LOW);
}


void rightwheel(){
  digitalWrite(sleepPin, HIGH); 
 
  digitalWrite(motorForward1Pin, LOW); 
  digitalWrite(motorReverse1Pin, HIGH);
  digitalWrite(motorForward2Pin, LOW); 
  digitalWrite(motorReverse2Pin, LOW);
  delay(2000);

  digitalWrite(motorForward1Pin, LOW); 
  digitalWrite(motorReverse1Pin, LOW);
  digitalWrite(motorForward2Pin, LOW); 
  digitalWrite(motorReverse2Pin, LOW);
  delay(1000);
  }
void leftwheel(){
 digitalWrite(sleepPin, HIGH); 
 
 digitalWrite(motorForward1Pin, LOW); 
 digitalWrite(motorReverse1Pin, LOW);
 digitalWrite(motorForward2Pin, HIGH); 
 digitalWrite(motorReverse2Pin, LOW);
 delay(1000);

 digitalWrite(motorForward1Pin, LOW); 
 digitalWrite(motorReverse1Pin, LOW);
 digitalWrite(motorForward2Pin, LOW); 
 digitalWrite(motorReverse2Pin, LOW);
 delay(1000);
 }
long readDistance(){
  // Clears the trigPin condition 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
  // Reads the echoPin, returns the sound wave travel time in microseconds 
  duration = pulseIn(echoPin, HIGH); 
  // Calculating the distance 
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 
  // Displays the distance on the Serial Monitor 
  Serial.print("Distance: "); 
  Serial.print(distance); 
  Serial.println(" cm");
  return distance; 
}
void loop() { 
// put your main code here, to run repeatedly:
   readDistance();
   if (distance >  20){
    go();
   }else if(distance <= 20){
    stop();
    delay(1000);
    leftwheel();
    readDistance();
   }
   if (distance <= 20) {
    rightwheel();
    readDistance();
   }
   if (distance <= 20){
    reverse();
   }
}
