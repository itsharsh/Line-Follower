//0 = Extreme Left (xl)
//1 = Left (l)
//2 = Centre (c)
//3 = Right (r)
//4 = Extreme Right (xr)
//sdata is raw data
//sval is 0 or 1

//Pins
byte spin[5] = {A5, A4, A3, A2, A1};        //el l c r er
int ledpin[5] = {12, 11, 10, 8, 7};         //el l c r er
byte lm1 = 11, lm2 = 10, rm1 = 9, rm2 = 6;  //Motor Pins

//Sensor Variables
int sdata[5], smin[5], smax[5];
int savg[5] = {480, 480, 480, 480, 480};  //Hard-Coded sensor calibrated values if s_calib() is not called
byte sval[5];

//Bot Control Config
byte cal_throttle = 110, throttle = 140;            //Bot Speed is controlled by throttle
int sturn = throttle * 0.76, rev = throttle * 0.50; //159 36 130   146 36 91

//Default variables
byte sleft = sturn, sright = sturn;
byte mturn = 0;
int turn = 0;
int motor_stop = 0;
void setup()
{
  Serial.begin(115200);
  init_pinmode();           //initialize motor pins as output and sensor pins as input
  //  led_all_glow(300);    //Sensor Debug Leds Glow to represent start of calibration
  //  s_calib();            //Start Calibration
  print_scalib_val();       //Calibration Results
  //  led_all_dim(200);     //Sensor Debug Leds Glow to represent stop of calibration
  go_straight();            //Command to give a little push to bot
}

void loop()
{
  get_sdata();              //Get Sensor Data
  //  print_sdata();        //Print Sensor Data
  get_sval(2);              //send '0' for nothing, '1' for Back & White and, '2' for 0's & 1's
  go();                     //Start Motors
  Serial.print(turn);       
  Serial.print("\t"); 
}
