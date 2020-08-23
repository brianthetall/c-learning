#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

int main(){

  int type;
  double op2;
  char s[MAXOP];

  while((type=getop(s))!=EOF){
    
    switch(type){
    case NUMBER:
      push(atof(s));
      break;
      
    case '+':
      push(pop()+pop());
      break;

    case '-':
      op2=pop();
      push(pop()-op2);
      break;

    case '*':
      push(pop()*pop());
      break;

    case '/':
      op2=pop();
      if (op2==0.0){
	printf("ERROR divide by zero");
	break;
      }
      push(pop()/op2);
      break;

    case '\n':
      printf("\t%.8g\n",pop());
      break;

    default:
      printf("unknown command: %s",s);
      break;
      
    }
  }
  return 0;
}

#define MAXVAL 100 //STACK DEPTH
int sp=0;
double val[MAXVAL];

void push(double f){
  if(sp<MAXVAL)
    val[sp++]=f;
  else
    printf("ERROR: Stack full! Can't push %g\n",f);
}

double pop(void){
  if(sp>0)
    return val[--sp];
  else{
    printf("Empty stack\n");
    return 0.0;
  }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[]){
  int i,c;
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';

  if (!isdigit(c) && c!='.')
    return c; //not a number
  i=0;
  if (isdigit(c))
    while(isdigit( s[++i] = c = getch() ))
      ;
  if (c=='.')//get decimal fraction part
    while(isdigit(s[++i] = c = getch() ))
      ;
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
