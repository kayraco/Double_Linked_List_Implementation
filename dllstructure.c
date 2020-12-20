#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct Node {
    int data;
    struct Node *next;
    struct Node *previous;
} Node;

Node* create_dll_from_array(int array[], int size);
void print_dll(Node* head);
void insert_after(Node* head, int valueToInsertAfter, int valueToBeInserted);
void delete_element(Node* head, int valueToBeDeleted);
void sort_dll(Node* head);
void swap(Node* prev, Node* current);
void questionSix(Node* head);

Node* create_dll_from_array(int array[], int size){
    int i;
    Node *head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    head->previous = NULL;
    Node *current;
    Node *temp;
    current = head;

    if (size == 0){
        return head;
    }
    for ( i = 0; i < size; i++){
        temp = current;
        current->next = malloc(sizeof(Node));
        current = current->next;
        current->data = array[i];
        current->previous = temp;

        if (i == 0) {
            head = current;
        }
    }
    current = head;
    return head;
}

void print_dll(Node* head){
    Node* temp = head;
    while (temp != NULL) {

        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert_after(Node* head, int valueToInsertAfter, int valueToBeInserted){

    Node *add = (Node*)malloc(sizeof(Node));
    Node *temp = (Node*)malloc(sizeof(Node));

    add->data = valueToBeInserted;
    add->next = NULL;
    add->previous = NULL;
    temp = head;

    while (temp != NULL){
        if (temp->data == valueToInsertAfter) {
            add->next = temp->next;
            add->previous = temp->next->previous;
            temp->next->previous = add;
            temp->next = add;
            return;

        } else if (temp->data != valueToBeInserted && temp->next == NULL){
            temp->next = add;
            add->previous = temp;
            add->next = NULL;
            return;
        }
        temp = temp->next;
    }
    free(add);
    free(temp);
}

void delete_element(Node* head, int valueToBeDeleted){
    Node *temp = malloc(sizeof(Node));
    temp = head;
    int counter = 0;
    while (temp != NULL){
        counter++;
        temp = temp->next;
    }
    temp = head;
    if (counter == 1 && valueToBeDeleted == head->data){
        free(head);
        return;
    }
        while (temp != NULL){
            if (head->data == valueToBeDeleted){
                
                head->data = head->next->data;
                head->next = head->next->next;
                head->next->next->previous = head;
                return;
            }
            if (temp->data == valueToBeDeleted && temp->next != NULL && temp->previous !=NULL){

                temp->next->previous = temp->previous;
                temp->previous->next = temp->next;
                free(temp);
                return;
            }
            if (temp->data == valueToBeDeleted){
                
                temp->previous->next = NULL;
                free(temp);
                return;
            }
    temp = temp->next;
    }
    free(temp);
}

void sort_dll(Node* head){
    Node* ptr;
    Node* temp;
    ptr = head;
    while (ptr != NULL){
        temp = head;
        while (temp->next != NULL){
            if (temp->data > temp->next->data){
                swap(temp, temp->next);
            }
            temp = temp->next;
        }
        ptr = ptr->next;
    }
}

void swap(Node* prev, Node* current){
    int temp;
    temp = current->data;
    current->data = prev->data;
    prev->data = temp;   
}

void questionSix(Node* head){
    while (head->next != NULL){
        head = head->next;
        free(head->previous);
    }
}
int main(){
    int array[5] = {11, 2, 7, 22, 4};
    Node* head;
    /* Question 1 */
    head = create_dll_from_array(array, 5); //size of array is 5
    /* Question 2 */
    print_dll(head);
    /* Question 3 */
    // To insert 13 after the first occurence of 7
    insert_after(head, 7, 13);
    // To insert 29 after the first occurence of 21
    insert_after(head, 21, 29);
    print_dll(head);
    /* Question 4 */
    delete_element(head, 13);
    print_dll(head);
    delete_element(head, 11);
    print_dll(head);
    /* Question 5 */
    sort_dll(head);
    print_dll(head);
    /* Question 6 */
    questionSix(head);
    return 0;
}
