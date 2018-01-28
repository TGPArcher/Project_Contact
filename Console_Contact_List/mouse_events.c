#include "mouse_events.h"

extern list contacts;
extern CANVAS active_page;

void m_events_init() {
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;

	event_queue = al_create_event_queue();
	if (!event_queue)
		fprintf(stderr, "could not create event queue\n");

	al_register_event_source(event_queue, al_get_mouse_event_source());

	m_routine(event_queue);
}

void m_routine(ALLEGRO_EVENT_QUEUE *event_queue) {
	while (1) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			if (ev.mouse.button == 1)
				on_click(ev);
			else if (ev.mouse.button == 2) {
				save_contacts(&contacts);
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES) {
			if (ev.mouse.dx || ev.mouse.dy)
				on_hover(ev);
			if (ev.mouse.dz)
				on_scroll(ev);
		}
	}
}

CANVAS_ELEMENT* raycast_canvas(POS cursor_pos) {
	CANVAS_ELEMENT *tmp = NULL;

	for (int i = 0; i < active_page.nr_of_layers; i++) {
		tmp = active_page.layers[i].elements;

		while (tmp) {
			if (tmp->interactable.raycast) {
				ANCHORS pos = { -1, -1 };

				switch (tmp->type) {
				case 0:
					pos = tmp->data.rectangle.anchors;
					break;
				case 1:
					pos = tmp->data.line.anchors;
					break;
				case 4:
					pos = tmp->data.contact.main_body.anchors;
					break;
				case 5:
					pos = tmp->data.i_button.hitbox;
					break;
				case 6:
					pos = tmp->data.t_button.margin.anchors;
					break;
				case 7:
					pos = tmp->data.input_field.hitbox;
					break;
				}

				if ((cursor_pos.x >= pos.upper.x && cursor_pos.x <= pos.lower.x) &&
					(cursor_pos.y >= pos.upper.y && cursor_pos.y <= pos.lower.y))
					return tmp;
			}

			tmp = (CANVAS_ELEMENT*)tmp->next;
		}
	}

	return NULL;
}
