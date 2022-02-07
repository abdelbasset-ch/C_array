#include <stdlib.h>
#include <stdio.h>
#include "astr.h"
#include "tools.h"


astr init_astr(int length, int alloc){
        astr tmp_astr=sp_alloc(sizeof (astr));
	tmp_astr->length=length;
	tmp_astr->alloc=alloc;
	tmp_astr->data=sp_alloc(sizeof(char)*(tmp_astr->alloc));
	for (int i=0;i<length;i++)
		tmp_astr->data[i]='_';
	return tmp_astr;
}

astr zero_length_astr(int alloc){
	return  init_astr(0,alloc);
}
void astr_destroy(astr _astr){
  
    sp_destroy(_astr->data,sizeof(char)*_astr->alloc);
    sp_destroy(_astr,sizeof(_astr));
  
}

void print_astr(astr _astr){
	printf("[");
	for(int i=0;i<_astr->length;i++){
		printf("%c ",_astr->data[i]);
	}
	printf("]\n");
}

void insert_astr(astr _astr, 
	int index, char _char){
	if(_astr->length>index)
	_astr->data[index]=_char;
}

void add_astr(astr _astr,char _char){
	if(_astr->alloc>_astr->length){
		_astr->length++;
		insert_astr(_astr, _astr->length-1
		,_char);
		
	}else if(_astr->alloc<=_astr->length){
		resize_astr(_astr);
		add_astr(_astr,_char);
	}
}
astr clone_astr(astr _astr){
        astr new_astr=init_astr(_astr->length,_astr->alloc);
	for(int i=0;i<new_astr->length;i++){
		new_astr->data[i]=_astr->data[i];
	}
	
	return new_astr;
	
}
void resize_astr(astr _astr){
	_astr->data=(char *) realloc(_astr->data,
		 (2*_astr->alloc)*sizeof(char));
	GLOBAL_ALLOC_MEMO+=_astr->alloc;
	_astr->alloc=2*_astr->alloc;
	
}

rstr astr_to_rstr(astr _astr){
        char* str=sp_alloc(sizeof(char)*_astr->length+1);
	for (int i=0; i<_astr->length;i++){
		str[i]=_astr->data[i];
	}
	str[_astr->length]='\0';
	return str;
}
astr rstr_to_astr(char* _str){
	int counter=0;
	char c=_str[0];
	for(int i=0;c!='\0';i++){
		c=_str[i];
		counter++;
	}
	astr tmp=zero_length_astr(1);
	for(int i=0;i<counter-1;i++){
		add_astr(tmp,_str[i]);
	}
	return tmp;
}
astr concat_astr(astr astr1, astr astr2){
	astr tmp_astr=init_astr(astr1->length+astr2->length,astr1->alloc+astr2->alloc);
	for(int i=0;i<astr1->length;i++){
		tmp_astr->data[i]=astr1->data[i];
	}
	for(int i=astr1->length,j=0;i<tmp_astr->length;i++,j++){
		tmp_astr->data[i]=astr2->data[j];
	}
	return tmp_astr;
}
void d_astr_concat(astr astr1, astr astr2){
	for(int i=0;i<astr2->length;i++){
		add_astr(astr1,astr2->data[i]);
	}
}
astr uppercase_astr(astr _astr){
	astr tmp=clone_astr(_astr);
	print_astr(tmp);
	for(int i=0;i<tmp->length;i++){
		if((int)tmp->data[i]>=97 && (int)tmp->data[i]<=122){
			tmp->data[i]=(char)((int)tmp->data[i]-32);
		}
	
	}
	return tmp;
}
astr lowercase_astr(astr _astr){
	astr tmp=clone_astr(_astr);
	for(int i=0;i<tmp->length;i++){
		if((int)tmp->data[i]>=65 && (int)tmp->data[i]<=90){
			tmp->data[i]=(char)((int)tmp->data[i]+32);
		}
	
	}
	return tmp;
}
int compare_astr(astr astr1, astr astr2){
	if(astr1->length==astr2->length){
		for(int i=0;i<astr1->length;i++){
			if(astr1->data[i]<astr2->data[i]){
				return 1;	
			}
			else if(astr1->data[i]>astr2->data[i]){
				return -1;	
			}
		}
		return 0;
	}
	else{
	int len=astr1->length<astr2->length?astr1->length:astr2->length;
	for (int i=0;i<len;i++){
		if(astr1->data[i]<astr2->data[i]){
			return 1;
		}
		else if(astr1->data[i]>astr2->data[i]){
			return -1;
		}
	}
	return astr1->length<astr2->length?1:-1;
	}
}
intarray find_astr(astr _astr, char* str){
	intarray tmp_intarray=zero_length_intarray(2);
	int counter=0;
	astr tmp_astr=rstr_to_astr(str);
	for(int i=0; i<_astr->length; i++){
		for(int j=0; j<tmp_astr->length && i+j<_astr->length; j++){
			if(_astr->data[i+j]==tmp_astr->data[j]){
				counter++;
			}
		}
		if(counter==tmp_astr->length){
			add_intarray(tmp_intarray,i);
		}
		counter=0;
	}

	
	astr_destroy(tmp_astr);
	return tmp_intarray;
}

intarray astr_proper_find(astr _astr, char* str){
	intarray tmp_intarray=zero_length_intarray(2);
	astr tmp_astr= rstr_to_astr(str);
	
	int counter=0;
	for(int i=0; i<_astr->length; i++){
		for(int j=0; j<tmp_astr->length && i+j<_astr->length; j++){
			if(_astr->data[i+j]==tmp_astr->data[j]){
				counter++;
			}
		}
		if(counter==tmp_astr->length){
			add_intarray(tmp_intarray,i);
			i+=tmp_astr->length;
		}
		counter=0;
	}

	
	astr_destroy(tmp_astr);
	return tmp_intarray;
}
astr astr_substr(astr _astr, int start, int end){
	astr tmp=zero_length_astr(1);
	if(start>_astr->length || end>_astr->length){
		printf("indexes must be in the range of astr length\n");
		return tmp;
	}
	for(int i=start; i<end; i++){
		add_astr(tmp,_astr->data[i]);
	}
	return tmp;
}

void astr_delete_from_to(astr _astr, int start
, int end){
	if(start>=_astr->length || end>_astr->length){
		printf("indexes must be in the range of astr length\n");
		return;
	}
	astr tmp=astr_substr(_astr,end,_astr->length);
	for(int i=start; i<_astr->length; i++){
		_astr->data[i]='_';
	}
	_astr->length-=(_astr->length-start);
	d_astr_concat(_astr,tmp);
	astr_destroy(tmp);
}
astr astr_trim(astr _astr){
  astr clone=clone_astr(_astr);
  while(clone->data[0]==' '){
    astr_delete_from_to(clone, 0, 1);
  }
  while(clone->data[clone->length-1]==' '){
    astr_delete_from_to(clone,clone->length-1,clone->length);
    }
  return clone;
}
void astr_replace_from_to(astr _astr,char* str, int start, int end){
  astr tmp=rstr_to_astr(str);
  astr sub=astr_substr(_astr,end,_astr->length);
  astr_delete_from_to(_astr,start,_astr->length);
  d_astr_concat(_astr,tmp);
  d_astr_concat(_astr,sub);
  astr_destroy(tmp);
  astr_destroy(sub);
  
}
void astr_delete(astr _astr,char* str){
  astr _str=rstr_to_astr(str);
  intarray find=astr_proper_find(_astr,str);
  astr_delete_from_to(_astr,find->data[0],find->data[0]+_str->length);
  astr_destroy(_str);
  intarray_destroy(find);
  
}
void astr_replace(astr _astr, char* _str1, char* _str2){
  astr astr1=rstr_to_astr(_str1);
  astr astr2=rstr_to_astr(_str2);
  intarray find=astr_proper_find(_astr,_str1);
  astr_replace_from_to(_astr,_str2,find->data[0],find->data[0]+astr1->length);
  astr_destroy(astr1);
  astr_destroy(astr2);
  intarray_destroy(find);
}
