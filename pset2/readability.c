#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main (void) {
    string text = get_string("Text:\n");

    int letters, words, sentences, length;

    letters = 0;
    words = 1;
    sentences = 0;

    length = strlen(text);

    for (int i = 0; i < length; i++) {
        if (isalpha(text[i])) {
            letters++;
        }
    }

    for (int j = 0; j < length; j++) {

        if (j != 0 && text[j] == ' ') {
            words ++;
        }
    }

     for (int k = 0; k < length; k++) {

        if (text[k] == '!' || text[k] == '.'|| text[k] == '?') {
            sentences ++;
        }
    }

    float L = ((float)letters/(float) words) * 100;
    float S = ((float)sentences/(float) words) * 100;

   int index = round((0.0588 * L) - (0.296 * S) - 15.8);

   if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index <= 0)
    {
        printf("Before Grade 1\n");
    }
    else {
        printf("Grade %d\n", index);
    }
}