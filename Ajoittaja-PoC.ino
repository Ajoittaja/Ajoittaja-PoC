#define PWR_PIN 21

// 100000 = ~2 minutes in milliseconds
long interval = 100000;  // interval at which to light the next LED
unsigned long previousTime = 0;  // store the last time an LED was updated

void setup()
{
	pinMode(PWR_PIN, OUTPUT);
}

void loop()
{
    // store the time since the Arduino started running in a variable
    unsigned long currentTime = millis();

    // compare the current time to the previous time an LED turned on
    // if it is greater than your interval, run the if statement
    if (currentTime - previousTime > interval) {
        // save the current time as the last time you changed an LED
        previousTime = currentTime;
        digitalWrite(PWR_PIN, LOW);
    } else {
        digitalWrite(PWR_PIN, HIGH);
    }   
}