//Design a lexical Analyzer for given language should ignore the redundant 
//spaces, tabs and new lines and ignore comments using C


#include <stdio.h>

int main() {
    int c;
    int in_comment = 0;  // Flag to track whether inside a comment

    while ((c = getchar()) != EOF) {
        if (in_comment) {
            if (c == '*' && (c = getchar()) == '/') {
                in_comment = 0;
            }
        } else {
            if (c == '/' && (c = getchar()) == '*') {
                in_comment = 1;
            } else if (c == ' ' || c == '\t') {
                // Ignore redundant spaces and tabs
                while ((c = getchar()) == ' ' || c == '\t');
                putchar(' ');  // Print only one space
            } else {
                putchar(c);  // Print the character as is
            }
        }
    }

    return 0;
}


