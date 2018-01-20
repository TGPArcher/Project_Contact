#include <allegro5/allegro.h>
#include "canvas_ui.h"
#include "list.h"
#include "c_pages.h"

extern void init_al();
extern void load_contacts(list*);
extern void print_list_to_canvas(CANVAS *canvas);
extern void draw_canvas(CANVAS*);
extern void m_events_init(CANVAS*);

extern CANVAS active_page;

list contacts = { NULL, NULL };

int main() {
	init_al();

	load_contacts(&contacts);

	set_display_page();
	print_list_to_canvas(&active_page, contacts.first);

	draw_canvas(&active_page);

	m_events_init(&active_page);

	return 0;
}