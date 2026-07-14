#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

int main(){
    struct Node n1, n2, n3;
    
    n1.data = 10;
    n2.data = 20;
    n3.data = 30;

    n1.next = &n2;
    n2.next = &n3;
    n3.next = NULL;

    struct Node *ptr = &n1; 
    
    printf("Start:\n");
    while (ptr != NULL) {
        printf("Current node data: %d, Address: %p\n", ptr->data, (void *)ptr);
        ptr = ptr->next; 
    }
    printf("Reached the end (NULL)\n");

    return 0;
}

