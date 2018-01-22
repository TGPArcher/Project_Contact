#pragma once
#include "canvas_ui.h"

extern void draw_active_page();

void on_scroll(ALLEGRO_EVENT);
void translate_element(CANVAS_ELEMENT*, int);