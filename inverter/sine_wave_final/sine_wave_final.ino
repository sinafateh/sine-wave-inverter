#define DEAD_TIME 200 // Dead time in microseconds (200 us)
#define PERIOD 20000  // Period in microseconds for 50Hz (20ms)
#define PWM_PIN 9     // PWM output pin
volatile bool toggle = false;

void setup() {
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(PWM_PIN, OUTPUT);

  // Set initial states
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);

  // Configure Timer1 for 50Hz toggle
  cli(); // Stop interrupts
  TCCR1A = 0; // Normal mode
  TCCR1B = 0; // Reset Timer1 configuration
  TCNT1 = 0;  // Reset Timer1 counter

  // Set compare match value for 50Hz
  OCR1A = PERIOD * 16 - 1; // Convert period to timer ticks (16MHz clock)

  TCCR1B |= (1 << WGM12); // CTC mode
  TCCR1B |= (1 << CS10);  // No prescaler

  TIMSK1 |= (1 << OCIE1A); // Enable Timer1 compare interrupt

  // Configure Timer2 for PWM
  TCCR2A = 0; // Reset Timer2 configuration
  TCCR2B = 0; // Reset Timer2 configuration
  TCNT2 = 0;  // Reset Timer2 counter

  TCCR2A |= (1 << WGM20) | (1 << WGM21); // Fast PWM mode
  TCCR2A |= (1 << COM2B1);               // Non-inverting mode on pin 9
  TCCR2B |= (1 << CS21);                 // Prescaler 8

  sei(); // Enable interrupts
}

ISR(TIMER1_COMPA_vect) {
  if (toggle) {
    // Turn off pin 5, apply dead time, then turn on pin 6
    digitalWrite(5, LOW);
    delayMicroseconds(DEAD_TIME);
    digitalWrite(6, HIGH);
  } else {
    // Turn off pin 6, apply dead time, then turn on pin 5
    digitalWrite(6, LOW);
    delayMicroseconds(DEAD_TIME);
    digitalWrite(5, HIGH);
  }
  toggle = !toggle; // Alternate the toggle state
}

void loop() {
  // Read the analog value from pin A0 (0 to 1023)
  int analogValue = analogRead(A0);

  // Map the analog value to a PWM duty cycle (0 to 255)
  int pwmValue = map(analogValue, 0, 1023, 0, 255);

  // Set the PWM duty cycle on Timer2 (Pin 9)
  OCR2B = pwmValue;
}
