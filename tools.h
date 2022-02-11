#ifndef TOOLS_H__
#define TOOLS_H__
// GLOBAL_ALLOC_MEMO keeps track of the dynamic allocated memory to avoid memory leak 
extern int GLOBAL_ALLOC_MEMO;
#define sum(a,b) a+b
#define substract(a,b) a-b
#define multiply(a,b) a*b
#define devide(a,b) a/b

//swap two variables 
void int_swap(int* a, int* b);
void char_swap(char* a, char* b);
void astr_swap(astr a, astr b);
// allocate memory dynamically and add it the GLOBAL_ALLOC_MEMO
void* sp_alloc(int alloc);
//destroy dynamically allocated memory and reduce it from GLOBAL_ALLOC_MEMO
void sp_destroy(void* p,int p_alloc);
//check if there is memory leaks
void check_memo_alloc();
//initiate GLOBAL ALLOC_MEMO to 0
void global_alloc_init();

#endif
