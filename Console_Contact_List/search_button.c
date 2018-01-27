#include <allegro5/allegro.h>
#include "canvas_ui.h"

extern CANVAS active_page;
extern void on_click(ALLEGRO_EVENT, CANVAS*);

void activate_search_bar() {
	ALLEGRO_EVENT ev = { .mouse = {.x = 150,.y = 65} };
	on_click(ev, &active_page);
}