#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "wordclock.h"

#define COLUMNS     24
#define ROWS        24

struct word {
	const uint16_t position;
	const uint8_t length;
};

struct wordclock {
	const struct word it;
	const struct word is;
	const struct {
		const struct {
			const struct word tuesday;
			const struct word thursday;
			const struct word sunday;
			const struct word friday;
			const struct word saturday;
			const struct word wednesday;
			const struct word monday;
		} weekday;
		const struct word the;
		const struct {
			const struct word twenty;
			const struct word twentieth;
			const struct word thirtieth;
			const struct word thirty;
			const struct word nineteenth;
			const struct word second;
			const struct word fourth;
			const struct word eleventh;
			const struct word fifteenth;
			const struct word eighteenth;
			const struct word fourteenth;
			const struct word sixteenth;
			const struct word thirteenth;
			const struct word sixth;
			const struct word first;
			const struct word third;
			const struct word seventeenth;
			const struct word tenth;
			const struct word fifth;
			const struct word twelfth;
			const struct word seventh;
			const struct word eighth;
			const struct word ninth;
		} day;
		const struct word of;
		const struct {
			const struct word november;
			const struct word january;
			const struct word may;
			const struct word february;
			const struct word april;
			const struct word august;
			const struct word october;
			const struct word september;
			const struct word december;
			const struct word july;
			const struct word march;
			const struct word june;
		} month;
	} date;
	const struct {
		const struct word the;
		const struct word time;
		const struct word is;
		const struct word quarter;
		const struct word half;
		const struct {
			const struct word twenty;
			const struct word ten;
			const struct word six;
			const struct word sixteen;
			const struct word two;
			const struct word one;
			const struct word seven;
			const struct word seventeen;
			const struct word five;
			const struct word nine;
			const struct word nineteen;
			const struct word twelve;
			const struct word four;
			const struct word fourteen;
			const struct word eight;
			const struct word eighteen;
			const struct word eleven;
			const struct word thirteen;
			const struct word three;
		} minute;
		const struct word past;
		const struct word to;
		const struct {
			const struct word three;
			const struct word seven;
			const struct word two;
			const struct word eleven;
			const struct word four;
			const struct word one;
			const struct word nine;
			const struct word six;
			const struct word ten;
			const struct word five;
			const struct word twelve;
			const struct word eight;
		} hour;
		const struct word oclock;
	} time;
	const struct {
		const struct word at;
		const struct word night;
		const struct word in;
		const struct word the;
		const struct word morning;
		const struct word evening;
		const struct word afternoon;
	} period;
	const struct word debug;
};

const struct wordclock wordclock = {
	.it = {0, 2},
	.is = {3, 2},
	.date = {
		.weekday = {
			.tuesday = {7, 7},
			.thursday = {15, 8},
			.sunday = {24, 6},
			.friday = {32, 6},
			.saturday = {39, 8},
			.wednesday = {50, 9},
			.monday = {61, 6}
		},
		.the = {69, 3},
		.day = {
			.twenty = {72, 6},
			.twentieth = {78, 9},
			.thirtieth = {87, 9},
			.thirty = {96, 6},
			.nineteenth = {103, 10},
			.second = {113, 6},
			.fourth = {120, 6},
			.eleventh = {127, 8},
			.fifteenth = {135, 9},
			.eighteenth = {146, 10},
			.fourteenth = {157, 10},
			.sixteenth = {168, 9},
			.thirteenth = {177, 10},
			.sixth = {187, 5},
			.first = {192, 5},
			.third = {198, 5},
			.seventeenth = {204, 11},
			.tenth = {216, 5},
			.fifth = {221, 5},
			.twelfth = {226, 7},
			.seventh = {233, 7},
			.eighth = {241, 6},
			.ninth = {247, 5}
		},
		.of = {253, 2},
		.month = {
			.november = {256, 8},
			.january = {264, 7},
			.may = {271, 3},
			.february = {275, 8},
			.april = {283, 5},
			.august = {288, 6},
			.october = {295, 7},
			.september = {303, 9},
			.december = {314, 8},
			.july = {322, 4},
			.march = {327, 5},
			.june = {332, 4}
		},
	},
	.time = {
		.the = {336, 3},
		.time = {340, 4},
		.is = {345, 2},
		.quarter = {349, 7},
		.half = {356, 4},
		.minute = {
			.twenty = {362, 6},
			.ten = {369, 3},
			.six = {372, 3},
			.sixteen = {372, 7},
			.two = {379, 3},
			.one = {381, 3},
			.seven = {384, 5},
			.seventeen = {384, 9},
			.five = {394, 4},
			.nine = {398, 4},
			.nineteen = {398, 8},
			.twelve = {408, 6},
			.four = {415, 4},
			.fourteen = {415, 8},
			.eight = {424, 5},
			.eighteen = {424, 8},
			.eleven = {432, 6},
			.thirteen = {438, 8},
			.three = {446, 5}
		},
		.past = {452, 4},
		.to = {456, 2},
		.hour = {
			.three = {459, 5},
			.seven = {465, 5},
			.two = {470, 3},
			.eleven = {474, 6},
			.four = {480, 4},
			.one = {485, 3},
			.nine = {488, 4},
			.six = {492, 3},
			.ten = {495, 3},
			.five = {499, 4},
			.twelve = {506, 6},
			.eight = {514, 5}
		},
		.oclock = {521, 7}
	},
	.period = {
		.at = {528, 2},
		.night = {531, 5},
		.in = {537, 2},
		.the = {540, 3},
		.morning = {544, 7},
		.evening = {553, 7},
		.afternoon = {561, 9}
	},
	.debug = {571, 5}
};

static const char *const characters = "ITAISBCTUESDAYDTHURSDAYESUNDAYFGFRIDAYHSATURDAYIJKWEDNESDAYLMMONDAYNOTHETWENTYTWENTIETHTHIRTIETHTHIRTYPNINETEENTHSECONDQFOURTHRELEVENTHFIFTEENTHSTEIGHTEENTHUFOURTEENTHVSIXTEENTHTHIRTEENTHSIXTHFIRSTWTHIRDXSEVENTEENTHYTENTHFIFTHTWELFTHSEVENTHZEIGHTHNINTHAOFBNOVEMBERJANUARYMAYCFEBRUARYAPRILAUGUSTDOCTOBERESEPTEMBERFGDECEMBERJULYHMARCHJUNETHEITIMEJISKLQUARTERHALFMNTWENTYOTENSIXTEENTWONESEVENTEENPFIVENINETEENQRTWELVESFOURTEENTEIGHTEENELEVENTHIRTEENTHREEUPASTTOVTHREEWSEVENTWOXELEVENFOURYONENINESIXTENZFIVEABCTWELVEDEEIGHTFGO'CLOCKATHNIGHTIINJTHEKMORNINGLMEVENINGNAFTERNOONODEBUG";
static bool wordclock_face[COLUMNS * ROWS];

static const struct word *const weekdays[] = {
	&wordclock.date.weekday.monday,
	&wordclock.date.weekday.tuesday,
	&wordclock.date.weekday.wednesday,
	&wordclock.date.weekday.thursday,
	&wordclock.date.weekday.friday,
	&wordclock.date.weekday.saturday,
	&wordclock.date.weekday.sunday
};

static const struct word *const months[] = {
	&wordclock.date.month.january,
	&wordclock.date.month.february,
	&wordclock.date.month.march,
	&wordclock.date.month.april,
	&wordclock.date.month.may,
	&wordclock.date.month.june,
	&wordclock.date.month.july,
	&wordclock.date.month.august,
	&wordclock.date.month.september,
	&wordclock.date.month.october,
	&wordclock.date.month.november,
	&wordclock.date.month.december
};

static void set_word(const struct word *const word) {
	for (int i = word->position; i < word->position + word->length; i++) {
		wordclock_face[i] = true;
	}
}

static void set_word_day(const struct tm *const tm) {
	switch (tm->tm_mday) {
		case 1:
			set_word(&wordclock.date.day.first);
			break;
		case 2:
			set_word(&wordclock.date.day.second);
			break;
		case 3:
			set_word(&wordclock.date.day.third);
			break;
		case 4:
			set_word(&wordclock.date.day.fourth);
			break;
		case 5:
			set_word(&wordclock.date.day.fifth);
			break;
		case 6:
			set_word(&wordclock.date.day.sixth);
			break;
		case 7:
			set_word(&wordclock.date.day.seventh);
			break;
		case 8:
			set_word(&wordclock.date.day.eighth);
			break;
		case 9:
			set_word(&wordclock.date.day.ninth);
			break;
		case 10:
			set_word(&wordclock.date.day.tenth);
			break;
		case 11:
			set_word(&wordclock.date.day.eleventh);
			break;
		case 12:
			set_word(&wordclock.date.day.twelfth);
			break;
		case 13:
			set_word(&wordclock.date.day.thirteenth);
			break;
		case 14:
			set_word(&wordclock.date.day.fourteenth);
			break;
		case 15:
			set_word(&wordclock.date.day.fifteenth);
			break;
		case 16:
			set_word(&wordclock.date.day.sixteenth);
			break;
		case 17:
			set_word(&wordclock.date.day.seventeenth);
			break;
		case 18:
			set_word(&wordclock.date.day.eighteenth);
			break;
		case 19:
			set_word(&wordclock.date.day.nineteenth);
			break;
		case 20:
			set_word(&wordclock.date.day.twentieth);
			break;
		case 21:
			set_word(&wordclock.date.day.twenty);
			set_word(&wordclock.date.day.first);
			break;
		case 22:
			set_word(&wordclock.date.day.twenty);
			set_word(&wordclock.date.day.second);
			break;
		case 23:
			set_word(&wordclock.date.day.twenty);
			set_word(&wordclock.date.day.third);
			break;
		case 24:
			set_word(&wordclock.date.day.twenty);
			set_word(&wordclock.date.day.fourth);
			break;
		case 25:
			set_word(&wordclock.date.day.twenty);
			set_word(&wordclock.date.day.fifth);
			break;
		case 26:
			set_word(&wordclock.date.day.twenty);
			set_word(&wordclock.date.day.sixth);
			break;
		case 27:
			set_word(&wordclock.date.day.twenty);
			set_word(&wordclock.date.day.seventh);
			break;
		case 28:
			set_word(&wordclock.date.day.twenty);
			set_word(&wordclock.date.day.eighth);
			break;
		case 29:
			set_word(&wordclock.date.day.twenty);
			set_word(&wordclock.date.day.ninth);
			break;
		case 30:
			set_word(&wordclock.date.day.thirtieth);
			break;
		case 31:
			set_word(&wordclock.date.day.thirty);
			set_word(&wordclock.date.day.first);
			break;
	}
}

static void set_word_minute(const struct tm *const tm) {
	switch (tm->tm_min) {
		case 15:
		case 45:
			set_word(&wordclock.time.quarter);
			break;
		case 30:
			set_word(&wordclock.time.half);
			break;
		case 1:
		case 59:
			set_word(&wordclock.time.minute.one);
			break;
		case 2:
		case 58:
			set_word(&wordclock.time.minute.two);
			break;
		case 3:
		case 57:
			set_word(&wordclock.time.minute.three);
			break;
		case 4:
		case 56:
			set_word(&wordclock.time.minute.four);
			break;
		case 5:
		case 55:
			set_word(&wordclock.time.minute.five);
			break;
		case 6:
		case 54:
			set_word(&wordclock.time.minute.six);
			break;
		case 7:
		case 53:
			set_word(&wordclock.time.minute.seven);
			break;
		case 8:
		case 52:
			set_word(&wordclock.time.minute.eight);
			break;
		case 9:
		case 51:
			set_word(&wordclock.time.minute.nine);
			break;
		case 10:
		case 50:
			set_word(&wordclock.time.minute.ten);
			break;
		case 11:
		case 49:
			set_word(&wordclock.time.minute.eleven);
			break;
		case 12:
		case 48:
			set_word(&wordclock.time.minute.twelve);
			break;
		case 13:
		case 47:
			set_word(&wordclock.time.minute.thirteen);
			break;
		case 14:
		case 46:
			set_word(&wordclock.time.minute.fourteen);
			break;
		case 16:
		case 44:
			set_word(&wordclock.time.minute.sixteen);
			break;
		case 17:
		case 43:
			set_word(&wordclock.time.minute.seventeen);
			break;
		case 18:
		case 42:
			set_word(&wordclock.time.minute.eighteen);
			break;
		case 19:
		case 41:
			set_word(&wordclock.time.minute.nineteen);
			break;
		case 20:
		case 40:
			set_word(&wordclock.time.minute.twenty);
			break;
		case 21:
		case 39:
			set_word(&wordclock.time.minute.twenty);
			set_word(&wordclock.time.minute.one);
			break;
		case 22:
		case 38:
			set_word(&wordclock.time.minute.twenty);
			set_word(&wordclock.time.minute.two);
			break;
		case 23:
		case 37:
			set_word(&wordclock.time.minute.twenty);
			set_word(&wordclock.time.minute.three);
			break;
		case 24:
		case 36:
			set_word(&wordclock.time.minute.twenty);
			set_word(&wordclock.time.minute.four);
			break;
		case 25:
		case 35:
			set_word(&wordclock.time.minute.twenty);
			set_word(&wordclock.time.minute.five);
			break;
		case 26:
		case 34:
			set_word(&wordclock.time.minute.twenty);
			set_word(&wordclock.time.minute.six);
			break;
		case 27:
		case 33:
			set_word(&wordclock.time.minute.twenty);
			set_word(&wordclock.time.minute.seven);
			break;
		case 28:
		case 32:
			set_word(&wordclock.time.minute.twenty);
			set_word(&wordclock.time.minute.eight);
			break;
		case 29:
		case 31:
			set_word(&wordclock.time.minute.twenty);
			set_word(&wordclock.time.minute.nine);
			break;
	}
}

static void set_word_hour(const struct tm *const tm) {
	const uint8_t minute = tm->tm_min;

	if (minute == 0) {
		set_word(&wordclock.time.oclock);
	} else if (minute <= 30) {
		set_word(&wordclock.time.past);
	} else {
		set_word(&wordclock.time.to);
	}

	uint8_t hour = tm->tm_hour;

	if (minute > 30) {
		hour++;
	}

	if (hour >= 12) {
		hour -= 12;
	}

	if (hour == 12) {
		hour = 0;
	}

	switch (hour) {
		case 0:
			set_word(&wordclock.time.hour.twelve);
			break;
		case 1:
			set_word(&wordclock.time.hour.one);
			break;
		case 2:
			set_word(&wordclock.time.hour.two);
			break;
		case 3:
			set_word(&wordclock.time.hour.three);
			break;
		case 4:
			set_word(&wordclock.time.hour.four);
			break;
		case 5:
			set_word(&wordclock.time.hour.five);
			break;
		case 6:
			set_word(&wordclock.time.hour.six);
			break;
		case 7:
			set_word(&wordclock.time.hour.seven);
			break;
		case 8:
			set_word(&wordclock.time.hour.eight);
			break;
		case 9:
			set_word(&wordclock.time.hour.nine);
			break;
		case 10:
			set_word(&wordclock.time.hour.ten);
			break;
		case 11:
			set_word(&wordclock.time.hour.eleven);
			break;
	}
}

static void set_word_period(const struct tm *const tm) {
	const uint8_t hour = tm->tm_hour;

	if (hour < 22) {
		set_word(&wordclock.period.in);
		set_word(&wordclock.period.the);
	} else {
		set_word(&wordclock.period.at);
	}

	if (hour >= 0 && hour < 12) {
		set_word(&wordclock.period.morning);
	} else if (hour >= 12 && hour < 18) {
		set_word(&wordclock.period.afternoon);
	} else if (hour >= 18 && hour < 22) {
		set_word(&wordclock.period.evening);
	} else {
		set_word(&wordclock.period.night);
	}
}

void wordclock_display(const struct tm *const tm, const enum wordclock_color color) {
	memset(wordclock_face, 0, sizeof wordclock_face);

	set_word(&wordclock.it);
	set_word(&wordclock.is);
	set_word(weekdays[tm->tm_wday - 1]);
	set_word(&wordclock.date.the);
	set_word_day(tm);
	set_word(&wordclock.date.of);
	set_word(months[tm->tm_mday - 1]);
	set_word(&wordclock.time.the);
	set_word(&wordclock.time.time);
	set_word(&wordclock.time.is);
	set_word_minute(tm);
	set_word_hour(tm);
	set_word_period(tm);

	const char *color_code;

	switch (color) {
		case WORDCLOCK_COLOR_RED:
			color_code = "\033[0;31m";
			break;
		case WORDCLOCK_COLOR_GREEN:
			color_code = "\033[0;32m";
			break;
		case WORDCLOCK_COLOR_YELLOW:
			color_code = "\033[0;33m";
			break;
		case WORDCLOCK_COLOR_BLUE:
			color_code = "\033[0;34m";
			break;
		case WORDCLOCK_COLOR_MAGENTA:
			color_code = "\033[0;35m";
			break;
		case WORDCLOCK_COLOR_CYAN:
			color_code = "\033[0;36m";
			break;
		default:
			color_code = "";
	}

	for (int i = 0; i < COLUMNS * ROWS; i++) {
		if (i != 0 && i % COLUMNS == 0) {
			printf("\n");
		}

		if (wordclock_face[i]) {
			printf("%s", color_code);
		}

		printf("%c \033[0m", characters[i]);
	}

	printf("\n");
}
