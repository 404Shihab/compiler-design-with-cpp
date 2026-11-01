/*
**Experiment No. 02: String Generation Using Context-Free Grammar Derivation**

**Problem Statement:**

Write a C++ program to generate valid strings using a Context-Free Grammar (CFG). The program should take the number of derivation steps as input and demonstrate the step-by-step derivation process starting from the start symbol `S`.

Use the following production rules:

- `S → aSb`
- `S → ε`

The program should:
1. Take the number of derivation steps from the user.
2. Display each derivation step.
3. Replace the final non-terminal `S` with ε (empty string).
4. Display the final generated string.*/


#include <iostream>
#include <string>
using namespace std;

string generateString(int n)
{
    string result = "";


    for (int i = 0; i < n; i++)
    {
        result += "a";
    }

    for (int i = 0; i < n; i++)
    {
        result += "b";
    }

    return result;
}


void showDerivation(int n)
{
    string current = "S";

    cout << "Derivation: " << current;

    for (int i = 0; i < n; i++)
    {

        int pos = current.find('S');
        current.replace(pos, 1, "aSb");
        cout << " => " << current;
    }

    int pos = current.find('S');
    current.replace(pos, 1, "");

    cout << " => ";


    if (current == "")
        cout <<"epsilon"<< endl;
    else
        cout <<current<<endl;
}

// Function to display the final generated string
void displayResult(const string& generatedString)
{
    if (generatedString == "")
    {
        cout <<"Generated String: epsilon" << endl;
    }
    else
    {
        cout<<"Generated String: "<<generatedString<< endl;
    }
}

int main()
{
    int n;

    cout << "Enter the number of derivation steps: ";
    cin >> n;


    if (n<0)
    {
        cout << "Invalid input!" << endl;
        return 0;
    }

    showDerivation(n);

    string result = generateString(n);
    displayResult(result);

    return 0;
}
