#include <stdio.h>

int main()
{
	char D[6] = {'a','e','r','k','s','\0'};
	char kelimeler[][8] = {"asker","serak","kars","kase","sera","akse","ark","kes","kas","ser","sek","kar",'\0'};

	int i, j;
	int harfsayisi = 0;
	int kelimesayisi = 0;
	char tahmin[100] = "a";
	int tahminharf;
	int puan = 0;
	int harfkontrol;
	int kelimekontrol;
	int kont = 0;
	int ciftharfkont = 0;

	while(D[harfsayisi] != '\0') {
		harfsayisi += 1;
	}

	while(kelimeler[kelimesayisi][0] != '\0') {
		kelimesayisi += 1;
	}

	printf("kulllanilmasi gereken harfler:");
	for(i = 0; i < harfsayisi; i++) {
		printf("%c, ", D[i]);
	}
	while(tahmin[0] != '0') {
		printf("\ntahmininizi giriniz (tek harfli olmamalidir): ");
		scanf("%s", &tahmin);
		tahminharf = 0;
		while(tahmin[tahminharf] != '\0') {
			tahminharf += 1;
		}
		if((tahmin[0] != '0') && (tahminharf != 1)) {
			harfkontrol = 0;
			for(i = 0; i < tahminharf; i++) {
				for(j = 0; j < harfsayisi; j++) {
					if (tahmin[i] == D[j]) {
						harfkontrol += 1;
					}
				}
			}
			if(harfkontrol == tahminharf) {
				i = 0;
				kont = 0;
				while((i < kelimesayisi) && (kont == 0)) {
					kelimekontrol = 0;
					for(j = 0; j < tahminharf; j++) {
						if(tahmin[j] == kelimeler[i][j]) {
							kelimekontrol += 1;
						}
					}
					if((kelimekontrol == tahminharf) && (kelimeler[i][tahminharf] == '\0'))	{
						printf("puaniniz: %d\n", tahminharf);
						puan += tahminharf;
						kont = 1;
						kelimeler[i][0] = '1';
					}
					i += 1;
				}
				if(kont == 0) {
					ciftharfkont = 0;
					for(i = 0; i < tahminharf; i++) {
						for(j = i + 1; j < tahminharf; j++) {
							if(tahmin[i] == tahmin[j]) {
								ciftharfkont = 1;
							}
						}
					}
					if(ciftharfkont == 1) {
						printf("Hatali harf kullanimi (bir harfi birden fazla kullandiniz), ");
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
		else if((tahminharf == 1) && (tahmin[0] != '0')) {
			printf("tahmininiz tek harflidir tekrar tahmin ediniz\n");
		}
	}
	printf("Oyun bitmistir. Tebrikler! Toplam puaniniz: %d\n", puan);

	return 0;
}
