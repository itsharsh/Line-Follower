void init_pinmode()
{
  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
  for (byte i = 0; i < 5; i++)
    pinMode(ledpin[i], OUTPUT);
  pinMode(13, OUTPUT);
}
//  led grounds
//  pinMode(3, OUTPUT);
//  pinMode(8, OUTPUT);
//  pinMode(12, OUTPUT);
//  digitalWrite(3, LOW);
//  digitalWrite(8, LOW);
//  digitalWrite(12, LOW);

