#include "on_click.h"

CANVAS_ELEMENT *selected_element = NULL;

void on_click(ALLEGRO_EVENT ev, CANVAS *canvas) {
	CANVAS_ELEMENT *test = raycast_canvas(create_pos(ev.mouse.x, ev.mouse.y));

	select_element(test);
	draw_active_page();
}

void select_element(CANVAS_ELEMENT *element) {
	select_effect(selected_element, 1);

	selected_element = element;
	if (selected_element) {
		select_effect(selected_element, -1);

		if (selected_element->type == 5)
			selected_element->data.i_button.f();
		if (selected_element->type == 6)
			selected_element->data.t_button.f();
		if (selected_element->type == 7)
			input_to_field(selected_element);
	}
}

void select_effect(CANVAS_ELEMENT *element, int operation) {
	static ALLEGRO_COLOR select_color = { .r = 50,.g = 50,.b = 50,.a = 255 };

	if (element)
		switch (element->type) {
		case 4:
			element->data.contact.min_body.color =
				blend_colors(element->data.contact.min_body.color, select_color, operation);
			break;
		}
}

ALLEGRO_COLOR blend_colors(ALLEGRO_COLOR color1, ALLEGRO_COLOR color2, int operation) {
	color1.r += color2.r * operation;
	color1.g += color2.g * operation;
	color1.b += color2.b * operation;

	return color1;
}