#include <Servo.h>
#include <SoftwareSerial.h> // use the software uart
SoftwareSerial bluetooth(2, 4); // RX, TX


unsigned long previousMillis = 0;        
const long interval = 500;           /
static uint32_t tmp; 


Servo servo;
Servo servo2;
Servo servo3;
Servo servo4;


int x_durum=90;
int y_durum=90;
int donme=90;
int buton_deger = 0;

int hangi=1;

void setup() {

  
  
servo.attach(9);
servo2.attach(8);
servo3.attach(7);
servo4.attach(6);
bluetooth.begin(9600); 
delay(200); // 
bluetooth.print("AT+NAMEserdar");                                   
delay(3000); 

}

void loop() {
 
 if (bluetooth.available()) { 
  switch(bluetooth.read())
{
  case '1': 
    
    if((hangi%2==1)){ 
       x_durum=x_durum-5;
       servo.write(x_durum);
       
    }

    if((hangi%2==0)){ 
       x_durum=x_durum+5;
       servo2.write(x_durum);
    }
    break;
    
  case '4':      
    if((hangi%2==1)){ 
       x_durum=x_durum+5;
       servo.write(x_durum);

    }
    if((hangi%2==0)){ 
       x_durum=x_durum-5;
       servo2.write(x_durum);
    }
    break;
  case '2':   
       y_durum=y_durum+5;
       servo4.write(y_durum);
       break;
  case '3':
       y_durum=y_durum-5;
       servo4.write(y_durum);
       break;
  case '9':
      buton_deger++;
      break;
      
  case 'a':
      
      hangi++;
      break;    
} 
 if((buton_deger%2==0)){
  servo3.write(30);
 }
 else{
  servo3.write(5);
 }




 unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    bluetooth.print(tmp++); 
  }

    

 }
}
