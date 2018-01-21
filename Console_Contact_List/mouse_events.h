#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "canvas_ui.h"
#include "list.h"
#include "c_init_elements.h"
#include "c_manipulation.h"

extern void save_contacts(list*);

void m_events_init();
void m_routine(ALLEGRO_EVENT_QUEUE*);
CANVAS_ELEMENT* raycast_canvas(POS);