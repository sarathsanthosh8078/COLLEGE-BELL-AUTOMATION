#include <DS3231.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int Relay = 7;
int mode =6;

DS3231  rtc(A0, A1);
Time t;




void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  rtc.begin();
  pinMode(Relay, OUTPUT);
  digitalWrite(Relay, HIGH);
  pinMode(mode, INPUT);
  
}

void loop() {
  t = rtc.getTime();
  lcd.setCursor(0,0);
  lcd.print("Time:");
  lcd.setCursor(7,0);
  lcd.print(rtc.getTimeStr());
if (mode = HIGH)
{
  Exam_mode();
}
else 
{
  if(rtc.getDOWStr()== "Monday" || rtc.getDOWStr()== "Tuesday" || rtc.getDOWStr()== "Wednesday" || rtc.getDOWStr()== "Thursday" )
  {
  
if( (t.hour == 10 && t.min ==00 && t.sec == 00)|| 
  (t.hour == 11 && t.min ==00 && t.sec == 00)||
  (t.hour == 11 && t.min ==10 && t.sec == 00)||
  (t.hour == 12 && t.min ==10 && t.sec == 00)||
  (t.hour == 13 && t.min ==00 && t.sec == 00)||
  (t.hour == 14 && t.min ==00 && t.sec == 00)||
  (t.hour == 15 && t.min ==00 && t.sec == 00)||
  (t.hour == 16 && t.min ==00 && t.sec == 00))
  {
    digitalWrite(Relay,LOW);
    lcd.setCursor(4,1);
    lcd.println("BELL ON ");
    delay(3000);
    digitalWrite(Relay,HIGH);
    lcd.setCursor(4,1);
    lcd.println("BELL OFF");
    lcd.clear();
    
    }
    
  }

 else if((t.hour == 9 && t.min ==00 && t.sec == 00)|| 
     (t.hour == 4&& t.min ==00 && t.sec == 00))                     // loop for loon bell 
     {

    digitalWrite(Relay,LOW);
    lcd.setCursor(4,1);
    lcd.println("BELL ON");
    delay(6000);                                           // bell last for 6 sec
    digitalWrite(Relay,HIGH);
    lcd.setCursor(4,1);
    lcd.println("BELL OFF");
    lcd.clear();
      
     }
  else if(rtc.getDOWStr() == "Friday")
  {
if((t.hour == 9 && t.min ==00 && t.sec == 00)|| 
  (t.hour == 10 && t.min ==00 && t.sec == 00)|| 
  (t.hour == 11 && t.min ==00 && t.sec == 00)||
  (t.hour == 11 && t.min ==10 && t.sec == 00)||
  (t.hour == 12 && t.min ==10 && t.sec == 00)||
  (t.hour == 14 && t.min ==00 && t.sec == 00)||
  (t.hour == 15 && t.min ==00 && t.sec == 00)||
  (t.hour == 16 && t.min ==00 && t.sec == 00))
  {
    digitalWrite(Relay,LOW);
    lcd.setCursor(4,1);
    lcd.println("BELL ON");
    delay(3000);
    digitalWrite(Relay,HIGH);
    lcd.setCursor(4,1);
    lcd.println("BELL OFF");
    lcd.clear();
    }
  else if((t.hour == 9 && t.min ==00 && t.sec == 00)|| 
     (t.hour == 4&& t.min ==00 && t.sec == 00))                     // loop for long bell 
     {

    digitalWrite(Relay,LOW);
    lcd.setCursor(4,1);
    lcd.println("BELL ON");
    delay(6000);                                           // bell last for 6 sec
    digitalWrite(Relay,HIGH);
    lcd.setCursor(4,1);
    lcd.println("BELL OFF");
    lcd.clear();
      
     }
  }
}
}
int Exam_mode()                                            //function for exam 
{
   if(rtc.getDOWStr()== "Monday" || rtc.getDOWStr()== "Tuesday" || rtc.getDOWStr()== "Wednesday" || rtc.getDOWStr()== "Thursday" )           // condition for normal working day except friday
   {
if( 
  (t.hour == 10 && t.min ==30 && t.sec == 00)|| 
  (t.hour == 11 && t.min ==30 && t.sec == 00)||
  (t.hour == 14 && t.min ==30 && t.sec == 00)||
  (t.hour == 15 && t.min ==30 && t.sec == 00))
  {
     digitalWrite(Relay,LOW);
    lcd.setCursor(4,1);
    lcd.println("BELL ON");
    delay(3000);
    digitalWrite(Relay,HIGH);
    lcd.setCursor(4,1);
    lcd.println("BELL OFF");
    lcd.clear();
   }
else if((t.hour == 9 && t.min ==30 && t.sec == 00)||
        (t.hour == 12 && t.min ==30 && t.sec == 00)||
        (t.hour == 13 && t.min ==30 && t.sec == 00)||
        (t.hour == 16 && t.min ==30 && t.sec == 00))
        {
            digitalWrite(Relay,LOW);
    lcd.setCursor(4,1);
    lcd.println("BELL ON");
    delay(6000);
    digitalWrite(Relay,HIGH);
    lcd.setCursor(4,1);
    lcd.println("BELL OFF");
    lcd.clear();
        }
  
}
 if(rtc.getDOWStr()== "Friday" )                        // condition for friday
   {
if( 
  (t.hour == 10 && t.min ==30 && t.sec == 00)|| 
  (t.hour == 11 && t.min ==30 && t.sec == 00)||
  (t.hour == 15 && t.min ==00 && t.sec == 00)||
  (t.hour == 16 && t.min ==00 && t.sec == 00))
  {
     digitalWrite(Relay,LOW);
    lcd.setCursor(4,1);
    lcd.println("BELL ON");
    delay(3000);
    digitalWrite(Relay,HIGH);
    lcd.setCursor(4,1);
    lcd.println("BELL OFF");
    lcd.clear();
   }
else if((t.hour == 9 && t.min ==30 && t.sec == 00)||
        (t.hour == 12 && t.min ==30 && t.sec == 00)||
         (t.hour == 14 && t.min ==00 && t.sec == 00)||
        (t.hour == 17 && t.min ==00 && t.sec == 00))
        {
            digitalWrite(Relay,LOW);
    lcd.setCursor(4,1);
    lcd.println("BELL ON");                                //LOOP FOR LONG BELL
    delay(6000);
    digitalWrite(Relay,HIGH);
    lcd.setCursor(4,1);
    lcd.println("BELL OFF");
    lcd.clear();
        }
  
}
}
