#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro.h>

void m_events_init() {
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;

	event_queue = al_create_event_queue();
	if (!event_queue)
		fprintf(stderr, "could not create event queue");

	al_register_event_source(event_queue, al_get_mouse_event_source());

	while (1) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

// 		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
// 			if (ev.mouse.button == 1)
// 				break;
	}
}

// void on_click(ALLEGRO_EVENT ev) {
// 	if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
// }