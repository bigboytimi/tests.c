#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*
write a push function for a stack in a linked list
write a pop function for a stack in a linked list
write a peek function for a stack in a linked list
write a display function for a stack in a linked list
*/

typedef struct node {
    int data;
    struct node *next;
} stack_n;

stack_n *top = 0;

// push function
void push(int val){
    stack_n *newnode;
    newnode = malloc(sizeof(struct node));
    
    if (newnode == NULL){
        printf("Error allocating memory");
    }
    
    if (top == NULL){
        newnode -> data = val;
        newnode -> next = NULL;
        top = newnode;
    } 
    else{
        newnode -> data = val;
        newnode -> next = top;
        top = newnode;
    }
}


//display function
void display(){
    struct node *temp;
    temp == top;
    if (top == NULL){
        printf("Empty stack");
    }
    else{
        while(temp != NULL){
            printf("The elements in the stack include: %d\n", temp -> data);
            temp = temp -> next;  
        }
    }
}

//peek function

void peek(){
    if (top == NULL){
        printf("The stack is empty");
    }
    else{
        printf("The last number in the stack is: %d\n", top->data);
    }
    
}


//pop function
void pop(){
    int item;
    stack_n *pointer;
    if (top == NULL){
        printf("The stack is empty");
    }
    else{
      item = top->data;
      pointer = top;
      top = top->next;
      free(pointer);
      printf("The deleted item is: %d\n", item);
    }
}
//example function
void main(){
    push(8); //first element in
    push(9); //second element in
    push(10); //third element in
    display(); // display each element
    peek(); // display the last element added
    pop(); //delete and display the last element = 10
    pop(); //delete and display the second to the last element = 9
    pop(); //delete and display the first element = 8
    pop(); //make the stack empty.
}
