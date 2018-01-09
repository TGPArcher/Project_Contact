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
void create_display();
void cls();
void draw_contact(int, int, char*, char*, ALLEGRO_COLOR*, ALLEGRO_COLOR*, ALLEGRO_COLOR*, ALLEGRO_COLOR*, int);

void a_main() {
	initializations();

	create_display();

	cls();

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

void create_display() {
	ALLEGRO_DISPLAY *display;

	al_set_new_display_flags(ALLEGRO_WINDOWED);
	al_set_new_window_title("Contact list");

	if ((display = al_create_display(500, 750)) == NULL)
		fprintf(stderr, "Could not create display\n");
}

// do it with a color parameter
void cls() {
	al_clear_to_color(al_map_rgb(168, 168, 168));
}

/*void display_page() {

	al_draw_filled_rectangle(
		0, 0,
		500, 100,
		al_map_rgb(145, 56, 60));
	

	al_draw_filled_rectangle(
		0, 705,
		500, 750,
		al_map_rgb(145, 56, 60));

	al_draw_line(
		20, 69,
		406, 69,
		al_map_rgb(0, 0, 0),
		2);

	ALLEGRO_BITMAP *add_button = al_load_bitmap("add_button.png");
	al_draw_bitmap(add_button, 380, 630, NULL);

	ALLEGRO_FONT *title_font = al_load_ttf_font("javatext.ttf", 50, NULL);

	al_draw_text(title_font, al_map_rgb(0, 0, 0), 30, 0, NULL, "CONTACTS");

	ALLEGRO_BITMAP *search_button = al_load_bitmap("search_button.png");
	al_draw_bitmap(search_button, 406, 0, NULL);

	//draw_contact(12, 110, "Sergiu", "068553218", NULL, NULL, NULL, NULL, 0);
}*/

void draw_contact(
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
}

void lf_main() {

	al_clear_to_color(al_map_rgb(207, 236, 247));

	ALLEGRO_BITMAP *search_image = al_load_bitmap("search_icon.png");
	al_draw_bitmap(search_image, 0, 0, NULL);


	ALLEGRO_EVENT_QUEUE *a_event;
	if ((a_event = al_create_event_queue()) == NULL)
		fprintf(stderr, "could not create an event queue!\n");

	ALLEGRO_EVENT_SOURCE *a_event_source;
	if ((a_event_source = al_get_keyboard_event_source()) == NULL)
		fprintf(stderr, "could not get keyboard event source. keyboard was not installed!\n");

	al_register_event_source(a_event, a_event_source);
	ALLEGRO_EVENT _e;

	ALLEGRO_FONT *a_font;
	if ((a_font = al_create_builtin_font()) == NULL)
		fprintf(stderr, "could not load font\n");
	
	while (1) {
		al_wait_for_event(a_event, &_e);

		if (_e.type == ALLEGRO_EVENT_KEY_CHAR) {
			if (_e.keyboard.unichar == 'a')
				al_flip_display();
			else if (_e.keyboard.unichar == 'w')
				al_draw_textf(a_font, al_map_rgb(65, 65, 65), 300, 50, ALLEGRO_ALIGN_CENTER, "Number of contacts %d", 5);
			else if (_e.keyboard.unichar == 'c') {
				al_draw_filled_circle(275, 500, 50, al_map_rgba(63, 205, 103, 100));
				al_draw_filled_circle(225, 500, 50, al_map_rgba(84, 155, 46, 175));
			}
			else if (_e.keyboard.unichar == 'q')
				break;
		}
	}
}