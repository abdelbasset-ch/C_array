#ifndef STRING_ARRAY_H__
#define STRING_ARRAY_H__
#include "astr.h"
typedef struct string_array* string_array;
typedef struct string_array s_string_array;

struct string_array{
  astr* data;
  int alloc;
  int length;
};

string_array string_array_init(int alloc, int length);
//initiate 0 length string_array
string_array zero_length_string_array(int alloc);
string_array string_array_clone(string_array str_arr);
void print_string_array(string_array str_arr);
void string_array_insert(string_array str_arr, astr _astr, int index);
void string_array_add(string_array str_arr,astr _astr);
//double the allocated memory of string_array
void string_array_resize(string_array str_arr);
//returns new string_array with the two string_arrays contcatinated
string_array concat_string_array(string_array str_arr1, string_array str_arr2);
//concatinate the second string_array to the first
void d_string_array_concat(string_array str_arr1, string_array str_arr2);
//returns all ocurrences of a astr 
intarray find_string_array(string_array _string_array, astr _astr);
//free allocated memory
void string_array_destroy(string_array str_arr);
string_array string_array_asc_order(string_array str_arr);
string_array string_array_desc_order(string_array str_arr);

/*void string_array_delete(string_array _string_array,char* str);
  void string_array_replace(string_array _string_array,char* _str1, char* _str2);*/

#endif
