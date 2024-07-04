const int TRIG_PIN = 9;   
const int ECHO_PIN = 10;  
const int RELAY_PIN = 8;   

const long UNLOCK_DISTANCE = 10;  

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); 
  Serial.begin(9600); 
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

 
  long duration = pulseIn(ECHO_PIN, HIGH);

  
  long distance = duration * 0.034 / 2;
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < UNLOCK_DISTANCE) {
    digitalWrite(RELAY_PIN, LOW); 
    Serial.println("Door Unlocked");
  } else {
    digitalWrite(RELAY_PIN, HIGH); 
    Serial.println("Door Locked");
  }
  delay(500); 
}

