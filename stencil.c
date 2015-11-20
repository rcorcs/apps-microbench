//#include <stdio.h>

int basicStencil(){
   int n = 100;
   int input[n];
   int output[n];	
   int i;
   for(i = 1; i<n-1; i++){ //stencil
      output[i] = input[i-1]+input[i]+input[i+1];
   }
   return output[n-1];
}

int main(){
   int resp;
   resp = basicStencil();
   printf("%d\n", resp);
   return 0;
}

