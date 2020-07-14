#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <string.h>
#include <math.h>


/*
The objective of this program is to compute the reading level of the user's input text.
This is determined by the Coleman-Liau formula index = 0.0588 * L - 0.296 * S - 15.8
NOTE: Letters do not include punctuation, digits, or other symbols
*/



int main(void)
{
    //initialize variables
    int letter_num = 0;
    int word_num = 0;
    int sent_num = 0;
    float avg_num_s = 0;//average # of sentences per 100 words

    //get text from user
    string user_text = get_string("Text: ");
    int txt_length = strlen(user_text);//length of string

    // printf("String length: %i\n", txt_length);

    char text[txt_length];

    bool isSentence = false;


    for (int i = 0; i < txt_length; i++)
    {
        if (isalpha(user_text[i]) != 0 )
        {
            letter_num ++;
        }

        // if (isalpha(user_text[i+1]) != 0 && user_text[i+1] != 45 && user_text[i+1] != 39)
        // if (user_text[i+1] == ' ' ||  user_text[i+1] == '.' ||  user_text[i+1] == '?'  )
        if (user_text[i] == ' '  )
        {
            if (isSentence == true)
            {
                isSentence = false;
            }
            else
            {
                word_num ++;

            }
        }
        //checks for exclamation, period, or question mark in next char, respectively, and NO hyphen
        else if ( (user_text[i] == 33 || user_text[i] == 46 || user_text[i] == 63)  )
        {
            word_num ++;
            sent_num ++ ;
            isSentence = true;
        }
    }

    printf("Total letters: %i\n", letter_num);
    printf("Total words: %i\n", word_num);
    printf("Total sentences: %i\n", sent_num);


    float num_100 = (float)word_num / 100; //calculate num of 100 words in text

    //Compute L  the avg num of letters per 100 words in text
    float avg_L = (float)letter_num / num_100;

    //Compute L  the avg num of letters per 100 words in text
    float avg_S = (float)sent_num / num_100;

    printf("Average # letters per 100 words: %.2f\n", avg_L);
    printf("Average # sentences per 100 words: %.2f\n", avg_S);


    //compute using formula
    int grade_index = round(0.0588 * avg_L - 0.296 * avg_S - 15.8);
    // printf("Grade level: %i\n", grade_index);

    if (grade_index < 1)
        {
            printf("Before Grade 1\n");
        }
    else if (grade_index >= 16)
        {
            printf("Grade 16+\n");
        }
    else
        {
            printf("Grade %i\n",grade_index );
        }

    // string output = "";

}

