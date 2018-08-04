#include "Gecikmeli.h"

Gecikmeli::Gecikmeli(unsigned int _gecikme_sayisi){
	gecikme_sayisi = _gecikme_sayisi;
	gecikmeler = (Gecikme**)calloc(gecikme_sayisi, sizeof(Gecikme*));
}

bool Gecikmeli::ekle(Gecikme* gecikme){
	if(gecikme_index >= gecikme_sayisi)
		return false;
	
	gecikme->bas_zaman = millis();
	
	if((gecikme->bas_zaman + gecikme->toplam_zaman) < gecikme->toplam_zaman) // Taşarsa ekleme yapma
		return false;
	
	gecikme->bitti = false;
	gecikmeler[gecikme_index] = gecikme;
	gecikme_index++;
	
	return true;
}

bool Gecikmeli::sil(Gecikme* gecikme){
	if(gecikme_index <= 0)
			return false;
		
		unsigned int i;
		for(i=0; i<gecikme_index; i++){
			if(gecikmeler[i] == gecikme){
				gecikmeler[i] = NULL;
				duzenle();
				return true;
			}
		}
		return false;
}

void Gecikmeli::duzenle(){
	unsigned int gercek_index = 0;
	unsigned int i;
	for(i=0; i<gecikme_sayisi; i++){ //Nesneleri boşluklara kaydır
		if(gecikmeler[i] != NULL){
			if(gercek_index != i){
				gecikmeler[gercek_index] = gecikmeler[i];
				gecikmeler[i] = NULL;
			}
			gercek_index++;
		}
	}
	gecikme_index = gercek_index;
}

bool Gecikmeli::guncelle(){
	if(gecikme_index <= 0)
		return false;
	
	unsigned long gecen_zaman = 0;	
	for(unsigned int i=0; i<gecikme_index; i++){
		if(gecikmeler[i] != NULL){
			gecen_zaman = millis() - gecikmeler[i]->bas_zaman;
			if(gecen_zaman >= gecikmeler[i]->toplam_zaman){

				if(*(gecikmeler[i]->cagri))
					(*(gecikmeler[i]->cagri))();
				
				if(gecikmeler[i]->tekrar_sayisi > 1){
					gecikmeler[i]->bas_zaman = millis();
					gecikmeler[i]->tekrar_sayisi--;
				}
				else if(gecikmeler[i]->tekrar_sayisi < 0){
					gecikmeler[i]->bas_zaman = millis();
				}
				else{
					gecikmeler[i]->bitti = true;
					sil(gecikmeler[i]);
				}
			}
		}
	}
}

unsigned int Gecikmeli::index(){
	return gecikme_index;
}




