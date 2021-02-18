#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main(void)
{

    string text = get_string("Text:\n");
    float letters = 0;
    float words = 1;
    float sentences = 0;
    for (int position=0 ; position<=(strlen(text)) ; position++) 
    {
        if (isalpha(text[position])) 
        {
            letters++;
        }
        else if (isspace(text[position])) 
        {
            if (letters != 0) 
            {
                words++;
            }
        }
        else if (text[position] == '.' || text[position] == '!' || text[position] == '?') 
        {
            sentences++;
        }
    }
    float L = (letters / words) * 100;

    float S = (sentences / words) * 100;

    float index = (0.0588 * L) - (0.296 * S) - 15.8;


    if (round(index) < 1)
    {
        printf("Before Grade 1");
    }
    else if (round(index) > 16)
    {
        printf("Grade 16+\n");
    }
    else 
    {
        printf("Grade %i\n", (int) round(index));
    }
}
