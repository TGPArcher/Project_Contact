#include "c_init_elements.h"

POS create_pos(int x, int y) {
	return (POS) { .x = x, .y = y };
}

ANCHORS create_anchors(POS up, POS low) {
	return (ANCHORS) { .upper = up, .lower = low };
}

RECTANGLE create_rectangle(ANCHORS anchors, ALLEGRO_COLOR color) {
	return (RECTANGLE) { .anchors = anchors, .color = color };
}

LINE create_line(ANCHORS anchors, ALLEGRO_COLOR color, int size) {
	return (LINE) { .anchors = anchors, .color = color, .size = size };
}

TEXT create_text(ALLEGRO_FONT *font, POS anchor, ALLEGRO_COLOR color, int flags, char *text) {
	return (TEXT) { .font = font, .anchor = anchor, .color = color, .flags = flags, .text = text };
}

IMAGE create_image(ALLEGRO_BITMAP *image, ANCHORS anchors, int flags) {
	return (IMAGE) { .image = image, .anchors = anchors, .flags = flags };
}

CONTACT create_contact(RECTANGLE main_body, RECTANGLE color_body, TEXT name_text, TEXT number_text, int count) {
	return (CONTACT) { .main_body = main_body, .min_body = color_body, .name_text = name_text, .number_text = number_text, .count = count };
}

DATA create_r_data(RECTANGLE rectangle) {
	return (DATA) { .rectangle = rectangle };
}

DATA create_l_data(LINE line) {
	return (DATA) { .line = line };
}

DATA create_t_data(TEXT text) {
	return (DATA) { .text = text };
}

DATA create_i_data(IMAGE image) {
	return (DATA) { .image = image };
}

DATA create_c_data(CONTACT contact) {
	return(DATA) { .contact = contact };
}

CANVAS_ELEMENT* create_canvas_element(DATA data, int type) {
	CANVAS_ELEMENT *new_element = (CANVAS_ELEMENT*)malloc(sizeof(CANVAS_ELEMENT));

	new_element->type = type;
	new_element->data = data;
	new_element->next = NULL;

	return new_element;
}

CANVAS_ELEMENT* e_init_rectangle(
	int x1, int y1, int x2, int y2,
	ALLEGRO_COLOR color) 
{
	CANVAS_ELEMENT *element = create_canvas_element(
		create_r_data(
			create_rectangle(
				create_anchors(create_pos(x1, y1), create_pos(x2, y2)),
				color)),
		0);

	return element;
}

CANVAS_ELEMENT* e_init_line(
	int x1, int y1, int x2, int y2,
	ALLEGRO_COLOR color,
	int thickness)
{
	CANVAS_ELEMENT *element = create_canvas_element(
		create_l_data(
			create_line(
				create_anchors(create_pos(x1, y1), create_pos(x2, y2)),
				color,
				thickness)),
		1);

	return element;
}

CANVAS_ELEMENT* e_init_image(
	char *name,
	int x, int y, int w, int h,
	int flags)
{
	CANVAS_ELEMENT *element = create_canvas_element(
		create_i_data(
			create_image(
				al_load_bitmap(name),
				create_anchors(create_pos(x, y), create_pos(w, h)),
				flags)),
		3);

	return element;
}

CANVAS_ELEMENT* e_init_text(
	char *font_name, int font_size,
	int x, int y,
	ALLEGRO_COLOR color,
	int flags, char *text)
{
	CANVAS_ELEMENT *element = create_canvas_element(
		create_t_data(
			create_text(
				al_load_ttf_font(font_name, font_size, NULL),
				create_pos(x, y),
				color,
				flags,
				text)),
		2);

	return element;
}

CANVAS_ELEMENT* e_init_contact(
	POS M, POS name_pos, POS nr_pos,
	ALLEGRO_COLOR M_color, ALLEGRO_COLOR m_color, ALLEGRO_COLOR name_color, ALLEGRO_COLOR nr_color,
	char *name, char *number,
	int count)
{
	static POS main_size = { .x = 475,.y = 100 };
	static POS min_size = { .x = 12,.y = 100 };

	CANVAS_ELEMENT *element = create_canvas_element(
		create_c_data(
			create_contact(
				create_rectangle(
					create_anchors(create_pos(M.x, M.y), create_pos(M.x + main_size.x, M.y + main_size.y)),
					M_color),
				create_rectangle(
					create_anchors(create_pos(M.x, M.y), create_pos(M.x + min_size.x, M.y + min_size.y)),
					m_color),
				create_text(
					al_load_ttf_font("javatext.ttf", 25, NULL),
					create_pos(name_pos.x, name_pos.y),
					name_color,
					NULL,
					name),
				create_text(
					al_load_ttf_font("javatext.ttf", 25, NULL),
					create_pos(nr_pos.x, nr_pos.y),
					nr_color,
					NULL,
					number),
				count)),
		4);

	return element;
}