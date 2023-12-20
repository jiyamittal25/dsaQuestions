#include<stdbool.h>
#include<string.h>

typedef struct {
    char ch[10000];
    int top;
}MyStack;

void createStack(MyStack* s){
    s->top=-1;
}
bool isEmpty(MyStack* s){
    return (s->top==-1);
}
void push(MyStack* s,char val){
    s->top++;
    s->ch[s->top]=val;
}
char pop(MyStack* s){
    if(isEmpty(s)) return '\0'; 
    char val=s->ch[s->top];
    s->top--;
    return val;
}
char peek(MyStack* s){
    if(isEmpty(s)) return '\0'; 
    return s->ch[s->top];
}
char* removeDuplicateLetters(char* s) {
    int freq[26] = {0};
    int n=strlen(s);
    unsigned char visited[26] = {0};
    for(int i=0;i<n;i++){
        freq[s[i]-'a']++;
    }
    // for(int i=0;i<26;i++){
    //     printf("%d ",freq[i]);
    // }
    MyStack* st=(MyStack*)malloc(sizeof(MyStack));
    createStack(st);
    MyStack* st1=(MyStack*)malloc(sizeof(MyStack));
    createStack(st1);
    push(st,s[0]);
    freq[s[0]-'a']--;
    visited[s[0]-'a']=1;
    for(int i=1;i<n;i++){
        if (visited[s[i]-'a']) {
            freq[s[i]-'a']--;
            continue;
        }
        while(!isEmpty(st) && peek(st)>s[i] && freq[peek(st)-'a']>0){
            char ch=peek(st);
            pop(st);
            visited[ch-'a']=0;
        }
        push(st,s[i]);
        visited[s[i]-'a']=1;
        freq[s[i]-'a']--;
    }
    
    int c=0;
    while(!isEmpty(st)){
        push(st1,pop(st));
        c++;
    }
    char* arr=(char*)malloc((c+1)*(sizeof(char)));
    int i = 0;
    while (!isEmpty(st1)) {
        arr[i] = pop(st1);
        i++;
    }
    arr[i] = '\0';
    return arr;
}
