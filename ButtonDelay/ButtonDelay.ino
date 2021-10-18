/*

ToDo:
Average out last 100 readings. Percentage HIGH as a number repeatedly sent to Unity

*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
//const int ledPin =  13;      // the number of the LED pin
int timer = 0;

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

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH && timer == 0) {
    // turn LED on:
    Serial.println("TRIGGER");
    readied = false;
    timer = 50;
  }
  if(timer>0){
    delay(50);
    //Serial.println(timer);
    timer--;
  }
  if(timer ==0 && readied == false){
    Serial.println("READY");
    readied = true;
  }
  
}
