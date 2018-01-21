#include "on_scroll.h"

extern CANVAS active_page;

void on_scroll(ALLEGRO_EVENT ev) {
	CANVAS_ELEMENT *tmp = NULL;

	for (int i = 0; i < active_page.nr_of_layers; i++) {
		tmp = active_page.layers[i].elements;

		while (tmp) {
			if (tmp->scrollable) {
				if ((ev.mouse.x >= tmp->scrollable->upper.x && ev.mouse.x <= tmp->scrollable->lower.x) &&
					(ev.mouse.y >= tmp->scrollable->upper.y && ev.mouse.y <= tmp->scrollable->lower.y))
					translate_element(tmp, ev.mouse.dz);
			}

			tmp = tmp->next;
		}
	}

	draw_active_canvas();
}

void translate_element(CANVAS_ELEMENT *element, int change) {
	change *= 10;

	switch (element->type) {
	case 0:
		element->data.rectangle.anchors.upper.y += change;
		element->data.rectangle.anchors.lower.y += change;
		break;
	case 1:
		element->data.rectangle.anchors.upper.y += change;
		element->data.rectangle.anchors.lower.y += change;
		break;
	case 2:
		element->data.text.anchor.y += change;
		break;
	case 3:
		element->data.image.anchors.upper.y += change;
		break;
	case 4:
		element->data.contact.main_body.anchors.upper.y += change;
		element->data.contact.main_body.anchors.lower.y += change;
		element->data.contact.min_body.anchors.upper.y += change;
		element->data.contact.min_body.anchors.lower.y += change;
		element->data.contact.name_text.anchor.y += change;
		element->data.contact.number_text.anchor.y += change;
		break;
	case 5:
		element->data.i_button.image.anchors.upper.y += change;
		element->data.i_button.hitbox.upper.y += change;
		element->data.i_button.hitbox.lower.y += change;
		break;
	}
}