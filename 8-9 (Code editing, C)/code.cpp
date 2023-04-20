
/*
Лабороторнвя работа № 8-9
Программирование на языке Си
Чувилин Виталий Антонович
М8О-109Б
*/

#include <stdio.h>
#include <algorithm>

using namespace std;

int sign(int a){
    return 2*(a >= 0) - 1;
}

int main() {
    const int i0 = 10, j0 = 20, l0 = -1;
    int i = i0, j = j0, l = l0;

    int inext = i, jnext = j, lnext = l;
    for (int k = 0; k <= 50; k++){
    	if (i >= 5 && i <= 15 && j >= -15 && j <= -5){
    		printf("Point in area.\n");
    		printf("k = %d, i = %d, j= %d, l = %d \n", k, i, j, l);
    		return 0;
    	}

    	//printf("step: %d\ni = %d, j= %d, l = %d \n", k, i, j, l);

    	inext = ((abs(max(i*(k+5), j*(k+6))) - abs(min(j*(k+7), l*(k+8)))) % 20 + 20) % 20;
    	jnext = ((3 - sign(i - j))*abs(min(min(i*l + 5, j*l - 3), i*j + 6)) % 25 + 25) % 25 - 7;
    	lnext = (i % 10 + 10) % 10 + (j % 10 + 10) % 10 + (l % 10 + 10) % 10;

    	i = inext;
    	j = jnext;
    	l = lnext;

    }

    printf("Point is not in area.\n");
    printf("i = %d, j = %d, l = %d \n", i, j, l);
    
    return 0;
}