#include <stdio.h>

typedef struct Quadruple {
    char operator1;
    char argument1;
    char argument2;
    char result;
} Quadruple;

void executeQuadruples(Quadruple quadruples[], int numQuadruples) {
    int variables[26] = {0};  // Assuming we have 26 variables (A-Z)

    for (int i = 0; i < numQuadruples; i++) {
        Quadruple quad = quadruples[i];

        switch (quad.operator1) {
            case '=':
                variables[quad.result - 'A'] = variables[quad.argument1 - 'A'];
                break;
            case '+':
                variables[quad.result - 'A'] = variables[quad.argument1 - 'A'] + variables[quad.argument2 - 'A'];
                break;
            // Add more cases for other operators like '-', '*', '/'
            // ...
            default:
                printf("Error: Unknown operator '%c'\n", quad.operator1);
                return;
        }
    }

    printf("Variable values after execution:\n");
    for (int i = 0; i < 26; i++) {
        if (variables[i] != 0) {
            printf("%c: %d\n", 'A' + i, variables[i]);
        }
    }
}

int main() {
    Quadruple quadruples[] = {
        {'=', 'A', '_', 'x'},
        {'=', 'B', '_', 'y'},
        {'+', 'x', 'y', 'z'},
        {'=', 'z', '_', 'C'}
    };

    int numQuadruples = sizeof(quadruples) / sizeof(quadruples[0]);

    executeQuadruples(quadruples, numQuadruples);

    return 0;
}

