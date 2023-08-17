#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NON_TERMINALS 10
#define MAX_TERMINALS 10

// Structure to represent a production rule
typedef struct {
    char nonTerminal;
    char production[20];
} ProductionRule;

// Structure to represent a parsing table entry
typedef struct {
    char nonTerminal;
    char terminal;
    char production[20];
} ParsingTableEntry;

ProductionRule productionRules[MAX_NON_TERMINALS];
ParsingTableEntry parsingTable[MAX_NON_TERMINALS][MAX_TERMINALS];

int numNonTerminals = 0;
int numTerminals = 0;

void initialize() {
    for (int i = 0; i < MAX_NON_TERMINALS; i++) {
        for (int j = 0; j < MAX_TERMINALS; j++) {
            parsingTable[i][j].nonTerminal = ' ';
            parsingTable[i][j].terminal = ' ';
            strcpy(parsingTable[i][j].production, "");
        }
    }
}

void addProductionRule(char nonTerminal, const char *production) {
    productionRules[numNonTerminals].nonTerminal = nonTerminal;
    strcpy(productionRules[numNonTerminals].production, production);
    numNonTerminals++;
}

void addToParsingTable(char nonTerminal, char terminal, const char *production) {
    int nonTerminalIndex = nonTerminal - 'A';
    int terminalIndex = terminal - 'a';

    parsingTable[nonTerminalIndex][terminalIndex].nonTerminal = nonTerminal;
    parsingTable[nonTerminalIndex][terminalIndex].terminal = terminal;
    strcpy(parsingTable[nonTerminalIndex][terminalIndex].production, production);
}

void printParsingTable() {
    printf("Predictive Parsing Table:\n");
    printf("%-10s", "Non-Terminal");
    for (int j = 0; j < numTerminals; j++) {
        printf("%-10c", parsingTable[0][j].terminal);
    }
    printf("\n");

    for (int i = 0; i < numNonTerminals; i++) {
        printf("%-10c", productionRules[i].nonTerminal);
        for (int j = 0; j < numTerminals; j++) {
            printf("%-10s", parsingTable[i][j].production);
        }
        printf("\n");
    }
}

int main() {
    initialize();

    printf("Enter the number of non-terminals: ");
    scanf("%d", &numNonTerminals);

    printf("Enter the non-terminals (one character each):\n");
    for (int i = 0; i < numNonTerminals; i++) {
        scanf(" %c", &productionRules[i].nonTerminal);
    }

    printf("Enter the number of terminals: ");
    scanf("%d", &numTerminals);

    printf("Enter the terminals (one character each):\n");
    for (int i = 0; i < numTerminals; i++) {
        scanf(" %c", &parsingTable[0][i].terminal);
    }

    for (int i = 0; i < numNonTerminals; i++) {
        char nonTerminal;
        char production[20];

        printf("Enter production for non-terminal %c: ", productionRules[i].nonTerminal);
        scanf("%s", production);

        addProductionRule(productionRules[i].nonTerminal, production);
    }

    for (int i = 0; i < numNonTerminals; i++) {
        char nonTerminal = productionRules[i].nonTerminal;
        char production[20] = "";
        strcpy(production, productionRules[i].production);

        for (int j = 0; j < strlen(production); j++) {
            char symbol = production[j];
            if (symbol >= 'A' && symbol <= 'Z') {
                for (int k = 0; k < numTerminals; k++) {
                    if (parsingTable[0][k].terminal == symbol) {
                        addToParsingTable(nonTerminal, symbol, production);
                        break;
                    }
                }
            }
        }
    }

    printParsingTable();

    return 0;
}

