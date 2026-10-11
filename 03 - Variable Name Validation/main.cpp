/*
Problem Name: Variable Name Validation

Question:
Write a C++ program that takes a data type and a variable name as input.
The program should check whether the data type and variable name are valid
according to the following rules:

1. The data type must be a valid predefined type supported by the program.
2. The variable name must start with an alphabet (A-Z, a-z) or underscore (_).
3. The remaining characters may contain alphabets, digits (0-9), or underscores (_).
4. Spaces and special characters are not allowed in a variable name.
5. C++ keywords cannot be used as variable names.
6. Display "Valid" if both the data type and variable name are valid;
   otherwise, display "Invalid".

Example:
Input: int myVariable
Output: Valid

Input: float _total
Output: Valid

Input: int 2value
Output: Invalid

Input: int if
Output: Invalid

Input: xyz number
Output: Invalid
*/


#include <iostream>
#include <string>
using namespace std;

int main()
{
    string dec;

    cout << "Enter data type and variable name: ";
    getline(cin, dec);


    int i=0;

    while (i <dec.length() && dec[i] != ' ')
    {
        i++;
    }

    string dataType = dec.substr(0, i);

    int start= i;
    while (start<dec.length() && dec[start] == ' ')
    {
        start++;
    }

    string variable = dec.substr(start);

    bool validType = false;
    bool validVariable = true;

    string dataTypes[] = 
    { "int", "char", "float", "double", "bool", "string" };

    for (int j = 0; j < 6; j++)
    {
        if (dataType == dataTypes[j])
        {
            validType = true;
            break;
        }
    }


    if (variable.length() == 0)
    {
        validVariable = false;
    }
    else
    {
 
        if (!((variable[0] >= 'A' && variable[0] <= 'Z') ||
              (variable[0] >= 'a' && variable[0] <= 'z') ||
              variable[0] == '_'))
        {
            validVariable = false;
        }

        for (int j=1; j <variable.length(); j++)
        {
            if (!((variable[j] >= 'A' && variable[j] <= 'Z') ||
                  (variable[j] >= 'a' && variable[j] <= 'z') ||
                  (variable[j] >= '0' && variable[j] <= '9') ||
                  variable[j] == '_'))
            {
                validVariable = false;
                break;
            }
        }
    }

    string keyWords[] = 
    {
        "if", "else", "switch", "case", "for", "while",
        "int", "char", "float", "double", "bool", "string",
        "void", "return", "break", "continue", "class",
        "public", "private", "const", "auto"
    };

    for (int j=0; j<21; j++)
    {
        if (variable == keyWords[j])
        {
            validVariable = false;
            break;
        }
    }


    if (validType && validVariable)
    {
        cout << "Valid";
    }
    else
    {
        cout << "Invalid";
    }

    return 0;
}
