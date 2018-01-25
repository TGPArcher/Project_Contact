#include "c_pages.h"

CANVAS active_page;
list contacts = { NULL, NULL };

void canvas_data_init() {
	load_contacts(&contacts);

	set_display_page();
	draw_active_page();
}

void draw_active_page() {
	draw_canvas(&active_page);
}

void set_add_page() {
	active_page = add_page();
}

void set_display_page() {
	active_page = display_page();
	print_list_to_canvas(&active_page, contacts.first);
}