//ADD % MOD OPERATOR & SUPPORT NEGATIVE NUMBERS:
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

  printf ("atof(-2)=%g\n\n", atof("-2"));
  
  while((type=getop(s))!=EOF){
    
    switch(type){
    case NUMBER:
      printf("NUMBER:atof=%g\n",atof(s));
      push(atof(s));
      break;

    case '%':
      op2=pop();
      push((int)pop() % (int)op2);
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
      printf("unknown command: %s\n",s);
      break;
      
    }
  }
  return 0;
}

#define MAXVAL 10 //STACK DEPTH
int sp=0;
double val[MAXVAL];

void push(double f){

  printf("pushing: %g\n",f);
  if(sp<MAXVAL)
    val[sp++]=f;
  else{
    printf("ERROR: Stack full! Can't push %g\n",f);
    exit(1);
  }
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
  s[i]='\0';
  if (c !=EOF)
    ungetch(c);

  printf("String: %s\n",s);
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
