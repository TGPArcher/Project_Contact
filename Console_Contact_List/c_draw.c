#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "canvas_ui.h"

extern draw_contact(int, int, char*, char*, ALLEGRO_COLOR*, ALLEGRO_COLOR*, ALLEGRO_COLOR*, ALLEGRO_COLOR*, int);

void draw_element(CANVAS_ELEMENT *element) {
	switch (element->type) {
		case 0:
			al_draw_filled_rectangle(
				element->data.rectangle.anchors.upper.x,
				element->data.rectangle.anchors.upper.y,
				element->data.rectangle.anchors.lower.x,
				element->data.rectangle.anchors.lower.y,
				element->data.rectangle.color);
			break;
		case 1:
			al_draw_line(
				element->data.line.anchors.upper.x,
				element->data.line.anchors.upper.y,
				element->data.line.anchors.lower.x,
				element->data.line.anchors.lower.y,
				element->data.line.color,
				element->data.line.size);
			break;
		case 2:
			al_draw_text(
				element->data.text.font,
				element->data.text.color,
				element->data.text.anchor.x,
				element->data.text.anchor.y,
				element->data.text.flags,
				element->data.text.text);
			break;
		case 3:
			al_draw_bitmap(
				element->data.image.image,
				element->data.image.anchors.upper.x,
				element->data.image.anchors.upper.y,
				element->data.image.flags);
			break;
		case 4:
			draw_contact(
				element->data.contact.anchors.upper.x,
				element->data.contact.anchors.upper.y,
				element->data.contact.name_text.text,
				element->data.contact.number_text.text,
				&element->data.contact.main_body.color,
				&element->data.contact.min_body.color,
				&element->data.contact.name_text.color,
				&element->data.contact.number_text.color,
				element->data.contact.count);
			break;
	}
}

void draw_canvas(CANVAS *canvas) {
	CANVAS_ELEMENT *tmp = canvas->elements;

	while (tmp) {
		draw_element(tmp);

		tmp = tmp->next;
	}

	al_flip_display();

	al_rest(15);
}