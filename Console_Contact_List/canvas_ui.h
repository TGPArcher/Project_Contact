#pragma once
#include <allegro5/allegro.h>

typedef struct {
	int x;
	int y;
}pos;

typedef struct {
	pos up_corner;
	pos size;
	ALLEGRO_COLOR color;
}rectangle;

typedef struct {
	pos up_corner;
	int size;
	ALLEGRO_COLOR color;
}text;

typedef struct {
	rectangle main_body;
	rectangle color_bar;
	text name_text;
	text number_text;
}contact;

typedef struct {
	int id;
	contact contact_element;

	contact_holder *next_element;
}contact_holder;

typedef struct {
	int id;
	text text_element;

	text_holder *next_element;
}text_holder;

typedef struct {
	int id;
	rectangle rectangle_element;

	rectangle_holder *next_element;
}rectangle_holder;

typedef struct {
	pos up_corner;
	pos down_corner;
	ALLEGRO_COLOR backgroud;

};