/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int precedence(char op) {
    switch(op) {
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

int isRightAssociative(char op) {
    return (op == '^');  
}

void infixToPostfix(char *infix, char *postfix) {
    int i, j = 0;
    char stack[MAX];
    int top = -1;

    for (i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            stack[++top] = infix[i];
        } else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            if (top != -1 && stack[top] == '(') {
                top--; 
            }
        } else { 
            while (top != -1 && stack[top] != '(' &&
                   (precedence(stack[top]) > precedence(infix[i]) ||
                   (precedence(stack[top]) == precedence(infix[i]) && !isRightAssociative(infix[i])))) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }

    while (top != -1) {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("%s\n", postfix);
    return 0;
}