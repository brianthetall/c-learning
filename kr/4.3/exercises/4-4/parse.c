#include <stdio.h>
#include <ctype.h>
#include "main.h"

int getch(void);
void ungetch(int);

int getop(char s[]){
  int i=0,c,d;
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';

  if (!isdigit(c) && c!='.'){
    if(c=='-'){//must check if followed by number
      d=getch();
      if(!isdigit(d))
	return c;
      else
	ungetch(d);
    }
    else
      return c; //not a number nor a negative sign
  }

  if (isdigit(c) || c=='-'){
    while(isdigit( s[++i] = c = getch() ))
      ;
  }
  
  if (c=='.')//get decimal fraction part
    while(isdigit(s[++i] = c = getch() ))
      ;

  //commands: [(p)rint,(d)uplicate,(s)wap,(c)lear]
  if(c=='p' || c=='d' || c=='s' || c=='c')
    return c;

  
  s[i]='\0';
  if (c !=EOF)
    ungetch(c);

  return NUMBER;
}
///////////////////////////////////////////////
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp=0;//next free position in buffer; decrement to get last value

int getch(void){//check for re-pushed characters before running getchar()
  return (bufp>0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
  if(bufp>=BUFSIZE)
    printf("buffer overflow");
  else
    buf[bufp++]=c;
}
