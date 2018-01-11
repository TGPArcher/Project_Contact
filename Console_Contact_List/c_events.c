#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro.h>

void m_routine(ALLEGRO_EVENT_QUEUE*);
void on_click(ALLEGRO_EVENT);
void on_hover(ALLEGRO_EVENT);
void on_scroll(ALLEGRO_EVENT);

void m_events_init() {
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;

	event_queue = al_create_event_queue();
	if (!event_queue)
		fprintf(stderr, "could not create event queue");

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
			else if (ev.mouse.button == 2)
				break;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES) {
			if (ev.mouse.dx || ev.mouse.dy)
				on_hover(ev);
			else if (ev.mouse.dz)
				on_scroll(ev);
		}
	}
}

void on_click(ALLEGRO_EVENT ev) {
	printf("Click\n");
}

void on_hover(ALLEGRO_EVENT ev) {
	printf("Hover\n");
}

void on_scroll(ALLEGRO_EVENT ev) {
	printf("Scroll\n");
}