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

	if (!al_install_mouse())
		fprintf(stderr, "could not install mouse\n");
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