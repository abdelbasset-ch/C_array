#ifndef TOOLS_H__
#define TOOLS_H__
extern int GLOBAL_ALLOC_MEMO;
#define sum(a,b) a+b
#define substract(a,b) a-b
#define multiply(a,b) a*b
#define devide(a,b) a/b
void int_swap(int* a, int* b);
void char_swap(char* a, char* b);
void* sp_alloc(int alloc);

void sp_destroy(void* p,int p_alloc);
void check_memo_alloc();
void global_alloc_init();

#endif
