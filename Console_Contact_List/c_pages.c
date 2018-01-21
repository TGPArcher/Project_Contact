#include "c_pages.h"

CANVAS active_page;
extern list contacts;

void draw_active_canvas() {
	draw_canvas(&active_page);
}

void set_add_page() {
	active_page = add_page();
}

void set_display_page() {
	active_page = display_page();
	print_list_to_canvas(&active_page, contacts.first);
}

void add_new_contact() {
	CANVAS_ELEMENT *tmp1 = active_page.layers[0].elements;
	CANVAS_ELEMENT *tmp2 = tmp1->next;

	struct Node *new_node = new_node_d(tmp1->data.input_field.text.text, tmp2->data.input_field.text.text);

	contacts.last = add_node_to_end(&contacts, new_node);

	set_display_page();
	draw_active_canvas();
}

CANVAS add_page() {
	CANVAS canvas = {
		.anchors = create_anchors(create_pos(0, 0), create_pos(500, 750)),
		.nr_of_layers = 1,
		.background = al_map_rgb(207, 207, 207) };

	canvas.layers = (LAYER*)malloc(sizeof(LAYER) * canvas.nr_of_layers);
	for (int i = 0; i < canvas.nr_of_layers; i++)
		canvas.layers[i].elements = NULL;

	CANVAS_ELEMENT *last = NULL;

	canvas.layers[0].elements = e_init_ifield("Name", "javatext.ttf", 25, al_map_rgb(0, 0, 0),
		create_anchors(create_pos(100, 200), create_pos(400, 200)),
		al_map_rgb(50, 50, 50), 1);
	last = canvas.layers[0].elements;

	last->next = e_init_ifield("Number", "javatext.ttf", 25, al_map_rgb(0, 0, 0),
		create_anchors(create_pos(100, 300), create_pos(400, 300)),
		al_map_rgb(50, 50, 50), 1);
	last = last->next;

	last->next = e_init_rectangle(0, 0, 500, 100, al_map_rgb(145, 56, 60),
		create_interactable(0, 0), NULL);
	last = last->next;

	last->next = e_init_rectangle(0, 705, 500, 750, al_map_rgb(145, 56, 60),
		create_interactable(0, 0), NULL);
	last = last->next;

	last->next = e_init_line(20, 69, 406, 69, al_map_rgb(0, 0, 0), 2,
		create_interactable(0, 0), NULL);
	last = last->next;

	last->next = e_init_text("javatext.ttf", 50, 30, 0, al_map_rgb(0, 0, 0), 0, "New Contact",
		create_interactable(0, 0), NULL);
	last = last->next;

	last->next = e_init_tbutton("javatext.ttf", 25, "Cancel", al_map_rgb(25, 25, 25),
		5, al_map_rgb(150, 150, 150),
		create_anchors(create_pos(100, 400), create_pos(240, 500)), al_map_rgb(200, 200, 200),
		create_interactable(1, 1), &set_display_page, NULL);
	last = last->next;

	last->next = e_init_tbutton("javatext.ttf", 25, "Apply", al_map_rgb(25, 25, 25),
		5, al_map_rgb(150, 150, 150),
		create_anchors(create_pos(260, 400), create_pos(400, 500)), al_map_rgb(200, 200, 200),
		create_interactable(1, 1), &add_new_contact, NULL);

	return canvas;
}

CANVAS display_page() {
	CANVAS canvas = {
		.anchors = create_anchors(create_pos(0, 0), create_pos(500, 750)),
		.nr_of_layers = 3,
		.background = al_map_rgb(207, 207, 207) };

	canvas.layers = (LAYER*)malloc(sizeof(LAYER) * canvas.nr_of_layers);
	for (int i = 0; i < canvas.nr_of_layers; i++)
		canvas.layers[i].elements = NULL;

	CANVAS_ELEMENT *last = NULL;

	canvas.layers[0].elements = e_init_rectangle(0, 0, 500, 100, al_map_rgb(145, 56, 60),
		create_interactable(0, 0), NULL);
	last = canvas.layers[0].elements;

	last->next = e_init_rectangle(0, 705, 500, 750, al_map_rgb(145, 56, 60),
		create_interactable(0, 0), NULL);
	last = last->next;

	last->next = e_init_line(20, 69, 406, 69, al_map_rgb(0, 0, 0), 2,
		create_interactable(0, 0), NULL);
	last = last->next;

	last->next = e_init_ibutton(
		"add_button_0.png", "add_button_1.png", "add_button_2.png",
		create_anchors(create_pos(380, 630), create_pos(110, 110)),
		0,
		create_interactable(1, 1),
		create_anchors(create_pos(380, 630), create_pos(490, 740)),
		&set_add_page,
		NULL);
	last = last->next;

	last->next = e_init_image("search_button.png", 406, 0, 100, 100, 0,
		create_interactable(0, 0), NULL);
	last = last->next;

	last->next = e_init_text("javatext.ttf", 50, 30, 0, al_map_rgb(0, 0, 0), 0, "CONTACTS",
		create_interactable(0, 0), NULL);

	return canvas;
}