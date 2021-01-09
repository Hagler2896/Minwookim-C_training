#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable: 4996)

#define LEN 20

struct names {
	char given[LEN];
	char family[LEN];
};

struct reservation{
	struct names guest;
	struct names host;
	char food[LEN];
	char place[LEN];

	int year;
	int month;
	int day;
	int hours;
	int minutes;
};

int main()
{
	struct reservation res = {
		.guest = {"Nick", "Carraway"},
		.host = {"Jay", "Gatsby"},
		.place = {"the Gatsby mansion"},
		.food = {"Escargot"},
		.year = 1925,
		.month = 4,
		.day = 10,
		.hours = 18,
		.minutes = 30
	};

	printf("Dear %s %s,\n", res.guest.given, res.guest.family);
	printf("I would like to serve you %s.\n", res.food);
	printf("Please visit the %s on %d/%d/%d at %d:%d.\n", res.place, res.day, res.month, res.year, res.hours, res.minutes);
	printf("Sincerely,\n%s %s", res.host.given, res.host.family);

}