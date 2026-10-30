/*
  DM3014 Interactive Devices, Ashley Hi 2026
  Week 10 - Motors & Relays
  ESP32-C3 DC Motor Control
  Start, stop, and change direction of motor.
  Additional Components: 12V DC Motor, 2-Channel 12V Relay Module
*/

const int R1 = 6; // relay 1: motor terminal A
const int R2 = 7; // relay 2: motor terminal B

void motor(int dir) { 
  digitalWrite(R1, LOW);
  digitalWrite(R2, LOW);
  delay(100);
  // 0 = stop
  if (dir == 1)  digitalWrite(R1, HIGH); //  1 = forwards
  if (dir == -1) digitalWrite(R2, HIGH); // -1 = reverse
}

void setup() {
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  motor(0);
  Serial.begin(115200);
}

void loop() {
  Serial.println("forwards");
  motor(1);
  delay(1000);

  Serial.println("stop");
  motor(0);
  delay(2000);

  Serial.println("reverse");
  motor(-1);
  delay(1000);

  Serial.println("stop");
  motor(0);
  delay(2000);
}
