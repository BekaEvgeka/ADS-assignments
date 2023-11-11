#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_size 10

typedef struct{
    int stack_array[max_size];
    int top;
}stack;

int isempty (stack * stck);
int isfull  (stack * stck);
int peek    (stack * stck);
int pop     (stack * stck);
int push    (stack * stck, int to_push);

int main(){

    stack *stack1Ptr, stck1;
    stack *stack2Ptr, stck2;
    stack1Ptr = &stck1;
    stack2Ptr = &stck2;
    stack1Ptr->top = -1;
    stack2Ptr->top = -1;

    push(stack1Ptr, 9999);
    push(stack1Ptr, 2021);
    push(stack1Ptr, 453);
    push(stack1Ptr, 1000);
    push(stack1Ptr, 1488);
    push(stack1Ptr, 1337);
    push(stack1Ptr, 448);
    push(stack1Ptr, 444);
    push(stack1Ptr, 555);
    push(stack1Ptr, 888);
    printf("Top element: %d\n",peek(stack1Ptr));

    int minelement = peek(stack1Ptr);
    int *pminelement = &minelement;
    // printf("(Points to: %p\nValue: %d)\n",pminelement, *pminelement);
    // printf("Elements: \n");

    while(!isempty(stack1Ptr)) {
      int data = pop(stack1Ptr);  
    //   printf("Popped from stack 1: %d\n",data);        
      if (data < minelement){
        *pminelement = data;
      }
      push(stack2Ptr, data); 
    //   printf("Pushed to stack 2: %d\n",data);
   }
    printf("Minelement in stack : %d\n",*pminelement);
    // printf("Minelement in stack : %d\n",*pminelement);

    while(!isempty(stack2Ptr)){
        int data = pop(stack2Ptr);
        if (data == *pminelement){
            int minimalelement = 234;
            push(stack1Ptr, minimalelement);
        }
        else{
            push(stack1Ptr, data);
        }
    }
    printf("Peek of stack1: %d\n",peek(stack1Ptr));

    while(!isempty(stack1Ptr)){
        int data = pop(stack1Ptr);
        printf("Element in stack: %d\n",data);
    }
}


int isempty(stack * stck){
    if (stck->top == -1)
        return 1;
    else
        return 0;
}

int isfull(stack * stck){
    if (stck->top==max_size)
        return 1;
    else
        return 0;
}

int peek(stack * stck){
    return stck->stack_array[stck->top];
}

int pop(stack * stck){
    int topop;
    if(!isempty(stck)){
        topop = stck->stack_array[stck->top];
        stck->top = stck->top - 1;
        return topop;
    }
    else
        printf("Stack is empty\n");
}

int push(stack * stck, int topush){
    if (!isfull(stck)){
        stck->top = stck->top + 1;
        stck->stack_array[stck->top] = topush;

    }
    else
        printf("Stack is full\n");
}