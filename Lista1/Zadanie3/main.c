#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "node.h"

int main() {
    struct Node* head0 = NULL;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct Node* head3;
    int value;
    double avg_time;
    int index;
    clock_t c_time;

    srandom(time(NULL));

    for (int i = 0; i < 1000; ++i) {
        head0 = append_back(head0, random());
    }

    for (int i = 0; i < 5; ++i) {
        avg_time = 0.0;
        index = random() % get_size(&head0);
        printf("Sredni czas dostepu do elementu numer %d: ", index);

        for (int j = 0; j < 20000; ++j) {
            c_time = clock();
            get_element(head0, index);
            c_time = clock() - c_time;

            avg_time += ((double) c_time) / CLOCKS_PER_SEC ;
        }
        avg_time /= 20000;
        printf("%f\n", avg_time);
    }

    avg_time = 0.0;
    printf("Sredni czas dostepu do losowego elementu: ");
    for (int j = 0; j < 20000; ++j) {
        c_time = clock();
        get_element(head0, random() % get_size(&head0));
        c_time = clock() - c_time;

        avg_time += ((double) c_time) / CLOCKS_PER_SEC ;
    }
    avg_time /= 20000;
    printf("%f\n", avg_time);


    printf("\nPrzyklad laczenia dwoch list:");

    printf("\nPierwsza lista:\n");
    for (int i = 0; i < 4; ++i) {
        value = random() % 100;
        head1 = append_back(head1, value);
        printf(" - %d", value);
    }
    value = random() % 100;
    head1 = append_back(head1, value);
    printf(" - %d - ", value);

    printf("\nDruga lista:\n");
    for (int i = 0; i < 3; ++i) {
        value = random() % 100;
        head2 = append_back(head2, value);
        printf(" - %d", value);
    }
    value = random() % 100;
    head2 = append_back(head2, value);
    printf(" - %d - ", value);

    head3 = merge(&head1, &head2);

    printf("\nPolaczona lista:\n");
    for (int i = 0; i < get_size(&head3) - 1; ++i) {
        printf(" - %d", get_element(head3, i));
    }
    printf(" - %d - ", get_element(head3, get_size(&head3) - 1));

    return 0;
}
