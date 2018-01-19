#include <stdlib.h>
#include <stdio.h>
#include "c_manipulation.h"
#include "c_init_elements.h"
#include "c_events.h"

extern void draw_canvas(CANVAS*);

void m_events_init(CANVAS *canvas) {
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;

	event_queue = al_create_event_queue();
	if (!event_queue)
		fprintf(stderr, "could not create event queue\n");

	al_register_event_source(event_queue, al_get_mouse_event_source());

	m_routine(event_queue, canvas);
}

void m_routine(ALLEGRO_EVENT_QUEUE *event_queue, CANVAS *canvas) {
	while (1) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			if (ev.mouse.button == 1)
				on_click(ev, canvas);
			else if (ev.mouse.button == 2)
				break;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES) {
			if (ev.mouse.dx || ev.mouse.dy)
				on_hover(ev, canvas);
			if (ev.mouse.dz)
				on_scroll(ev, canvas);
		}
	}
}

void on_click(ALLEGRO_EVENT ev, CANVAS *canvas) {
	CANVAS_ELEMENT *test = raycast_canvas(canvas, create_pos(ev.mouse.x, ev.mouse.y));

	select_element(test);
	draw_canvas(canvas);
}

void on_hover(ALLEGRO_EVENT ev, CANVAS *canvas) {

	static ALLEGRO_COLOR hover_color = { .r = 227,.g = 225,.b = 232,.a = 255 };
	static ALLEGRO_COLOR last_color = { .r = 0,.g = 0,.b = 0,.a = 0 };

	static CANVAS_ELEMENT *last_element = NULL;
	CANVAS_ELEMENT *element = raycast_canvas(canvas, create_pos(ev.mouse.x, ev.mouse.y));

	if (element != last_element) {
		// restore color of the previous hovered element
		hover_effect(last_element, last_color);

		// save elements previous state
		last_color = get_element_color(element);
		last_element = element;
		// apply hover effect to new element
		hover_effect(element, hover_color);

		draw_canvas(canvas);
	}
}

ALLEGRO_COLOR get_element_color(CANVAS_ELEMENT *element) {
	if (element)
		switch (element->type) {
		case 0:
			return element->data.rectangle.color;
			break;
		case 1:
			return element->data.line.color;
			break;
		case 2:
			return element->data.text.color;
			break;
// 		case 3: -images have no color
// 			return ?
// 			break;
		case 4:
			return element->data.contact.main_body.color;
			break;
// 		case 5: -buttons with images have no color
// 			return ?
// 			break;
		}
	else
		return (ALLEGRO_COLOR) { .r = 0, .g = 0, .b = 0 };
}

void hover_effect(CANVAS_ELEMENT *element, ALLEGRO_COLOR color) {
	if(element)
		switch (element->type) {
			case 0:
				element->data.rectangle.color = color;
				break;
			case 1:
				element->data.line.color = color;
				break;
// 			case 2: - text has no raycast at the moment
// 				element->data.? = color;
// 				break;
// 			case 3: - images have no color and raycast at the moment
// 				element->data.? = color;
// 				break;
			case 4:
				element->data.contact.main_body.color = color;
				break;
			case 5:
				ALLEGRO_BITMAP *tmp_bitmap = element->data.i_button.image.image;
				element->data.i_button.image.image = element->data.i_button.hover;
				element->data.i_button.hover = tmp_bitmap;
				break;
		}
}

void on_scroll(ALLEGRO_EVENT ev, CANVAS *canvas) {
	CANVAS_ELEMENT *tmp = NULL;

	for (int i = 0; i < canvas->nr_of_layers; i++) {
		tmp = canvas->layers[i].elements;

		while (tmp) {
			if (tmp->scrollable) {
				if ((ev.mouse.x >= tmp->scrollable->upper.x && ev.mouse.x <= tmp->scrollable->lower.x) &&
					(ev.mouse.y >= tmp->scrollable->upper.y && ev.mouse.y <= tmp->scrollable->lower.y))
					translate_element(tmp, ev.mouse.dz);
			}

			tmp = tmp->next;
		}
	}

	draw_canvas(canvas);
}
