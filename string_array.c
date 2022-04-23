#include <stdlib.h>
#include <stdio.h>
#include "tools.h"
#include "astr.h"
#include "string_array.h"
#include "intarray.h"
//#define VNAME(x) #x
string_array string_array_init(int alloc, int length){
  string_array str_arr=(string_array) sp_alloc(sizeof(s_string_array));
  str_arr->alloc=alloc;
  str_arr->length=length;
  str_arr->data=(astr*) sp_alloc(sizeof(astr)*alloc);
  for(int i=0;i<alloc;i++){
    str_arr->data[i]=NULL;
  }
  return str_arr;
}
string_array zero_length_string_array(int alloc){
  return string_array_init(alloc,0);
}
string_array string_array_clone(string_array str_arr){
  string_array str_clone=string_array_init(str_arr->alloc, str_arr->length);
  for(int i=0;i<str_clone->length;i++){
    str_clone->data[i]=clone_astr(str_arr->data[i]);
  }
  return str_clone;
}
void print_string_array(string_array str_arr){
  for(int i=0;i<str_arr->length;i++){
    print_astr(str_arr->data[i]);
    
  }
}
void string_array_insert(string_array str_arr, astr _astr, int index){
  if(index<str_arr->length){
    //astr_destroy(str_arr->data[index]);
    str_arr->data[index]=clone_astr(_astr);
  }
}
void string_array_add(string_array str_arr,astr _astr){
  if( str_arr->length>=str_arr->alloc){
    string_array_resize(str_arr);
    string_array_add(str_arr,_astr);
  }else{
    str_arr->length++;
    string_array_insert(str_arr,_astr,str_arr->length-1);
  }
}
void string_array_resize(string_array str_arr){
  //sp_destroy(str_arr->data,str_arr->alloc);
  str_arr->data=realloc(str_arr->data,(2*str_arr->alloc)*sizeof(astr));
  GLOBAL_ALLOC_MEMO+=str_arr->alloc*sizeof(astr);
  str_arr->alloc+=str_arr->alloc;
  
}

string_array concat_string_array(string_array str_arr1, string_array str_arr2){
  string_array new_str_arr=zero_length_string_array(1);
  for(int i=0; i<str_arr1->length;i++){
    string_array_add(new_str_arr,str_arr1->data[i]);
  }
  for(int i=0; i<str_arr2->length;i++){
    string_array_add(new_str_arr,str_arr2->data[i]);
  }
  return new_str_arr;
}
void d_string_array_concat(string_array str_arr1, string_array str_arr2){
  for(int i=0; i<str_arr2->length;i++){
    string_array_add(str_arr1,str_arr2->data[i]);
  }
}

intarray find_string_array(string_array str_arr, astr _astr){
  intarray find=zero_length_intarray(1);
  for(int i=0; i<str_arr->length;i++){
    if(compare_astr(str_arr->data[i],_astr)==0){
      add_intarray(find,i);
    }
  }
  return find;
}
void string_array_destroy(string_array* str_arr){
  string_array a=*str_arr;
  for(int i=0;i<a->length;i++){
    astr_destroy(&a->data[i]);
  }
  sp_destroy(a->data,a->alloc*sizeof(astr));
  sp_destroy(a,sizeof(string_array));
  *str_arr=NULL;
}
string_array string_array_asc_order(string_array str_arr){
  string_array tmp_str=zero_length_string_array(1);
  for(int i=0; i<str_arr->length;i++){
    astr _astr=clone_astr(str_arr->data[i]);
    for(int j=i;j<str_arr->length;j++){
      if(compare_astr(_astr,str_arr->data[j])==-1){
	astr_destroy(&_astr);
	_astr=clone_astr(str_arr->data[j]);
      }
    }
    string_array_add(tmp_str,_astr);
    astr_destroy(&_astr);
  }
  return tmp_str;
}
string_array string_array_desc_order(string_array str_arr){
 string_array tmp_str=zero_length_string_array(1);
  for(int i=0; i<str_arr->length;i++){
    astr _astr=clone_astr(str_arr->data[i]);
    for(int j=i;j<str_arr->length;j++){
      if(compare_astr(_astr,str_arr->data[j])==1){
	astr_destroy(&_astr);
	_astr=clone_astr(str_arr->data[j]);
      }
    }
    string_array_add(tmp_str,_astr);
    astr_destroy(&_astr);
  }
  return tmp_str;
}

/*void string_array_delete(string_array _string_array,char* str);
  void string_array_replace(string_array _string_array,char* _str1, char* _str2);*/

