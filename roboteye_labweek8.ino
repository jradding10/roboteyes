// robot eyes
//by Jacqueline Radding
// This displays 9 types of robot eyes depending on which IR remote button you hit(1-9)

#include <LiquidCrystal.h> // lcd library

#include <IRremote.h> // ir library
#include <ir_Lego_PF_BitStreamEncoder.h>

int receiverpin = 7; // Signal pin the IR receiver is connected to
// Create objects needed by the IRremote Library
IRrecv irrecv(receiverpin); // Create an irrecv object instance
decode_results results; // Create a place to hold the IR code read

char KeyName[9]; // 9 char key name
char KeyHigh[17]; // this will be the robot eyebrows on the top of the lcd
char KeyLow[17]; // this will be the robot eyes on the botton of the LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; // lcd pins
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // lcd pins applied

 
void setup() {
   lcd.begin(16, 2); // 16 columns x 2 rows
 lcd.setCursor(0, 1); // sends cursor to first line
 pinMode(receiverpin, INPUT_PULLUP); // Use a Pullup Resistor for the IR sensor
 // input to reduce the noise on this signal; for more

// reliable reading of this signal by the Arduino.
 Serial.begin(9600);
 Serial.println("IR Receiver Button Decode");
 irrecv.enableIRIn(); // Start the IR receiver
}


void loop() {
 if (irrecv.decode(&results)) // Have we received an IR signal?
 {

 translateIR(); // Determine which key pressed
 Serial.println(results.value, HEX);
 irrecv.resume(); // Get ready to receive the next value
 LCDdisplaykey(); // this function displays eyes on the LCD depending on what buttons are hit
 }
}




void translateIR() // takes action based on IR code received

// describing Remote IR codes
{
 switch (results.value) // hex values that result in a remote number click
 {
case 0xFF6897: Serial.print(" 0  " ); 
//strcpy(KeyName," 0 ");
strcpy(KeyHigh,".-----.  .-----.");
strcpy(KeyLow,"< (0) >  < (0) >"); // open wide
break;
 case 0xFF30CF: Serial.print(" 1   "); 
 strcpy(KeyName," 1");
 strcpy(KeyHigh,".-----.  .-----.");
strcpy(KeyLow,"< (-) >  < (-) >"); // updated squint
 break;
 case 0xFF18E7: Serial.print(" 2   ");
 strcpy(KeyName," 2 ");
 strcpy(KeyHigh,"._____.  ._____.");
strcpy(KeyLow,"< {0} >  < {0} >"); // glasses
 break;
 case 0xFF7A85: Serial.print(" 3"); 
 strcpy(KeyName," 3 ");
 strcpy(KeyHigh,"._____.  ._____.");
strcpy(KeyLow,"| -o- |  | -o- |"); // squint with glasses
 break;
 case 0xFF10EF: Serial.print(" 4 "); 
  strcpy(KeyName," 4");
  strcpy(KeyHigh," -----    ----- ");
strcpy(KeyLow,"< -+- >  < -+- >"); // target eye
  break;
 case 0xFF38C7: Serial.print(" 5 "); 
 strcpy(KeyName," 5");
 strcpy(KeyHigh,"._____.  ._____.");
strcpy(KeyLow,"<  0  >  <  0  >"); // empty stare
 break;
 case 0xFF5AA5: Serial.print(" 6"); 
 strcpy(KeyName," 6       ");
 strcpy(KeyHigh,"///////  ///////");
strcpy(KeyLow,"<(0)  >  <(0)  >");// glance to left with silly eyebrows
 break;
 case 0xFF42BD: Serial.print(" 7 "); 
strcpy(KeyName," 7  ");
strcpy(KeyHigh,"._____.  ._____");
strcpy(KeyLow,"<  /0/>  <  /o/>"); // glance to right
break;
 case 0xFF4AB5: Serial.print(" 8 "); 
 strcpy(KeyName," 8    ");
 strcpy(KeyHigh,"|||||||  |||||||");
strcpy(KeyLow,"< -=- >  < -=- >"); //shocked
 break;
 case 0xFF52AD: Serial.print(" 9 "); 
 strcpy(KeyName," 9   ");
 strcpy(KeyHigh,".-----.  .-----.");
strcpy(KeyLow,"< --- >  < --- >");//blink
 break;
 case 0xFFA25D: Serial.print(" PWR "); 
 strcpy(KeyName," PWR   ");
 break;
 case 0xFF629D: Serial.print(" VOL+ "); 
 strcpy(KeyName," VOL+      ");
 break;
 case 0xFFE21D: Serial.print(" STOP"); 
 strcpy(KeyName," STOP    ");
 break;
 case 0xFF22DD: Serial.print(" LEFT");
 strcpy(KeyName," LEFT    ");
break;
 case 0xFF02FD: Serial.print(" PAUSE"); 
 strcpy(KeyName," PAUSE   ");
 break;
 case 0xFFC23D: Serial.print(" RIGHT"); 
 strcpy(KeyName," RIGHT  ");
 break;
 case 0xFFE01F: Serial.print(" DOWN"); 
 strcpy(KeyName," DOWN   ");
 break;
 case 0xFFA857: Serial.print(" VOL-"); 
 strcpy(KeyName," VOL-     ");
 break;
 case 0xFF906F: Serial.print(" UP");
 strcpy(KeyName," UP     ");
 break;
 case 0xFF9867: Serial.print(" EQ"); 
 strcpy(KeyName," EQ    ");
 break;
 case 0xFFB04F: Serial.print(" STE "); 
 strcpy(KeyName," STEP   ");
 break;
 case 0xFFFFFFFF: Serial.print(" REPEAT"); 
 strcpy(KeyName," REPEAT   ");
 break;
 default: Serial.println(" Invalid Code"); 
 strcpy(KeyName," Invalid");
 }// End Case

 delay(500); // Do not get immediate repeat

 } //END translateIR function
//Notice that the special functions in the IRremote lib

void LCDdisplaykey(){ // displays robot eyebrows and eyes
  lcd.setCursor(0, 0); // sends cursor to first line
  lcd.print(KeyHigh);
  lcd.setCursor(0,1);
  lcd.print(KeyLow);
  
  }
