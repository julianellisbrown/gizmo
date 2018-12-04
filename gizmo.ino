// Initial global variables set for analog input to 3 different light dependent resistors(LDR). 0 being no light (high reading), 1023 being lots of light (low reading)
int sensorValue_1;
int sensorLow_1 = 1023;
int sensorHigh_1 = 0;

int sensorValue_2;
int sensorLow_2 = 1023;
int sensorHigh_2 = 0;

int sensorValue_3;
int sensorLow_3 = 1023;
int sensorHigh_3 = 0;

//colour variables are set for variable LED
int redValue = 0;
int greenValue = 0;
int blueValue = 0;
//LED pin constant set for calibrating mode at beginning
const int ledPin = 13;


void setup() {
  Serial.begin(9600);
//Pin modes for the 3 LED outputs are established as outputs from the PWM digital pins
  pinMode(0, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);

 
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); // LEDPin is turned on to show operator that the arduino is in calibrate mode
  while (millis() < 5000) {   // While loop runs code for 5 seconds
    sensorValue_1 = analogRead(A0);
    if (sensorValue_1 > sensorHigh_1){ //These 6 if statements find the highest and lowest reading of all 3 LDRs within the while loop and presribe them to the high and low sensor variables
      sensorHigh_1 = sensorValue_1;
    }
    if(sensorValue_1 < sensorLow_1){
      sensorLow_1 = sensorValue_1;
    }
    
    sensorValue_2 = analogRead(A2);
    if (sensorValue_2 > sensorHigh_2){
      sensorHigh_2 = sensorValue_2;
    }
    if(sensorValue_2 < sensorLow_2){
      sensorLow_2 = sensorValue_2;
    }
    sensorValue_3 = analogRead(A5);
    if (sensorValue_3 > sensorHigh_3){
      sensorHigh_3 = sensorValue_3;
    }
    if(sensorValue_3 < sensorLow_3){
      sensorLow_3 = sensorValue_3;
    }
  }
  digitalWrite(ledPin, LOW); //LEDPin is turned off
}

void loop(){
  //The variable for each LDR sensor is set to each analog reader
  sensorValue_1 = analogRead(A0);
  int pitch_1 = map(sensorValue_1, sensorLow_1, sensorHigh_1, 40, 500); // the map fuction is used to take the highest and lowest sensor values found in void_setup and scale them to two inputs (40, 500), and the variable analog read is scaled between the two
  tone(8, pitch_1, 20); //the tone function then uses the mapped values to change the frequency sent to the speaker, with a delay of 20 milliseconds to all the tone to play
  redValue = sensorValue_1/4; //sesnsor value one is divided by 4 to obtain the correct 8-bit frequency for the LED
  
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

  analogWrite(0, redValue); //The LED is given RGB values corresponding to the 3 LDR sensor values
  analogWrite(2, greenValue);
  analogWrite(4, blueValue);

  
}

