/* * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 6
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K potentiometer:
 *Black wire to Ground
 *Red wire to VCC
 *Green wire middle one to VEE
 */
// swtich 1 connected at Pin 8 and other end to GND
// switch 2 connected at Pin 9 and other end to GND
// Refer Circuit
 
int sw1 = 9;  // Connect pin 9 to SW1
int sw2 = 8;  // Connect pin 8 to SW2
int sets_cnt = 0;
int reps_cnt = 0;
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7,6,5,4,3,2);
 
void setup() 
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("CFD SCORE COUNT");
  // Declare Switches as INPUT to Arduino
  pinMode(sw1,INPUT);
  pinMode(sw2,INPUT);
  digitalWrite(sw1,HIGH);
  digitalWrite(sw2,HIGH);  
}
 
void loop() 
{
  //reset button set-up
    if(digitalRead(sw2) == LOW && digitalRead(sw1) == LOW)
  {
    sets_cnt = 0;
    reps_cnt = 0;
    lcd.setCursor(0,0);
    lcd.print("CFD SCORE COUNT");
    lcd.setCursor(0,1);
    lcd.print("                ");
    delay(2000);
  }
  else
  {
    if(digitalRead(sw1) == LOW)   // if SW1 is pressed perform action described in loop
    {
      sets_cnt++;                    
      lcd.setCursor(0, 0);
      lcd.print(String(sets_cnt) + "  set(s)       ");
      delay(300);
    }
    if(digitalRead(sw2) == LOW)    // if SW2 is pressed perform action described in loop
    {
      reps_cnt++;                     
      lcd.setCursor(0, 1);
      lcd.print( String(reps_cnt) + "  rep(s)");
      delay(300);
    }
  }

}