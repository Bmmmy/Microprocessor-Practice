#include <LiquidCrystal.h>
#include <Keypad.h>
#define Ls138_A 30
#define Ls138_B 31
#define Ls138_C 32
#define R0 2
#define R1 3
#define R2 4
#define R3 5
#define R4 6
#define R5 7
#define R6 8
#define R7 9
#define row_size 8
#define col_size 8
#define delay_time 300
#define data_1 {0,1,1,0,1,0,1,1,\
                0,0,0,0,0,0,0,0,\
                1,1,0,0,0,1,0,1,\
                0,0,0,0,0,0,0,0,\
                1,0,0,0,0,1,0,0,\
                0,1,0,1,0,0,0,0,\
                0,0,1,0,0,0,0,0,\
                1,0,0,0,0,0,0,0}
#define data_2 {0,1,1,0,1,0,1,1,\
                1,0,0,0,0,0,0,0,\
                1,1,0,0,1,1,0,1,\
                0,0,1,0,0,0,1,0,\
                1,0,0,1,0,1,0,0,\
                0,1,0,1,0,0,0,0,\
                0,0,1,0,0,0,0,0,\
                1,0,0,0,0,0,0,0}
#define data_3 {0,1,1,0,1,0,1,1,\
                0,0,0,1,0,1,0,0,\
                1,1,0,0,0,1,0,1,\
                0,0,0,1,0,1,1,0,\
                1,0,0,0,0,1,0,0,\
                0,1,0,1,0,0,1,0,\
                0,0,1,0,0,1,0,0,\
                1,0,1,0,1,0,1,0}                
#define data_0 {0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0}                
#define data_4 {0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,1,1,0,0,0,\
                0,0,0,1,1,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0}
#define data_5 {0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,1,1,1,1,0,0,\
                0,0,1,1,1,1,0,0,\
                0,0,1,1,1,1,0,0,\
                0,0,1,1,1,1,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0}
                
#define data_6 {0,0,0,0,0,0,0,0,\
                0,1,1,1,1,1,1,0,\
                0,1,1,1,1,1,1,0,\
                0,1,1,1,1,1,1,0,\
                0,1,1,1,1,1,1,0,\
                0,1,1,1,1,1,1,0,\
                0,1,1,1,1,1,1,0,\
                0,0,0,0,0,0,0,0}
                
#define data_7 {1,1,1,1,1,1,1,1,\
              1,1,1,1,1,1,1,1,\
              1,1,1,1,1,1,1,1,\
              1,1,1,1,1,1,1,1,\
              1,1,1,1,1,1,1,1,\
              1,1,1,1,1,1,1,1,\
              1,1,1,1,1,1,1,1,\
              1,1,1,1,1,1,1,1}
              
 #define data_a0 {1,1,1,1,1,1,1,0,\
                1,1,1,1,1,1,1,1,\
                1,1,1,1,1,1,1,1,\
                1,1,1,1,1,1,1,1,\
                1,1,1,1,1,1,1,1,\
                1,1,1,1,1,1,1,1,\
                0,0,1,1,1,1,1,1,\
                1,0,1,1,1,1,1,1}

#define data_a1 {1,1,1,1,1,1,1,0,\
                1,1,1,1,1,1,1,1,\
                1,1,1,1,1,1,1,1,\
                0,1,1,1,1,1,1,1,\
                0,1,1,1,1,1,1,1,\
                0,1,1,1,1,1,1,1,\
                0,1,1,1,1,1,1,1,\
                1,1,1,1,1,1,1,1}
                
#define data_a2 {1,1,1,1,1,1,1,0,\
                1,1,1,1,1,1,1,1,\
                1,1,1,1,1,1,1,1,\
                0,0,0,1,1,1,1,1,\
                1,1,1,1,1,1,1,1,\
                1,1,1,1,1,1,1,1,\
                1,1,1,1,1,1,1,1,\
                1,1,1,1,1,1,1,1}
#define data_a3 {1,1,1,1,1,1,1,0,\
                1,1,0,1,1,1,1,1,\
                1,1,0,1,1,1,1,1,\
                1,1,0,1,1,1,1,1,\
                1,1,0,1,1,1,1,1,\
                1,1,1,1,1,1,1,1,\
                1,1,1,1,1,1,1,1,\
                1,1,1,1,1,1,1,1}
#define data_a4 {1,1,1,1,1,1,1,0,\
                1,0,0,0,0,1,1,1,\
                1,1,1,1,1,1,1,1,\
                1,1,1,1,1,1,1,1,\
                1,1,1,1,1,1,1,1,\
                1,1,1,1,1,1,1,1,\
                1,1,1,1,1,1,1,1,\
                1,1,1,1,1,1,1,1}
#define data_a5 {1,1,1,1,1,0,1,0,\
                1,1,1,1,0,0,1,1,\
                1,1,1,1,1,0,1,1,\
                1,1,1,1,1,0,1,1,\
                1,1,1,1,1,1,1,1,\
                1,1,1,1,1,1,1,1,\
                1,1,1,1,1,1,1,1,\
                1,1,1,1,1,1,1,1}
#define data_a6 {1,1,1,1,1,1,1,0,\
                1,1,1,1,1,1,0,1,\
                1,1,1,1,1,1,0,1,\
                1,1,1,1,1,0,0,1,\
                1,1,1,1,1,1,0,1,\
                1,1,1,1,1,1,0,1,\
                1,1,1,1,1,1,1,1,\
                1,1,1,1,1,1,1,1}
#define data_a7 {1,1,1,1,1,1,1,0,\
                1,1,1,1,1,1,1,1,\
                1,1,1,1,1,1,1,1,\
                1,1,1,1,1,1,1,1,\
                1,1,1,1,1,1,1,1,\
                1,1,1,1,1,0,0,0,\
                1,1,1,1,1,1,1,1,\
                1,1,1,1,1,1,1,1}
#define data_a8 {1,1,1,1,1,1,1,0,\
                1,1,1,1,1,1,1,0,\
                1,1,1,1,1,1,1,0,\
                1,1,1,1,1,1,1,0,\
                1,1,1,1,1,1,1,0,\
                1,1,1,1,1,1,1,0,\
                1,1,1,1,1,1,1,1,\
                1,1,1,1,1,1,1,1}

#define data_a9 {1,1,1,1,1,1,1,1,\
                1,1,1,1,1,1,1,1,\
                1,1,1,1,1,1,1,1,\
                1,1,1,1,1,1,1,1,\
                1,1,1,1,1,1,1,1,\
                1,1,1,1,1,1,1,1,\
                1,1,1,1,1,1,1,1,\
                1,1,1,1,1,1,1,1}
#define data_a10{0,0,0,0,0,0,0,1,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0}
#define data_a11{0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0,\
                0,0,0,0,0,0,0,0}             
#define data_99 {1,1,1,1,1,1,1,1,\
                1,0,0,0,0,0,0,1,\
                1,0,1,1,1,1,0,1,\
                1,0,1,1,0,1,0,1,\
                1,0,0,0,0,1,0,1,\
                1,1,1,1,1,1,0,1,\
                1,1,0,0,0,0,0,1,\
                1,1,1,1,1,1,1,1}
                
#define data_fail{1,0,0,0,0,0,0,1,\
                  0,1,0,0,0,0,1,0,\
                  0,0,1,0,0,1,0,0,\
                  0,0,0,1,1,0,0,0,\
                  0,0,0,1,1,0,0,0,\
                  0,0,1,0,0,1,0,0,\
                  0,1,0,0,0,0,1,0,\
                  1,0,0,0,0,0,0,1}
const byte ROWS =4;
const byte COLS =4;
char hexaKeys[ROWS][COLS]={
                        {'F','E','D','C'},
                        {'B','3','6','9'},
                        {'A','2','5','8'},
                        {'0','1','4','7'}};
byte rowPins[ROWS]={25,24,23,22};
byte colPins[COLS]={29,28,27,26};
LiquidCrystal lcd(49,48,47,43,42,41);
Keypad customKeypad=Keypad(makeKeymap(hexaKeys),rowPins,colPins,ROWS,COLS);                           
                
int joyPinX = A1;
int joyPinY = A2;
int SW = A3;
int value = 0;
int xzero = 0;
int yzero = 0;
int SWstate = 0;
boolean word_array[8][row_size][col_size]={data_0,data_1,data_2,data_3,data_4,data_5,data_6,data_7};
boolean word_array1[13][row_size][col_size]={data_a0,data_a1,data_a2,data_a3,data_a4,data_a5,data_a6,data_a7,data_a8,data_a9,data_a10,data_a11,data_fail};
boolean word_array2[1][row_size][col_size]={data_99};
boolean led[row_size][col_size];
byte row_pin[row_size]={R0,R1,R2,R3,R4,R5,R6,R7};

void setup(){
    lcd.begin(16,2);
    lcd.print("Input Game: ");
    pinMode(Ls138_A,OUTPUT);
    pinMode(Ls138_B,OUTPUT);
    pinMode(Ls138_C,OUTPUT);
    pinMode(R0,OUTPUT);
    pinMode(R1,OUTPUT);
    pinMode(R2,OUTPUT);
    pinMode(R3,OUTPUT);
    pinMode(R4,OUTPUT);
    pinMode(R5,OUTPUT);
    pinMode(R6,OUTPUT);
    pinMode(R7,OUTPUT);
    clear_led();
    pinMode(A14,OUTPUT);
    digitalWrite(A14,LOW);
    Serial.begin(9600);

    pinMode(SW,INPUT_PULLUP);
    yzero = analogRead(joyPinY);
    xzero = analogRead(joyPinX);
}

void loop(){
  int si=0;
  char customKey = customKeypad.getKey();
    if(customKey=='3'){      
      lcd.print(customKey); 
     int MAP=0;
     int Rx=7;
     int Ry=0;
     int Succ=0;
     int b=0; 
     int checktime=0;
     while(Succ!=1){
          for (unsigned int number = 60; number >=0; number--){
              unsigned long startTime = millis();
              for(unsigned long elapsed =0; elapsed <1000;elapsed = millis()-startTime){

                lcd.setCursor(0,1);
                lcd.print("Time: ");
                if(number<10){
                    lcd.print(number);
                   lcd.setCursor(7,1); 
                   lcd.print(" ");
                }else{
                  lcd.print(number);
                }
                int x,y,value;
                value = analogRead(joyPinX);
                x = value - xzero;
                value = analogRead(joyPinY);
                y = value - yzero;
                if((x>=-4&&x<=4)&&(y<=4&&y>=-4)){
                  Rx=Rx;
                  Ry=Ry;
                  b=0;
                }else if((x>=-5&&x<=5)&&y>=-1){//上
                  Ry=Ry-1;
                  if(word_array1[MAP][Rx][Ry]!=1){
                    
                    word_array1[MAP][Rx][Ry+1]=0;
                    word_array1[MAP][Rx][Ry]=1;
                    b=1;
                  }else{
                    Ry=Ry+1;
                    b=0;
                  }
                  
                }else if((x>=-5&&x<=5)&&y<=-1){//下
                  Ry=Ry+1;
                  if(word_array1[MAP][Rx][Ry]!=1){
                    word_array1[MAP][Rx][Ry-1]=0;
                    word_array1[MAP][Rx][Ry]=1;
                    b=1;
                  }else{
                    Ry=Ry-1;
                    b=0;
                  }
                }else if(x>=-1&&(y>=-5&&y<=5)){//左
                  Rx=Rx+1;
                  if(word_array1[MAP][Rx][Ry]!=1){
                    word_array1[MAP][Rx-1][Ry]=0;
                    word_array1[MAP][Rx][Ry]=1;
                    b=1;  
                  }else{
                    Rx=Rx-1;
                    b=0;
                  }
                }else if(x<=-1&&(y>=-5&&y<=5)){//右
                  Rx=Rx-1;
                  if(word_array1[MAP][Rx][Ry]!=1){
                    word_array1[MAP][Rx+1][Ry]=0;
                    word_array1[MAP][Rx][Ry]=1;
                    b=1;  
                  }else{
                    Rx=Rx+1;
                    b=0;  
                  }
                }else{
                  Rx=Rx;
                  Ry=Ry;
                  b=0;
                }
                if(b==1){
                  if(Rx==6 && Ry==0 && MAP==0){
                    MAP=1;
                  }else if(Rx==6 && Ry==0 && MAP==1){
                    MAP=0;
                  }else if(Rx==3 && Ry==0 && MAP==1){
                    MAP=2;
                  }else if(Rx==3 && Ry==0 && MAP==2){
                    MAP=1;
                  }else if(Rx==3 && Ry==2 && MAP==2){
                    MAP=3;
                  }else if(Rx==3 && Ry==2 && MAP==3){
                    MAP=2;
                  }else if(Rx==1 && Ry==2 && MAP==3){
                    MAP=4;
                  }else if(Rx==1 && Ry==2 && MAP==4){
                    MAP=3;
                  }else if(Rx==1 && Ry==4 && MAP==4){
                    MAP=5;
                  }else if(Rx==1 && Ry==4 && MAP==5){
                    MAP=4;
                  }else if(Rx==3 && Ry==5 && MAP==5){
                    MAP=6;
                  }else if(Rx==3 && Ry==5 && MAP==6){
                    MAP=5;
                  }else if(Rx==5 && Ry==6 && MAP==6){
                    MAP=7;
                  }else if(Rx==5 && Ry==6 && MAP==7){
                    MAP=6;
                  }else if(Rx==5 && Ry==7 && MAP==7){
                    MAP=8;
                  }else if(Rx==5 && Ry==7 && MAP==8){
                    MAP=7;
                  }else if(Rx==0 && Ry==7 && MAP==8){
                   MAP=9; 
                  }
                }
                
              
                if(MAP==9){
                  word_to_led1(9);
                  display_led(led,1000);
                  word_to_led1(10);
                  display_led(led,1000);
                  word_to_led1(11);
                  display_led(led,1000);
                  word_to_led1(10);
                  display_led(led,1000);
                  word_to_led1(11);
                  display_led(led,1000);
                  Succ=1;
                  //checktime=1;
                  break;
                }else{
                  word_to_led1(MAP);
                  display_led(led,100);
                  word_array1[MAP][Rx][Ry]=0;
                  word_to_led1(MAP);
                  display_led(led,100);
                  word_array1[MAP][Rx][Ry]=1;
                  word_to_led1(MAP);
                  display_led(led,100);
                  checktime=0;
                }                
             }
             if(number==0 && checktime !=1){
                  Succ=1; 
                  word_to_led1(12);
                  display_led(led,1000);
                  
                  word_to_led1(10);
                  display_led(led,1000);
                  
                  word_to_led1(12);
                  display_led(led,1000);
                  
                  word_to_led1(10);
                  display_led(led,1000);
                  break;
             }else if(Succ==1){
                   word_array1[0][6][0]=0;
                   word_array1[1][3][0]=0;
                   word_array1[2][3][2]=0;
                   word_array1[3][1][2]=0;
                   word_array1[4][1][4]=0;
                   word_array1[5][3][5]=0;
                   word_array1[6][5][6]=0;
                   word_array1[7][5][7]=0;
                   word_array1[8][0][7]=0;

                  break; 
             }
         }
      }
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Input Game:");
    
      
  }else if(customKey == '2'){
    si=1;
      lcd.print(customKey);
      for(int i=1;i<=3;i++){
        int succ=0;
        int rx=7;
        int ry=0;
        int Checktime=0;
        while(succ!=1){
          for (unsigned int number = 30; number >=0; number--){
              unsigned long startTime = millis();
              for(unsigned long elapsed =0; elapsed <1000;elapsed = millis()-startTime){
                lcd.setCursor(0,1);
                lcd.print("Time: ");
                if(number<10){
                    lcd.print(number);
                   lcd.setCursor(7,1); 
                   lcd.print(" ");
                }else{
                  lcd.print(number);
                }
                int x,y,value;
                value = analogRead(joyPinX);
                x = value - xzero;
                value = analogRead(joyPinY);
                y = value - yzero;
                Serial.print("X=");
                Serial.print(x);
                Serial.print(" Y=");
                Serial.println(y);
                
                if((x>=-4&&x<=4)&&(y<=4&&y>=-4)){
                  rx=rx;
                  ry=ry;
                }else if((x>=-5&&x<=5)&&y>=-1){//左
                  if(ry!=0){
                    ry=ry-1;
                    if(word_array[i][rx][ry]==1){
                        word_array[i][rx][ry]=1;
                        word_array[i][rx][ry+1]=0;
                    }else{
                      word_array[i][rx][ry]=1;
                      word_array[i][rx][ry+1]=0;
                    }
                  }
                  
                }else if((x>=-5&&x<=5)&&y<=-1){//右
                  if(ry!=7){
                    ry=ry+1;
                    if(word_array[i][rx][ry]==1){
                        word_array[i][rx][ry]=1;
                        word_array[i][rx][ry-1]=0;
                    }else{
                      word_array[i][rx][ry]=1;
                      word_array[i][rx][ry-1]=0;    
                    }
                  }
                }else if(x>=-1&&(y>=-5&&y<=5)){//下
                  if(rx!=7){
                    rx=rx+1;
                    if(word_array[i][rx][ry]==1){
                      word_array[i][rx][ry]=1;
                      word_array[i][rx-1][ry]=0;
                      
                    }else{
                      word_array[i][rx][ry]=1;    
                      word_array[i][rx-1][ry]=0;      
                    }
                  }
                }else if(x<=-1&&(y>=-5&&y<=5)){//上
                  if(rx!=0){
                    rx=rx-1;
                    if(word_array[i][rx][ry]==1){
                      word_array[i][rx][ry]=1;
                      word_array[i][rx+1][ry]=0;
                      
                    }else{
                      word_array[i][rx][ry]=1;
                      word_array[i][rx+1][ry]=0;    
                   }
                  }
                }else{
                  rx=rx;
                  ry=ry;
                }
                
                if(word_to_led(i,0)==0){
                    word_to_led(0,0);
                    display_led(led,1000);
                    word_to_led(4,0);
                    display_led(led,1000);
                    word_to_led(5,0);
                    display_led(led,1000);
                    word_to_led(6,0);
                    display_led(led,1000);
                    word_to_led(7,0);
                    display_led(led,1000);
                    Checktime=1;
                    succ=1;
                   
                }else{
                   word_to_led(i,0);
                   display_led(led,100);
                   word_array[i][rx][ry]=1; 
                   word_to_led(i,0);
                   display_led(led,100);
                   word_array[i][rx][ry]=0; 
                   word_to_led(i,0);
                   display_led(led,100);
                   Checktime=0;
                }  
              }
              if(number==0 && Checktime !=1){
                  succ=1; 
                  i=4;
                  word_to_led1(12);
                  display_led(led,1000);
                  
                  word_to_led1(10);
                  display_led(led,1000);
                  
                  word_to_led1(12);
                  display_led(led,1000);
                  
                  word_to_led1(10);
                  display_led(led,1000);
                  break;
             }else if(succ==1){
                break; 
             }
          }
        }
    }    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Input Game:");
  }else if(customKey == '1'){
      int RX=6;
      int RY=1;
      lcd.print(customKey);
      int SSucc=0;
      int a=0;
      while(SSucc!=1){
        for (unsigned int number = 10; number >=0; number--){
              unsigned long startTime = millis();
              for(unsigned long elapsed =0; elapsed <1000;elapsed = millis()-startTime){
                lcd.setCursor(0,1);
                lcd.print("Time: ");
                if(number<10){
                    lcd.print(number);
                   lcd.setCursor(7,1); 
                   lcd.print(" ");
                }else{
                  lcd.print(number);
                }
                int x,y,value;
                value = analogRead(joyPinX);
                x = value - xzero;
                value = analogRead(joyPinY);
                y = value - yzero;
                
                  Serial.print("X=");
                  Serial.print(x);
                  Serial.print(" Y=");
                  Serial.println(y);
                if((x>=-4&&x<=4)&&(y<=4&&y>=-4)){
                  RX=RX;
                  RY=RY;
                }else if((x>=-5&&x<=5)&&y>=-1){//上
                  RY=RY-1;
                  if(word_array2[0][RX][RY]!=1){
                    word_array2[0][RX][RY+1]=0;
                    word_array2[0][RX][RY]=1;
                  }else{
                    RY=RY+1;
                  }
                  
                }else if((x>=-5&&x<=5)&&y<=-1){//右
                  RY=RY+1;
                  if(word_array2[0][RX][RY]!=1){
                    word_array2[0][RX][RY-1]=0;
                    word_array2[0][RX][RY]=1;
                  }else{
                    RY=RY-1;
                  }
                }else if(x>=-1&&(y>=-5&&y<=5)){//左
                  RX=RX+1;
                  if(word_array2[0][RX][RY]!=1){
                    word_array2[0][RX-1][RY]=0;
                    word_array2[0][RX][RY]=1;
                  }else{
                    RX=RX-1;
                  }
                }else if(x<=-1&&(y>=-5&&y<=5)){//右
                  RX=RX-1;
                  if(word_array2[0][RX][RY]!=1){
                    word_array2[0][RX+1][RY]=0;
                    word_array2[0][RX][RY]=1;
                  }else{
                    RX=RX+1;
                  }
                }else{
                  RX=RX;
                  RY=RY;
                }
        
                if(word_array2[0][3][4]==1){
                  word_to_led(0,0);
                  display_led(led,1000);
                  word_to_led(4,0);
                  display_led(led,1000);
                  word_to_led(5,0);
                  display_led(led,1000);
                  word_to_led(6,0);
                  display_led(led,1000);
                  word_to_led(7,0);
                  display_led(led,1000);
                  SSucc=1;
                  a=1;
                  break;
                }else{
                  word_to_led2(0);
                  display_led(led,100);
                  word_array2[0][RX][RY]=1;
                  word_to_led2(0);
                  display_led(led,100);
                  word_array2[0][RX][RY]=0;
                  word_to_led2(0);
                  display_led(led,100);
                  a=0;
                }
                
                
              }
              if(number==0 && a!=1){
                  SSucc=1; 
                  word_to_led1(12);
                  display_led(led,1000);
                  
                  word_to_led1(10);
                  display_led(led,1000);
                  
                  word_to_led1(12);
                  display_led(led,1000);
                  
                  word_to_led1(10);
                  display_led(led,1000);
                  break;
               }else if(SSucc==1){
                   
                  break; 
               }
          }
      }
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Input Game:");
  }
}
void word_to_led2(int n){
    for(int i=0; i<row_size; i++){
      for(int j=0; j<col_size; j++){
        led[i][j]=word_array2[n][i][j];  
     }
    }
}

void word_to_led1(int n){
    for(int i=0; i<row_size; i++){
      for(int j=0; j<col_size; j++){
        led[i][j]=word_array1[n][i][j];  
       }
    }
}
int word_to_led(int n,int Temp){
    
  
    for(int i=0; i<row_size; i++){
      for(int j=0; j<col_size; j++){
        led[i][j]=word_array[n][i][j];
        if(led[i][j]==1){
          Temp++;
        }  
       }
    }
    return Temp;
}

void clear_led(){
    for(int i=0; i<row_size; i++){
      digitalWrite(row_pin[i],LOW);
    }
}


void display_led(byte led[row_size][col_size], int continue_time){
    for(int k=0; k<continue_time; k++){
      for(int i=0; i<col_size; i++){
        clear_led();
        low_74138pin(i);
      
        for(int j=0; j<row_size; j++){
          if(led[j][i] == 1){
            digitalWrite(row_pin[j],HIGH);
          }
        }
      }
    }
}

void low_74138pin(int num){
    
    switch(num){
        case 0:
            digitalWrite(Ls138_A,LOW);
            digitalWrite(Ls138_B,LOW);
            digitalWrite(Ls138_C,LOW);
            break;
      
        case 1:
            digitalWrite(Ls138_A,HIGH);
            digitalWrite(Ls138_B,LOW);
            digitalWrite(Ls138_C,LOW);
            break;
      
        case 2:
            digitalWrite(Ls138_A,LOW);
            digitalWrite(Ls138_B,HIGH);
            digitalWrite(Ls138_C,LOW);
            break;
      
        case 3:
            digitalWrite(Ls138_A,HIGH);
            digitalWrite(Ls138_B,HIGH);
            digitalWrite(Ls138_C,LOW);
            break;
      
        case 4:
            digitalWrite(Ls138_A,LOW);
            digitalWrite(Ls138_B,LOW);
            digitalWrite(Ls138_C,HIGH);
            break;
      
        case 5:
            digitalWrite(Ls138_A,HIGH);
            digitalWrite(Ls138_B,LOW);
            digitalWrite(Ls138_C,HIGH);
            break;
      
        case 6:
            digitalWrite(Ls138_A,LOW);
            digitalWrite(Ls138_B,HIGH);
            digitalWrite(Ls138_C,HIGH);
            break;
      
        case 7:
            digitalWrite(Ls138_A,HIGH);
            digitalWrite(Ls138_B,HIGH);
            digitalWrite(Ls138_C,HIGH);
            break;
    }
}
