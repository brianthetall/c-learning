
typedef struct{
  int col,row;
  char **map;
  char* (*toString)(void);
  void (*close)(void*);//void* is kmap*
}kmap;

kmap* getKmaps(int);
char* toString(void);
