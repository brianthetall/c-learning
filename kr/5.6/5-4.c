//strend(s,t)
//return 1 if t is at end of s
//else return 0

#include <stdio.h>
size_t strlen(const char *);
int strend(const char*,const char*);

int main(int argc, char **argv){
  if (argc!=3)
    return 0;

  char* s = *++argv;
  char* t = *++argv;

  printf("sending s=%s, t=%s\n",s,t);
  int result=strend(s,t);
  printf("Result=%d\n",result);
  return result;
}

size_t strlen(const char *s){
  size_t i=0;

  while( *s++ != '\0' )
    i++;

  return i;
}


int strend(const char* s,const char* t){

  size_t len_s=strlen(s);
  size_t len_t=strlen(t);

  if (len_t>len_s)
    return 0;

  //advance to the ends of each, then compare until at start of t
  const char* S=s;
  const char* T=t;
  while( *s++ != '\0' )
    printf("s: %d:%c\n",s,*s);
  while( *t++ != '\0' )
    printf("t: %d:%c\n",t,*t);

  s--;t--;//back off the null
  
  printf("S=%d, T=%d\n",S,T);

  while( t >= T ){
    printf("Compare: %c ?= %c\n",*s,*t);
    if( *s != *t )
      return 0;
    t--;s--;
  }
  
  return 1;
}
