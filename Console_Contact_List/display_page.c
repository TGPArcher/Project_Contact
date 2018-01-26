#include "display_page.h"
#include <stdio.h>

extern CANVAS active_page;

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

	last->next = e_init_ibutton(
		"add_button_0.png", "add_button_1.png", "add_button_2.png",
		create_anchors(create_pos(380, 630), create_pos(110, 110)),
		0,
		create_interactable(1, 1),
		create_anchors(create_pos(380, 630), create_pos(490, 740)),
		&set_add_page,
		NULL);
	last = last->next;

	last->next = e_init_ifield(
		"SEARCH", "javatext.ttf", 30, al_map_rgb(0, 0, 0),
		create_anchors(create_pos(120, 69), create_pos(488, 69)), al_map_rgb(0, 0, 0), 2,
		NULL, &search_by_name);
	last = last->next;

	last->next = e_init_ibutton(
		"search_button_0.png", "search_button_2.png", "search_button_2.png",
		create_anchors(create_pos(20, 0), create_pos(100, 100)),
		0,
		create_interactable(1, 1),
		create_anchors(create_pos(20, 0), create_pos(120, 100)),
		&activate_search_bar,
		NULL);

	return canvas;
}

void print_list_to_canvas(CANVAS *canvas, struct Node *list) {
	CANVAS_ELEMENT *last = NULL;
	struct Node *tmp = list;
	int count = 0;

	if (tmp) {
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
	}
	else
		canvas->layers[2].elements = tmp;

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

void remove_delete_button() {
	if(active_page.nr_of_layers == 3)
		if (active_page.layers[1].elements) {
			free(active_page.layers[1].elements);
			active_page.layers[1].elements = NULL;
		}
}

void add_delete_button(ANCHORS anchors) {
	active_page.layers[1].elements = e_init_ibutton(
		"delete_icon_0.png", "delete_icon_1.png", "delete_icon_1.png",
		create_anchors(create_pos(440, anchors.upper.y + 25), create_pos(40, 50)),
		0,
		create_interactable(1, 1),
		create_anchors(create_pos(440, anchors.upper.y + 25), create_pos(480, anchors.upper.y + 25 + 50)),
		&delete_from_canvas,
		set_scroll_rect(create_pos(0, 100), create_pos(500, 705)));
}


