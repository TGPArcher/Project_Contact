#include "c_manipulation.h"
#include "c_init_elements.h"
#include "list.h"
#include "c_pages.h"
#include <stdio.h>
#include <string.h>

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
