#include <string.h>
bool isValid(char* s){
    char arr[strlen(s)];
    int top=-1;
    int n=strlen(s);
    for(int i=0;i<n;i++){
        if((s[i]==')' || s[i]=='}' || s[i]==']') && top==-1 ) return false;
        if((s[i]==')' && arr[top]!='(') || (s[i]=='}' && arr[top]!='{') || (s[i]==']' && arr[top]!='['))  return false;
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') {
            arr[++top]=s[i];
        }
        else{
            top--;
        }
    }
    return (top==-1);
}
