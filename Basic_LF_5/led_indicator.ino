void led_all_glow(int lag){
  for (byte i = 0; i < 5; i++)  {
    digitalWrite(ledpin[i], HIGH);
    delay(lag);
  }
}

void led_all_dim(int lag){
  for (byte i = 0; i < 5; i++)  {
    digitalWrite(ledpin[i], LOW);
    delay(lag);
  }
}

void led_glow(byte led){
  led_all_dim(0);
  digitalWrite(ledpin[led], HIGH);
}
