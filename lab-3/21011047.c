#include <stdio.h>

int main() {
	int M, N, k, i, j, toplam, k_toplam, l, m;
	
	
	printf("resim boyutunu giriniz(M x N)\n");
	printf("M i giriniz:");
	scanf("%d", &M);
	printf("\nN i giriniz:");
	scanf("%d", &N);
	int resim[M][N];
	
	printf("\n Konvolusyon boyutu giriniz (k):");
	scanf("%d", &k);
	while((k > N) || (k > M) || (k % 2 == 0)) {
		printf("k N veya M den buyuk ve cift olamaz lutfen tekrar giriniz:");
		scanf("%d", &k);
	}
	int konvol[k][k];
	
	printf("\n resmin deðerlerini giriniz");
	for(i = 0; i < M; i++) {
		for(j = 0; j < N; j++) {
			printf("\nresim[%d][%d]:", i, j);
			scanf("%d", &resim[i][j]);
		}
	}
	printf("\n konvulsyon degerlerini giriniz");
	for(i = 0; i < k; i++) {
		for(j = 0; j < k; j++) {
			printf("\nkonvol[%d][%d]:", i, j);
			scanf("%d", &konvol[i][j]);
		}
	}
	
	int sonuc[M - k + 1][N - k + 1];
	for(i = 0; i < M - k + 1; i++) {
		for(j = 0; j < N - k + 1; j++) {
			toplam = 0;
			k_toplam = 0;
			for(l = 0; l < k; l++) {
				for(m = 0; m < k; m++) {
					toplam += resim[l + i][m + j] * konvol[l][m];
					k_toplam += konvol[l][m];
				}
			}
			sonuc[i][j] = toplam / k_toplam;
		}
	}
	
	printf("\n\nSONUC: \n");
	for(i = 0; i < M - k + 1; i++) {
		for(j = 0; j < N - k + 1; j++) {
			printf("[ %d ]", sonuc[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
