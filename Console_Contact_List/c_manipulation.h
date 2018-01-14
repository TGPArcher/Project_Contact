#pragma once
#include "canvas_ui.h"

void select_element(CANVAS_ELEMENT*);
void select_effect(CANVAS_ELEMENT*, int);
ALLEGRO_COLOR blend_colors(ALLEGRO_COLOR, ALLEGRO_COLOR, int);

CANVAS_ELEMENT* get_canvas_last_element(CANVAS*, int);

CANVAS display_page();
void print_list_to_canvas(CANVAS*);

CANVAS_ELEMENT* raycast_canvas(CANVAS*, POS);
void translate_element(CANVAS_ELEMENT*, int);