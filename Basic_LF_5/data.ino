void get_sdata()
{
  for (byte i = 0; i < 5; i++)
  {
    sdata[i] = analogRead(spin[i]);
  }
}

void print_sdata()
{
  for (byte i = 0; i < 5; i++)
  {
    Serial.print(sdata[i]); Serial.print("\t");
  }
  Serial.println();
}
