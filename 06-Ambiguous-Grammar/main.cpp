/*
Question: Analyzing Ambiguous Context-Free Grammars

Write a C++ program to analyze an arithmetic expression using the
following context-free grammar:

E -> E + E
E -> E * E
E -> (E)
E -> id

The program should accept an arithmetic expression containing id, +,
*, and parentheses. It should generate all valid parenthesized
interpretations of the expression and determine whether the grammar
is ambiguous for the given input.

If multiple interpretations exist, display all interpretations and
report that the grammar is ambiguous. Otherwise, report that the
grammar is not ambiguous.
*/


#include <iostream>
#include <string>
using namespace std;

string result[1000];
int count = 0;

void findWays(string s)
{
    if (s == "id")
    {
        result[count++] = "id";
        return;
    }

    int len = s.length();

    for (int i = 0; i < len; i++)
    {
        if (s[i] == '+' || s[i] == '*')
        {
            string left = s.substr(0, i);
            string right = s.substr(i + 1);

            string leftWays[1000], rightWays[1000];
            int leftCount = 0, rightCount = 0;

            int oldCount = count;

            findWays(left);
            leftCount = count - oldCount;

            for (int j = 0; j < leftCount; j++)
            {
                leftWays[j] = result[oldCount + j];
            }
                

            count = oldCount;

            findWays(right);
            rightCount = count - oldCount;

            for (int j = 0; j < rightCount; j++)
            {
                rightWays[j] = result[oldCount + j];
            }
                

            count = oldCount;

            for (int j = 0; j < leftCount; j++)
            {
                for (int k = 0; k < rightCount; k++)
                {
                    result[count++] = "(" + leftWays[j]+ s[i] + rightWays[k] + ")";
                }
            }
        }
    }
}

int main()
{
    string expression;

    cout << "Enter expression: ";
    cin >> expression;

    findWays(expression);

    cout << endl<< "Valid interpretations:";

    for (int i = 0; i < count; i++)
    {
        cout << result[i] << endl;
    }

    if (count > 1)
        cout <<endl << "Grammar Status: Ambiguous"  <<endl;
    else if (count == 1)
        cout << endl << "Grammar Status: Not Ambiguous" <<endl;
    else
        cout << endl << "Invalid expression" <<endl;

    return 0;
}