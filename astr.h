#ifndef ASTR
#define ASTR
#include "intarray.h"
#define rstr char*
typedef struct _astr S_astr;
typedef struct _astr* astr;

struct _astr {
	char* data;
	int alloc;
	int length;
};


astr init_astr(int length, int alloc);
astr zero_length_astr(int alloc);
void astr_destroy(astr _astr);
void print_astr(astr _astr);
void insert_astr(astr _astr, 
	int index, char _char);
void add_astr(astr _astr,char _char);
astr clone_astr(astr _astr);
void resize_astr(astr _astr);
rstr astr_to_rstr(astr _astr);
astr rstr_to_astr(char* _str); 
astr concat_astr(astr astr1, astr astr2);
void d_astr_concat(astr astr1, astr astr2);
astr uppercase_astr(astr _astr);
astr lowercase_astr(astr _astr);
int compare_astr(astr astr1, astr astr2);
intarray find_astr(astr _astr, char* str);
intarray astr_proper_find(astr _astr, char* str);
astr astr_substr(astr _astr, int start, int end);
void astr_delete_from_to(astr _astr, int start, int end);
//astr astr_trim(astr _astr);
//void astr_replace_from_to(astr* _astr, int start, int end);
//void astr_delete(astr* _astr,char* _char);
//void astr_replace(astr* _astr,char* _char);

#endif
