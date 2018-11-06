void motor_val(byte a, byte b, byte c, byte d)
{
  //  a = 0; b = 0; c = 0; d = 0;
  analogWrite(lm1, a);
  analogWrite(lm2, b);
  analogWrite(rm1, c);
  analogWrite(rm2, d);
}

void go_stop()
{
  Serial.print("Stop"); Serial.print("\t");
  motor_val(0, 0, 0, 0);
  mturn = 0;
}

void go_360()
{
  Serial.print("360"); Serial.print("\t");
  motor_val(0, throttle, throttle, 0);
}

void go_reverse()
{
  Serial.print("Reverse"); Serial.print("\t");
  motor_val(throttle, 0, throttle, 0);
}

void go_straight ()
{
  Serial.print("Straight"); Serial.print("\t");
  motor_val(0, throttle, 0, throttle);
  mturn = 3;
}

void go_sleft()
{
  Serial.print("Slight Left"); Serial.print("\t");
  motor_val(0, sleft, 0, throttle);
  mturn = 2;
}

void go_sright()
{
  Serial.print("Slight Right"); Serial.print("\t");
  motor_val(0, throttle, 0, sright);
  mturn = 4;
}

void go_hleft()
{
  //  if (mturn != 5)
  {
    Serial.print("Hard Left"); Serial.print("\t");
    motor_val(rev, 0, 0, throttle);
    mturn = 1;
  }
}

void go_hright()
{
  //  if (mturn != 1)
  {
    Serial.print("Hard Right"); Serial.print("\t");
    motor_val(0, throttle, rev, 0);
    mturn = 5;
  }
}

/*
  void go_left()
  {
  //  if (mturn != 5)
  {
    Serial.print("Left"); Serial.print("\t");
    motor_val(0, 0, 0, throttle);
  //    mturn = 1;
  }
  }

  void go_right()
  {
  //  if (mturn != 1)
  {
    Serial.print("Right"); Serial.print("\t");
    motor_val(0, throttle, 0, 0);
  //    mturn = 5;
  }
  }
*/

/*
  0=stop
  1=hl
  2=sl
  3=f
  4=sr
  5=hr
*/
