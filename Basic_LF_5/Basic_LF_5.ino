//0 = Extreme Left (xl)
//1 = Left (l)
//2 = Centre (c)
//3 = Right (r)
//4 = Extreme Right (xr)
//sdata is raw data
//sval is 0 or 1

byte spin[5] = {A0, A1, A2, A3, A4};
int ledpin[5] = {12, 11, 10, 8, 7};
byte lm1 = 3, lm2 = 5, rm1 = 6, rm2 = 9;

int sdata[5], smin[5], smax[5], savg[5];
byte sval[5];

byte cal_throttle = 110   , throttle = 110;
int sturn = throttle * 0.76, rev = throttle * 0.50; //159 36 130   146 36 91
byte sleft = sturn, sright = sturn;
byte mturn = 0;
int turn = 0;
int motor_stop = 0;
void setup()
{
  Serial.begin(115200);
  init_pinmode();
  led_all_glow(300);
  s_calib();
  print_scalib_val();
  led_all_dim(200);
  go_straight();
}

void loop()
{
  get_sdata();
  //  print_sdata();
  get_sval(2);      // send '0' for nothing, '1' for Back & White and, '2' for 0's & 1's
  go();
  Serial.print(turn);
  Serial.print("\t");
}
