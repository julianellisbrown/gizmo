int sensorValue_1;
int sensorLow_1 = 1023;
int sensorHigh_1 = 0;

int sensorValue_2;
int sensorLow_2 = 1023;
int sensorHigh_2 = 0;

int sensorValue_3;
int sensorLow_3 = 1023;
int sensorHigh_3 = 0;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

const int ledPin = 13;

void setup() {
  Serial.begin(9600);

  pinMode(0, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);

   
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  while (millis() < 5000) {
    sensorValue_1 = analogRead(A0);
    if (sensorValue_1 > sensorHigh_1){
      sensorHigh_1 = sensorValue_1;
      Serial.print(sensorHigh_1);
      Serial.print(" ");
    }
    if(sensorValue_1 < sensorLow_1){
      sensorLow_1 = sensorValue_1;
      Serial.print(sensorLow_1);
       Serial.print(" ");
    }
    
    sensorValue_2 = analogRead(A2);
    if (sensorValue_2 > sensorHigh_2){
      sensorHigh_2 = sensorValue_2;
      Serial.print(sensorHigh_2);
       Serial.print(" ");
    }
    if(sensorValue_2 < sensorLow_2){
      sensorLow_2 = sensorValue_2;
      Serial.print(sensorLow_3);
       Serial.print(" ");
    }
    sensorValue_3 = analogRead(A5);
    if (sensorValue_3 > sensorHigh_3){
      sensorHigh_3 = sensorValue_3;
      Serial.print(sensorHigh_3);
       Serial.print(" ");
    }
    if(sensorValue_3 < sensorLow_3){
      sensorLow_3 = sensorValue_3;
      Serial.print(sensorLow_3);
       Serial.print(" ");
    }
  }
  digitalWrite(ledPin, LOW);
}

void loop(){
  sensorValue_1 = analogRead(A0);
  int pitch_1 = map(sensorValue_1, sensorLow_1, sensorHigh_1, 40, 500);
  tone(8, pitch_1, 20);
  redValue = sensorValue_1/4;
  
   delay(10);
   
  sensorValue_2 = analogRead(A2);
  int pitch_2 = map(sensorValue_2, sensorLow_2, sensorHigh_2, 40, 500);
  tone(10, pitch_2, 20);
  greenValue = sensorValue_2/4;


  delay(10);

  sensorValue_3 = analogRead(A5);
  int pitch_3 = map(sensorValue_3, sensorLow_3, sensorHigh_3, 40, 500);
  tone(12, pitch_3, 20);
  blueValue = sensorValue_3/4;

  delay(10);

  analogWrite(0, redValue);
  analogWrite(2, greenValue);
  analogWrite(4, blueValue);

  
}

