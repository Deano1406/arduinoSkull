
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE

int pos = 45;    // variable to store the servo position
int playbackPin = 8; // variable to setup the laugh playback
int redPin = 11;
int greenPin = 10;
int bluePin = 6;
int colourFade = 0;
const int openPos = 10;
const int closedPos = 50;
const int fadeDelay = 200;

void setup() {
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    pinMode(playbackPin, OUTPUT);

    myservo.attach(9);  // attaches the servo on pin 9 to the servo object
    myservo.write(pos);
    delay(1000);
}

void laugh() {
    digitalWrite(playbackPin, HIGH);

    for (pos = closedPos; pos >= openPos; pos -= 1) { // goes from 60 degrees to 0 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(4);                       // waits 15ms for the servo to reach the position
    }
    for (pos = openPos; pos <= closedPos; pos += 1) { // goes from 0 degrees to 60 degrees
        // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(10);                       // waits 15ms for the servo to reach the position
    }
    digitalWrite(playbackPin, LOW);

}

void setColor(int red, int green, int blue) {
#ifdef COMMON_ANODE
    red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
#endif
    analogWrite(redPin, red);
    analogWrite(greenPin, green);
    analogWrite(bluePin, blue);
}

void colourFadeBlueToRed() {
    for (colourFade = 0; colourFade <= 255; colourFade += 1) {
        setColor(255 - colourFade, 150, colourFade);
        delay(fadeDelay);
    }
}

void colourFadeRedToBlue() {
    for (colourFade = 255; colourFade >= 0; colourFade -= 1) {
        setColor(255 - colourFade, 150, colourFade);
        delay(fadeDelay);
    }
}

void loop() {
    laugh();
    laugh();
    laugh();
    myservo.write(45);
    if (colourFade = 0) {
        colourFadeRedToBlue();
    } else {
        colourFadeBlueToRed();
    }
}








