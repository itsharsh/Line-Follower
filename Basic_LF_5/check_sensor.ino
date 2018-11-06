int all0 = 0;
int all1 = 0;
byte chk_hard90 = 0;
int tpoint_turn = 1; //1 for left, 5 for right
int tpoint_mturn = 5;
int intersection_turn = 5; //1 for left, 5 for right
int intersection_mturn = 1;

void go()
{ /*
    if (sval[0] == 0 && sval[1] == 0 && sval[2] == 0 && sval[3] == 0 && sval[4] == 0) //All 0
     all_0();
    else */if (sval[0] == 1 && sval[1] == 1 && sval[2] == 1 && sval[3] == 1 && sval[4] == 1)  //All 1
    all_1();

  else
  {
    all0 = 0;
    all1 = 0;

    if (sval[0] == 0 && sval[1] == 0 && sval[2] == 1 && sval[3] == 0 && sval[4] == 0)  //Straight
    {
      turn = -1;
      go_straight();
    }
    else if (sval[0] == 0 && sval[1] == 1 && sval[2] == 0 && sval[3] == 0 && sval[4] == 0 && (mturn == 1 || mturn == 3))  //Slight Left
    {
      turn = 0;
      go_sleft();
    }
    else if (sval[0] == 0 && sval[1] == 0 && sval[2] == 0 && sval[3] == 1 && sval[4] == 0 && (mturn == 3 || mturn == 5))  //Slight Right
    {
      turn = 0;
      go_sright();
    }
    /*
        else if (sval[0] == 1 && sval[2] == 1 && sval[4] == 1 && (turn == -1 || turn == 0) && mturn != intersection_mturn) //Intersection Center
          intersection();

        else if (sval[0] == 1 && sval[2] == 0 && sval[4] == 1 && (turn == -1 || turn == 0 || turn == 4) && mturn != tpoint_mturn) //T-point
          tpoint();

        else if (sval[0] == 1 && sval[1] == 1 && sval[2] == 1 && (turn == -1 || turn == 0)) //Acute Left
          acute(1);
        else if (sval[3] == 1 && sval[4] == 1 && sval[2] == 1 && (turn == -1 || turn == 0)) //Acute Right
          acute(2);

        else if (sval[0] == 1 && sval[4] == 0 && (sval[1] == 1 || sval[2] == 1 || sval[3] == 1) && turn != 3) //Cut Left
          cut(1);
        else if (sval[0] == 0 && sval[4] == 1 && (sval[1] == 1 || sval[2] == 1 || sval[3] == 1) && turn != 3) //Cut Right
          cut(2);
    */
    else if (sval[0] == 1 && sval[2] == 0 && sval[3] == 0 && sval[4] == 0 && (turn == -1 || turn == 0)) //Hard90 Left
      hard90(1);
    else if (sval[0] == 0 && sval[1] == 0 && sval[2] == 0 && sval[4] == 1 && (turn == -1 || turn == 0)) //Hard90 Right
      hard90(2);
    /*
        else if (sval[0] == 1 && sval[1] == 1 && sval[2] == 0 && (turn == -1 || turn == 0)) //Acute Left
          acute(1);
        else if (sval[3] == 1 && sval[4] == 1 && sval[2] == 0 && (turn == -1 || turn == 0)) //Acute Right
          acute(2);
    */
    else if (sval[0] == 0 && sval[1] == 1 && sval[3] == 1 && sval[1] == 0 ) //
    {
      go_straight(); delay(120);
    }

    else
      prev();
    //  Serial.print("\t"); Serial.print(turn);
  }
}

void intersection()
{
  Serial.print("Intersection\t");
  turn = 1;
  if (intersection_turn == 1)
    go_hleft();
  else if (intersection_turn == 5)
    go_hright();
}

void tpoint()
{
  Serial.print("T-point\t");
  turn = 2;
  if (tpoint_turn == 1)
    go_hleft();
  else if (tpoint_turn == 5)
    go_hright();
}

void acute(byte chk)
{
  Serial.print("Acute\t");
  turn = 3;
  go_straight();
  delay(8);
  if (chk == 1)
    go_hleft();
  else if (chk == 2)
    go_hright();
}

void hard90(byte chk)
{
  Serial.print("90\t");
  chk_hard90 = chk;
  turn = 4;
  if (chk_hard90 == 1)
    go_hleft();
  else if (chk_hard90 == 2)
    go_hright();
}

void cut (byte chk)
{
  Serial.print("Cut\t");
  turn = 5;
  if (chk == 1)
    go_hleft();
  else if (chk == 2)
    go_hright();
}

void all_0()
{
  prev();
  all1 = 0;
  all0++;
  if (all0 > 400 && mturn == 3)
  {
    all0 = 0;
    //    led_glow(5);
    //    go_stop();
    //    delay(3000);
    //    go_prev();
    //      go_reverse();
    //      delay(250);
    //      go_360();
  }
}

void all_1()
{
  all0 = 0;
  all1++;
  if (all1 > 80)
  {
    all1 = 0;
    go_stop();
    //    delay(3000);
    //    go_reverse();
    //    delay(270);
    //    go_360();
    //    delay(670);
  }
}

void prev()
{
  switch (mturn)
  {
    case 1:
      go_hleft(); break;
    case 2:
      go_sleft(); break;
    case 3:
      go_straight(); break;
    case 4:
      go_sright(); break;
    case 5:
      go_hright(); break;
  }
}
/*
  turn
  -1=Straight
  0=Soft
  1=Intersection
  2=T-point
  3=Acute
  4=Hard 90
  5=Cut

  mturn

  0=stop
  1=hl
  2=sl
  3=f
  4=sr
  5=hr
*/
