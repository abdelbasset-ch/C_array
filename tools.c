#include "tools.h"
#include <stdlib.h>
#include <stdio.h>

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
