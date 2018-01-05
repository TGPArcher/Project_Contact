#pragma once

struct Node {
	int id;
	char name[21];
	char phone_nr[11];

	struct Node *next_node;
	struct Node *prev_node;
};

typedef struct {
	struct Node *first;
	struct Node *last;
}list;