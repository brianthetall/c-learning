
typedef struct{
  char col,row;
  char **map;
  char* (*toString)(void);
  void (*kmap_close)(void*);//void* is kmap*
}kmap;

void kmap_close(kmap*);
kmap* kmap_build(int);
char* toString(void);
