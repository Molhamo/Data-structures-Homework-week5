#include <stdlib.h>
#include <stdio.h>

typedef struct stack{
    char bracket[15];
    int top;
}stack;

void initialize(stack *stk){
    stk->top=-1;
}

void push(stack *stk, char ch){
    if(stk->top>=15)
        printf("Stack is full");
    else{
        stk->top++;
        stk->bracket[stk->top]=ch;
    }
}

char pop(stack *stk){
    if(stk->top==-1)
        return;
    else{
        stk->top--;
        return stk->bracket[(stk->top)+1];
    }
}

void main(){
    char ch;
    stack stk;
    int err=0;
    initialize(&stk);
    FILE *txt=fopen("code.txt", "r");
    while((ch=fgetc(txt))!=EOF){
        if(ch=='(' || ch=='[' || ch=='{')
            push(&stk, ch);
        else{
            switch(ch){
                case ')':
                    if(pop(&stk)=='(')
                        continue;
                    else{
                        printf("unopened '()' parentheses\n");
                        err++;
                    }
                    break;
                case ']':
                    if(pop(&stk)=='[')
                        continue;
                    else{
                        printf("unopened '[]' parentheses\n");
                        err++;
                    }
                    break;
                case '}' :
                    if(pop(&stk)=='{')
                        continue;
                    else{
                        printf("unopened '{}' parentheses\n");
                        err++;
                    }
                    break;
            }
        }
        if(err==1)
            break;
    }
    fclose(txt);
}