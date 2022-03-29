#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100

int stack[MAX_STACK_SIZE];
int tos = -1;

typedef enum {
    lparen, rparen, plus, minus, times, divide, mod,
    eos, operand
} precedence;

precedence getToken(char* symbol)
{

    switch (*symbol) {
    case'(': return lparen;
    case')': return rparen;
    case'+': return plus;
    case'-': return minus;
    case'/': return divide;
    case'*': return times;
    case'%': return mod;
    case'\0':return eos;
    default: return operand;
    }
}

void push(int i) {
    tos++;
    stack[tos] = i;
}
int pop() {
    return stack[tos];
    tos--;
}

int main() {

    FILE* fp = fopen("a.txt", "r");
    char c = 0;
    int op1, op2,result = 0;
    precedence token;
    while (1) {
        fscanf(fp, "%c", &c);
        if (c == '\n') break;
        printf("%c", c);
        token = getToken(&c);
        if (token == operand)
            push(c - '0'); /* convert:char -> integer*/
        else {
            op2 = pop();
            op1 = pop();
            switch (token) {
            case plus: push(op1 + op2); break;
            case minus: push(op1 - op2); break;
            case times: push(op1 * op2); break;
            case divide: push(op1 / op2); break;
            case mod: push(op1 % op2);
            }
        }
    }
    result = pop();
    printf("\n%d", result);
    fclose(fp);
    return 0;
}
