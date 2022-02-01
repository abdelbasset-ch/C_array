#include <stdlib.h>
#include <stdio.h>
#include "tools.h"
#include "intarray.h"
#include "astr.h"




int main(){
  global_alloc_init();
  {
    astr _astr=rstr_to_astr("tototo");
    printf("astr : ");
    print_astr(_astr);
    /*printf("astr clone : ");
    print_astr(clone_astr(_astr));
    printf("astr_length : %d\nastr_alloc : %d\n",_astr->length,_astr->alloc);
    printf("astr->str : %s\n",astr_to_rstr(_astr));
    print_astr(uppercase_astr(_astr));
    print_astr(lowercase_astr(_astr));
    printf("uppercase : %s\n",astr_to_rstr(uppercase_astr(_astr))); 
    printf("concatination : %s\n",astr_to_rstr(concat_astr(_astr,rstr_to_astr(" toto"))));*/
    /*print_intarray(astr_proper_find(_astr,"toto"));
    print_intarray(find_astr(_astr,"toto"));
    print_astr(astr_substr(_astr,0,2));
    astr_delete_from_to(_astr,1,2);
    print_astr(_astr);*/
    astr_destroy(_astr);
    //free(_astr);
  }
check_memo_alloc();
return 0;
}
