#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int top;
    int arr[100];
}MyStack;

void createStack(MyStack* s){
    s->top=-1;
}
bool isEmpty(MyStack* s){
    return s->top==-1;
}
void push(MyStack* s,int val){
    if(s->top==99) return;
    s->top++;
    s->arr[s->top]=val;
}
int pop(MyStack* s){
    if(isEmpty(s)) return -1;
    int val= s->arr[s->top];
    s->top--;
    return val;
}
int peek(MyStack* s){
    if(isEmpty(s)) return -1;
    return s->arr[s->top];
}

int postfix(char* str){
    MyStack* st=(MyStack*)malloc(sizeof(MyStack));
    createStack(st);
    int i=0;
    while(str[i]!='?'){
        if(!(str[i]>='0' && str[i]<='9')){
            if(str[i]==' '){
                i++;
                continue;
            }
            int val1=pop(st);
            int val2=pop(st);
            if(str[i]=='+'){
                push(st,val2+val1);
            }
            else if(str[i]=='-'){
                push(st,val2-val1);
            }
            else if(str[i]=='*'){
                push(st,val2*val1);
            }
            else if(str[i]=='/'){
                push(st,val2/val1);
            }
        }
        else{
            int val=0;
            while(str[i]!=' '){
                val=val*10+(str[i]-'0');
                i++;
            }
            push(st,val);
        }
        i++;
    }
    return peek(st);
}


int main() {
    int ans=postfix("2 43 12 * + 12 + ? ");
    printf("%d\n",ans);
    return 0;
}

