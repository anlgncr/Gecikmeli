# Gecikmeli
Fonksiyon çağrılarını erteleme kütüphanesi.

Kütüphaneyi kullanabilmek için öncelikle sınıf tanımlası yapılır.


Gecikmeli gecikme(5); 


Buradaki 5 sayısı aynı anda en fazla 5 adet gecikme kullanacağımızı belirtir. İstenen değer kadar girilebilir tabi Arduinonun 2kb lık ram boyutunu geçmeyecek şekilde :) (Not. Göstergeler Arduino'da (Atmega328) 2 byte yer kapladığı için her bir tanımlama 2 byte'tır)

Daha sonra struct Gecikme türünde bir yapı tanımlanmalıdır.


Gecikmeli::Gecikme ornek_yapi;


Daha sonra yapıya ait veriler ister {} yardımıyla ister tek tek girilebilir.


ornek_yapi = {fonksiyon_adı, toplam_süre, tekrar sayısı}; 

veya

ornek_yapi.cagri = foksiyon_adı;

ornek_yapi.toplam_sure = toplam_süre;

ornek_yapi.tekrar_sayisi = tekrar_sayısı;


Tekrar sayısı 0 olursa tekrar etmez

Tekrar sayısı 0 dan fazla olursa o sayı kadar tekrar eder

Tekrar sayısı -1 olursa sürekli tekrar eder


Oluşturulan ornek_yapı nın çalışması havuza eklenmelidir.

gecikme.ekle(&ornek_yapi);


Burada ornek_yapının adresini arguman olarak kullandığımıza dikkat edin.

Daha sonra bu gecikme sınıfının loop fonksiyonu içerisinde sürekli güncellenmelidir.


void loop(){

  gecikme.guncelle();
  
}
