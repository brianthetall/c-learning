//Pointer version of strcat(s,t)

#include <stdio.h>
#include <stdlib.h>

char* strcat(const char*, const char*);
size_t strlen(const char*);

int main(int argc, char **argv){
  char **backup=argv;
  
  printf("Argc=%d\n",argc);
  
  for(int i=1;i<argc;i++){
    printf("%s: ",*++argv);
    printf("strlen=%d\n",strlen(*argv));
  }

  argv=backup;//restore pointer
  argv++;//skip program name

  char *temp = *argv++;
  for(int i=1 ; i<argc-1 ; i++){
    temp = strcat( temp, *argv++);
  }
  printf("Final: %s\n",temp);
  
  return 0;
}


size_t strlen(const char *s){
  size_t i=0;

  while( *s++ != '\0' )
    i++;

  return i;
}


char* strcat(const char* s,const char* t){
  char *retval=(char*)malloc(sizeof(char) * (strlen(s)+strlen(t)) );
  char *start=retval;
  
  while( *s != '\0' )
    *retval++ = *s++;

  while( *t != '\0' )
    *retval++ = *t++;

  return start;
}
