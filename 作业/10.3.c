unsigned int MyStrlen(char *p) {
    unsigned int len;

    len = 0;
    for (; *p != '\0'; p++) // (1) '\0'
        len += 1; // (2) += 1
    
    return len; // (3) len
}
unsigned int MyStrlen(char s[]) {
    char *p = s;
    while (*p != '\0') // (1) '\0'
        p++;
    return p - s; // (2) p - s
}
int MyStrcmp(char *p1, char *p2) {
    for (; *p1 == *p2; p1++, p2++) {
        if (*p1 == '\0') {
            return *p2 ? -1 : 0; 
        }
    }
    return (*p1 > *p2) - (*p1 < *p2);  // (2) (*p1 > *p2) - (*p1 < *p2)
}
int MyStrlen(char s[], char t[]) {
    int i;
    for (i = 0; s[i] == t[i]; i++) {
        if (s[i] == '\0')
            return 0;
    }
    return ((int)s[i] - (int)t[i]); 
}

#include <stdio.h>
#include <string.h>
int main() {
    char password[] = "secret";
    char userInput[81];

    printf("Input password: ");
    scanf("%s", userInput);

    if (strcmp(userInput, password) == 0) { // strcmp(userInput, password) == 0
        printf("Correct passward! Welcome to the system...\n");
    } else if (strcmp(userInput, password) < 0) { // strcmp(userInput, password) < 0
        printf("Invaild password! user input < password\n");
    } else {
        printf("Invaild password! user input < password\n");
    }
    
    return 0;
}