const int potPin = A0;     // Pin where potentiometer is connected
const int ledPin = 9;      // Pin where LED is connected (PWM pin)

void setup() {
  pinMode(ledPin, OUTPUT);   // Set LED pin as output
  Serial.begin(9600);        // Start serial communication at 9600 baud rate
}

void loop() {
  int potValue = analogRead(potPin);  // Read the potentiometer value (0 to 1023)

  // Map the potentiometer value to a range suitable for the LED (0 to 255)
  int ledBrightness = map(potValue, 0, 1023, 0, 255);

  analogWrite(ledPin, ledBrightness);  // Set the LED brightness using PWM

  // Print the raw potentiometer value and the mapped brightness
  Serial.print("Potentiometer Value: ");
  Serial.print(potValue);              // Raw potentiometer value
  Serial.print(" | Mapped LED Brightness: ");
  Serial.println(ledBrightness);       // Mapped LED brightness

  delay(100);  // Small delay to avoid flooding the console
}
