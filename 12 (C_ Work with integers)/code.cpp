// Чувилин Виталий Антонович
// М8О-109Б

#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);

	int m = n;
	int rev = 0;
	while(n != 0){
		int x = n % 10;

		rev = rev * 10 + x;

		n /= 10;
	}

	int ans = 0;
	for (int i = 0; i < 3; i++){
		int tmp = rev;

		while(tmp != 0){
			int x = tmp % 10;

			if (x % 3 == i){
				ans = ans * 10 + x;
			}

			tmp /= 10;
		}
	}

	printf("New num: %d\n", ans);
	ans = m - ans;
	if (ans < 0) ans = -ans;
	printf("Diff: %d\n",ans);
}


