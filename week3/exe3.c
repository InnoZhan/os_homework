#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
} list;

void print_list(list *my_list) {
    while (my_list->next != NULL) {
        printf("%d ", my_list->val);
        my_list = my_list->next;
    }
    printf("\n");
}

void insert_node(list *my_list, int pos, int val) {
    if (my_list != NULL) {
        list *temp = my_list;
        int i = 0;

        while ((i < pos) && (temp->next != NULL)) {
            temp = temp->next;
            i++;
        }

        list *new_node = NULL;
        new_node = malloc(sizeof(list));
        new_node->val = temp->val;
        new_node->next = temp->next;
        temp->next = new_node;
        temp->val = val;
    }
}

void delete_node(list *my_list, int pos) {
    list *temp = my_list;
    int i = 0;

    while ((i != pos) && (temp->next->next != NULL)) {
        temp = temp->next;
        i++;
    }
    list *temp2 = temp->next;

    temp->val = temp->next->val;
    temp->next = temp->next->next;
    free(temp2);
}

int main() {
    int n;
    list *my_list = NULL;
    my_list = malloc(sizeof(list));
    my_list->next = NULL;

    printf("Input number of items for list\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        printf("Input element number %d:\n", i);
        scanf("%d", &x);
        insert_node(my_list, i, x);
    }
    printf("\n");
    print_list(my_list);
    printf("Input number of the element to be deleted\n");
    scanf("%d", &n);
    delete_node(my_list, n);
    print_list(my_list);

    return 0;
}