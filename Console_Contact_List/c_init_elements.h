#pragma once
#include "c_manipulation.h"

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