/* This mini PLC created by arduino UNO and 4*10Amps relay moduale and HMI 16*2 LCD controlled locally by 2 mini switch  
*/
// define LCD Pins
#include <LiquidCrystal.h>   
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// define character for LCD
// filled rectangle
byte OnChar[8] = {
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};
// ON character word
byte OnCharW[8] = {
  0b11111,
  0b00010,
  0b01000,
  0b11111,
  0b00000,
  0b11111,
  0b10001,
  0b11111
};
// empty rectangle
byte OffChar[8] = {
  0b11111,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b11111
};
// OFF character word
byte OffCharW[8] = {
  0b10100,
  0b11111,
  0b10100,
  0b11111,
  0b00000,
  0b11111,
  0b10001,
  0b11111
};

// declare 2 button
int SW = 13;
int SW2 = 10;
// initial value
int value = 0;
// declare output 
int relay1 = 9;
int relay2 = 8;
int relay3 = 7;
int relay4 = 6;
// delay 
int d = 500;

// setup the things
void setup() {
  pinMode (SW,INPUT);
  pinMode (SW2,INPUT);
  
  pinMode (relay1,OUTPUT);
  pinMode (relay2,OUTPUT);
  pinMode (relay3,OUTPUT);
  pinMode (relay4,OUTPUT);

  // for initial start I want them in Off mode
  digitalWrite (relay1, HIGH);
  digitalWrite (relay2, HIGH);
  digitalWrite (relay3, HIGH);
  digitalWrite (relay4, HIGH);

  // intro 
  lcd.begin(16,2);
  lcd.print("PLC Power ON");
  delay(2000);
  lcd.clear();
  
  // setup LCD Cursor(0,1) characters
  lcd.print("Relay Set = ");
  lcd.createChar(0, OnChar);
  lcd.createChar(2, OnCharW);
  lcd.createChar(1, OffChar);
  lcd.createChar(3, OffCharW);
}

// Relay set=
// choose your relay by this function "worked as set parameter"
void PwRe(int i){
  if (i==HIGH && value==0)
{ value++;
  lcd.setCursor(11,0);
lcd.print("1  ON");
  delay (d);}
  else if (i==HIGH && value==1)
{value++;
 lcd.setCursor(11,0);
lcd.print("2  ON");
  delay (d);}
  else if (i==HIGH && value==2)
{value++;
 lcd.setCursor(11,0);
lcd.print("3  ON");
  delay (d);}
  else if(i==HIGH && value==3){
 value++;
 lcd.setCursor(11,0);
lcd.print("4  ON");
  delay (d);}
  else if(i==HIGH && value==4){
 value++;
 lcd.setCursor(11,0);
lcd.print("1 OFF");
  delay (d);}
  else if(i==HIGH && value==5){
 value++;
 lcd.setCursor(11,0);
lcd.print("2 OFF");
  delay (d);}
  else if(i==HIGH && value==6){
 value++;
 lcd.setCursor(11,0);
lcd.print("3 OFF");
  delay (d);}
  else if(i==HIGH && value==7){
 value++;
 lcd.setCursor(11,0);
lcd.print("4 OFF");
  delay (d);}
  else if(i==HIGH && value==8){
 value=1;
 lcd.setCursor(11,0);
lcd.print("1  ON");
  delay (d);}}

// the selector code "relay activator"
void on(int e)
{switch (value)
  {
    case 1:
    {if ((e==HIGH)){
    digitalWrite(relay1,LOW);
    lcd.setCursor(1,1);
    lcd.write(byte(0));
    lcd.write(byte(2));
   }}
    break ;
      case 2:
    {if (e==HIGH ){
    digitalWrite(relay2,LOW);
    lcd.setCursor(5,1);
      lcd.write(byte(0));
    lcd.write(byte(2));}}
    break ;
      case 3:
    {if (e==HIGH ){
    digitalWrite(relay3,LOW);
    lcd.setCursor(9,1);
      lcd.write(byte(0));
    lcd.write(byte(2));}}
    break ;
      case 4:
    {if (e==HIGH ){
    digitalWrite(relay4,LOW);
    lcd.setCursor(13,1);
      lcd.write(byte(0));
    lcd.write(byte(2));}}
    break ;
    case 5:
    {if ((e==HIGH)){
    digitalWrite(relay1,HIGH);
    lcd.setCursor(1,1);
    lcd.write(byte(1));
    lcd.write(byte(3));}}
    break ;
   case 6:
    {if ((e==HIGH)){
    digitalWrite(relay2,HIGH);
    lcd.setCursor(5,1);
     lcd.write(byte(1));
    lcd.write(byte(3));}}
    break ;
   case 7:
    {if ((e==HIGH)){
    digitalWrite(relay3,HIGH);
    lcd.setCursor(9,1);
     lcd.write(byte(1));
    lcd.write(byte(3));}}
    break ;
   case 8:
    {if ((e==HIGH)){
    digitalWrite(relay4,HIGH);
    lcd.setCursor(13,1);
    lcd.write(byte(1));
    lcd.write(byte(3));}}
    break ;}}

// display Cursor(0,1) relay numbers
  void screen ()
  {
    lcd.setCursor(0,1);
    lcd.print("1");
    lcd.setCursor(4,1);
    lcd.print("2");
    lcd.setCursor(8,1);
    lcd.print("3");
    lcd.setCursor(12,1);
    lcd.print("4");
  }

void loop() {
int w=digitalRead (SW);
int w2=digitalRead (SW2);
PwRe(w);
on(w2); 
screen ();}
