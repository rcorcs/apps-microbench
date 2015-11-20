//#include <stdio.h>

int basicScan(){
   int n = 100;
   int vec[n];	
   int i;
   for(i = 0; i<n; i++){//scan +:vec
      vec[i] = vec[i-1]+3; //scan operation
   }
   return vec[n-1];
}

int aliasedBasicScan(){
   int n = 100;
   int vec[n];	
   int i;
   for(i = 0; i<n; i++){//scan +:vec
      int *lv = vec; //alias
      vec[i] = lv[i-1]+3; //scan operation
   }
   return vec[n-1];
}

int preAliasedBasicScan(){
   int n = 100;
   int vec[n];	
   int *lv = vec; //alias
   int i;
   for(i = 0; i<n; i++){//scan +:vec
      vec[i] = lv[i-1]+3; //scan operation
   }
   return vec[n-1];
}

void scanInsideFunction(int *vec, int i){
   vec[i] = vec[i-1]+3; //scan operation
}

int aliasedFunctionScan(){
   int n = 100;
   int vec[n];	
   int i;
   for(i = 0; i<n; i++){//scan +:vec
      scanInsideFunction(vec,i);
   }
   return vec[n-1];
}

int almostScan(){
   int n = 100;
   int vec[n];	
   int i;
   for(i = 0; i<n; i++){
      vec[i] = vec[0]+3;
   }
   return vec[n-1];
}

void resetInsideFunction(int *vec,int i){
   vec[i] = 3;
}

int almostFunctionScan(){
   int n = 100;
   int vec[n];	
   int i;
   for(i = 0; i<n; i++){
      resetInsideFunction(vec,i);
   }
   return vec[n-1];
}

int ifMAXScan(){
   int n = 100;
   int vec[n];
   int i;
   for(i = 1; i<n; i++){
      if(vec[i-1]>vec[i])
         vec[i] = vec[i-1]
   }
   return vec[n-1];
}

int ternaryMAXScan(){
   int n = 100;
   int vec[n];
   int i;
   for(i = 1; i<n; i++){
      vec[i] = (vec[i-1]>vec[i])?vec[i-1]:vec[i];
   }
   return vec[n-1];
}

int main(){
   int resp;
   resp = basicScan();
   printf("%d\n", resp);
   resp = aliasedBasicScan();
   printf("%d\n", resp);
   resp = preAliasedBasicScan();
   printf("%d\n", resp);
   resp = aliasedFunctionScan();
   printf("%d\n", resp);
   resp = almostScan();
   printf("%d\n", resp);
   resp = almostFunctionScan();
   printf("%d\n", resp);
   return 0;
}

