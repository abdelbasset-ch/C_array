#include <stdlib.h>
#include <stdio.h>
#include "operations.h"
#include "intarray.h"
#include "astr.h"

int main(){
astr _astr=rstr_to_astr("adadad");
printf("astr : ");
print_astr(_astr);
printf("astr_length : %d\nastr_alloc : %d\n",_astr.length,_astr.alloc);
printf("astr->str : %s\n",astr_to_rstr(_astr));
printf("uppercase : %s\n",astr_to_rstr(uppercase_astr(_astr))); 
printf("concatination : %s\n",astr_to_rstr(concat_astr(_astr,rstr_to_astr(" basset"))));
print_intarray(find_astr(_astr,"adad"));
print_intarray(astr_proper_find(_astr,"adad"));
print_intarray(find_astr(_astr,"adad"));

return 0;
}