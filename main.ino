int led_verde = 2;
int led_amar = 3;
int led_verm = 4;
int buzzer = 7;
int sensor_gas=0;
void setup()
{
  pinMode (led_verde, OUTPUT);
  pinMode (led_amar, OUTPUT);
  pinMode (led_verm, OUTPUT);
  pinMode (buzzer, OUTPUT);  
  pinMode(A5, INPUT);
  Serial.begin(9600);
}

void loop()
{
  sensor_gas = analogRead(A5);
  if(sensor_gas > 0) {
    ativa_sensor(sensor_gas);
  }
  else {
    desativa_sensor(sensor_gas);
  }
  delay(10);
}

void ativa_sensor(int sensor) {
  if(sensor >= 50 && sensor < 100) {
    quantidade_baixa();
  }
  if(sensor > 100 && sensor < 200) {
    quantidade_media();
  }
  if(sensor >= 200) {
    quantidade_alta();
  }
}

void quantidade_baixa() {
  digitalWrite(led_amar, LOW);
  digitalWrite(led_verm, LOW);
  digitalWrite(led_verde, HIGH);
  tone(buzzer, 250);
  delay(500);
  noTone(buzzer);
  delay(500);
}

void quantidade_media() {
  digitalWrite(led_verde, LOW);
  digitalWrite(led_verm, LOW);
  digitalWrite(led_amar, HIGH);
  tone(buzzer, 500);
  delay(250);
  noTone(buzzer);
  delay(250);
}

void quantidade_alta() {
  digitalWrite(led_amar, LOW);
  digitalWrite(led_verde, LOW);
  digitalWrite(led_verm, HIGH);
  tone(buzzer, 1000);
  delay(100);
  noTone(buzzer);
  delay(100);
}

void desativa_sensor(int sensor) {
  digitalWrite(led_verde, LOW);
  digitalWrite(led_amar, LOW);
  digitalWrite(led_verm, LOW);
  noTone(buzzer);
}