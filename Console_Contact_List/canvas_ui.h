#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_color.h>
#pragma once

typedef struct {
	int raycast;
	int hover;
}INTERACTABLE;

typedef struct {
	int x, y;
}POS;

typedef struct {
	POS upper, lower;
}ANCHORS;

typedef struct {
	ANCHORS anchors;
	ALLEGRO_COLOR color;
}RECTANGLE;

typedef struct {
	ANCHORS anchors;
	ALLEGRO_COLOR color;
	int size;
}LINE;

typedef struct {
	ALLEGRO_FONT *font;
	POS anchor;
	ALLEGRO_COLOR color;
	int flags;
	char *text;
}TEXT;

typedef struct {
	ALLEGRO_BITMAP *image;
	ANCHORS anchors;
	int flags;
}IMAGE;

typedef struct {
	RECTANGLE main_body;
	RECTANGLE min_body;
	TEXT name_text;
	TEXT number_text;
	int count;
}CONTACT;

typedef struct {
	IMAGE image;
	ALLEGRO_BITMAP *hover;
	ALLEGRO_BITMAP *click;
	ANCHORS hitbox;

	void(*f)();
}I_BUTTON;

typedef struct {
	TEXT text;
	RECTANGLE margin;
	RECTANGLE background;

	void(*f)();
}T_BUTTON;

typedef struct {
	char input_buffer[21];
	TEXT text;
	LINE support_line;
	ANCHORS hitbox;

	void(*on_exit)();
	void(*on_change)();
}INPUT_FIELD;

typedef union {
	RECTANGLE rectangle;
	LINE line;
	TEXT text;
	IMAGE image;
	CONTACT contact;
	I_BUTTON i_button;
	T_BUTTON t_button;
	INPUT_FIELD input_field;
}DATA;

typedef struct {
	DATA data;
	int type;
	int id;

	INTERACTABLE interactable;
	ANCHORS *scrollable;

	struct CANVAS_ELEMENT *next;
}CANVAS_ELEMENT;

typedef struct {
	CANVAS_ELEMENT *elements;
}LAYER;

typedef struct {
	ANCHORS anchors;
	ALLEGRO_COLOR background;

	int nr_of_layers;
	LAYER *layers;
}CANVAS;