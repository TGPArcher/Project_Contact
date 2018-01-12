#pragma once
#include "canvas_ui.h"

CANVAS_ELEMENT* get_canvas_last_element(CANVAS*, int);
ANCHORS recalculate_anchors(ANCHORS anchors, int count);
POS recalculate_pos(POS anchors, int y);

CANVAS display_page();
void print_list_to_canvas(CANVAS*);