#include <time.h>
#include <naiveConsole.h>

static unsigned long ticks = 0;
int ticks_elapsed();
int seconds_elapsed();

void timer_handler() {
	
	ticks++;
	if(seconds_elapsed() >= 5) {
		// ya pasaron 5 segundos. es hora de imprimir el mensaje
		ncPrint("Ya pasaron 5 segundos");
		ticks = 0;
	}
}

int ticks_elapsed() {
	return ticks;
}

int seconds_elapsed() {
	return ticks / 18;
}
