#include "add_pages.h"
#include "Colors.h"

CANVAS add_page() {
	CANVAS canvas = {
		.anchors = create_anchors(create_pos(0, 0), create_pos(500, 750)),
		.nr_of_layers = 1,
		.background = al_color_html(BACKGROUND_COLOR) };

	canvas.layers = (LAYER*)malloc(sizeof(LAYER) * canvas.nr_of_layers);
	for (int i = 0; i < canvas.nr_of_layers; i++)
		canvas.layers[i].elements = NULL;

	CANVAS_ELEMENT *last = NULL;

	canvas.layers[0].elements = e_init_ifield("Name", "Roboto.ttf", 25, al_color_html("#000000"),
		create_anchors(create_pos(100, 250), create_pos(400, 250)),
		al_color_html("#000000"), 1,
		NULL, NULL);
	last = canvas.layers[0].elements;

	last->next = e_init_ifield("Number", "Roboto.ttf", 25, al_color_html("#000000"),
		create_anchors(create_pos(100, 350), create_pos(400, 350)),
		al_color_html("#000000"), 1,
		NULL, NULL);
	last = last->next;

	last->next = e_init_rectangle(0, 0, 500, 100, al_color_html(MAIN_COLOR),
		create_interactable(0, 0), NULL);
	last = last->next;

	last->next = e_init_rectangle(0, 705, 500, 750, al_color_html(MAIN_COLOR),
		create_interactable(0, 0), NULL);
	last = last->next;

	last->next = e_init_line(20, 80, 406, 80, al_color_html(MAIN_TEXT_COLOR), 2,
		create_interactable(0, 0), NULL);
	last = last->next;

	last->next = e_init_text("Roboto.ttf", 50, 15, 20, al_color_html(MAIN_TEXT_COLOR), 0, "NEW CONTACT",
		create_interactable(0, 0), NULL);
	last = last->next;

	last->next = e_init_tbutton("Roboto.ttf", 25, "Cancel", al_map_rgb(25, 25, 25),
		5, al_map_rgb(150, 150, 150),
		create_anchors(create_pos(100, 400), create_pos(240, 500)), al_map_rgb(200, 200, 200),
		create_interactable(1, 1), &set_display_page, NULL);
	last = last->next;

	last->next = e_init_tbutton("Roboto.ttf", 25, "Apply", al_map_rgb(25, 25, 25),
		5, al_map_rgb(150, 150, 150),
		create_anchors(create_pos(260, 400), create_pos(400, 500)), al_map_rgb(200, 200, 200),
		create_interactable(1, 1), &add_new_contact, NULL);

	return canvas;
}