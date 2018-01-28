#include "on_hover.h"

extern CANVAS active_page;

void on_hover(ALLEGRO_EVENT ev) {

	static ALLEGRO_COLOR hover_color = { .r = 227,.g = 225,.b = 232,.a = 255 };
	static ALLEGRO_COLOR last_color = { .r = 0,.g = 0,.b = 0,.a = 0 };

	static CANVAS_ELEMENT *last_element = NULL;
	CANVAS_ELEMENT *element = raycast_canvas(create_pos(ev.mouse.x, ev.mouse.y));

	if (element != last_element) {
		// restore color of the previous hovered element
		hover_effect(last_element, last_color);

		// save elements previous state
		last_color = get_element_color(element);
		last_element = element;
		// apply hover effect to new element
		hover_effect(element, hover_color);

		draw_active_page();
	}
}

ALLEGRO_COLOR get_element_color(CANVAS_ELEMENT *element) {
	if (element)
		switch (element->type) {
		case 0:
			return element->data.rectangle.color;
			break;
		case 4:
			return element->data.contact.main_body.color;
			break;
		case 6:
			return element->data.t_button.background.color;
			break;
		default:
			return (ALLEGRO_COLOR) { .r = 0, .g = 0, .b = 0 };
		}
	else
		return (ALLEGRO_COLOR) { .r = 0, .g = 0, .b = 0 };
}

void hover_effect(CANVAS_ELEMENT *element, ALLEGRO_COLOR color) {
	if (element)
		switch (element->type) {
		case 0:
			element->data.rectangle.color = color;
			break;
		case 4:
			element->data.contact.main_body.color = color;
			break;
		case 5:
			ALLEGRO_BITMAP *tmp_bitmap = element->data.i_button.image.image;
			element->data.i_button.image.image = element->data.i_button.hover;
			element->data.i_button.hover = tmp_bitmap;
			break;
		case 6:
			element->data.t_button.background.color = color;
			break;
		}
}