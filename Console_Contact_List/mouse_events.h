#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include "list.h"
#include "canvas_ui.h"
#include "c_init_elements.h"
#include "on_click.h"
#include "on_hover.h"
#include "on_scroll.h"

extern void save_contacts(list*);

void m_events_init();
void m_routine(ALLEGRO_EVENT_QUEUE*);
CANVAS_ELEMENT* raycast_canvas(POS);