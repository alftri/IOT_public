//usamos la palabra const si el valor no va a cambiar nunca
const int pin_pulsador = 10; // GPIO10 de nuestra placa NodeMCU, que está conectado al pulsador
const int pin_led = 4;  // GPIO4 de nuestra placa NodeMCU, que está conectado al led

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status


void setup() {
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(pin_led, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(pin_pulsador, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(pin_pulsador);
  Serial.println(buttonState);  
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(pin_led, HIGH);
  } else {
    // turn LED off:
    digitalWrite(pin_led, LOW);
  }
  delay(100);
}
