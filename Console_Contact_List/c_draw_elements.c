#include <stdlib.h>
#include "canvas_ui.h"
#include "c_manipulation.h"
#include "c_draw_elements.h"

void draw_rectangle(RECTANGLE rectangle) {
	al_draw_filled_rectangle(
		rectangle.anchors.upper.x,
		rectangle.anchors.upper.y,
		rectangle.anchors.lower.x,
		rectangle.anchors.lower.y,
		rectangle.color);
}

void draw_line(LINE line) {
	al_draw_line(
		line.anchors.upper.x,
		line.anchors.upper.y,
		line.anchors.lower.x,
		line.anchors.lower.y,
		line.color,
		line.size);
}

void draw_text(TEXT text) {
	al_draw_text(
		text.font,
		text.color,
		text.anchor.x,
		text.anchor.y,
		text.flags,
		text.text);
}

void draw_image(IMAGE image) {
	al_draw_bitmap(
		image.image,
		image.anchors.upper.x,
		image.anchors.upper.y,
		image.flags);
}

void draw_contact(CONTACT contact) {
	contact.main_body.anchors = recalculate_anchors(
		contact.main_body.anchors,
		contact.count);
	contact.min_body.anchors = recalculate_anchors(
		contact.min_body.anchors,
		contact.count);
	contact.name_text.anchor = recalculate_pos(
		contact.name_text.anchor,
		contact.main_body.anchors.upper.y);
	contact.number_text.anchor = recalculate_pos(
		contact.number_text.anchor,
		contact.main_body.anchors.upper.y);
	
	draw_rectangle(contact.main_body);

	draw_rectangle(contact.min_body);

	draw_text(contact.name_text);

	draw_text(contact.number_text);
}