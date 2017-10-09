typedef struct{

  int (*count)(char*,const char*);
  void (*free)(void*);
  int (*list)(char**,char*,char*);
  
}tokenizer;

int count(char*,const char*);
void free(void*);
tokenizer* tokenizer_build(void);
int list(char**,char*,char*);
