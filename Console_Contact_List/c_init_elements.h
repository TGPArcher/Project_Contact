#pragma once
#include "canvas_ui.h"
#include <allegro5/allegro_ttf.h>

INTERACTABLE create_interactable(int, int);
ANCHORS* set_scroll_rect(POS, POS);
POS create_pos(int x, int y);
ANCHORS create_anchors(POS up, POS low);
LINE create_line(ANCHORS anchors, ALLEGRO_COLOR color, int size);
RECTANGLE create_rectangle(ANCHORS anchors, ALLEGRO_COLOR color);
TEXT create_text(ALLEGRO_FONT *font, POS anchor, ALLEGRO_COLOR color, int flags, char *text);
IMAGE create_image(ALLEGRO_BITMAP *image, ANCHORS anchors, int flags);
CONTACT create_contact(RECTANGLE main_body, RECTANGLE color_body, TEXT name_text, TEXT number_text, int count);
I_BUTTON create_i_button(IMAGE, ALLEGRO_BITMAP*, ALLEGRO_BITMAP*, ANCHORS, void(*));
T_BUTTON create_t_button(TEXT, RECTANGLE, RECTANGLE, void(*));
INPUT_FIELD create_i_field(TEXT, LINE, ANCHORS);

DATA create_r_data(RECTANGLE rectangle);
DATA create_l_data(LINE line);
DATA create_t_data(TEXT text);
DATA create_i_data(IMAGE image);
DATA create_c_data(CONTACT contact);
DATA create_ib_data(I_BUTTON button);
DATA create_tb_data(T_BUTTON button);
DATA create_ifield_data(INPUT_FIELD input);

CANVAS_ELEMENT* create_canvas_element(DATA, INTERACTABLE, ANCHORS*, int);

CANVAS_ELEMENT* e_init_rectangle(
	int, int, int, int,
	ALLEGRO_COLOR,
	INTERACTABLE,
	ANCHORS*);

CANVAS_ELEMENT* e_init_line(
	int, int, int, int,
	ALLEGRO_COLOR,
	int,
	INTERACTABLE,
	ANCHORS*);

CANVAS_ELEMENT* e_init_image(
	char*,
	int, int, int, int,
	int,
	INTERACTABLE,
	ANCHORS*);

CANVAS_ELEMENT* e_init_text(
	char*, int,
	int, int,
	ALLEGRO_COLOR,
	int, char*,
	INTERACTABLE,
	ANCHORS*);

CANVAS_ELEMENT* e_init_contact(
	POS, POS, POS,
	ALLEGRO_COLOR, ALLEGRO_COLOR, ALLEGRO_COLOR, ALLEGRO_COLOR,
	char*, char*,
	int,
	INTERACTABLE,
	ANCHORS*);

CANVAS_ELEMENT* e_init_ibutton(
	char*, char*, char*,
	ANCHORS,
	int,
	INTERACTABLE, ANCHORS, void(),
	ANCHORS*);

CANVAS_ELEMENT* e_init_tbutton(
	char*, int, char*, ALLEGRO_COLOR,
	ANCHORS, ALLEGRO_COLOR,
	ANCHORS, ALLEGRO_COLOR,
	INTERACTABLE, void(),
	ANCHORS*);

CANVAS_ELEMENT* e_init_ifield(
	char*, char*, int, ALLEGRO_COLOR,
	ANCHORS, ALLEGRO_COLOR, int);

POS recalculate_anchors(POS, POS, int);