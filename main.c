#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100

int stack[MAX_STACK_SIZE];
int tos = -1;

typedef enum {
    lparen, rparen, plus, minus, times, divide, mod,
    eos, operand, eol, unknown
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
    case'0': return operand;
    case'1': return operand;
    case'2': return operand;
    case'3': return operand;
    case'4': return operand;
    case'5': return operand;
    case'6': return operand;
    case'7': return operand;
    case'8': return operand;
    case'9': return operand;
    case'\n':return eol;
    default: return unknown;
    }
}

void push(int i) {
    stack[++tos] = i;
}
int pop() {
    return stack[tos--];
}

int main(int argc, char **argv) {

    FILE* fp = argc == 2 ? fopen(argv[1], "rb") : NULL;
    if (!fp) fp = stdin;
    char c = 0;
    int op1, op2,result = 0;
    precedence token;
    while (1) {
        fscanf(fp, "%c", &c);
        if (c == '\n') break;
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
            case mod: push(op1 % op2); break;
            default: goto BREAK; // TODO: remove goto
            }
        }
    }
    BREAK:
    result = pop();
    printf("%d\n", result);
    fclose(fp);
    return 0;
}
