#include <stdio.h>
#include <stdlib.h>

typedef struct Triple {
    char opt;
    char argument1;
    char argument2;
} Triple;

void generateTriple(Triple *triples, int *tripleIndex, char op, char arg1, char arg2) {
    Triple triple;
    triple.opt = op;
    triple.argument1 = arg1;
    triple.argument2 = arg2;
    
    triples[(*tripleIndex)++] = triple;
}

void displayTriples(Triple *triples, int numTriples) {
    printf("Generated Triples:\n");
    for (int i = 0; i < numTriples; i++) {
        printf("(%c, %c, %c)\n", triples[i].opt, triples[i].argument1, triples[i].argument2);
    }
}

int main() {
    Triple triples[100];  // Array to hold triples
    int numTriples = 0;   // Counter for triples

    // Generate triples
    generateTriple(triples, &numTriples, '=', 'A', 'x');
    generateTriple(triples, &numTriples, '=', 'B', 'y');
    generateTriple(triples, &numTriples, '+', 'x', 'y');
    generateTriple(triples, &numTriples, '=', 'C', 'z');

    // Display generated triples
    displayTriples(triples, numTriples);

    return 0;
}

