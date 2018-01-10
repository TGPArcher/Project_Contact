#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#pragma once

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

typedef union {
	RECTANGLE rectangle;
	LINE line;
	TEXT text;
	IMAGE image;
	CONTACT contact;
}DATA;

typedef struct {
	DATA data;
	int type;

	struct CANVAS_ELEMENT *next;
}CANVAS_ELEMENT;

typedef struct {
	ANCHORS anchors;

	CANVAS_ELEMENT *elements;
}CANVAS;