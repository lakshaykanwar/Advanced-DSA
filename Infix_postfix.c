#include <stdio.h>
#include <ctype.h>

#define max 100

char ar[max];
int top = -1;

void push(char ch) {
    ar[++top] = ch;
}

char pop() {
    return ar[top--];
}

int precedence(char ch) {
    switch(ch) {
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        case '^':
            return 3;

        default:
            return 0;
    }
}

int main() {
    char infix[max], postfix[max];
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for(i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if(isalnum(ch)) {
            postfix[j++] = ch;
        }
        else if(ch == '(') {
            push(ch);
        }
        else if(ch == ')') {
            while(top != -1 && ar[top] != '(') {
                postfix[j++] = pop();
            }
            pop();
        }
        else {
            while(top != -1 && ar[top] != '(' &&
                  precedence(ar[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while(top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}