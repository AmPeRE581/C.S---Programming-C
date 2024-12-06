#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Funzione per controllare se una stringa è palindroma */
int is_palindrome(const char *str) {
    int left = 0, right = strlen(str) - 1;

    while (left < right) {
        /* Ignora caratteri non alfanumerici */
        while (left < right && !isalnum((unsigned char)str[left])) {
            left++;
        }
        while (left < right && !isalnum((unsigned char)str[right])) {
            right--;
        }

        /* Confronta i caratteri */
        if (tolower((unsigned char)str[left]) != tolower((unsigned char)str[right])) {
            return 0; /* Non è palindroma */
        }

        left++;
        right--;
    }

    return 1; /* È palindroma */
}

/* Funzione per trovare l'ultima stringa palindroma */
char *find_last_palindrome(char **strings) {
    char *last_palindrome = NULL;

    for (int i = 0; strings[i] != NULL; i++) {
        if (is_palindrome(strings[i])) {
            last_palindrome = strings[i]; /* Mantieni il puntatore */
        }
    }

    return last_palindrome;
}

int main() {
    /* Esempio di vettore di stringhe */
    char *strings[] = {
        "aerea",
        "etna gigante",
        "non palindrome",
        "another one",
        NULL, /* Terminazione con NULL */
    };

    char *result = find_last_palindrome(strings);

    if (result != NULL) {
        printf("L'ultima stringa palindroma è: '%s'\n", result);
    } else {
        printf("Nessuna stringa palindroma trovata.\n");
    }

    return 0;
}