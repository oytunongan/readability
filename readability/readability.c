#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    float L = ((letters * 100) / (float) words);
    float S = ((sentences * 100) / (float) words);
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    int Ave = round(index);
    if (Ave < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (Ave >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", Ave);
    }
    // printf("index: %f, Ave: %i, letters: %i, words: %i, sentences: %i\n", index, Ave, letters, words, sentences);
}
int count_letters(string text)
{
    int numberL = 0;
    int lenght = strlen(text);
    for (int i = 0; i < lenght; i++)
    {
        if ((isalpha(text[i]) != 0) || (ispunct(text[i]) != 0))
        {
            numberL++;
        }
        if (ispunct(text[i]) != 0)
        {
            numberL--;
        }
    }
    return numberL;
}
int count_words(string text)
{
    int numberW = 1;
    int lenght = strlen(text);
    for (int i = 0; i < lenght; i++)
    {
        if (isblank(text[i]) != 0)
        {
            numberW++;
        }
    }
    return numberW;
}
int count_sentences(string text)
{
    int numberS = 0;
    int lenght = strlen(text);
    for (int i = 0; i < lenght; i++)
    {
        if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            numberS++;
        }
    }
    return numberS;
}