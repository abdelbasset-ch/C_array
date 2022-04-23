#ifndef ASTR
#define ASTR
#include "intarray.h"
#define rstr char*
typedef struct _astr s_astr;
typedef struct _astr* astr;

struct _astr {
	char* data;
	int alloc;
	int length;
};


astr init_astr(int length, int alloc);
//initiate astr with 0 length
astr zero_length_astr(int alloc);
void astr_destroy(astr* _astr);
void print_astr(astr _astr);
void insert_astr(astr _astr, 
	int index, char _char);
void add_astr(astr _astr,char _char);
astr clone_astr(astr _astr);
//double the allocated memory
void resize_astr(astr _astr);
rstr astr_to_rstr(astr _astr);
astr rstr_to_astr(char* _str);
//return new astr with the two astr concatinated
astr concat_astr(astr astr1, astr astr2);
//concatinate the second to the first astr
void d_astr_concat(astr astr1, astr astr2);
astr uppercase_astr(astr _astr);
astr lowercase_astr(astr _astr);
//compare alphabetically two astr
int compare_astr(astr astr1, astr astr2);
//find all the appearences of a string for example toto in tototo returns 0 2 
intarray find_astr(astr _astr, char* str);
//find all the appearences of a string for exqmple toto in tototo returns 0
intarray astr_proper_find(astr _astr, char* str);
//returns a part of a string
astr astr_substr(astr _astr, int start, int end);
void astr_delete_from_to(astr _astr, int start, int end);
//delete blanck space from the left and the right of a string 
astr astr_trim(astr _astr);
void astr_replace_from_to(astr _astr,char* str, int start, int end);
void astr_delete(astr _astr,char* str);
void astr_replace(astr _astr,char* _str1, char* _str2);

#endif
