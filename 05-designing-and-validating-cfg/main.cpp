/*
Experiment No. 1: Designing and Validating a Context-Free Grammar (CFG)

Question:
Write a C++ program to design and validate the basic format of CFG production rules.

Requirements:
1. Check whether the left-hand side contains exactly one uppercase letter (non-terminal).
2. Check whether the production arrow (->) exists.
3. Validate the right-hand side containing letters or digits.
4. Accept epsilon (ε) as a valid production.
5. Display whether the production rule is valid or invalid.
6. Take the entire production rule as input using getline().

Sample Input and Output:

Input: S->aSb
Output: Valid production rule.

Input: S->ε
Output: Valid production rule.

Input: ab->S
Output: Invalid: Left-hand side must contain exactly one non-terminal.

Input: S=aSb
Output: Invalid: Missing '->' in the production rule.
*/



#include <iostream>
#include <string>
using namespace std;

bool isValidNonTerminal(char symbol)
{
    return (symbol >= 'A' && symbol <= 'Z');
}


bool isValidProduction(const string& production)
{
    if (production.empty())
    {
        return false;
    }

    for (int i = 0; i < production.length(); i++)
    {
        char ch = production[i];

        if (!((ch >= 'A' && ch <= 'Z') ||(ch >= 'a' && ch <= 'z') ||(ch >= '0' && ch <= '9')))
        {
            return false;
        }
    }

    return true;
}


bool validateGrammar(const string& rule)
{
    int arrow = rule.find("->");

    if (arrow == -1)
    {
        cout << "Invalid: Missing '->' in the production rule."
             << endl;
        return false;
    }

 
    string left = rule.substr(0, arrow);

    if (left.length() != 1 || !isValidNonTerminal(left[0]))
    {
        cout << "Invalid: Left-hand side must contain exactly one non-terminal"<< endl;
        return false;
    }

    string right = rule.substr(arrow + 2);

    if (right == "ε")
    {
        return true;
    }


    if (!isValidProduction(right))
    {
        cout << "Invalid: Incorrect production format." << endl;
        return false;
    }

    return true;
}


void displayResult(const string& rule, bool valid)
{
    if (valid)
    {
        cout << "Valid production rule." << endl;
    }
}

int main()
{
    string rule;

    cout << "Enter a production rule: ";
    getline(cin, rule);

    bool valid = validateGrammar(rule);

    displayResult(rule, valid);

    return 0;
}

