#include "display.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sense.h"


int main(void) {

	int hours = 0;
	int minutes = 0;
	int seconds = 0;
	int value = 3;


	open_display();
	while (value == 3){ //&& hours <= 23 && hours > -1 && minutes <= 59 && minutes > -1 && seconds <= 59 && seconds > -1){
		display_time(hours, minutes, seconds);
		value = scanf("%d:%d:%d", &hours, &minutes, &seconds);
	}
	close_display();
	exit(1);
	return 0;
}
