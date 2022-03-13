#ifndef ZADANIE2_NODE_H
#define ZADANIE2_NODE_H

struct Node;
struct Node* append_front(struct Node*, int);
void append_back(struct Node**, int);
struct Node* drop_front(struct Node*);
void drop_back(struct Node**);
void display(struct Node*);
int get_element(struct Node**, int);
int get_size(struct Node**);
struct Node* merge(struct Node**, struct Node**);
void delete_list(struct Node**);

#endif //ZADANIE2_NODE_H
