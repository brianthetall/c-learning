
typedef struct{
  char **map;
  char* (*toString)(void);
}kmap;

kmap* getKmaps(int);
char* toString(void);
