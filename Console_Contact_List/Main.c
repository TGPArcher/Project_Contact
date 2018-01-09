#include <allegro5/allegro.h>
#include "canvas_ui.h"

extern void a_main();
extern CANVAS display_page();

int main() {
	a_main();

	display_page();

	return 0;
}