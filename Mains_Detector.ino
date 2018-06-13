/*
 * Simple mains detector
 */

#define pinVolts 2
bool previousState = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(pinVolts, INPUT);
  Serial.println("Setup Completed");
}

void loop() {
  if (digitalRead(pinVolts) == HIGH && previousState == LOW) {
    previousState = HIGH;
    Serial.println("MAINS OFF");
  }

  if (digitalRead(pinVolts) == LOW && previousState == HIGH) {
    previousState = LOW;
    Serial.println("MAINS ON");
  }

  delay(250);
}
