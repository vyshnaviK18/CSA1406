#include <stdio.h>

typedef struct {
    char operation;
    int operand1;
    int operand2;
} Quadruple;

Quadruple quadruples[100];
int quadIndex = 0;

int tempCount = 0;

int findOrCreateTemp(int operand1, int operand2, char operation) {
    for (int i = 0; i < quadIndex; i++) {
        if (quadruples[i].operation == operation &&
            quadruples[i].operand1 == operand1 &&
            quadruples[i].operand2 == operand2) {
            return i;
        }
    }

    quadruples[quadIndex].operation = operation;
    quadruples[quadIndex].operand1 = operand1;
    quadruples[quadIndex].operand2 = operand2;
    
    return quadIndex++;
}

int main() {
    int a = 5, b = 3, c = 7;

    int expr1 = a + b * c;
    int expr2 = a + b * c;
    int expr3 = a * b + c;

    int temp1 = findOrCreateTemp(b, c, '*');
    int temp2 = findOrCreateTemp(a, temp1, '+');

    printf("Temporary Variables:\n");
    for (int i = 0; i < quadIndex; i++) {
        if (quadruples[i].operation == '+' || quadruples[i].operation == '*') {
            printf("t%d = %d %c %d\n", i, quadruples[i].operand1, quadruples[i].operation, quadruples[i].operand2);
        }
    }

    printf("\nResult:\n");
    printf("expr1 = t%d\n", temp2);
    printf("expr2 = t%d\n", temp2);
    printf("expr3 = %d\n", expr3);

    return 0;
}

