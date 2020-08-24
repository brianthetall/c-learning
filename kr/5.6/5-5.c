//strncpy, strncat, strncmp

#include <stdio.h>
#include <stdlib.h>

char* strncpy(char*,const char*,size_t);
char* strncat(char*,const char*,size_t);
int strncmp(const char*,const char*,size_t);

size_t strlen(const char *);

int main(int argc, char** argv){

  if (argc!=3){
    printf("Feed me two strings\n");
    return -1;
  }

  char* s = *++argv;
  char* t = *++argv;

  printf("strncat=%s\n", strncat(s,t,3));
  printf("strncpy=%s\n", strncpy(s,t,1));  

  return 0;
}


size_t strlen(const char *s){
  size_t i=0;

  while( *s++ != '\0' )
    i++;

  return i;
}

char* strncpy(char* s, const char* t, size_t n){
  char *start=s;
  for(int i=0; (*s++=*t++) != '\0' && i<n;i++);
  *s='\0';
  return start;
}

//I'm of the opinion Strings should be immutable.
char* strncat(char* s,const char* t,size_t n){
  char* retval = calloc(sizeof(char), strlen(s)+n);
  char* start = retval;
  for(;*s!='\0';)
    *retval++=*s++;
  for(int i=0; i<n; i++)
    *retval++=*t++;

  s=start;
  return s;
}
