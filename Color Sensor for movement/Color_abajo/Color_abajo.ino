const int s0 = 1;  
const int s1 = 2;  
const int s2 = 3;  
const int s3 = 4;  
const int out =5;  
const int s20 = 6;  
const int s21 = 7;  
const int s22 = 8;  
const int s23 = 9;  
const int out2 =10; 
// LED pins connected to Arduino
int redLed = 2;  
int greenLed = 12;  
int blueLed = 4;
int redLed2 = 7;  
int greenLed2 =13 ;  
int blueLed2 = 9;
// Variables  
int red = 0;  
int green = 0;  
int blue = 0;  
int red2 = 0;  
int green2 = 0;  
int blue2 = 0; 
    
void setup()   
{  
  Serial.begin(9600); 
  pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);  
  pinMode(redLed, OUTPUT);  
  pinMode(greenLed, OUTPUT);  
  pinMode(blueLed, OUTPUT);  
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, HIGH);  
   pinMode(s20, OUTPUT);  
  pinMode(s21, OUTPUT);  
  pinMode(s22, OUTPUT);  
  pinMode(s23, OUTPUT);  
  pinMode(out2, INPUT);  
  pinMode(redLed2, OUTPUT);  
  pinMode(greenLed2, OUTPUT);  
  pinMode(blueLed2, OUTPUT);  
  digitalWrite(s20, HIGH);  
  digitalWrite(s21, HIGH); 
  
  digitalWrite(greenLed2, LOW); 
   
  digitalWrite(greenLed, LOW); 

}  
    
void loop() 
{  
  color(); 
  Serial.print("R Intensity:");  
  Serial.print(red, DEC);  
  Serial.print(" G Intensity: ");  
  Serial.print(green, DEC);  
  Serial.print(" B Intensity : ");  
  Serial.print(blue, DEC);  
  //Serial.println();  
   
   if ((red>50 && red<80 ) && (green>65 && green<100) &&  (blue>40 && blue<80) )
  {  
   Serial.println(" - (White Color)");  
   digitalWrite(redLed, LOW);  
   digitalWrite(greenLed, HIGH); // Turn GREEN LED ON 
   digitalWrite(blueLed, LOW);  
  }  
   else if ((red>260 && red<300 ) && (green>325 && green<360) &&  (blue>235 && blue<260) )
  {  
   Serial.println(" - ( Black Color)");  
   digitalWrite(redLed, LOW);  
   digitalWrite(greenLed, LOW); // Turn GREEN LED ON 
   digitalWrite(blueLed, LOW);  
  } 
  else if (red < blue && red < green && red < 20)
  {  
   Serial.println(" - (Red Color)");  
   digitalWrite(redLed, HIGH); // Turn RED LED ON 
   digitalWrite(greenLed, LOW);  
   digitalWrite(blueLed, LOW);  
  }  

  else if (blue < red && blue < green)   
  {  
   Serial.println(" - (Blue Color)");  
   digitalWrite(redLed, LOW);  
   digitalWrite(greenLed, LOW);  
   digitalWrite(blueLed, HIGH); // Turn BLUE LED ON  
  }  

  else if (green < red && green < blue)  
  {  
   Serial.println(" - (Green Color)");  
   digitalWrite(redLed, LOW);  
   digitalWrite(greenLed, LOW); // Turn GREEN LED ON 
   digitalWrite(blueLed, LOW);  
  }  

  else{
  Serial.println();  
  }
  
  delay(1000);   
  digitalWrite(redLed, LOW);  
  digitalWrite(greenLed, LOW);  
  digitalWrite(blueLed, LOW);  

  color2(); 
  Serial.print("R2 Intensity:");  
  Serial.print(red2, DEC);  
  Serial.print(" G2 Intensity: ");  
  Serial.print(green2, DEC);  
  Serial.print(" B2 Intensity : ");  
  Serial.print(blue2, DEC);  
  //Serial.println();  
   
   if (((red2>170 &&  red2<210 ) && (green2>230 && green2<265) &&  (blue2>235 && blue2<250)) or ((red2>360 &&  red2<400 ) && (green2>405 && green2<420) &&  (blue2>345 && blue2<375)) )
  { 
   Serial.println(" - (Yellow Color)");  
   digitalWrite(redLed2, LOW);  
   digitalWrite(greenLed2, HIGH); // Turn GREEN LED ON 
   digitalWrite(blueLed2, LOW);  
  }  
   else if ((red2>260 && red2<300 ) && (green2>325 && green2<360) &&  (blue2>230 && blue2<260) )
  {  
   Serial.println(" - ( Black Color)");  
   digitalWrite(redLed2, LOW);  
   digitalWrite(greenLed2, LOW); // Turn GREEN LED ON 
   digitalWrite(blueLed2, LOW);  
  } 
  else if (red2 < blue2 && red2 < green2 && red2 < 20)
  {  
   Serial.println(" - (Red Color)");  
   digitalWrite(redLed2, HIGH); // Turn RED LED ON 
   digitalWrite(greenLed2, LOW);  
   digitalWrite(blueLed2, LOW);  
  }  

  else if (blue2 < red2 && blue2 < green2)   
  {  
   Serial.println(" - (Blue Color)");  
   digitalWrite(redLed2, LOW);  
   digitalWrite(greenLed2, LOW);  
   digitalWrite(blueLed2, HIGH); // Turn BLUE LED ON  
  }  

  else if (green2 < red2 && green2 < blue2)  
  {  
   Serial.println(" - (Green Color)");  
   digitalWrite(redLed2, LOW);  
   digitalWrite(greenLed2, HIGH); // Turn GREEN LED ON 
   digitalWrite(blueLed2, LOW);  
  }  

  else{
  Serial.println();  
  }
  
  delay(1000);   
  digitalWrite(redLed2, LOW);  
  digitalWrite(greenLed2, LOW);  
  digitalWrite(blueLed2, LOW);  
 }  
   
void color()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  //count OUT, pRed, RED  
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
  //count OUT, pBLUE, BLUE  
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  //count OUT, pGreen, GREEN  
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
   
  
}

void color2()  
{    
  digitalWrite(s22, LOW);  
  digitalWrite(s23, LOW);  
  //count OUT2, pRed, RED  
  red2 = pulseIn(out2, digitalRead(out2) == HIGH ? LOW : HIGH);  
  digitalWrite(s23, HIGH);  
  //count OUT, pBLUE, BLUE  
  blue2 = pulseIn(out2, digitalRead(out2) == HIGH ? LOW : HIGH);  
  digitalWrite(s22, HIGH);  
  //count OUT, pGreen, GREEN  
  green2 = pulseIn(out2, digitalRead(out2) == HIGH ? LOW : HIGH);
   
  
}

