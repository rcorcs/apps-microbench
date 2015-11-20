//#include <stdio.h>

int basicMap(){
   int n = 100;
   int vec[n];	
   int i;
   for(i = 0; i<n; i++){ //map
      vec[i] = 0; //map operation
   }
   return vec[n-1];
}

int resetMap(){
   int n = 100;
   int vec[n];	
   int i;
   for(i = 0; i<n; i++){ //map
      vec[i] = 0; //map operation
      int tmp = i*sqrt(i*10);
      vec[i] = tmp+i;
   }
   return vec[n-1];
}

int reductionMap(){
   int n = 100;
   int vec[n];	
   int i,j;
   for(i = 0; i<n; i++){ //map
      vec[i] = 0;
      for(j = 0; j<n; j++){ //reduce +:vec
         vec[i] += 1;
      }
   }
   return vec[i-1];
}

int anotherReductionMap(){
   int n = 100;
   int vec[n];	
   int i,j;
   for(i = 0; i<n; i++){ //map
      vec[i] = 0; //map operation
   }
   for(i = 0; i<n; i++){ //map
      for(j = 0; j<n; j++){ //reduce +:vec
         vec[i] += 1;
      }
   }
   return vec[i-1];
}

int aliasedMap(){
   int n = 100;
   int vec[n];	
   int i;
   for(i = 0; i<n; i++){ //map
      int *lv = vec; //alias
      lv[i] = sqrt(i*10); //map operation
   }
   return vec[n-1];
}

int preAliasedMap(){
   int n = 100;
   int vec[n];	
   int *lv = vec; //alias
   int i;
   for(i = 0; i<n; i++){ //map
      lv[i] = sqrt(i*10); //map operation
   }
   return vec[n-1];
}

void mapFunction(int *vec,int i){
   vec[i] = sqrt(i*10); //map operation
}


int aliasedFunctionMap(){
   int n = 100;
   int vec[n];	
   int i;
   for(i = 0; i<n; i++){ //map
      mapFunction(vec,i);
   }
   return vec[n-1];
}


int main(){
   int resp;
   resp = basicMap();
   printf("%d\n", resp);
   resp = resetMap();
   printf("%d\n", resp);
   resp = reductionMap();
   printf("%d\n", resp);
   resp = anotherReductionMap();
   printf("%d\n", resp);
   resp = aliasedMap();
   printf("%d\n", resp);
   resp = preAliasedMap();
   printf("%d\n", resp);
   resp = aliasedFunctionMap();
   printf("%d\n", resp);
   return 0;
}

