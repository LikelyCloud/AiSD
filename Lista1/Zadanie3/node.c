#include <stdlib.h>
#include <printf.h>
#include "node.h"

struct Node {
    int value;
    struct Node* previous;
    struct Node* next;
};

struct Node* append_front(struct Node* node, int value) {
    struct Node* pt = (struct Node*)malloc(sizeof(struct Node));

    pt->value = value;

    if (get_size(&node) == 0) {
        pt->previous = pt;
        pt->next = pt;
        free(node);
    } else {
        pt->previous = node->previous;
        pt->next = node;
        (node->previous)->next = pt;
        node->previous = pt;
    }

    return pt;
}

struct Node* append_back(struct Node* node, int value) {
    struct Node* pt = (struct Node*)malloc(sizeof(struct Node));

    if (get_size(&node) == 0) {
        pt->value = value;
        pt->previous = pt;
        pt->next = pt;
        free(node);
        return pt;
    } else {
        pt = append_front(node, value);
        return pt->next;
    }
}

struct Node* drop_front(struct Node* node) {
    struct Node* pt;

    if (get_size(&node) == 0) {
        pt = NULL;
    } else {
        pt = node->next;
        pt->previous = node->previous;
        (node->previous)->next = pt;
        free(node);
    }

    return pt;
}

struct Node* drop_back(struct Node* node) {
    struct Node* pt;

    if (get_size(&node) == 0) {
        pt = NULL;
    } else {
        pt = drop_front(node->previous);
    }

    return pt;
}

void display(struct Node* node) {
    struct Node* first = node;

    if (get_size(&node) > 0) {
        printf("%d\n", node->value);
        node = node->next;

        while (node != first) {
            printf("%d\n", node->value);
            node = node->next;
        }
    }
    printf("\n");
}

int get_size(struct Node** node) {
    int counter;
    struct Node* temp;
    struct Node* first;

    if (*node == NULL) {
        return 0;
    }

    counter = 1;
    first = *node;
    temp = (*node)->next;

    while (temp != first) {
        ++counter;
        temp = temp->next;
    }

    return counter;
}

int get_element(struct Node* node, int index) {
    int counter = 0;
    struct Node* temp;

    index %= get_size(&node);
    temp = node;
    while (counter < index && (temp->next != node || counter == 0)) {
        temp = temp->next;
        ++counter;
    }

    if (counter == index) {
        return temp->value;
    } else {
        puts("Error! Element does not exist!");
        exit(EXIT_FAILURE);
    }
}

struct Node* merge(struct Node** node1, struct Node** node2) {
    struct Node* pt;
    struct Node* temp1;
    struct Node* temp2;

    if (*node1 == NULL) {
        pt = *node2;
    } else if (*node2 == NULL) {
        pt = *node1;
    } else {
        pt = *node1;

        temp1 = pt->previous;
        temp2 = (*node2)->previous;
        (pt->previous)->next = *node2;
        (*node2)->previous = temp1;
        pt->previous = temp2;
        (temp2)->next = pt;
    }

    return pt;
}
