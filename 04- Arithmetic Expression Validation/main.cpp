/*
Problem Name: Arithmetic Expression Validation

Question:
Write a C++ program that takes an arithmetic expression as input
and checks whether the expression is valid or invalid using a stack.

The program should follow these rules:

1. Opening brackets '(', '{', '[' must have matching closing
   brackets ')', '}', ']'.
2. Brackets must be closed in the correct order.
3. Arithmetic operators (+, -, *, /, %) must not appear consecutively
   or at the beginning of the expression.
4. An arithmetic operator must be followed by a valid operand.
5. Variables and numeric characters are treated as operands.
6. Two operands must not appear consecutively without an operator.
7. The expression must not end with an operator or an unclosed bracket.
8. Spaces in the expression should be ignored.
9. Display "Valid Equation" if the expression satisfies all the
   conditions; otherwise, display "Invalid Equation".

Sample Input 1:
a+(b*c)

Sample Output 1:
Valid Equation

Sample Input 2:
a++b

Sample Output 2:
Invalid Equation

Sample Input 3:
{a+[b*c]}

Sample Output 3:
Valid Equation

Sample Input 4:
(a+b]

Sample Output 4:
Invalid Equation

Sample Input 5:
a+

Sample Output 5:
Invalid Equation
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string eqn;
    stack<char> st;

    cout << "Enter equation: ";
    getline(cin, eqn);

    bool valid = true;
    bool operand = true;

    for (int i=0; i<eqn.length(); i++)
    {
        char ch = eqn[i];

        if (ch == ' ')
            continue;

        if (ch== '(' || ch=='{' || ch =='[')
        {
            if (!operand)
            {
                valid = false;
                break;
            }

            st.push(ch);
            operand = true;
        }

        else if (ch==')' || ch=='}' || ch==']')
        {
            if (st.empty() || operand)
            {
                valid = false;
                break;
            }

            if ((ch == ')' && st.top() != '(') ||(ch == '}' && st.top() != '{') ||
                (ch == ']' && st.top() != '['))
            {
                valid = false;
                break;
            }

            st.pop();
            operand = false;
        }
        else if (ch == '+' || ch == '-' ||ch == '*' || ch == '/' || ch =='%')
        {
            if (operand)
            {
                valid = false;
                break;
            }

            operand = true;
        }
        else if (isalnum(ch))
        {
            if (!operand)
            {
                valid = false;
                break;
            }

            operand = false;
        }
        else
        {
            valid = false;
            break;
        }
    }

    if (!st.empty() || operand)
        valid = false;

    if (valid)
        cout << "Valid Equation";
    else
        cout << "Invalid Equation";

    return 0;
}