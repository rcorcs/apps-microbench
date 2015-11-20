//#include <stdio.h>

int basicReduction(){
   int n = 100;
   int val = 0;
   int i;
   for(i = 0; i<n; i++){
      val += i;
   }
   return val;
}

int basicAssignReduction(){
   int n = 100;
   int val = 0;
   int i;
   for(i = 0; i<n; i++){
      val = val + i;
   }
   return val;
}

int funcCallReduction(){
   int n = 100;
   int val = 0;
   int i;
   for(i = 0; i<n; i++){
      val = val + sqrt(2*i);
   }
   return val;
}

int preComputeReduction(){
   int n = 100;
   int val = 0;
   int i;
   for(i = 0; i<n; i++){
      int tmp = sqrt(2*i);
      val = val + tmp;
   }
   return val;
}

int almostReduction(){
   int n = 100;
   int val;
   int i;
   for(i = 0; i<n; i++){
      val = i*2;
      val += sqrt(i);
   }
   return val;
}

int impostorReduction(){
   int n = 100;
   int val = 0;
   int tmp;
   int i;
   for(i = 0; i<n; i++){
      tmp = i*2;
      tmp += sqrt(i);
      val = val + tmp;
   }
   return val;
}

int conditionalReduction(){
   int n = 100;
   int val = 0;
   int tmp = rand();
   int i;
   for(i = 0; i<n; i++){
      if(tmp<10){
         val = val + tmp;
      }
   }
   return val;
}

int doubleReduction(){
   int n = 100;
   int val1 = 0;
   int val2 = 0;
   int i;
   for(i = 0; i<n; i++){
      val1 += i*2;
      val2 += sqrt(i*100);
   }
   return val;
}

int doubleDifferentReduction(){
   int n = 100;
   int val1 = 1;
   int val2 = 0;
   int i;
   for(i = 0; i<n; i++){
      val1 *= i+1;
      val2 += sqrt(i*100);
   }
   return val;
}

int conditionalDoubleReduction(){
   int n = 100;
   int val1 = 0;
   int val2 = 0;
   int tmp = rand();
   int i;
   for(i = 0; i<n; i++){
      if(tmp<10){
         val1 += i*2;
      }else{
         val2 += sqrt(i*100);
      }
   }
   return val;
}

int aliasedReduction(){
   int n = 100;
   int val;
   int i;
   for(i = 0; i<n; i++){
      int *tmp = &val; //alias
      val = *tmp + i;
   }
   return val;
}

int preAliasedReduction(){
   int n = 100;
   int val;
   int *tmp = &val; //alias
   int i;
   for(i = 0; i<n; i++){
      val = *tmp + i;
   }
   return val;
}

int aliasedCopyReduction(){
   int n = 100;
   int val;
   int i;
   for(i = 0; i<n; i++){
      int tmp = val; //"read-alias" by copy
      val = tmp + i;
   }
   return val;
}

int conditionalAliasedReduction(){
   int n = 100;
   int val = 0;
   int *ptr;
   int tmp = rand();
   int i;
   for(i = 0; i<n; i++){
      if(tmp<10){
         ptr = &val; //alias
      }
      val = *ptr + i;
   }
   return val;
}

int conditionalPreAliasedReduction(){
   int n = 100;
   int val = 0;
   int tmp = rand();
   int *ptr;
   int i;
   if(tmp<10){
      ptr = &val; //alias
   }
   for(i = 0; i<n; i++){
      val = *ptr + i;
   }
   return val;
}

void reduceInsideFunction(int *val){
   int tmp = sqrt((int)val);
   *val = *val + tmp;
}

int aliasedFunctionReduction(){
   int n = 100;
   int val;
   int i;
   for(i = 0; i<n; i++){
      reduceInsideFunction(&val);
   }
   return val;
}

int aliasedAlmostReduction(){
   int n = 100;
   int val;
   int i;
   for(i = 0; i<n; i++){//none
      int *tmp = &val; //alias
      *tmp = 1; //reset accumulator
      val += i;
   }
   return val;
}

int preAliasedAlmostReduction(){
   int n = 100;
   int val;
   int *tmp = &val; //alias
   int i;
   for(i = 0; i<n; i++){//none
      *tmp = 1; //reset aliased accumulator
      val += i;
   }
   return val;
}

void aliasedResetFunction(int *val){
   *val = sqrt((int)val);
}

int aliasedFunctionAlmostReduction(){
   int n = 100;
   int val;
   int i;
   for(i = 0; i<n; i++){//none
      aliasedResetFunction(&val); //alias
      val += i;
   }
   return val;
}

int vectorReduction(){
   int n = 100;
   int vec[n];
   int i,k;
   for(k = 0; k<n; k++){ //map
      vec[k] = 0; //map operation
      for(i = 0; i<n; i++){//reduce +:vec[k]
         vec[k] = vec[k]+3; //reduce operation
      }
   }
   return vec[n-1];
}

int vectorAliasedReduction(){
   int n = 100;
   int vec[n];
   int i,k;
   for(k = 0; k<n; k++){ //map
      vec[k] = 0; //map operation
      for(i = 0; i<n; i++){//reduce +:vec[k]
         int *lv = vec; //alias
         vec[k] = lv[k]+3; //reduce operation
      }
   }
   return vec[n-1];
}

void reduceArrayFunction(int *vec,int i){
   vec[i] = vec[i]+sqrt(i*2);
}

int vectorFunctionReduction(){
   int n = 100;
   int vec[n];
   int i,k;
   for(k = 0; k<n; k++){ //map
      vec[k] = 0; //map operation
      for(i = 0; i<n; i++){//reduce +:vec[k]
         reduceArrayFunction(vec,k); //reduce operation
      }
   }
   return vec[n-1];
}

int mapNotReduction(){
   int n = 100;
   int vec[n];
   int i;
   for(i = 0; i<n; i++){//map
      vec[i] = vec[i]+3; //map operation
   }
   return vec[n-1];
}

int scanNotReduction(){
   int n = 100;
   int vec[n];
   int i;
   for(i = 0; i<n; i++){//scan
      vec[i] = vec[i-1]+3; //scan operation
   }
   return vec[n-1];
}

//Indirect array accesses
int indirectArrayAccessReduction(){
   int n = 100;
   int vec[n];
   int idx[n];

   int i,k;
   for(i = 0; i<n; i++){
      idx[i] = i;
   }
   for(k = 0; k<n; k++){ //map
      vec[idx[k]] = 0; //map operation
      for(i = 0; i<n; i++){//reduce +:vec[k]
         vec[idx[k]] = vec[idx[k]]+3; //reduce operation
      }
   }
   return vec[n-1];
}

int basicANDReduction(){
   int n = 100;
   int val = 1;
   int i;
   for(i = 0; i<n; i++){
      val = val && i&0x01;
   }
   return val;
}

int ifMAXReduction(){
   int n = 100;
   int max = 1;
   int i;
   for(i = 0; i<n; i++){
      if(i>max)
         max = i;
   }
   return max;
}

int ternaryMAXReduction(){
   int n = 100;
   int max = 1;
   int i;
   for(i = 0; i<n; i++){
      max = (i>max)?i:max;
   }
   return max;
}

int extendedMAXReduction(){
   int n = 100;
   int vec[n];
   int max = vec[0];
   int maxidx = 0;
   int i;
   for(i = 1; i<n; i++){
      if(vec[i]>max){
         maxidx = i;
         max = vec[i];
      }
   }

   return max;
}

int complexMAXReduction(){
   int n = 100;
   int vec[n];
   int max = -1;
   int maxidx = -1;
   int i;
   for(i = 0; i<n; i++){
      if(vec[i]>max || argidx<0){
         maxidx = i;
         max = vec[i];
      }
   }

   return max;
}

int main(){
   int resp;
   resp = basicReduction();
   printf("%d\n",resp);
   resp = basicAssignReduction();
   printf("%d\n",resp);
   resp = funcCallReduction();
   printf("%d\n",resp);
   resp = preComputeReduction();
   printf("%d\n",resp);
   resp = almostReduction();
   printf("%d\n",resp);
   resp = impostorReduction();
   printf("%d\n",resp);
   resp = aliasedReduction();
   printf("%d\n",resp);
   resp = preAliasedReduction();
   printf("%d\n",resp);
   resp = aliasedCopyReduction();
   printf("%d\n",resp);
   resp = aliasedFunctionReduction();
   printf("%d\n",resp);
   resp = aliasedAlmostReduction();
   printf("%d\n",resp);
   resp = preAliasedAlmostReduction();
   printf("%d\n",resp);
   resp = aliasedFunctionAlmostReduction();
   printf("%d\n",resp);
   resp = vectorReduction();
   printf("%d\n",resp);
   resp = vectorAliasedReduction();
   printf("%d\n",resp);
   resp = vectorFunctionReduction();
   printf("%d\n",resp);
   resp = scanNotReduction();
   printf("%d\n",resp);
   resp = indirectArrayAccessReduction();
   printf("%d\n",resp);
   resp = basicANDReduction();
   printf("%d\n",resp);
   resp = ifMAXReduction();
   printf("%d\n",resp);
   resp = ternaryMAXReduction();
   printf("%d\n",resp);
   return 0;
}
