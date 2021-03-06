#include <stdlib.h>
#include <stdio.h>
#include "charray2d.h"
#include "tools.h"
//this part is made using a char**
/*charray2d charray2d_create( int w,int h,char bg){
  charray2d _charray2d=(charray2d) sp_alloc(sizeof(S_charray2d));
  _charray2d->w=w;
  _charray2d->h=h;
  _charray2d->bg=bg;
  _charray2d->data= (char**) sp_alloc(sizeof(char*)*w);
  for(int i=0; i<w; i++){
    _charray2d->data[i]=sp_alloc(sizeof(char)*h);
  }
  for(int i=0;i<w;i++){
    for(int j=0;j<h;j++){
      _charray2d->data[i][j]=bg;
    }
  }
  return _charray2d;
}

void charray2d_print(charray2d _charray2d){
   for(int i=0;i<_charray2d->w;i++){
    for(int j=0;j<_charray2d->h;j++){
      printf("%c ",_charray2d->data[i][j]);
    }
    printf("\n");
  }
}
void charray2d_insert(charray2d _charray2d,int w, int h, char c){
  if(h<=_charray2d->h && w<=_charray2d->w)
    _charray2d->data[w][h]=c;
}
void charray2d_destroy(charray2d* AA){
  charray2d a=*AA;
  for(int i=0;i<a->w;i++)
    sp_destroy(a->data[i],sizeof(char)*a->h);
  sp_destroy(a->data, sizeof(char*)*a->w);
  sp_destroy(a,sizeof(S_charray2d));
  *AA=NULL;
  }*/


//this part is made using char*
/*charray2d charray2d_create( int w,int h, char bg){
  charray2d charray_2d=(charray2d) sp_alloc(sizeof(S_charray2d));
  charray_2d->w=w;
  charray_2d->h=h;
  charray_2d->bg=bg;
  charray_2d->data=(char*)sp_alloc(sizeof(char)*w*h);
  for(int i=0;i<h*w;i++){
    charray_2d->data[i]=bg;
  }
  return charray_2d;
}
void charray2d_print(charray2d _charray2d){
  for(int i=0; i<_charray2d->w;i++){
    for(int j=i*_charray2d->h; j<i*_charray2d->h+_charray2d->h;j++){
      printf("%c ",_charray2d->data[j]);
    }
    printf("\n");
  }
}
void charray2d_insert(charray2d _charray2d, int w, int h,char c){
  _charray2d->data[w*_charray2d->h+h]=c;
}
void charray2d_destroy(charray2d* AA){
  charray2d a=*AA;
  sp_destroy(a->data,sizeof(char)*a->w*a->h);
  sp_destroy(a,sizeof(S_charray2d));
  *AA=NULL;
  
  }*/

//this part is made using char* and char**
charray2d charray2d_create( int w,int h, char bg){
  charray2d charray_2d=(charray2d) sp_alloc(sizeof(S_charray2d));
  charray_2d->w=w;
  charray_2d->h=h;
  charray_2d->bg=bg;
  charray_2d->data=(char*)sp_alloc(sizeof(char)*w*h);
  for(int i=0;i<h*w;i++){
    charray_2d->data[i]=bg;
  }
  for(int i=0;i<w;i++){
    charray_2d->_data[i]=&charray_2d->data[i*h];
  }
  return charray_2d;
}
void charray2d_print(charray2d _charray2d){
  for(int i=0; i<_charray2d->w;i++){
    for(int j=i*_charray2d->h; j<i*_charray2d->h+_charray2d->h;j++){
      printf("%c ",_charray2d->data[j]);
    }
    printf("\n");
  }
}
void charray2d_insert(charray2d _charray2d, int w, int h,char c){
  _charray2d->data[w*_charray2d->h+h]=c;
}
void charray2d_destroy(charray2d* AA){
  charray2d a=*AA;
  sp_destroy(a->data,sizeof(char)*a->w*a->h);
  sp_destroy(a,sizeof(S_charray2d));
  *AA=NULL;
  
  }
