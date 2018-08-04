#include <Gecikmeli.h>

Gecikmeli gecikme(2);
Gecikmeli::Gecikme cagir, cagir1;

void yaz(){
  Serial.println("Shut up!");
  gecikme.ekle(&cagir1);
}
void yaz2(){
  Serial.println("You shut up!!!!");
  gecikme.ekle(&cagir);
}

void setup() {
  Serial.begin(9600);
  cagir = {yaz, 1000, 0};
  cagir1 = {yaz2, 2000, 0};
  gecikme.ekle(&cagir);
}

void loop() {
  gecikme.guncelle();
}

