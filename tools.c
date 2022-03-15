#include "tools.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


int GLOBAL_ALLOC_MEMO=0;
void int_swap(int* a, int* b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
void char_swap(char* a, char* b){
	char tmp=*a;
	*a=*b;
	*b=tmp;
}
void astr_swap(astr a, astr b){
  astr tmp=clone_astr(a);
  a=b;
  b=tmp;
  astr_destroy(tmp);
}
void* sp_alloc(int alloc){
  void* p=malloc(alloc);
  GLOBAL_ALLOC_MEMO+=alloc;
  return p;
}

void sp_destroy(void* p,int p_alloc){
  free(p);
  p=NULL;
  GLOBAL_ALLOC_MEMO-=p_alloc;
   
}
void check_memo_alloc(){
  if(GLOBAL_ALLOC_MEMO!=0){
    printf("memory leak = %d\n",GLOBAL_ALLOC_MEMO);
  }
}
void global_alloc_init(){
  GLOBAL_ALLOC_MEMO=0;
}
float puissance_iter(int a,int b){
  float result=1;
  if(b==0)
    return result;
  for(int i=1;i<=abs(b);i++){
    if(b>0)
      result*=a;
    else
      result*=(float) 1/a;
  }
  return result;
}
float puissance_recu(int a, int b){
  if(b==0){
    return 1;
  }else if(b<0){
    return 1/puissance_recu(a,abs(b));
  }else{
    return a*puissance_recu(a,b-1);
  }
}
float puissance_alex(int a, int b){
  if(b==0)
    return 1;
  else if(b<0)
    return 1/puissance_alex(a,abs(b));
  else if(b%2==0)
    return puissance_alex(a*a,b/2);
  else if(b%2==1)
    return a*puissance_alex(a*a,(b-1)/2);
}
int random_int(int min, int max){
  int amp=max-min+1;
  double ran=(1.0*rand()/INT_MAX)*amp;
  int result=ran+min;
  return result;
}
