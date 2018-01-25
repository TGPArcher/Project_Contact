#pragma once
#include <stdio.h>
#include "canvas_ui.h"
#include "c_init_elements.h"

//extern
void set_add_page();
void add_delete_button(ANCHORS);
void remove_delete_button();
void draw_active_page();
CANVAS_ELEMENT* raycast_canvas(POS);
void input_to_field(CANVAS_ELEMENT*);

void on_click(ALLEGRO_EVENT, CANVAS*);
void select_element(CANVAS_ELEMENT*);
void select_effect(CANVAS_ELEMENT*, int);
ALLEGRO_COLOR blend_colors(ALLEGRO_COLOR, ALLEGRO_COLOR, int);