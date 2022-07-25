int IRSensor = 2; // connect ir sensor to arduino pin 2
int LED = 13; // conect Led to arduino pin 13

void setup() 
{
  pinMode (IRSensor, INPUT); // sensor pin INPUT
  pinMode (LED, OUTPUT); // Led pin OUTPUT
  Serial.begin(9600);
}

void loop(){
  int sensorStatus = digitalRead(IRSensor); 
  if (sensorStatus == HIGH) // Check if the pin high or not
  {

    digitalWrite(LED, HIGH);
    Serial.println("Motion Ended!"); 
  }
  else  {
    digitalWrite(LED, LOW); 
    Serial.println("Motion Detected!"); 
  }
}
