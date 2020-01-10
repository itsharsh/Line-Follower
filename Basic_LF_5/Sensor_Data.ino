void get_sdata() {
  for (byte i = 0; i < 5; i++)
    sdata[i] = analogRead(spin[i]);
}

void print_sdata() {
  for (byte i = 0; i < 5; i++) {
    Serial.print(sdata[i]); Serial.print("\t");
  }
  Serial.println();
}

void get_sval(byte tmp) {
  if (tmp == 1 || tmp == 2)
    Serial.println();
  for (byte i = 0; i < 5; i++){
    if (sdata[i] < savg[i]){
      sval[i] = 1;
      switch (tmp){
        case 1:
          Serial.print("White\t"); break;
        case 2:
          Serial.print(sval[i]); Serial.print("\t");
          break;
      }
    }
    else if (sdata[i] >= savg[i]){
      led_glow(i);
      sval[i] = 0;
      switch (tmp){
        case 1:
          Serial.print("Black\t"); break;
        case 2:
          Serial.print(sval[i]); Serial.print("\t");
          break;
      }
    }
  }
}
