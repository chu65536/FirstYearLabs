// Чувилин Виталий
// М8О-109Б

#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);

	int mtx[n * n];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			scanf("%d", &mtx[i * n + j]);
		}
	}

	int mx;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (j == 0) {
				mx = mtx[i * n + j];
				continue;
			}

			if (mtx[i * n + j] > mx){
				mx = mtx[i * n + j];
			}
		}
		mtx[i * n + i] = mx;
	}

	printf("Ans\n");
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			printf("%d ", mtx[i * n + j]);
		}	printf("\n");
	}


} 
