#include <stdlib.h>
#include "canvas_ui.h"
#include "c_draw_elements.h"

void draw_element(CANVAS_ELEMENT *element) {
	switch (element->type) {
		case 0:
			draw_rectangle(element->data.rectangle);
			break;
		case 1:
			draw_line(element->data.line);
			break;
		case 2:
			draw_text(element->data.text);
			break;
		case 3:
			draw_image(element->data.image);
			break;
		case 4:
			draw_contact(element->data.contact);
			break;
	}
}

void draw_canvas(CANVAS *canvas) {

	for (int i = canvas->nr_of_layers - 1; i >= 0; i--) {
		CANVAS_ELEMENT *tmp = canvas->layers[i].elements;

		while (tmp) {
			draw_element(tmp);

			tmp = tmp->next;
		}
	}

	al_flip_display();
}