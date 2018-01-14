#include "c_manipulation.h"
#include "c_init_elements.h"
#include "list.h"

CANVAS_ELEMENT *selected_element = NULL;

void select_element(CANVAS_ELEMENT *element) {
	select_effect(selected_element, 1);
	selected_element = element;
	if (selected_element)
		select_effect(selected_element, -1);
}

void select_effect(CANVAS_ELEMENT *element, int operation) {
	static ALLEGRO_COLOR select_color = { .r = 50,.g = 50,.b = 50,.a = 255 };

	if(element)
		switch (element->type) {
			// 	case 0:
			// 		
			// 		break;
			// 	case 1:
			// 		
			// 		break;
			// 	case 2:
			// 
			// 		break;
			// 	case 3:
			// 		
			// 		break;
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

CANVAS_ELEMENT* get_canvas_last_element(CANVAS *canvas, int layer) {
	CANVAS_ELEMENT *tmp = canvas->layers[layer].elements;

	while (tmp && tmp->next)
		tmp = tmp->next;

	return tmp;
}

CANVAS display_page() {
	CANVAS canvas = { 
		.anchors = create_anchors(create_pos(0, 0), create_pos(500, 750)), 
		.nr_of_layers = 3, 
		.background = al_map_rgb(207, 207, 207) };
	
	canvas.layers = (LAYER*)malloc(sizeof(LAYER) * canvas.nr_of_layers);
	for (int i = 0; i < canvas.nr_of_layers; i++)
		canvas.layers[i].elements = NULL;

	CANVAS_ELEMENT *last = NULL;

	canvas.layers[0].elements = e_init_rectangle(0, 0, 500, 100, al_map_rgb(145, 56, 60), 
		create_interactable(0, 0), NULL);
	last = canvas.layers[0].elements;

	last->next = e_init_rectangle(0, 705, 500, 750, al_map_rgb(145, 56, 60), 
		create_interactable(0, 0), NULL);
	last = last->next;

	last->next = e_init_line(20, 69, 406, 69, al_map_rgb(0, 0, 0), 2, 
		create_interactable(0, 0), NULL);
	last = last->next;

	last->next = e_init_image("add_button.png", 380, 630, 110, 110, 0, 
		create_interactable(0, 0), NULL);
	last = last->next;

	last->next = e_init_image("search_button.png", 406, 0, 100, 100, 0, 
		create_interactable(0, 0), NULL);
	last = last->next;

	last->next = e_init_text("javatext.ttf", 50, 30, 0, al_map_rgb(0, 0, 0), 0, "CONTACTS", 
		create_interactable(0, 0), NULL);

	return canvas;
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
			case 3:
				pos = tmp->data.image.anchors;
				break;
			case 4:
				pos = tmp->data.contact.main_body.anchors;
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
