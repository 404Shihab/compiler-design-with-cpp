/*
Write a C++ program that takes multiple characters as input 
and classifies each character as an alphabet, vowel, consonant, 
numeric value, logical operator, or special character. 
If a character is an alphabet, further check whether it is a vowel or consonant. 
If it is not an alphabet, check whether it is a numeric value or a logical operator. 
Otherwise, identify it as a special character.
*/


#include <iostream>
using namespace std;
int main()
{
    string input;

    cout << "Enter characters: ";
    getline(cin, input);

    for (int i=0; i <input.length(); i++)
    {
        char ch = input[i];

        if ((ch >='A' && ch <= 'Z') || (ch >='a' && ch <='z'))
        {
            cout <<ch<<" -- Alphabet";

            if (ch == 'A' || ch == 'E' || ch == 'I' ||ch == 'O' || ch == 'U' ||ch == 'a' || ch == 'e' || ch == 'i' ||
                ch == 'o' || ch == 'u')
            {
                cout <<" -- Vowel" << endl;
            }
            else
            {
                cout <<" -- Consonant" << endl;
            }
        }

        else if (ch>='0' && ch <='9')
        {
            cout <<ch <<" -- Numeric" << endl;
        }
        else if (ch =='&' || ch =='|')
        {
            cout << ch <<" -- Logical Operator" << endl;
        }

        else if (ch ==' ')
        {
            continue;
        }
        else
        {
            cout <<ch<< " -- Special Character" << endl;
        }
    }

    return 0;
}