// Lab 11 - Pentagon numbers are produced according to the formula Pn=n(3n−1)/2. Print pentagon numbers less than 100 to the screen.

#include <stdio.h>

int main()
{
    float i = 1,p;
    for(i = 1; p <= 100; i++){
        p = i*(3*i-1)/2;
        if (p >= 100)
        {
            break;
        }else{
            printf("%f\n",p);
        }
    }
    
    return 0;
}