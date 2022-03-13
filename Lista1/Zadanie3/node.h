#ifndef ZADANIE3_NODE_H
#define ZADANIE3_NODE_H

struct Node;
int get_size(struct Node**);
struct Node* append_front(struct Node*, int);
struct Node* append_back(struct Node*, int);
struct Node* drop_front(struct Node*);
struct Node* drop_back(struct Node*);
void display(struct Node*);
int get_element(struct Node*, int);
struct Node* merge(struct Node**, struct Node**);

#endif //ZADANIE3_NODE_H
