#include <allegro5/allegro.h>
#include "canvas_ui.h"

extern void init_al();
extern CANVAS display_page();
extern void print_list_to_canvas(CANVAS *canvas);
extern void draw_canvas(CANVAS*);

int main() {
	init_al();

	CANVAS main_screen = display_page();
	print_list_to_canvas(&main_screen);
	draw_canvas(&main_screen);

	return 0;
}