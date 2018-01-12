#include "c_manipulation.h"
#include "c_init_elements.h"

CANVAS_ELEMENT* get_canvas_last_element(CANVAS *canvas, int layer) {
	CANVAS_ELEMENT *tmp = canvas->layers[layer].elements;

	while (tmp && tmp->next)
		tmp = tmp->next;

	return tmp;
}

ANCHORS recalculate_anchors(ANCHORS anchors, int count) {
	POS size = create_pos(
		anchors.lower.x - anchors.upper.x,
		anchors.lower.y - anchors.upper.y);

	return (anchors = create_anchors(
		create_pos(anchors.upper.x, anchors.upper.y + (size.y + 11) * count),
		create_pos(anchors.lower.x, anchors.lower.y + (size.y + 11) * count)));
}

POS recalculate_pos(POS anchors, int y) {
	return (anchors = create_pos(anchors.x, anchors.y + y));
}

CANVAS display_page() {
	CANVAS canvas = { .anchors = create_anchors(create_pos(0, 0), create_pos(500, 750)), .nr_of_layers = 3 };
	
	canvas.layers = (LAYER*)malloc(sizeof(LAYER) * canvas.nr_of_layers);
	for (int i = 0; i < canvas.nr_of_layers; i++)
		canvas.layers[i].elements = NULL;

	CANVAS_ELEMENT *last = NULL;

	canvas.layers[0].elements = e_init_rectangle(0, 0, 500, 100, al_map_rgb(145, 56, 60));
	last = canvas.layers[0].elements;

	last->next = e_init_rectangle(0, 705, 500, 750, al_map_rgb(145, 56, 60));
	last = last->next;

	last->next = e_init_line(20, 69, 406, 69, al_map_rgb(0, 0, 0), 2);
	last = last->next;

	last->next = e_init_image("add_button.png", 380, 630, 110, 110, 0);
	last = last->next;

	last->next = e_init_image("search_button.png", 406, 0, 100, 100, 0);
	last = last->next;

	last->next = e_init_text("javatext.ttf", 50, 30, 0, al_map_rgb(0, 0, 0), 0, "CONTACTS");

	return canvas;
}

void print_list_to_canvas(CANVAS *canvas) {
	CANVAS_ELEMENT *last = NULL;

	canvas->layers[2].elements = e_init_contact(
		create_pos(12, 110), create_pos(30, 10), create_pos(30, 50),
		al_map_rgb(174, 174, 174), al_map_rgb(120, 115, 130), al_map_rgb(48, 48, 48), al_map_rgb(88, 88, 88),
		"Petru", "068454141",
		0);

	last = get_canvas_last_element(canvas, 2);

	for (int i = 1; i < 8; i++) {
		last->next = e_init_contact(
			create_pos(12, 110), create_pos(30, 10), create_pos(30, 50),
			al_map_rgb(174, 174, 174), al_map_rgb(120, 115, 130), al_map_rgb(48, 48, 48), al_map_rgb(88, 88, 88),
			"Petru", "068454141",
			i);

		last = last->next;
	}
}
