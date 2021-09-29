#include <iostream>

typedef struct list{
int item;
struct list *next;
}
list;

void push(list** l, int item){
    list *node = (list*)malloc(sizeof(list));
    node->item = item;
    node->next = *l;
    *l =  node;
}
void reverse_list(list **l){
    list *prev = NULL;
    list *next = NULL;
    list *current = *l;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;

    }
    *l = prev;

}

void printList(list *l){
    while (l != NULL)
    {
        std::cout<<l->item<<" ";
        l=l->next;

    }
     std::cout<<std::endl;
    
}
int main(){
    list *head = NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    push(&head,5);

    printList(head);
    reverse_list(&head);
    printList(head);
    reverse_list(&head);

}