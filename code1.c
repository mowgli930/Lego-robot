#define POWER 100
//Roterar runt tills den hittar föremål
//Puttar ut den samtidigt som den stannar innanför ringen 
//så länge den har nånting framför sig
//Använder raw input för color sensor, fungerar på olika
//underlag till skillnad från innan
void reverse();
void turnLeft();
void forward();
void checkobject();
void checksvartkant();
task main(){
    SetSensorColorFull(IN_3);
    SetSensorLowspeed(IN_4);
    unsigned int rawRed, rawGreen, rawBlue;
    string redStr, greenStr, blueStr;
//Vänta 3 sekunder? si senor / hombresito
     Wait(3000);
    while(true){
      turnLeft();
  }
}
checkobject();
checksvartkant();
void checksvartkant()
{
  if(ColorSensorRaw(S3,INPUT_BLUE)<96 &&
  ColorSensorRaw(S3,INPUT_GREEN)<96 &&
  ColorSensorRaw(S3,INPUT_RED)<96){
    reverse();
  }
}
void checkobject()
{
  while(SensorUS(IN_4) <= 70){
    if(ColorSensorRaw(S3,INPUT_BLUE)<96
    && ColorSensorRaw(S3,INPUT_GREEN)<96 &&
    ColorSensorRaw(S3,INPUT_RED)<96)
      break;
    forward();
  }
}
void forward()
{
  OnFwd(OUT_AC, POWER);
  Wait(15);
}
void reverse()
{
  OnRev(OUT_AC, POWER);
  Wait(700);
}
void turnLeft()
{
  OnFwd(OUT_A, POWER);
  OnRev(OUT_C, POWER);
  Wait(15);
}