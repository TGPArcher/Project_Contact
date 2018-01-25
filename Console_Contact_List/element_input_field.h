#pragma once
#include "list.h"
#include "canvas_ui.h"
#include <string.h>
#include <stdio.h>

extern void draw_active_page();

void input_to_field(CANVAS_ELEMENT*);
char* move_from_field(char[21]);
void add_letter(char[21], char);
void remove_letter(char[21]);