task main(){
  //Checkar avstånd, efter en sekund checkar avstånd igen och jämför.
  SetSensorLowspeed(IN_4);
   while(1){
    int a = 0;
    int b = 0;
    int svar = 0;
    a = SensorUS(IN_4);
    Wait(1000);
    b = SensorUS(IN_4);
    if(a == b){  //står stilla
      svar = 0;
    }
    else if(a > b){ //kommer närmare
      svar = 1;
    }
    else if(a < b){ //åker ifrån
      svar = 2;
    }
    else {
      TextOut(0, 0, "Inget av ovanstående",
        DRAW_OPT_CLEAR_WHOLE_SCREEN);
    }
    TextOut(0,LCD_LINE1,NumToStr(svar),
      DRAW_OPT_CLEAR_WHOLE_SCREEN);
    TextOut(0,LCD_LINE2, "0=star stilla");
    TextOut(0,LCD_LINE3, "1=kommer narmare");
    TextOut(0,LCD_LINE4, "2=aker ifran");
  }
}