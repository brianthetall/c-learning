#include <ncurses.h>

/* board size */
#define BDEPTH	8
#define BWIDTH	8

/* where to start the instructions */
#define INSTRY	2
#define INSTRX	35
/* notification line */
#define NOTIFYY	21

/* corner of board */
#define BOARDY	2
#define BOARDX	0

#define CX(x)		(2 + 4 * (x))
#define CY(y)		(1 + 2 * (y))
#define cellmove(y, x)	wmove(boardwin, CY(y), CX(x))
#define CXINV(x)	(((x) - 1) / 4)
#define CYINV(y)	(((y) - 2) / 2)

typedef struct {
    short x, y;
} cell;

static WINDOW *boardwin;	/* the board window */
static WINDOW *msgwin;

static void init_program(void)
{

    initscr();
    cbreak();                   /* immediate char return */
    noecho();                   /* no immediate echo */
    boardwin = newwin(BDEPTH * 2 + 1, BWIDTH * 4 + 1, BOARDY, BOARDX);
    msgwin = newwin(1, INSTRX - 1, NOTIFYY, 0);
    scrollok(msgwin, TRUE);
    keypad(boardwin, TRUE);

    if (has_colors()) {
        int bg = COLOR_BLACK;

        start_color();
    }
    
}

static void dosquares(void)
{
    int i, j;

    mvaddstr(0, 20, "Wagner Chess");

    move(BOARDY, BOARDX);
    waddch(boardwin, ACS_ULCORNER);
    for (j = 0; j < 7; j++) {
	waddch(boardwin, ACS_HLINE);
	waddch(boardwin, ACS_HLINE);
	waddch(boardwin, ACS_HLINE);
	waddch(boardwin, ACS_TTEE);
    }
    waddch(boardwin, ACS_HLINE);
    waddch(boardwin, ACS_HLINE);
    waddch(boardwin, ACS_HLINE);
    waddch(boardwin, ACS_URCORNER);

    for (i = 1; i < BDEPTH; i++) {
	move(BOARDY + i * 2 - 1, BOARDX);
	waddch(boardwin, ACS_VLINE);
	for (j = 0; j < BWIDTH; j++) {
	    waddch(boardwin, ' ');
	    waddch(boardwin, ' ');
	    waddch(boardwin, ' ');
	    waddch(boardwin, ACS_VLINE);
	}
	move(BOARDY + i * 2, BOARDX);
	waddch(boardwin, ACS_LTEE);
	for (j = 0; j < BWIDTH - 1; j++) {
	    waddch(boardwin, ACS_HLINE);
	    waddch(boardwin, ACS_HLINE);
	    waddch(boardwin, ACS_HLINE);
	    waddch(boardwin, ACS_PLUS);
	}
	waddch(boardwin, ACS_HLINE);
	waddch(boardwin, ACS_HLINE);
	waddch(boardwin, ACS_HLINE);
	waddch(boardwin, ACS_RTEE);
    }

    move(BOARDY + i * 2 - 1, BOARDX);
    waddch(boardwin, ACS_VLINE);
    for (j = 0; j < BWIDTH; j++) {
	waddch(boardwin, ' ');
	waddch(boardwin, ' ');
	waddch(boardwin, ' ');
	waddch(boardwin, ACS_VLINE);
    }

    move(BOARDY + i * 2, BOARDX);
    waddch(boardwin, ACS_LLCORNER);
    for (j = 0; j < BWIDTH - 1; j++) {
	waddch(boardwin, ACS_HLINE);
	waddch(boardwin, ACS_HLINE);
	waddch(boardwin, ACS_HLINE);
	waddch(boardwin, ACS_BTEE);
    }
    waddch(boardwin, ACS_HLINE);
    waddch(boardwin, ACS_HLINE);
    waddch(boardwin, ACS_HLINE);
    waddch(boardwin, ACS_LRCORNER);
}

void play(){
  dosquares();
    cellmove(6,6);
    waddch(boardwin,'\b');
    waddch(boardwin,'K');
    wrefresh(boardwin);
    refresh();

  while(1){
      
    
  }
}

int main(){

  init_program();
  //  play();
  dosquares();
  refresh();
  wrefresh(boardwin);
  while(1){}

}
