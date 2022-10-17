
// Create variables for calibrating the sensor
int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

// Name a constant for calibration LED
const int ledPin = 13;


void setup(){
  
  // Set digital pin direction and turn it high
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  
  
  // Use a while() loop for calibration
  while (millis() < 5000){
    
    // Compare sensor values for calibration
    sensorValue = analogRead(A0);
    
    if (sensorValue > sensorHigh){
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow){
      sensorLow = sensorValue;
    }
  }
  
  // Indicate calibration has finished
  digitalWrite(ledPin, LOW);
  
  Serial.begin(9600);
}



void loop(){
  sensorValue = analogRead(A0);
  
  int pitch =
    map(sensorValue, sensorLow, sensorHigh, 100, 1000);
    
  tone(8, pitch, 300);
  delay(150);
  
  Serial.print("sensorLow value: ");
  Serial.print(sensorLow);
  Serial.print("\t");
  Serial.print("sensorHigh value: ");
  Serial.print(sensorHigh);
  Serial.print("\t");
  Serial.print("sensorValue value: ");
  Serial.println(sensorValue);
  Serial.println("");
  Serial.println("");
}



