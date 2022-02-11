#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int key = 0;

int only_digits(string arg);
string cipher_engine(string text, int k);

int main(int argc, string argv[])
{
    if (argc == 2 && only_digits(argv[1])) // verification that the cl argument is correct
    {
        // request input to the user
        string plaintext = get_string("plaintext:  ");
        // call cipher algorithm
        string ciphertext = cipher_engine(plaintext, key);
        printf("ciphertext: %s\n", ciphertext);
        return 0;
    }
    else
    {
        // error when cl command is incorrect
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

// function that verifies that the key argument is a valid positive integer
int only_digits(string arg)
{
    key = atoi(arg); // this function call transforms a string into a number

    if (key > 0)
    {
        return 1; // if the key is greater than zero we are good
    }
    else
    {
        return 0; // if not, the program must be interrupted
    }
}

// function that encodes the string using the key
string cipher_engine(string text, int k)
{
    string cipher = text;
    char letter;
    int i = 0;
    for (i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i])) // verifies that the character is a letter
        {
            if (isupper(text[i])) // verifies that the character is uppercase
            {
                int j = text[i] - 65; // assigns an alphabetical index
                cipher[i] = 65 + (j + k) % 26; // encrypts the character using the formula
            }
            else // if the character is lowercase
            {
                int j = text[i] - 97; // assigns an alphabetical index
                cipher[i] = 97 + (j + k) % 26; // encrypts the character using the formula
            }
        }
        else
        {
            cipher[i] = text[i]; // if the character is not a letter, we just copy it (spaces & punctuation)
        }
    }
    return cipher;
}

