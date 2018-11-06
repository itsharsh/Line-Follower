void s_calib()
{
  Serial.println("\nCalibrating sensors...");
  digitalWrite(13, HIGH);
  motor_val(0, cal_throttle, cal_throttle, 0);

  for (byte i = 0; i < 5; i++)
  {
    smin[i] = 1023;
    smax[i] = 0;
  }

  for (int j = 1; j <= 2000; j++)
  {
    get_sdata();
    for (byte i = 0; i < 5; i++)
    {
      if (sdata[i] < smin[i])
        smin[i] = sdata[i];
      else if (sdata[i] > smax[i])
        smax[i] = sdata[i];
    }
    delay(1);
  }

  for (byte i = 0; i < 5; i++)
  {
    savg[i] = (smin[i] + smax[i]) / 2;
  }
  go_stop();
  delay(1000);
  Serial.println("Done");
  digitalWrite(13, LOW);
}

void print_scalib_val()
{
  for (byte i = 0; i < 5; i++)
  {
    Serial.print(i + 1);
    Serial.print(" : Min=");
    Serial.print(smin[i]);
    Serial.print(", Max=");
    Serial.print(smax[i]);
    Serial.print(", Avg=");
    Serial.println(savg[i]);
  }
}
