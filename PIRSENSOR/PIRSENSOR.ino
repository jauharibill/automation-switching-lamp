
const int pinLED = 13;
const int pinPIR = 2;
int pir = 0;
int state = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinLED, OUTPUT);
  pinMode(pinPIR, INPUT);
  Serial.begin(9600);
}

int TIME = 60;

void loop() {
  
  pir = digitalRead(pinPIR);

  if (pir == HIGH) {
    digitalWrite(pinLED, HIGH);

    if (state == LOW) {
      state = HIGH;
      Serial.println("Motion Detected!");
    }
    TIME = 20;
  }

  if(TIME > 0) {
    TIME--;
    delay(1000);
  }

  if (pir == LOW && TIME == 0) {
    
    digitalWrite(pinLED, LOW);

    if (state == HIGH) {
      state = LOW;
      Serial.println("Nothing Happen");
    }
  }

  
  
}
