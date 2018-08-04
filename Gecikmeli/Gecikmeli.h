#ifndef Gecikmeli_h
#define Gecikmeli_h
#include "arduino.h"


class Gecikmeli{
	public:
		Gecikmeli(unsigned int);
		
		struct Gecikme{
			void (*cagri)(void);
			unsigned long toplam_zaman;
			int tekrar_sayisi;
			bool bitti;
			unsigned long bas_zaman;
		};
		
		bool ekle(Gecikme*);
		bool sil(Gecikme*);
		bool guncelle();
		unsigned int index();
		
	private:
		Gecikme** gecikmeler;
		unsigned int gecikme_sayisi = 0;
		unsigned int gecikme_index = 0;
		void duzenle();
};
#endif