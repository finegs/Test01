#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses/ncurses.h>

int main(int argc, char* argv[]) {

	if(argc > 0) {
		fprintf(stdout, "### %s is started\n", argv[0]);
	}

	while(1) {

		initscr();
		noecho();
		curs_set(FALSE);

		usleep(1000*1000*5);
	}

	endwin();


	return 0;
}
