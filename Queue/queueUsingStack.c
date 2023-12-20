#include <stdbool.h>
typedef struct{
    int arr[100];
    int top;
} MyStack;


void createStack(MyStack* s){
    s->top=-1;
}
bool isEmpty(MyStack* s){
    return (s->top == -1);
}
void push(MyStack* s,int d){
    if(s->top==99) return;
    s->arr[++s->top]=d;
}
int pop(MyStack* s){
    if(isEmpty(s)) return -1;
    int val=s->arr[s->top];
    s->top--;
    return val;
}
int peek(MyStack* s){
    if(isEmpty(s)) return -1;
    return s->arr[s->top];
}

typedef struct {
    MyStack* s1;
    MyStack* s2;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    if (obj == NULL) {
        // Handle memory allocation failure
        exit(EXIT_FAILURE);
    }
    obj->s1 = (MyStack*)malloc(sizeof(MyStack));
    obj->s2 = (MyStack*)malloc(sizeof(MyStack));
    createStack(obj->s1);
    createStack(obj->s2);
    return obj;
}

bool myQueueEmpty(MyQueue* obj) {
    return isEmpty(obj->s1);
}

void myQueuePush(MyQueue* obj, int x) {
    if(obj->s1->top==99) return;
    while(!isEmpty(obj->s1)){
        push(obj->s2,pop(obj->s1));
    }
    push(obj->s1,x);
    while(!isEmpty(obj->s2)){
        push(obj->s1,pop(obj->s2));
    }
}

int myQueuePop(MyQueue* obj) {
    return pop(obj->s1);
}

int myQueuePeek(MyQueue* obj) {
    return peek(obj->s1);
}

void myQueueFree(MyQueue* obj) {
    free(obj->s1);
    free(obj->s2);
    free(obj);
}
