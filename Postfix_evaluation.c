#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push element onto stack
void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow!\n");
        exit(1);
    }
    stack[++top] = value;
}

// Pop element from stack
int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return stack[top--];
}

int main()
{
    char postfix[MAX];
    int i, op1, op2, result;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for (i = 0; postfix[i] != '\0'; i++)
    {
        char ch = postfix[i];

        if (isdigit(ch))
        {
            push(ch - '0');
        }
        else
        {
            op2 = pop();
            op1 = pop();

            switch (ch)
            {
                case '+':
                    result = op1 + op2;
                    break;

                case '-':
                    result = op1 - op2;
                    break;

                case '*':
                    result = op1 * op2;
                    break;

                case '/':
                    if (op2 == 0)
                    {
                        printf("Error: Division by zero!\n");
                        return 1;
                    }
                    result = op1 / op2;
                    break;

                case '^':
                    result = 1;
                    while (op2 > 0)
                    {
                        result *= op1;
                        op2--;
                    }
                    break;

                default:
                    printf("Error: Invalid operator '%c'\n", ch);
                    return 1;
            }

            push(result);
        }
    }

    if (top != 0)
    {
        printf("Invalid postfix expression!\n");
        return 1;
    }

    printf("Result = %d\n", pop());

    return 0;
}