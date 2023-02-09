# define BUZZER 8
# define DO 261.63 
# define RE 293.66
# define MI 329.63
# define FA 349.23
# define SOL 392.00
# define LA 440
# define SI 493.88

int cancion[] = {DO,  RE,  MI,  FA,  SOL, LA,  SI,  DO*2};
int tiempos[] = {500, 500, 500, 500, 500, 500, 500, 500};

void setup() {
    
}

void loop() {
  tone(BUZZER, DO);
  delay(1000);
  tone(BUZZER, RE);
  delay(1000);
  tone(BUZZER, MI);
  delay(1000);
  tone(BUZZER, FA);
  delay(1000);
  tone(BUZZER, SOL);
  delay(1000);
  tone(BUZZER, LA);
  delay(1000);
  tone(BUZZER, SI);
  delay(1000);
  tone(BUZZER, DO *2);
  delay(1000);
 
  /*
  //Otra manera de tocar la canción
  for (int i=0; i<sizeof(cancion);i++){
  	tone(BUZZER, cancion[i]);
  	delay(tiempos[i]);
  }
  */  
}