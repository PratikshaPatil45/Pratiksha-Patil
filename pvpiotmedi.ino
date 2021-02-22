#include <Time.h>
#include <TimeLib.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int h=0;
int m=0;
int s=0;
int ti=0;
int ledPina = 13;
int ledPinb = 12;
int ledPinC = 11;
void setup() {
 Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  lcd.begin(16,2);
  lcd.clear();
  lcd.print(" Smart  MEDIBOX");
  lcd.setCursor(0,1);
  lcd.print("  CARE  unit   ");
  Serial.println("A");
  delay(5000);
  Serial.println("AT+CMGF=1");
  delay(3000);
  byte discard = Serial.read();
  Serial.end();
  delay(1000);
  Serial.begin(9600);
}
void loop() {

  czas();
  delay(1000);
  if(m==1){
    SendSMS();
  }
}
  
   
  void czas() {
    lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("time=");
  s +=1;
  if(s>=60){ s=s-60; m +=1;}
  if(m==60){ m=0; h +=1;}
  if(h==24){h=1;}
  lcd.print(int(h/10));
  lcd.print(h%10);
  lcd.print(":"); 
  lcd.print(int(m/10));
  lcd.print(m%10);
  lcd.print(":");
  lcd.print(int(s/10));
  lcd.print(s%10);
 
}


 void SendSMS()
{
  lcd.clear();
  lcd.print("BLOOD PRESSURE");
  Serial.println("AT+CMGF=1\r");                   //Set the module to SMS mode
  delay(100);
  Serial.println("AT+CMGS=\"9146787884\"\r");  //Your phone number don't forget to include your country code, example +212123456789"
  delay(500);
  Serial.print("SMART MEDIBOX= ITS TIME TO TAKE MEDICINE");
  delay(500);
 Serial.write(0x1A);
   delay(5000);
   lcd.clear();
  lcd.print(" Smart  MEDIBOX ");
  lcd.setCursor(0,1);
  lcd.print("  CARE     unit ");

}

