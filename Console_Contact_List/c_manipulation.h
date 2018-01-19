#pragma once
#include "canvas_ui.h"

void select_element(CANVAS_ELEMENT*);
void select_effect(CANVAS_ELEMENT*, int);
ALLEGRO_COLOR blend_colors(ALLEGRO_COLOR, ALLEGRO_COLOR, int);

void input_to_field(CANVAS_ELEMENT *input_field);
char* move_from_field(char field[21]);
void add_letter(char field[21], char c);
void remove_letter(char field[21]);

CANVAS_ELEMENT* get_canvas_last_element(CANVAS*, int);

CANVAS display_page();
void print_list_to_canvas(CANVAS*);

CANVAS_ELEMENT* raycast_canvas(CANVAS*, POS);
void translate_element(CANVAS_ELEMENT*, int);