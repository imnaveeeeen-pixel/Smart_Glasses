#define trigPin 2
#define echoPin 3
#define voicePin 4  // Connected to ISD1820 playback (P-E or P-L)

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(voicePin, OUTPUT);
  digitalWrite(voicePin, LOW);
  Serial.begin(9600);
}

void loop() {
  // Trigger ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read echo
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance > 0 && distance < 50) { // If obstacle < 50 cm
    digitalWrite(voicePin, HIGH);  // Trigger voice playback
    delay(1000);                   // Wait to finish message
    digitalWrite(voicePin, LOW);   // Reset trigger
  }

  delay(500);  // Avoid rapid triggering
}