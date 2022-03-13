#include <stdlib.h>
#include <printf.h>
#include "node.h"

struct Node {
    int head;
    struct Node* tail;
};

struct Node* append_front(struct Node* node, int value) {
    struct Node* pt = (struct Node*)malloc(sizeof(struct Node));

    pt->head = value;
    pt->tail = node;

    return pt;
}

void append_back(struct Node** node, int value) {
    struct Node* temp;
    struct Node* pt = (struct Node*)malloc(sizeof(struct Node));

    pt->head = value;
    pt->tail = NULL;

    if (*node == NULL) {
        *node = pt;
    } else {
        temp = *node;
        while (temp->tail != NULL) {
            temp = temp->tail;
        }
        temp->tail = pt;
    }
}

struct Node* drop_front(struct Node* node) {
    struct Node* pt;

    if (node == NULL) {
        pt = NULL;
    } else {
        pt = node->tail;
        free(node);
    }

    return pt;
}

int get_size(struct Node** node) {
    int counter = 0;
    struct Node* temp = *node;

    while (temp != NULL) {
        ++counter;
        temp = temp->tail;
    }

    return counter;
}

void drop_back(struct Node** node) {
    struct Node* temp;

    if (get_size(node) == 0) {
       //
    } else if (get_size(node) == 1) {
        *node = NULL;
    } else {
        temp = *node;
        while ((temp->tail)->tail != NULL) {
            temp = temp->tail;
        }
        free(temp->tail);
        temp->tail = NULL;
    }
}

int get_element(struct Node** node, int index) {
    int counter = 0;
    struct Node* temp;

    temp = *node;
    while (counter < index && temp->tail != NULL) {
        temp = temp->tail;
        ++counter;
    }

    if (counter == index) {
        return temp->head;
    } else {
        puts("Error! Element does not exist!");
        exit(EXIT_FAILURE);
    }
}


void display(struct Node* node) {
    while (node != NULL) {
        printf("%d\n", node->head);
        node = node->tail;
    }
    printf("\n");
}

struct Node* merge(struct Node** node1, struct Node** node2) {
    struct Node* temp;
    struct Node* pt;

    if (*node1 == NULL) {
        pt = *node2;
    } else {
        pt = *node1;
        temp = pt;

        while (temp->tail != NULL) {
            temp = temp->tail;
        }

        temp->tail = *node2;
    }

    return pt;
}

void delete_list(struct Node** node) {
    struct Node* temp;

    while (*node != NULL) {
        temp = (*node)->tail;
        free(*node);
        *node = temp;
    }
}
