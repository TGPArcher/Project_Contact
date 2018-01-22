#include <allegro5/allegro.h>

extern void init_al();
extern void canvas_data_init();
extern void m_events_init();

int main() {
	init_al();
	canvas_data_init();
	m_events_init();

	return 0;
}