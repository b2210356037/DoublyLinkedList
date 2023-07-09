#include <iostream>
// doubly linkedlist introduction playground
struct n {
    int x;
    n* next;
    n* prev;
};
typedef n node;

void print(node* r) {
    node* iter = r;
    printf("%d\n", iter->x);
    iter = iter->next;
    while (iter != NULL)
    {
        printf("%d\n", iter->x);
        iter = iter->next;
    }
}


node* addAscend(node* r, int x) {
    if (r == NULL) { //if linkedlist is empty
        r = (node*)malloc(sizeof(node));
        r->next = NULL;
        r->prev = NULL;
        r->x = x;
        return r;
    }
    if (r->x > x) { //if smaller than 1. value
        node* temp = (node*)malloc(sizeof(node*));
        temp->x = x;
        temp->next = r;
        temp->prev = NULL;
        r->prev = temp;
        return temp;
    }
    node* iter = r;
    while (iter->next != NULL && iter->next->x < x) {
        iter = iter->next;
    }
    node* temp = (node*)malloc(sizeof(node));
    temp->next = iter->next;
    iter->next = temp;
    temp->prev = iter;
    if(temp -> next != NULL){
        temp->next->prev = temp;
    }
    temp->x = x;
    return r;
}

node* remove(node* r, int x) {
    node* temp;
    node* iter = r;

    if (r->x == x)
    {
        temp = r;
        r = r->next;
        free(temp);
        return r;
    }
    while (iter->next != NULL && iter->next->x != x)
    {
        iter = iter->next;
    }
    if (iter->next == NULL) {
        printf("The integer: %d has not found\n", x);
        return r;
    }
    temp = iter->next;
    iter->next = iter->next->next;
    free(temp);
    if (iter->next != NULL) {
        iter->next->prev = iter;
    }
    return r;
}

int main() {
    node* root;
    root = NULL;

    root = addAscend(root, 15);
    root = addAscend(root, 10);
    root = addAscend(root, 35);
    root = addAscend(root, 20);
    root = remove(root, 20);
    root = addAscend(root, -10);
    root = remove(root, 999);
    root = addAscend(root, 1450);

    printf("root: %d\n", root->x);
    print(root);

}