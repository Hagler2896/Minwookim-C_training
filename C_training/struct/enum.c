#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#pragma warning(disable: 4996)

int main()
{
	enum spectrum {red, orange, yellow, green, blue, violet};
	
	enum spectrum color;
	color = blue;

	if (color == yellow)
		printf("Yellow");

	for (color = red; color <= violet; color++)
		printf("%d\n", color);

	printf("red = %d, orange = %d\n", red, orange);

	enum kids { jackjack, dash, snoopy, nano, pitz};

	enum kids my_kid = nano;
	printf("nano %d %d\n", my_kid, nano);

	enum levels {low = 100, medium = 500, high = 2000};

	int score = 800;
	if (score > high)
		printf("High score!\n");
	else if (score > medium)
		printf("Good job\n");		
	else if (score > low)
		printf("Not bad\n");
	else
		printf("Do your best\n");

	enum pet {cat, dog = 10, lion, tiger};

	printf("cat %d\n", cat);
	printf("lion %d\n", lion);

	return 0;
}

