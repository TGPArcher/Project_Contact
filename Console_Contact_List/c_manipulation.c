#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "canvas_ui.h"

extern void draw_canvas(CANVAS*);

POS create_pos(int x, int y) {
	return (POS) { .x = x, .y = y };
}

ANCHORS create_anchors(POS up, POS low) {
	return (ANCHORS) { .upper = up, .lower = low };
}

RECTANGLE create_rectangle(ANCHORS anchors, ALLEGRO_COLOR color) {
	return (RECTANGLE) { .anchors = anchors, .color = color };
}

LINE create_line(ANCHORS anchors, ALLEGRO_COLOR color, int size) {
	return (LINE) { .anchors = anchors, .color = color, .size = size };
}

TEXT create_text(ALLEGRO_FONT *font, POS anchor, ALLEGRO_COLOR color, int flags, char *text) {
	return (TEXT) { .font = font, .anchor = anchor, .color = color, .flags = flags, .text = text };
}

IMAGE create_image(ALLEGRO_BITMAP *image, ANCHORS anchors, int flags) {
	return (IMAGE) { .image = image, .anchors = anchors, .flags = flags };
}

CONTACT create_contact(ANCHORS anchors, RECTANGLE main_body, RECTANGLE color_body, TEXT name_text, TEXT number_text, int count) {
	return (CONTACT) { .anchors = anchors, .main_body = main_body, .min_body = color_body, .name_text = name_text, .number_text = number_text, .count = count };
}

DATA create_r_data(RECTANGLE rectangle) {
	return (DATA) { .rectangle = rectangle };
}

DATA create_l_data(LINE line) {
	return (DATA) { .line = line };
}

DATA create_t_data(TEXT text) {
	return (DATA) { .text = text };
}

DATA create_i_data(IMAGE image) {
	return (DATA) { .image = image };
}

DATA create_c_data(CONTACT contact) {
	return(DATA) { .contact = contact };
}

CANVAS_ELEMENT* create_canvas_element(DATA data, int type) {
	CANVAS_ELEMENT *new_element = (CANVAS_ELEMENT*)malloc(sizeof(CANVAS_ELEMENT));

	new_element->type = type;
	new_element->data = data;
	new_element->next = NULL;

	return new_element;
}

CANVAS display_page() {
	CANVAS canvas = { .anchors = create_anchors(create_pos(0, 0), create_pos(500, 750)) };
	CANVAS_ELEMENT *last = NULL;

	canvas.elements = create_canvas_element(
		create_r_data(
			create_rectangle(
				create_anchors(create_pos(0, 0), create_pos(500, 100)),
				al_map_rgb(145, 56, 60))),
		0);
	last = canvas.elements;

	last->next = create_canvas_element(
		create_r_data(
			create_rectangle(
				create_anchors(create_pos(0, 705), create_pos(500, 750)),
				al_map_rgb(145, 56, 60))),
		0);
	last = last->next;

	last->next = create_canvas_element(
		create_l_data(
			create_line(
				create_anchors(create_pos(20, 69), create_pos(406, 69)),
				al_map_rgb(0, 0, 0),
				2)),
		1);
	last = last->next;

	last->next = create_canvas_element(
		create_i_data(
			create_image(
				al_load_bitmap("add_button.png"),
				create_anchors(create_pos(380, 630), create_pos(110, 110)),
				NULL)),
		3);
	last = last->next;

	last->next = create_canvas_element(
		create_i_data(
			create_image(
				al_load_bitmap("search_button.png"),
				create_anchors(create_pos(406, 0), create_pos(100, 100)),
				NULL)),
		3);
	last = last->next;

	last->next = create_canvas_element(
		create_t_data(
			create_text(
				al_load_ttf_font("javatext.ttf", 50, NULL),
				create_pos(30, 0),
				al_map_rgb(0, 0, 0),
				NULL,
				"CONTACTS")),
		2);

	draw_canvas(&canvas);
}
