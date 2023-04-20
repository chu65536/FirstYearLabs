/*
Лабороторнвя работа № 8-9
Программирование на языке Си
Чувилин Виталий Антонович
М8О-109Б
*/

#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>

int main(){
    int number = 0;
    int i=' '; char newc;

    while(i!=EOF){
        i=getchar(); newc = i;
        
        if (newc - '0' >= 0 && newc - '0' <= 9){
            number = number * 10 + (newc -'0'); 
        }

        else{
            double ans = number * 25.4;
            printf("%din = %1.1fmm\n", number, ans);
            number = 0;
        }
    }

    return 0;
}
