/*
8.1.2023
Neta Cohen
325195774
WH3
*/

#include <stdio.h>

#define MAX_LINE_LEN 256
#define MAX_WORD_LEN 30
#define MAX_FILE_LEN 64000

/* functions: */

// Recursive function that check wether string2 is substring of string1.
int substring(char *string1, char *string2, int start1, int start2, int end1 , int end2);


// Function of getting the next word from the buffer and returning its length.
int getword(char* buffer , int* start , char* w);


// This Function returns the number of characters in the line the pointer it gets points to.
int getLine(char *buffer , int *index, char *line);

// This recursive function checks wether it's possible to get from string1 to string2 by adding n chars.
int similar(char *string1, char *string2, int n);

//This function receives a word and a line and checks wether the word is in the line. It uses the substring function.
int isWordInLine(char *line, char *word);

int main()
{
    char keyword[MAX_WORD_LEN] = "";
    char flagArr [2] = "";
    char buffer[MAX_FILE_LEN + 1];
    int index = 0;
    int endIndex = 0;
    int scan = 1;

    // Read the file
    while ((scan = getchar()) != EOF)
    {
        buffer[endIndex] = (char)scan;
        endIndex++;
    }
    buffer[endIndex] = '\0';
    unsigned long length = strlen(buffer);

    // Get the first word from the buffer
    getword(buffer , &index , keyword);

    // Getting 'a' or 'b', to chose what to print
    getword(buffer , &index , flagArr);
    char flag = flagArr[0];

    while (index < length) 
    {
        // Printing all the lines in the text with the spesific word.
        if (flag == 'a') 
        {
            char line [MAX_LINE_LEN] = "";
            getLine(buffer, &index, line);
            if (isWordInLine(line, keyword)) 
            {
                printf("%s", line);
            }
        } 
        //printing all the word in the text that similar to the key word or have only one letter extra than the key word.
        else 
        {
            char word [MAX_WORD_LEN] = "";
            getword(buffer, &index, word);
            if(similar(word , keyword , 1))
            {
                printf("%s\n" , word);
            }
        }
    }

    return 0;
}


// Recursive function that check wether string2 is substring of string1.
int substring(char *string1, char *string2, int start1, int start2, int end1 , int end2) 
{
    if ((end2 < start2) || (end1 < start1))
    {
        return 0;
    }

    if((end2 - start2) == (end1- start1))
    {
        int startCopy1 = start1;
        int startCopy2 = start2;
        int flag = 1;

        while ((startCopy1 < end1) && (startCopy2 < end2) && flag)
        {
            if (*(string1 + startCopy1) != *(string2 + startCopy2))
            {
                flag = 0;
            }
            startCopy2++;
            startCopy1++;
        }
        if (flag == 1)
        {
            return 1;
        }
    }
    if (substring(string1, string2, start1 + 1, start2, end1, end2) || substring(string1, string2, start1, start2, end1 - 1, end2)) 
    {
        return 1;
    }

    return 0;
}

// Function of getting the next word from the buffer and returning its length.
int getword(char* buffer , int* start , char* w)
{
    int counter = 0;
    char c = buffer[*start];
    do 
    {
        c = buffer[*start];
        w[counter] = c;
        (*start)++;
        counter++;
    } while ( (c != '\n') && (c != '\t') && (c != ' ') && (counter < MAX_WORD_LEN));

    w[counter -1] = '\0';
    return counter;
}

// This Function returns the number of characters in the line the pointer it gets points to.
int getLine(char *buffer , int *index, char *line)
{
    int counter = 0;
    char c = ' ';
    do 
    {
        c = *(buffer + (*index));
        *(line + counter) = c;
        (*index)++;
        counter++;
    } while ((c != '\n') && (counter < MAX_LINE_LEN));

    line[counter] = '\0';
    return counter;
}

// This recursive function checks wether it's possible to get from string1 to string2 by adding n chars.
int similar(char *string1, char *string2, int n)
{
    int len_s = (int) strlen(string1);
    if(n == 0 || ( len_s == strlen(string2) ) )
    {
        if(strcmp(string1, string2) == 0 )
        {
            return 1;
        }
        return 0;
    }

    char copy [MAX_WORD_LEN];
    for(int position = 0; position < len_s; position++)
    {
        strcpy(copy , string1);
        for(int i = position + 1; i < len_s; i++)
        {
            copy[i - 1]  = copy[i];
        }
        copy[len_s - 1] = '\0';
        if(similar(copy, string2, n-1) == 1)
        {
            return 1;
        }
    }
    return 0;
}

//This function receives a word and a line and checks wether the word is in the line. It uses the substring function.
int isWordInLine(char *line, char *word)
{
    if((substring(line, word, 0, 0, (int)strlen(line), (int)strlen(word))) == 1)
    {
        return 1;
    }
    return 0;
}
