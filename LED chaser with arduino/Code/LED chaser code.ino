 // 🔁 Advanced 12-LED Chaser Effects with Arduino Uno

int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
int ledCount = sizeof(ledPins) / sizeof(ledPins[0]);

void setup() {
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  chaseForward();     delay(300);
  chaseBackward();    delay(300);
  pingPong();         delay(300);
  blinkAll(2);        delay(300);
  snakeWave();        delay(300);
  randomFlash(15);    delay(300);
  slowToFast();       delay(500);
  centerOut();        delay(300);
  outsideIn();        delay(300);
  doubleChase();      delay(300);
  twinkleStars(20);   delay(300);
  heartbeatBlink(1);  delay(300);
  waveTrail();        delay(300);
}

// 1️⃣ LED Chase Forward
void chaseForward() {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  }
}

// 2️⃣ LED Chase Backward
void chaseBackward() {
  for (int i = ledCount - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  }
}

// 3️⃣ Ping Pong Effect
void pingPong() {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(60);
    digitalWrite(ledPins[i], LOW);
  }
  for (int i = ledCount - 2; i > 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(60);
    digitalWrite(ledPins[i], LOW);
  }
}

// 4️⃣ Blink All LEDs
void blinkAll(int times) {
  for (int i = 0; i < times; i++) {
    for (int j = 0; j < ledCount; j++) digitalWrite(ledPins[j], HIGH);
    delay(200);
    for (int j = 0; j < ledCount; j++) digitalWrite(ledPins[j], LOW);
    delay(200);
  }
}

// 5️⃣ Snake Wave
void snakeWave() {
  for (int step = 0; step < 4; step++) {
    for (int i = step; i < ledCount; i += 4) {
      digitalWrite(ledPins[i], HIGH);
    }
    delay(150);
    for (int i = step; i < ledCount; i += 4) {
      digitalWrite(ledPins[i], LOW);
    }
  }
}

// 6️⃣ Random Flash
void randomFlash(int times) {
  for (int i = 0; i < times; i++) {
    int randIndex = random(0, ledCount);
    digitalWrite(ledPins[randIndex], HIGH);
    delay(100);
    digitalWrite(ledPins[randIndex], LOW);
  }
}

// 7️⃣ Slow to Fast Chase
void slowToFast() {
  int delayTime = 200;
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[i], LOW);
    delayTime = max(20, delayTime - 15);  // Increase speed
  }
}

// 8️⃣ Center-Out Effect
void centerOut() {
  int mid = ledCount / 2;
  for (int i = 0; i < mid; i++) {
    digitalWrite(ledPins[mid - i - 1], HIGH);
    digitalWrite(ledPins[mid + i], HIGH);
    delay(120);
    digitalWrite(ledPins[mid - i - 1], LOW);
    digitalWrite(ledPins[mid + i], LOW);
  }
}

// 9️⃣ Outside-In Effect
void outsideIn() {
  for (int i = 0; i < ledCount / 2; i++) {
    digitalWrite(ledPins[i], HIGH);
    digitalWrite(ledPins[ledCount - 1 - i], HIGH);
    delay(120);
    digitalWrite(ledPins[i], LOW);
    digitalWrite(ledPins[ledCount - 1 - i], LOW);
  }
}

// 🔟 Double Chase
void doubleChase() {
  for (int i = 0; i < ledCount - 1; i++) {
    digitalWrite(ledPins[i], HIGH);
    digitalWrite(ledPins[i + 1], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
    digitalWrite(ledPins[i + 1], LOW);
  }
}

// 1️⃣1️⃣ Twinkle Stars
void twinkleStars(int count) {
  for (int i = 0; i < count; i++) {
    int index = random(0, ledCount);
    digitalWrite(ledPins[index], HIGH);
    delay(70);
    digitalWrite(ledPins[index], LOW);
  }
}

// 1️⃣2️⃣ Heartbeat Blink
void heartbeatBlink(int times) {
  for (int t = 0; t < times; t++) {
    for (int i = 0; i < ledCount; i++) digitalWrite(ledPins[i], HIGH);
    delay(120);
    for (int i = 0; i < ledCount; i++) digitalWrite(ledPins[i], LOW);
    delay(120);
    for (int i = 0; i < ledCount; i++) digitalWrite(ledPins[i], HIGH);
    delay(300);
    for (int i = 0; i < ledCount; i++) digitalWrite(ledPins[i], LOW);
    delay(500);
  }
}

// 1️⃣3️⃣ Wave Trail
void waveTrail() {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], HIGH);
    if (i > 0) digitalWrite(ledPins[i - 1], LOW);
    delay(80);
  }
  digitalWrite(ledPins[ledCount - 1], LOW);
}
