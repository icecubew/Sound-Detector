/* Arduino pins where the LED is attached*/
#define LED_1 13
#define LED_2 12
#define LED_3 11
#define sensorPin A0 // Analog input pin that the Sensor is attached to

/* boolean variables to hold the status of the pins*/

bool ledPin1Status;
bool ledPin2Status;
bool ledPin3Status;

void setup() {
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);// initialize serial communications at 9600 bps:
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);

  if (sensorValue > 555)
    ledPin1Status = 1;
  if (sensorValue > 558)
    ledPin2Status = 1;
  if (sensorValue > 560)
    ledPin3Status = 1;

  if (ledPin1Status == 1 || ledPin2Status == 1 || ledPin3Status == 1 )
  {
    if (sensorValue > 555 || sensorValue < 537  )
      digitalWrite(LED_1, HIGH);

     if (sensorValue > 558 || sensorValue < 534  )
      digitalWrite(LED_2, HIGH);

     if (sensorValue > 560 || sensorValue < 534  )
      digitalWrite(LED_3, HIGH);

    delay(200);

    ledPin3Status = 0;
    ledPin2Status = 0;
    ledPin1Status = 0;
  }
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, LOW);
}
