#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include "c_manipulation.h"
#include "c_init_elements.h"

extern void draw_canvas(CANVAS*);
extern void cls(ALLEGRO_COLOR);

void m_routine(ALLEGRO_EVENT_QUEUE*, CANVAS*);
void on_click(ALLEGRO_EVENT, CANVAS*);
void on_hover(ALLEGRO_EVENT);
void on_scroll(ALLEGRO_EVENT);

ALLEGRO_COLOR get_element_color(CANVAS_ELEMENT*);
void hover_effect(CANVAS_ELEMENT*, ALLEGRO_COLOR);

void m_events_init(CANVAS *canvas) {
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;

	event_queue = al_create_event_queue();
	if (!event_queue)
		fprintf(stderr, "could not create event queue");

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
			else if (ev.mouse.dz)
				on_scroll(ev);
		}
	}
}

void on_click(ALLEGRO_EVENT ev, CANVAS *canvas) {
	printf("Click\n");
	CANVAS_ELEMENT *test = raycast_canvas(canvas, create_pos(ev.mouse.x, ev.mouse.y));

	if (test)
		printf("-------------------->  %d\n", test->type);
}

void on_hover(ALLEGRO_EVENT ev, CANVAS *canvas) {

	static init = 1;
	static ALLEGRO_COLOR hover_color;
	static ALLEGRO_COLOR last_color;

	if (init) {
		hover_color = al_map_rgb(227, 225, 232);
		last_color = al_map_rgba(0, 0, 0, 0);
		init = 0;
	}

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

		cls(canvas->background);
		draw_canvas(canvas);
		al_flip_display();
	}
}

void on_scroll(ALLEGRO_EVENT ev) {
	printf("Scroll\n");
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
			// 			case 3: - images have no color
			// 				return ?
			// 				break;
		case 4:
			return element->data.contact.main_body.color;
			break;
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
		}
}