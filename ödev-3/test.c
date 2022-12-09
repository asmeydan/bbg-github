#include <stdio.h>

int main() {
	char D[7] = {'k','a','m','n','e','r','i'};
	char kelimeler[][7] = {"anemik","kameri","marine","minare","makine","anemi","mekan","krema","kerim","inmek","imkan","imren","imran","erkan","ekran","mera","krem","mine","mira","name","ekim","erik","kim","nem","nam","ani","kin","kir"};

	int i, j;
	int harfsayisi = 0;
	int kelimesayisi = 0;
	char tahmin[7];
	int tahminharf;
	int puan = 0;
	int harfkontrol;
	int kelimekontrol;
	int kont = 0;
	int ciftharfkont = 0;
	
    while(D[harfsayisi] != '\0'){
    	harfsayisi += 1;
	}
	
	while(kelimeler[kelimesayisi][0] != '\0'){
    	kelimesayisi += 1;
	}
	
	printf("kulllanilmasi gereken harfler: ");
	for(i = 0; i < harfsayisi; i++) {
		printf("%c, ", D[i]);
	}
	
	while(tahmin[0] != '0') {
		printf("\ntahmininizi giriniz: ");
		scanf("%s", &tahmin);
//		printf("%s\n", tahmin);
		
		if(tahmin[0] == '0') {
//			printf("tahmin: 0\n");
		}
		else {
//			printf("tahmin sifirdan farkli \n");
			tahminharf = 0;
			while(tahmin[tahminharf] != '\0'){
    			tahminharf += 1;
			}
//			printf("tahminin harf sayisi: %d \n", tahminharf);
			harfkontrol = 0;
			for(i = 0; i < tahminharf; i++) {
				for(j = 0; j < harfsayisi; j++) {
//					printf("i: %c, j: %c \n", tahmin[i], D[j]);
					if(tahmin[i] == D[j]) {
						harfkontrol += 1;
					}
				}
			}
			if(harfkontrol == tahminharf) {
//				printf("dogru harfler\n");
				i = 0;
				kont = 0;
				while((i < kelimesayisi) && (kont == 0)) {
//					printf("%s -- %s\n", tahmin, kelimeler[i]);
					kelimekontrol = 0;
					for(j = 0; j < tahminharf; j++) {
						if(tahmin[j] == kelimeler[i][j]) {
							kelimekontrol += 1;
						}
					}
					if((kelimekontrol == tahminharf) && (kelimeler[i][tahminharf] == '\0')) {
						printf("BRAVOOOOOOOOO---\n");
						printf("puaniniz: %d\n", tahminharf);
						puan += tahminharf;
						kont = 1;
					}
					i += 1;
				}
				if(kont == 0) {
					for(i = 0; i < tahminharf; i++) {
						for(j = i + 1; j < tahminharf; j++) {
							if(tahmin[i] == tahmin[j]) {
								ciftharfkont = 1;
							}
						}
					}
					if(ciftharfkont == 1) {
						printf("Hatali harf kullanimi, ");
					}
					printf("puaniniz -%d", tahminharf);
					puan -= tahminharf;
				}
			}
			else {
				printf("Hatali harf kullanimi, Puaniniz: -%d\n", tahminharf);
				puan -= tahminharf;
			}
		}
	}
	printf("Oyun bitmiştir. Tebrikler! Toplam puaniniz: %d\n", puan);
	

    return 0;
}
