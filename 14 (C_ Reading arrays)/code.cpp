// Чувилин Виталий
// М8О-109Б

#include <stdio.h> 

int main(){
	int n, m;
	scanf("%d", &n);
	m = n;

	int mtx[n * m];

	int cnt = 1;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			int ind = n * i + j;
			scanf("%d", &mtx[n * i + j]);
		}
	}

	int x = 1, y = 0;
	printf("%d ", mtx[0]);

	bool up, down, left, right;
	down = true;
	up = left = right = false;
	while (x < m){
		// Down
		while(down){
			printf("%d ", mtx[n * y + x]);
			y++;
			if (x == y){
				down = false;
				left = true;
			}
		}

		//Left
		while(left){
			printf("%d ", mtx[n * y + x]);
			x--;
			if (x == -1){
				left = false;
				right = true;
				x++;
				y++;
			}
		}
		if (n % 2 == 0 && y >= n) 
			break;

		// Right
		while(right){
			printf("%d ", mtx[n * y + x]);
			x++;
			if (x == y){
				right = false;
				up = true;
			}
		}

		// Up
		while(up){
			printf("%d ", mtx[n * y + x]);
			y--;
			if (y == -1){
				up = false;
				down = true;
				x++;
				y++;
			}
		}
	}

	printf("\n");
}