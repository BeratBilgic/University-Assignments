#include <stdio.h>

int findHCF(int x,int y,int div);

int main(){
    printf("%d\n",findHCF(24,18,18));
}

int findHCF(int x,int y,int div){
    if (x%div == 0 && y%div == 0)
    {
        return div;
    }else{
        return findHCF(x,y,div-1);
    }
}