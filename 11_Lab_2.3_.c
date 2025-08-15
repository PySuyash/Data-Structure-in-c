// Vowel and consonant counter. Use a pointer to traverse a string and count vowels and consonants without array indexing.

#include <stdio.h>
#include <ctype.h>

int main() {
    char string[100];
    char * ptr = string;
    int vowels = 0;
    int consonant = 0;

    printf("\nEnter a string: ");
    scanf("%s", string);

    while (*ptr != '\0') {
        char ch = tolower(*ptr);
        if (ch >= 'a' && ch <= 'z') {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels ++;
            } else {
                consonant ++;
            }
         }
         ptr ++;
    }
    
    printf("Vowels : %d\n", vowels);
    printf("Consonant : %d\n", consonant);

}