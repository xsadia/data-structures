#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int value;
	struct Node *next;
} Node;

void append(Node* tail, int value);
void prepend(Node** head, int value);
int insert_middle_rec(Node* prev, int position, int current_position, int value);
Node* get_last_node(Node* node);
int list_size(Node* head);
int* to_array(Node* head);
void print_list(Node* head);

int main() 
{
	Node* head = (Node*) malloc(sizeof(Node*));
	head->value = 1;

	for (int i = 2; i <= 10; i++)
	{
		append(get_last_node(head), i);
	}
	prepend(&head, 11);
	insert_middle_rec(head, 4, 0, 12);

	printf("List size: %d\n", list_size(head));

	Node* curr = head;

	int* ls_array = to_array(head);

	printf("List as array: [ ");

	for(int i = 0; i < list_size(head); i++)
	{
		printf("%d ", ls_array[i]);
	}

	printf("]\n");

	print_list(head);

	return 0;
}

void append(Node* tail, int value) 
{
	Node* new_node = (Node*) malloc(sizeof(Node*));
	new_node->value = value;
	new_node->next = NULL;
	tail->next = new_node;
}

void prepend(Node** head, int value)
{
	Node* new_node = (Node*) malloc(sizeof(Node*));
	new_node->value = value;
	new_node->next = *head;
	*head = new_node;
}

int insert_middle_rec(Node* prev, int position, int current_position, int value)
{
	if(prev->next == NULL) return -1;

	if(current_position == position) 
	{
		Node* new_node = (Node*) malloc(sizeof(Node*));
		new_node->value = value;
		new_node->next = prev->next;
		prev->next = new_node;

		return 0;
	}

	return insert_middle_rec(prev->next, position, current_position + 1, value);
}

Node* get_last_node(Node* node) 
{
	if(node->next == NULL) return node;

	return get_last_node(node->next);
}

int list_size(Node* head)
{
	int size = 0;
	Node* curr = head;

	while(curr != NULL)
	{
		size++;
		curr = curr->next;
	}

	return size;
}

int* to_array(Node* head)
{
	int size = list_size(head);
	int* list = malloc(size);
	
	Node* curr = head;
	for(int i = 0; i < size; i++)
	{
		list[i] = curr->value;
		curr = curr->next;
	}

	return list;
}

void print_list(Node* head)
{
	Node* curr = head;
	while(curr != NULL)
	{
		printf("%d -> ", curr->value);
		curr = curr->next;
	}

	printf("NULL\n");

	return;
}