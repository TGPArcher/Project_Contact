#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "canvas_ui.h"

POS create_pos(int x, int y) {
	return (POS) { .x = x, .y = y };
}

ANCHORS create_anchors(POS up, POS low) {
	return (ANCHORS) { .upper = up, .lower = low };
}

RECTANGLE create_rectangle(ANCHORS anchors, ALLEGRO_COLOR color) {
	return (RECTANGLE) { .anchors = anchors, .color = color };
}

LINE create_line(ANCHORS anchors, ALLEGRO_COLOR color) {
	return (LINE) { .anchors = anchors, .color = color };
}

TEXT create_text(ALLEGRO_FONT *font, ANCHORS anchors, ALLEGRO_COLOR color, int flags, char *text) {
	return (TEXT) { .font = font, .anchors = anchors, .color = color, .flags = flags, .text = text };
}

IMAGE create_image(ALLEGRO_BITMAP *image, ANCHORS anchors, int flags) {
	return (IMAGE) { .image = image, .anchors = anchors, .flags = flags };
}

CONTACT create_contact(ANCHORS anchors, RECTANGLE main_body, RECTANGLE color_body, TEXT name_text, TEXT number_text, int count) {
	return (CONTACT) { .anchors = anchors, .main_body = main_body, .color_body = color_body, .name_text = name_text, .number_text = number_text, .count = count };
}

DATA create_data(void *data, int type) {
	switch (type) {
		case 0: 
			return (DATA) { .rectangle = (*(RECTANGLE*)data) };
			break;
		case 1:
			return (DATA) { .line = (*(LINE*)data) };
			break;
		case 2:
			return (DATA) { .text = (*(TEXT*)data) };
			break;
		case 3:
			return (DATA) { .image = (*(IMAGE*)data) };
			break;
		case 4:
			return (DATA) { .contact = (*(CONTACT*)data) };
			break;
	}
}

CANVAS_ELEMENT* create_canvas_element(DATA data, int type) {
	CANVAS_ELEMENT *new_element = (CANVAS_ELEMENT*)malloc(sizeof(CANVAS_ELEMENT));

	new_element->type = type;
	new_element->data = data;
	new_element->next = NULL;

	return new_element;
}

CANVAS display_page() {
	CANVAS canvas = { .anchors = create_anchors(create_pos(0, 0), create_pos(500, 100)) };

	canvas.elements = create_canvas_element(
		create_data(
			create_rectangle(
				create_anchors(create_pos(0, 0), create_pos(500, 100)),
				al_map_rgb(145, 56, 60)),
			0),
		0);
	al_draw_filled_rectangle(
		0, 0,
		500, 100,
		al_map_rgb(145, 56, 60));


	al_draw_filled_rectangle(
		0, 705,
		500, 750,
		al_map_rgb(145, 56, 60));

	al_draw_line(
		20, 69,
		406, 69,
		al_map_rgb(0, 0, 0),
		2);

	ALLEGRO_BITMAP *add_button = al_load_bitmap("add_button.png");
	al_draw_bitmap(add_button, 380, 630, NULL);

	ALLEGRO_FONT *title_font = al_load_ttf_font("javatext.ttf", 50, NULL);

	al_draw_text(title_font, al_map_rgb(0, 0, 0), 30, 0, NULL, "CONTACTS");

	ALLEGRO_BITMAP *search_button = al_load_bitmap("search_button.png");
	al_draw_bitmap(search_button, 406, 0, NULL);

	//draw_contact(12, 110, "Sergiu", "068553218", NULL, NULL, NULL, NULL, 0);
}
