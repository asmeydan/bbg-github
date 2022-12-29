#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	int i, j, l, N, M, sayi, sayiM, k = 0, y_uzunluk, yN, yM, yem = 0, hamle_sayisi = 0, puan = 0, yemek_sayisi, flag = 0, kalan;
	char hamle = 'A';
	
	// OYUN ALANININ BÜYÜKLÜÐÜNÜ BELÝRLEME
	printf("Oyun alanini giriniz(N x M): \n");
	scanf("%d %d", &N, &M);
	printf("N: %d M: %d \n", N, M);
	
	// OYUN ALANINI OLUÞTURMA
	int map[N][M];
	for(i = 0; i < N; i++) {
		for(j = 0; j < M; j++) {
			map[i][j] = -1;
		}
	}
	
	// RASTGELELÝK ÝÇÝN DÝZÝ OLUÞTURMA
	int random[N * M];
	for(i = 0; i < N; i++) {
		for(j = 0; j < M; j++) {
			random[k] = k;
			k += 1;
		}
	}
	
	
	// YEMEK SAYISINI ALMA
	do {
		printf("Yemek sayisini giriniz(oyun alanindan buyuk olamaz): \n");
  		scanf("%d", &yemek_sayisi);
	}
	while (yemek_sayisi >= N * M);
	
	// YEMEKLERÝN YERLERÝNÝ BELÝRLEME
	// 2 YEMEÐÝN ÜST ÜSTE OLMAMASINI SAÐLAMA
	for(i = 0; i < yemek_sayisi; i++) {
		sayi = rand()%k;
		map[random[sayi] / M][random[sayi] % M] = 0;
		for(j = 0; j < k; j++) {
			if(random[j] == random[sayi]) {
				for(l = j; l < (k - 1); l++) {
					random[l] = random[l + 1];
				}
			}
		}
		random[k - 1] = '\0';
		k -= 1;
	}
	
	// YILAN
	sayi = rand()%k;
	map[random[sayi] / M][random[sayi] % M] = 1;
	y_uzunluk = 1;
	yN = random[sayi] / M;
	yM = random[sayi] % M;
	
	
	// HARÝTAYI YAZDIRMA
	for(i = 0; i < N; i++) {
		for(j = 0; j < M; j++) {
			if(!(map[i][j] == -1)) {
				printf("[ %d ]", map[i][j]);
			}
			else {
				printf("[   ]", map[i][j]);
			}
		}
		printf("\n");
	}
	
	// OYUNUN DEVAMLILIÐI
	while(!flag) {
		
		
		// HAMLE GÝRME
		do {
			printf("Hamlenizi giriniz(U: yukari, D: asagi, L: sol, R: sag):\n");
			scanf(" %c", &hamle);
		}
		while(!((hamle == 'U') || (hamle == 'D') || (hamle == 'L') || (hamle == 'R') || (hamle == 'u') || (hamle == 'd') || (hamle == 'l') || (hamle == 'r')));
		
		// U'YA BASILINCA 
		if((hamle == 'U') || (hamle == 'u')) {
			//YILANIN BÜTÜN SAYILARINI ARTTIRMA
			for(i = 0; i < N; i++) {
				for(j = 0; j < M; j++) {
					if(map[i][j] > 0) {
						map[i][j] += 1;
					}
				}
			}
			// DUVARA ÇARPTIYSA YANMA
			if(yN - 1 < 0) {
				flag = 1;
				printf("duvara carptin\n");
				kalan = yemek_sayisi - puan;
				printf("kalan yem sayisi:%d \n", kalan);
				printf("yilaninizin uzunlugu: %d \n", y_uzunluk);
			}
			// YILANIN ARKA UCUNU KISALTMA
			for(i = 0; i < N; i++) {
				for(j = 0; j < M; j++) {
					if(map[i][j] > y_uzunluk) {
						map[i][j] = -1;
					}
				}
			}
			
			// YEM YENÝP YENMEDÝÐÝNÝ TESPÝT ETME
			if(map[yN - 1][yM] == 0) {
				yem = 1;
			}
			
			//YILANIN KAFASINI OLUÞTURMA
			map[yN - 1][yM] = 1;
			yN -= 1;
		}
		
		// D'YA BASILINCA 
		if((hamle == 'D') || (hamle == 'd')) {
			for(i = 0; i < N; i++) {
				for(j = 0; j < M; j++) {
					if(map[i][j] > 0) {
						map[i][j] += 1;
					}
				}
			}
			if(yN + 1 > N - 1) {
				flag = 1;
				printf("duvara carptin\n");
				kalan = yemek_sayisi - puan;
				printf("kalan yem sayisi:%d \n", kalan);
				printf("yilaninizin uzunlugu: %d \n", y_uzunluk);
			}
			for(i = 0; i < N; i++) {
				for(j = 0; j < M; j++) {
					if(map[i][j] > y_uzunluk) {
						map[i][j] = -1;
					}
				}
			}
			
			if(map[yN + 1][yM] == 0) {
				yem = 1;
			}
			
			map[yN + 1][yM] = 1;
			yN += 1;
		}
		
		// R'YA BASILINCA 
		if((hamle == 'R') || (hamle == 'r')) {
			for(i = 0; i < N; i++) {
				for(j = 0; j < M; j++) {
					if(map[i][j] > 0) {
						map[i][j] += 1;
					}
				}
			}
			if(yM + 1 > M - 1) {
				flag = 1;
				printf("duvara carptin\n");
				kalan = yemek_sayisi - puan;
				printf("kalan yem sayisi:%d \n", kalan);
				printf("yilaninizin uzunlugu: %d \n", y_uzunluk);
			}
			for(i = 0; i < N; i++) {
				for(j = 0; j < M; j++) {
					if(map[i][j] > y_uzunluk) {
						map[i][j] = -1;
					}
				}
			}
			
			if(map[yN][yM + 1] == 0) {
				yem = 1;
			}
			
			map[yN][yM + 1] = 1;
			yM += 1;
		}
		
		// L'YA BASILINCA 
		if((hamle == 'L') || (hamle == 'l')) {
			for(i = 0; i < N; i++) {
				for(j = 0; j < M; j++) {
					if(map[i][j] > 0) {
						map[i][j] += 1;
					}
				}
			}
			if(yM - 1 < 0) {
				flag = 1;
				printf("duvara carptin\n");
				kalan = yemek_sayisi - puan;
				printf("kalan yem sayisi:%d \n", kalan);
				printf("yilaninizin uzunlugu: %d \n", y_uzunluk);
			}
			for(i = 0; i < N; i++) {
				for(j = 0; j < M; j++) {
					if(map[i][j] > y_uzunluk) {
						map[i][j] = -1;
					}
				}
			}
			
			if(map[yN][yM - 1] == 0) {
				yem = 1;
			}
			
			map[yN][yM - 1] = 1;
			yM -= 1;
		}
		
		
		
		// HARÝTAYI YAZDIRMA (DÖNGÜNÜN ÝÇÝ)
		for(i = 0; i < N; i++) {
			for(j = 0; j < M; j++) {
				if(!(map[i][j] == -1)) {
					printf("[ %d ]", map[i][j]);
				}
				else {
					printf("[   ]", map[i][j]);
				}
			}
			printf("\n");
		}
		
		hamle_sayisi += 1;
		printf("Hamle sayisi: %d\n\n\n", hamle_sayisi);
		
		
		//YEM YENMÝÞSE 
		if(yem) {
			y_uzunluk += 1;
			puan += 1;
			if(puan == yemek_sayisi) {
				flag = 1;
				printf("\n Tebrikler kazandiniz\n");
			}
		}
		yem = 0;
	}
	
	printf("\nHamle sayisi: %d\n", hamle_sayisi);
	
	return 0;
}
