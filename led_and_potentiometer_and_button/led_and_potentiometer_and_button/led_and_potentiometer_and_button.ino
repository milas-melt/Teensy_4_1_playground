const int potPin = A0;     // Pin where potentiometer is connected
const int ledPin = 9;      // Pin where LED is connected (PWM pin)
const int buttonPin = 2;   // Pin where button is connected

bool ledState = false;     // Variable to store the LED state (on/off)
bool lastButtonState = HIGH; // Tracks the previous button state
bool buttonPressed = false;  // Tracks if the button was pressed

void setup() {
  pinMode(ledPin, OUTPUT);   // Set LED pin as output
  pinMode(buttonPin, INPUT_PULLUP);  // Set button pin as input with internal pull-up resistor
  Serial.begin(9600);        // Start serial communication at 9600 baud rate
}

void loop() {
  // Read the button state
  bool buttonState = digitalRead(buttonPin);

  // Check if the button is pressed (and debounced)
  if (buttonState == LOW && lastButtonState == HIGH) {
    buttonPressed = !buttonPressed; // Toggle buttonPressed state
    delay(50);  // Basic debounce delay
  }

  lastButtonState = buttonState;  // Update last button state

  // If the button is pressed, toggle the LED on/off state
  if (buttonPressed) {
    int potValue = analogRead(potPin);  // Read the potentiometer value (0 to 1023)
    int ledBrightness = map(potValue, 0, 1023, 0, 255);  // Map potentiometer to LED brightness

    analogWrite(ledPin, ledBrightness);  // Set LED brightness
  } else {
    analogWrite(ledPin, 0);  // Turn off the LED
  }

  // Print potentiometer value and button status
  Serial.print("Potentiometer Value: ");
  Serial.print(analogRead(potPin));
  Serial.print(" | LED State: ");
  Serial.println(buttonPressed ? "ON" : "OFF");

  delay(100);  // Small delay for smoother operation
}
