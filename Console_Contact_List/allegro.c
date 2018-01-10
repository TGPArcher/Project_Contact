#include <stdlib.h>
#include <stdio.h>
#include "allegro5\allegro.h"
#include "allegro5\allegro_image.h"
#include "allegro5\allegro_font.h"
#include "allegro5\allegro_ttf.h"
#include "allegro5\allegro_primitives.h"
#include "canvas_ui.h"

typedef struct {
	int x;
	int y;
}pos;

void initializations();
void create_display(int, int, int, char*);
void cls(int, int, int);

void init_al() {
	initializations();

	create_display(500, 750, 1, "Contact list");

	cls(168, 168, 168);

	al_flip_display();
}

void initializations() {
	if (!al_init())
		fprintf(stderr, "could not load allegro!\n");

	if (!al_install_keyboard())
		fprintf(stderr, "could not instal keyboard!\n");

	if (!al_init_image_addon())
		fprintf(stderr, "could not load image addon\n");

	if (!al_init_font_addon())
		fprintf(stderr, "could not load font addon\n");

	if (!al_init_ttf_addon())
		fprintf(stderr, "could not load ttf addon");

	if (!al_init_primitives_addon())
		fprintf(stderr, "could not load primitives addon\n");
}

void create_display(int w, int h, int flag, char *title) {
	ALLEGRO_DISPLAY *display;

	al_set_new_display_flags(flag);
	al_set_new_window_title(title);

	if ((display = al_create_display(w, h)) == NULL)
		fprintf(stderr, "Could not create display\n");
}

// do it with a color parameter
void cls(int x, int y, int z) {
	al_clear_to_color(al_map_rgb(x, y, z));
}

//draw_contact(12, 110, "Sergiu", "068553218", NULL, NULL, NULL, NULL, 0);

/*void draw_contact(
	int x, int y,
	char *name, char *number, 
	ALLEGRO_COLOR *big_color, ALLEGRO_COLOR *small_color, ALLEGRO_COLOR *name_color, ALLEGRO_COLOR *number_color,
	int count) {
	
	static int init = 1;
	static ALLEGRO_FONT *contact_font;
	static ALLEGRO_COLOR _def_big_color;
	static ALLEGRO_COLOR _def_small_color;
	static ALLEGRO_COLOR _def_name_color;
	static ALLEGRO_COLOR _def_number_color;

	if (init) {
		contact_font = al_load_ttf_font("javatext.ttf", 25, NULL);
		_def_big_color = al_map_rgb(174, 174, 174);
		_def_small_color = al_map_rgb(120, 115, 130);
		_def_name_color = al_map_rgb(48, 48, 48);
		_def_number_color = al_map_rgb(88, 88, 88);
		init = 0;
	}

	static pos big_size = { .x = 476,.y = 100 };
	static pos small_size = { .x = 12,.y = 100 };
	static pos name_size = { .x = 22,.y = 10 };
	static pos number_size = { .x = 22,.y = 50 };

	y += (big_size.y + 11) * count;

	big_color == NULL ?
		al_draw_filled_rectangle(
			x, y,
			x + big_size.x, y + big_size.y,
			_def_big_color) :
		al_draw_filled_rectangle(
			x, y,
			x + big_size.x, y + big_size.y,
			*big_color);

	small_color == NULL ?
		al_draw_filled_rectangle(
			x, y,
			x + small_size.x, y + small_size.y,
			_def_small_color) :
		al_draw_filled_rectangle(
			x, y,
			x + small_size.x, y + small_size.y,
			*small_color);

	name_color == NULL ?
		al_draw_textf(contact_font, _def_name_color, x + name_size.x, y+name_size.y, NULL, "%s", name) :
		al_draw_textf(contact_font, *name_color, x + name_size.x, y + name_size.y, NULL, "%s", name);
	number_color == NULL ?
		al_draw_textf(contact_font, _def_number_color, x + number_size.x, y + number_size.y, NULL, "%s", number) :
		al_draw_textf(contact_font, *number_color, x + number_size.x, y + number_size.y, NULL, "%s", number);
}*/