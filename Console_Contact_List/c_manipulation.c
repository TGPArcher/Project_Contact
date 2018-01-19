#include "c_manipulation.h"
#include "c_init_elements.h"
#include "list.h"
#include "c_pages.h"
#include <stdio.h>
#include <string.h>

CANVAS_ELEMENT *selected_element = NULL;

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

	if(element)
		switch (element->type) {
			// 	case 0: - rectangles are just for design, cannot be selected	
			// 		break;
			// 	case 1: - lines can't be targeted	
			// 		break;
			// 	case 2: - texts can't be selected, see T_BUTTONS
			// 		break;
			// 	case 3: - images can't be selected, see I_BUTTONS
			// 		break;
		case 4:
			element->data.contact.min_body.color = 
				blend_colors(element->data.contact.min_body.color, select_color, operation);
			break;
// 		case 5: - is troublesome for now
// 			ALLEGRO_BITMAP *tmp_bitmap = element->data.i_button.image.image;
// 			element->data.i_button.image.image = element->data.i_button.click;
// 			element->data.i_button.click = tmp_bitmap;
// 			break;
		}
}

void input_to_field(CANVAS_ELEMENT *input_field) {
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	if (!event_queue)
		fprintf(stderr, "could not create event\n");
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	while (1) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_CHAR) {
			if (ev.keyboard.keycode == ALLEGRO_KEY_ENTER)
				break;
			if (ev.keyboard.keycode == ALLEGRO_KEY_BACKSPACE)
				remove_letter(input_field->data.input_field.input_buffer);
			else
				add_letter(input_field->data.input_field.input_buffer, ev.keyboard.unichar);
			
			input_field->data.input_field.text.text =
				move_from_field(input_field->data.input_field.input_buffer);
			
			draw_active_canvas();
		}
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
			break;
	}
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

ALLEGRO_COLOR blend_colors(ALLEGRO_COLOR color1, ALLEGRO_COLOR color2, int operation) {
	color1.r += color2.r * operation;
	color1.g += color2.g * operation;
	color1.b += color2.b * operation;

	return color1;
}

CANVAS_ELEMENT* get_canvas_last_element(CANVAS *canvas, int layer) {
	CANVAS_ELEMENT *tmp = canvas->layers[layer].elements;

	while (tmp && tmp->next)
		tmp = tmp->next;

	return tmp;
}

void print_list_to_canvas(CANVAS *canvas, struct Node *list) {
	CANVAS_ELEMENT *last = NULL;
	struct Node *tmp = list;
	int count = 0;

	canvas->layers[2].elements = e_init_contact(
		create_pos(12, 110), create_pos(30, 10), create_pos(30, 50),
		al_map_rgb(174, 174, 174), al_map_rgb(120, 115, 130), al_map_rgb(48, 48, 48), al_map_rgb(88, 88, 88),
		tmp->name, tmp->phone_nr,
		count,
		create_interactable(1, 1),
		set_scroll_rect(create_pos(0, 100), create_pos(500, 705)));

	last = canvas->layers[2].elements;
	tmp = tmp->next_node;
	count++;

	while (tmp) {
		last->next = e_init_contact(
			create_pos(12, 110), create_pos(30, 10), create_pos(30, 50),
			al_map_rgb(174, 174, 174), al_map_rgb(120, 115, 130), al_map_rgb(48, 48, 48), al_map_rgb(88, 88, 88),
			tmp->name, tmp->phone_nr,
			count,
			create_interactable(1, 1),
			set_scroll_rect(create_pos(0, 100), create_pos(500, 705)));

		last = last->next;
		tmp = tmp->next_node;
		count++;
	}
}

CANVAS_ELEMENT* raycast_canvas(CANVAS *canvas, POS cursor_pos) {
	CANVAS_ELEMENT *tmp = NULL;

	for (int i = 0; i < canvas->nr_of_layers; i++) {
		tmp = canvas->layers[i].elements;

		while (tmp) {
			ANCHORS pos = { -1, -1 };

			switch (tmp->type) {
			case 0:
				pos = tmp->data.rectangle.anchors;
				break;
			case 1:
				pos = tmp->data.line.anchors;
				break;
// 			case 2: - texts can't be targeted -> unless they are buttons
// 				pos = tmp->data.text.anchor;
// 				break;
// 			case 3: - images can't be targeted -> unless they are buttons
// 				pos = tmp->data.image.anchors;
// 				break;
			case 4:
				pos = tmp->data.contact.main_body.anchors;
				break;
			case 5:
				pos = tmp->data.i_button.hitbox;
				break;
			case 6:
				//pos = *tmp->scrollable;
				break;
			case 7:
				pos = tmp->data.input_field.hitbox;
				break;
			}

			if ((cursor_pos.x >= pos.upper.x && cursor_pos.x <= pos.lower.x) &&
				(cursor_pos.y >= pos.upper.y && cursor_pos.y <= pos.lower.y))
				if (tmp->interactable.raycast)
					return tmp;
				else
					return NULL;
			
			tmp = tmp->next;
		}
	}

	return tmp;
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
	}
}
