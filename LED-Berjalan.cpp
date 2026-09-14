// BRIN-Internship-Test-no.1

#include <Arduino.h>
unsigned long sec_1 = 0 , sec_2 = 0, sec_3 = 0, sec_4 = 0;
uint8_t time = 1;

uint8_t counter1 = 0;
uint8_t counter2 = 0;

void setup() {
  for (size_t i = 0; i < 4; i++)
  {
    pinMode(0 + i, OUTPUT);
    pinMode(4 + i, OUTPUT);
    pinMode(8 + i, OUTPUT);
    pinMode(A0 + i, OUTPUT);
  }
pinMode(12, OUTPUT);
}

void loop() {
// Blocking Codeline
  // digitalWrite(LED_BUILTIN, HIGH);
  // delay(1000);
  // digitalWrite(LED_BUILTIN, LOW);
  // delay(1000);

  sec_2 = millis();
  if (sec_2 - sec_1 >= time * 500) {
    digitalWrite(3 - counter1, digitalRead(3 - counter1) ^ 1);
    digitalWrite(4 + counter1, digitalRead(4 + counter1) ^ 1);
    counter1 = (counter1 + 1) % 4;
    sec_1 = sec_2;
  }

  sec_4 = millis();
  if (sec_4 - sec_3 >= time * 1000) {
    digitalWrite(A0 + counter2, digitalRead(A0 + counter2) ^ 1);
    digitalWrite(11 - counter2, digitalRead(11 - counter2) ^ 1);
    counter2 = (counter2 + 1) % 4;
    sec_3 = sec_4;
  }

  digitalWrite(12, LOW);
  if(sec_4 - sec_2 >= sec_3 - sec_1) {
    digitalWrite(12, HIGH);
    digitalWrite(12, digitalRead(12));
  }
  else {
    digitalWrite(12, LOW);
  }
}