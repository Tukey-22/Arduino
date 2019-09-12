
#include <IRremote.h>
int RECV_PIN = 11; //Alıcının bağlı olduğu pin
IRrecv irrecv(RECV_PIN);
decode_results results;

int kirmizi = 5;
int yesil = 6;
int mavi = 9;

int k;
int y;
int m;


void setup() {
  irrecv.enableIRIn(); // Alıcıyı baslatır
  pinMode(kirmizi, OUTPUT);
  pinMode(yesil, OUTPUT);
  pinMode(mavi, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {

    //
    //
    //Mavi ledin yanacağı kısım

    if (results.value == 0x20DF8679) {
      m++;
    }
    m = m % 4;

    if (m == 0) {
      analogWrite(mavi, LOW); 
    }
    if (m == 1) {
      analogWrite(mavi, 50); 
    }
    if (m == 2) {
      analogWrite(mavi, 170); 
    }
    if (m == 3) {
      analogWrite(mavi, 255); 
    }

    //
    //
    //Yeşil ledin yanacağı kısım

    if (results.value == 0x20DF8E71) {
      y++;
    }
    y = y % 4;

    if (y == 0) {
      analogWrite(yesil, LOW); 
    }
    if (y == 1) {
      analogWrite(yesil, 50); 
    }
    if (y == 2) {
      analogWrite(yesil, 170);
    }
    if (y == 3) {
      analogWrite(yesil, 255); 
    }

    //
    //
    //Kırmızı ledin yanacağı kısım

    if (results.value == 0x20DF4EB1) {
      k++;
    }
    k = k % 4;

    if (k == 0) {
      analogWrite(kirmizi, LOW); 
    }
    if (k == 1) {
      analogWrite(kirmizi, 50); 
    }
    if (k == 2) {
      analogWrite(kirmizi, 170); 
    }
    if (k == 3) {
      analogWrite(kirmizi, 255); 
    }

//
//
// Tüm ledlerin kapanacağı kısım

    if (results.value == 0x20DFC639) {

      analogWrite(kirmizi, LOW);
      analogWrite(yesil, LOW);
      analogWrite(mavi, LOW);
      y = 0;
      m = 0;
      k = 0;
      delay(100);
    }

    irrecv.resume();
  }
}




