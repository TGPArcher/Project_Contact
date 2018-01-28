#pragma once
#include <stdio.h>
#include "canvas_ui.h"
#include "c_init_elements.h"

CANVAS_ELEMENT* raycast_canvas(POS);
void draw_active_page();

void on_hover(ALLEGRO_EVENT);
ALLEGRO_COLOR get_element_color(CANVAS_ELEMENT*);
void hover_effect(CANVAS_ELEMENT*, ALLEGRO_COLOR);
