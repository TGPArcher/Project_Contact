#pragma once

#include "canvas_ui.h"

POS create_pos(int x, int y);
ANCHORS create_anchors(POS up, POS low);
LINE create_line(ANCHORS anchors, ALLEGRO_COLOR color, int size);
RECTANGLE create_rectangle(ANCHORS anchors, ALLEGRO_COLOR color);
TEXT create_text(ALLEGRO_FONT *font, POS anchor, ALLEGRO_COLOR color, int flags, char *text);
IMAGE create_image(ALLEGRO_BITMAP *image, ANCHORS anchors, int flags);
CONTACT create_contact(RECTANGLE main_body, RECTANGLE color_body, TEXT name_text, TEXT number_text, int count);

DATA create_r_data(RECTANGLE rectangle);
DATA create_l_data(LINE line);
DATA create_t_data(TEXT text);
DATA create_i_data(IMAGE image);
DATA create_c_data(CONTACT contact);

CANVAS_ELEMENT* create_canvas_element(DATA data, int type);

ANCHORS recalculate_anchors(ANCHORS anchors, int count);
POS recalculate_pos(POS anchors, int y);

CANVAS display_page();