#include <stdbool.h>
#include <string.h>

typedef struct{
    int arr[30001];
    int top;
}MyStack;

void createStack(MyStack* s){
    s->top=-1;
}
bool isEmpty(MyStack* s){
    return (s->top==-1);
}
void push(MyStack* s,int val){
    s->top++;
    s->arr[s->top]=val;
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

int longestValidParentheses(char* s) {
    int length=0;
    int i=0;
    int n=strlen(s);
    MyStack* st=(MyStack*)malloc(sizeof(MyStack));
    createStack(st);
    push(st,-1);
    while(i<n){
        if(s[i]==')'){
            pop(st);
            if(isEmpty(st)){
                push(st,i);
            }
            else{
                int c=i-peek(st);
                if(c>length){
                    length=c;
                }
            }
        }
        else{
            push(st,i);
        }
        i++;
    }
    return length;
}
