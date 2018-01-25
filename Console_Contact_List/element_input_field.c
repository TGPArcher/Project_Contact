#include "element_input_field.h"

extern list contacts;

void input_to_field(CANVAS_ELEMENT *input_field) {
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	if (!event_queue)
		fprintf(stderr, "could not create event\n");

	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	while (1) {
		int changed = 0;
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_CHAR) {
			if (ev.keyboard.keycode == ALLEGRO_KEY_ENTER)
				break;
			if (ev.keyboard.keycode == ALLEGRO_KEY_BACKSPACE) {
				remove_letter(input_field->data.input_field.input_buffer);
				changed = 1;
			}
			else {
				add_letter(input_field->data.input_field.input_buffer, ev.keyboard.unichar);	
				changed = 1;
			}

			input_field->data.input_field.text.text =
				move_from_field(input_field->data.input_field.input_buffer);
			
			if (changed)
				if (input_field->data.input_field.on_change)
					input_field->data.input_field.on_change(&contacts, input_field->data.input_field.text.text);

			draw_active_page();
		}
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			break;
		}
	}

	if (input_field->data.input_field.on_exit)
		input_field->data.input_field.on_exit();
}

char* move_from_field(char field[21]) {
	int length = strlen(field);

	char *input = (char*)malloc(length + 1);
	strcpy_s(input, length + 1, field);

	return input;
}

void add_letter(char field[21], char c) {
	int field_len = strlen(field);

	if (field_len < 20)
		field[field_len] = c;
}

void remove_letter(char field[21]) {
	int field_len = strlen(field);

	if (field_len > 0) {
		strncpy_s(field, field_len, field, field_len - 1);
	}
}