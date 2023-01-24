//Esto es un comentario de una sola linea
/*Esto es un comentatio de 
 * varias lineas
 */

#define LED_PIN D2 //Definimos que pin usaremos para conectar el led

void setup() {
  pinMode(LED_PIN, OUTPUT); //El pin lo vamos a usar en modo salida
}

void loop() {
  digitalWrite(LED_PIN, HIGH);   //Pon 3v en la salida
  delay(1000);                   //Espera 1s
  digitalWrite(LED_PIN, LOW);    //Pon 0v en la salida
  delay(1000);                   //Espera 1s
}
