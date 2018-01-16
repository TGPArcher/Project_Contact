#include <allegro5/allegro.h>
#include "canvas_ui.h"
#include "list.h"

extern void init_al();
extern void load_contacts(list*);
extern CANVAS display_page();
extern void print_list_to_canvas(CANVAS *canvas);
extern void draw_canvas(CANVAS*);
extern void m_events_init(CANVAS*);
extern CANVAS add_page();

CANVAS main_screen;

int main() {
	init_al();

	list contacts = { NULL, NULL };
	load_contacts(&contacts);

	main_screen = display_page();
	print_list_to_canvas(&main_screen, contacts.first);

	draw_canvas(&main_screen);

	m_events_init(&main_screen);

	return 0;
}

void modify() {
	main_screen = add_page();
}