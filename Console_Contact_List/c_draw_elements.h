#pragma once

#include "allegro5\allegro.h"
#include "allegro5\allegro_image.h"
#include "allegro5\allegro_font.h"
#include "allegro5\allegro_ttf.h"
#include "allegro5\allegro_primitives.h"

#include "canvas_ui.h"

void draw_rectangle(RECTANGLE rectangle);
void draw_line(LINE line);
void draw_text(TEXT text);
void draw_image(IMAGE image);
void draw_contact(CONTACT contact);
void draw_ibutton(I_BUTTON i_button);
void draw_ifield(INPUT_FIELD input_field);