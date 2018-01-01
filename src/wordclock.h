#ifndef WORDCLOCK_H
#define WORDCLOCK_H

#include <time.h>

enum wordclock_color {
	WORDCLOCK_COLOR_RED,
	WORDCLOCK_COLOR_GREEN,
	WORDCLOCK_COLOR_YELLOW,
	WORDCLOCK_COLOR_BLUE,
	WORDCLOCK_COLOR_MAGENTA,
	WORDCLOCK_COLOR_CYAN
};

void wordclock_display(const struct tm *tm, enum wordclock_color color);

#endif
