#include <stdio.h>
#include <string.h>

// Function to eliminate left factoring
void eliminateLeftFactoring(char *production) {
    int len = strlen(production);

    // Find the length of the common prefix
    int commonLen = 0;
    while (commonLen < len - 1 && production[commonLen] == production[commonLen + 1]) {
        commonLen++;
    }

    if (commonLen > 0) {
        // Print the factored part
        printf("Common prefix: ");
        for (int i = 0; i <= commonLen; i++) {
            printf("%c", production[i]);
        }
        printf("\n");

        // Generate new non-terminal symbol
        char newSymbol = 'A';
        while (strchr(production, newSymbol) != NULL) {
            newSymbol++;
        }

        // Print the new productions
        printf("%c -> %c%s'\n", production[0], newSymbol, production + commonLen + 1);
        printf("%c' -> %c%s' | e\n", newSymbol, production[commonLen + 1], newSymbol);

    } else {
        printf("No left factoring found.\n");
    }
}

int main() {
    char production[50];
    
    printf("Enter the production: ");
    scanf("%s", production);

    eliminateLeftFactoring(production);

    return 0;
}

