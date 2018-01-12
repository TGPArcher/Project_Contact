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

CANVAS_ELEMENT* e_init_rectangle(
	int, int, int, int,
	ALLEGRO_COLOR);

CANVAS_ELEMENT* e_init_line(
	int, int, int, int,
	ALLEGRO_COLOR,
	int);

CANVAS_ELEMENT* e_init_image(
	char*,
	int, int, int, int,
	int);

CANVAS_ELEMENT* e_init_text(
	char*, int,
	int, int,
	ALLEGRO_COLOR,
	int, char*);

CANVAS_ELEMENT* e_init_contact(
	POS, POS, POS,
	ALLEGRO_COLOR, ALLEGRO_COLOR, ALLEGRO_COLOR, ALLEGRO_COLOR,
	char*, char*,
	int);