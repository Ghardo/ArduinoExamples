int sensorPin = A0;    
int sensorValue = 0;  

// === Dont Change this ===
#define BTN_NONE -1
#define BTN_PULLUP 1
#define BTN_PULLDOWN 0

#define INDEX_BTN_VALUE 0
#define INDEX_BTN_ID 1
#define INDEX_BTN_MODE 2

// === Define Buttons ===
#define BUTTON_COUNT 3
#define BTN_GREEN 0
#define BTN_RED 1
#define BTN_BLUE 2

// === Configure Buttons ===
int buttons[BUTTON_COUNT][3] = {
  {900, BTN_GREEN, BTN_PULLDOWN},
  {800, BTN_RED, BTN_PULLDOWN},
  {700, BTN_BLUE, BTN_PULLUP}
};

void setup() { 
  Serial.begin(9600);
}

void loop() {
  switch (getButtonPress()) {
    case BTN_BLUE:
      	Serial.println("Blue");
      	break;
    case BTN_RED:
    	Serial.println("Red");
       	break;
    case BTN_GREEN:
      	Serial.println("Green");
      	break;
  }
  
  delay(100);
}

int getButtonPress() {
  bool btnPressed = false;
  sensorValue = analogRead(sensorPin);
  int i;

  for (i = 0; i < BUTTON_COUNT; i++) {
    if (sensorValue > buttons[i][INDEX_BTN_VALUE]) {
      btnPressed = true;
      break;
    }
  }

  if (!btnPressed) 
    return BTN_NONE;
    
  if  (buttons[i][INDEX_BTN_MODE] == BTN_PULLUP) {
    do {
      delay(10);
    } while(analogRead(sensorPin) > 0);
  }
 
  return buttons[i][INDEX_BTN_ID];
}