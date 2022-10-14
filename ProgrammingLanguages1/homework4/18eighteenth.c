/* Homework 4 - 18.Write C code to print the Floyd's Triangle.
   1
   01
   101
   0101
   10101 */

   #include <stdio.h>

   int main()
   {
      int c,i,j,count = 1; 
      printf("enter the value of the row\n");
      scanf("%d",&c);

      for ( i = 1; i <= c; i++){
         if(i%2 == 0){
            count = 0;
         }
         else{
            count = 1;
         }
         for ( j = 1; j <= i; j++){
            if (count % 2 == 1 ){
               printf("1");
            }
            else{
               printf("0");
            }
            count++;
         }
         printf("\n");
      }
      
      return 0;
   }