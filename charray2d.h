#ifndef CHARRAY2D_H__
#define CHARRAY2D_H__

typedef struct charray2d* charray2d;
typedef struct charray2d S_charray2d;

struct charray2d {
  int h; int w; char bg;
  char* data;
  char** _data;
};

charray2d charray2d_create( int w,int h, char bg);
void charray2d_print(charray2d _charray2d);
void charray2d_insert(charray2d _charray2d, int w, int h,char c);
void charray2d_destroy(charray2d* AA);

#endif
