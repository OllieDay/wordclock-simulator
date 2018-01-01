#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "wordclock.h"

static void screen_clear(void) {
	printf("\033[H\033[J");
}

int main(void) {
	while (true) {
		time_t t = time(NULL);
		struct tm *tm = localtime(&t);

		screen_clear();
		wordclock_display(tm, WORDCLOCK_COLOR_RED);

		sleep(60 - tm->tm_sec);
	}
}
