#pragma once
#include "canvas_ui.h"

CANVAS_ELEMENT* get_canvas_last_element(CANVAS*, int);

CANVAS display_page();
void print_list_to_canvas(CANVAS*);

CANVAS_ELEMENT* raycast_canvas(CANVAS*, POS);
void translate_element(CANVAS_ELEMENT*, int);