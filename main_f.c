#include <stdlib.h>
#include <stdio.h>
#include "tools.h"
#include "intarray.h"
#include "astr.h"

int main(){
  global_alloc_init();
  {
    astr _astr=rstr_to_astr("tototo");
    astr c_astr=clone_astr(_astr);
    printf("astr : ");
    print_astr(_astr);
    printf("astr clone : ");
    print_astr(c_astr);
    printf("astr_length : %d\nastr_alloc : %d\n",_astr->length,_astr->alloc);
    char* str1=astr_to_rstr(_astr);
    printf("astr->str : %s\n",str1);
    astr u_astr=uppercase_astr(_astr);
    astr l_astr=lowercase_astr(_astr);
    print_astr(u_astr);
    print_astr(l_astr);
    //printf("uppercase : %s\n",astr_to_rstr(_astr));
    intarray p_find=astr_proper_find(_astr,"toto");
    print_intarray(p_find);
    intarray find=find_astr(_astr,"toto");
    print_intarray(find);
    astr sub_astr=astr_substr(_astr,0,2);
    print_astr(sub_astr);
    astr_delete_from_to(_astr,1,2);
    print_astr(_astr);
    astr_destroy(c_astr);
    astr_destroy(u_astr);
    astr_destroy(l_astr);
    intarray_destroy(p_find);
    intarray_destroy(find);
    astr_destroy(sub_astr);
    printf("%d\n",GLOBAL_ALLOC_MEMO);
    destroy(str1,_astr->length+1);
    printf("%d\n",GLOBAL_ALLOC_MEMO);
    astr_destroy(_astr);
    //astr_destroy(sub_astr);
  }
check_memo_alloc();
return 0;
}
