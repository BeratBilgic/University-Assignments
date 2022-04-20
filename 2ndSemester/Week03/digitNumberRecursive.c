#include <stdio.h>

int findDigit(int x);

int main(){
    printf("%d\n",findDigit(123456789));
}

int findDigit(int x){
    if (x < 10)
    {
        return 1;
    }else{
        return 1 + findDigit(x/10);;
    }
}