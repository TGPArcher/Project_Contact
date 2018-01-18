#pragma once
#include "canvas_ui.h"

void m_events_init(CANVAS*);
void m_routine(ALLEGRO_EVENT_QUEUE*, CANVAS*);
void on_click(ALLEGRO_EVENT, CANVAS*);
void on_hover(ALLEGRO_EVENT, CANVAS*);
void on_scroll(ALLEGRO_EVENT, CANVAS*);

ALLEGRO_COLOR get_element_color(CANVAS_ELEMENT*);
void hover_effect(CANVAS_ELEMENT*, ALLEGRO_COLOR);