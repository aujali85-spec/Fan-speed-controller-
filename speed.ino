#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

#include <DHT11.h>
DHT11 dht11(A0);

#define enA 9
#define in1 6
#define in2 7

void setup() {
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  DHT11 dht11(A0);

  // Set fixed rotation direction
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void loop() {
  int potValue = analogRead(A0); // Read potentiometer value
  int temp = dht11.readTemperature();
  int pwmOutput = map(potValue, 0, 1023, 0, 255); // Map to PWM range
  analogWrite(enA, pwmOutput); // Control motor speed
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Temp");
  lcd.setCursor(5,0);
  lcd.print(temp);
  lcd.setCursor(7,0);
  lcd.write(223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Fan Speed");
  lcd.setCursor(10,1);
  lcd.print(pwmOutput);
}
