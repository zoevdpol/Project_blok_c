// lowest and highest sensor readings: 
int TIP120pin = 11; //TIP120pin connected to pin 11 of the Arduino 
const int sensorMin = 0;     // sensor minimum 
const int sensorMax = 1024;  // sensor maximum 
 
void setup() { 
  // initialize serial communication @ 9600 baud: 
  Serial.begin(9600);
  pinMode(TIP120pin, OUTPUT); // Set pin for output to control TIP120 Base pin 
  
} 
void loop() { 
  // read the sensor on analog A0: 
  // zie: https://www.arduino.cc/reference 
  int sensorReading = analogRead(A0); 
  int digiSensorReading1 = digitalRead(2);
  int digiSensorReading2 = digitalRead(3);
  int digiSensorReading3 = digitalRead(4);
  int digiSensorReading4 = digitalRead(5);
  int digiSensorReading5 = digitalRead(6);
  
  // map the sensor range (four options): 
  // zie: https://www.arduino.cc/reference/en/language/functions/math/map/  
  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);
   
   //range value: 
//  switch (range) { 
//  case 0:    // A fire closer than 1.5 feet away. 
//    Serial.println("** Close Fire **"); 
//    break; 
//  case 1:    // A fire between 1-3 fee t away. 
//    Serial.println("** Distant Fire **"); 
//    break; 
//  case 2:    // No fire detected. 
//    Serial.println("No Fire"); 
//    break; 
//  } 
//  delay(1);
    Serial.println(digiSensorReading1 );
    if(digiSensorReading1 or digiSensorReading2 or digiSensorReading3 or digiSensorReading4 or digiSensorReading5){
      analogWrite(TIP120pin, 255); 
    }else if(!digiSensorReading1 or digiSensorReading2 or digiSensorReading3 or digiSensorReading4 or digiSensorReading5){
      analogWrite(TIP120pin, 0);  
    }
}// lowest and highest sensor readings: 
int TIP120pin = 11; //TIP120pin connected to pin 11 of the Arduino 
const int sensorMin = 0;     // sensor minimum 
const int sensorMax = 1024;  // sensor maximum 
 
void setup() { 
  // initialize serial communication @ 9600 baud: 
  Serial.begin(9600);
  pinMode(TIP120pin, OUTPUT); // Set pin for output to control TIP120 Base pin 
  
} 
void loop() { 
  // read the sensor on analog A0: 
  // zie: https://www.arduino.cc/reference 
  int sensorReading = analogRead(A0); 
  int digiSensorReading1 = digitalRead(2);
  int digiSensorReading2 = digitalRead(3);
  int digiSensorReading3 = digitalRead(4);
  int digiSensorReading4 = digitalRead(5);
  int digiSensorReading5 = digitalRead(6);
  
  // map the sensor range (four options): 
  // zie: https://www.arduino.cc/reference/en/language/functions/math/map/  
  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);
   
   //range value: 
//  switch (range) { 
//  case 0:    // A fire closer than 1.5 feet away. 
//    Serial.println("** Close Fire **"); 
//    break; 
//  case 1:    // A fire between 1-3 fee t away. 
//    Serial.println("** Distant Fire **"); 
//    break; 
//  case 2:    // No fire detected. 
//    Serial.println("No Fire"); 
//    break; 
//  } 
//  delay(1);
    Serial.println(digiSensorReading1 );
    if(digiSensorReading1 or digiSensorReading2 or digiSensorReading3 or digiSensorReading4 or digiSensorReading5){
      analogWrite(TIP120pin, 255); 
    }else if(!digiSensorReading1 or digiSensorReading2 or digiSensorReading3 or digiSensorReading4 or digiSensorReading5){
      analogWrite(TIP120pin, 0);  
    }
}
