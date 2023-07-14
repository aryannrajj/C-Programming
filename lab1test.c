#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Size 20

int precedence(char operator)
{
    switch (operator)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

char *infixToPostfix(char *infix)
{
    int i, j;
    int len = strlen(infix);
    char *postfix = (char *)malloc(sizeof(char) * (len + 2));
    char stack[Size];
    int top = -1;

    for (i = 0, j = 0; i < len; i++)
    {
        if (infix[i] == ' ' || infix[i] == '\t')
            continue;
        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
            postfix[j] = '\0';
            printf("%s\n", postfix);
        }
        else if (infix[i] == '(')
        {
            stack[++top] = infix[i];
        }
        else if (infix[i] == ')')
        {
            while (top > -1 && stack[top] != '(')
            {
                postfix[j++] = stack[top--];
                postfix[j] = '\0';
                printf("%s\n", postfix);
            }
            if (top > -1 && stack[top] != '(')
                return "Invalid Expression";
            else
                top--;
        }
        else if (isOperator(infix[i]))
        {
            while (top > -1 && precedence(stack[top]) >= precedence(infix[i]))
            {
                postfix[j++] = stack[top--];
                postfix[j] = '\0';
                printf("%s\n", postfix);
            }
            stack[++top] = infix[i];
        }
    }
    while (top > -1)
    {
        postfix[j++] = stack[top--];
        postfix[j] = '\0';
        printf("%s\n", postfix);
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char infix[Size];
    printf("Enter an infix expression: ");
    gets(infix);
    char *postfix = infixToPostfix(infix);
    printf("Postfix expression: %s\n\n", postfix);
    free(postfix);
    return 0;
}
