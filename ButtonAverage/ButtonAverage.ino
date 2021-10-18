/*

ToDo:
Make bad code nice

*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
//const int ledPin =  13;      // the number of the LED pin
int timer = 0;
int arraySize = 35;

int recentReadings[35];
int arrayPos = 0;
int average = 0;
int lastAverage = 0;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

bool readied = false;

void setup() {
  Serial.begin(115200);
  // initialize the LED pin as an output:
  //pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  //Serial.println(arrayPos%arraySize);
  recentReadings[arrayPos%arraySize] = buttonState;

  average = 0;
  for(int i=0;i<arraySize;i++){
    average+=recentReadings[i];
  }

  if(average<lastAverage && timer == 0){
    Serial.println(average);
    timer = 1;
  }
  lastAverage = average;
  //average = average/arraySize;
  //Serial.println(average);
  arrayPos++;
  //timer++;
  delay(6);
  if(average == 0){
    timer = 0;
  }
  

//  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
//  if (buttonState == HIGH && timer == 0) {
//    // turn LED on:
//    Serial.println("TRIGGER");
//    readied = false;
//    timer = 50;
//  }
//  if(timer>0){
//    delay(50);
//    //Serial.println(timer);
//    timer--;
//  }
//  if(timer ==0 && readied == false){
//    Serial.println("READY");
//    readied = true;
//  }
  
}
