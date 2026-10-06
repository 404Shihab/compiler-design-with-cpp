/*
Write a C++ program that takes a sentence as 
input and identifies each word as a Keyword, 
Numeric value, or Variable. The program should 
store predefined C++ keywords in an array and compare 
ach input word with the keywords. If a word matches 
a keyword, it should be identified as a Keyword. 
If it contains only digits, it should be identified as Numeric. 
Otherwise, it should be identified as a Variable.
*/


#include<iostream>
using namespace std;
int main()
{


    string keyWords[] = {"if","else", "switch", "case", "for", "while", "cout", "void", "continue", "break", "return"};
    string dataType[] = {"int", "char", "double", "float","string"};
    cout << "Enter a sentence: ";

    string sentence;
    getline(cin, sentence);

    string word;


    for(int i=0; i<=sentence.length(); i++)
    {
        if(sentence[i] == ' ' || i == sentence.length())
        {
            bool found = false;

            for(int j=0; j<5; j++)
            {
                if(word== dataType[j])
                {
                    cout << word << " -- data type" << endl;
                    found = true;
                }
            }

            if(!found)
            {

                for(int j=0; j<11; j++)
                {
                    if(word== keyWords[j])
                    {
                        cout << word << " --key word" << endl;
                        found = true;
                    }
                }
            }

            if(!found)
            {
                bool numeric = true;
                for(int j=0; j<word.length(); j++)
                {
                    if(word[j]<'0' || word[j]>'9')
                    {
                        numeric = false;
                        break;
                    }
                }
                if(numeric == true)
                {
                    cout << word << "-- Numeric" <<endl;
                }
                else{
                    cout<< word << " -- Variable" <<endl;
                }
            }
            word = "";
        }
        else
        {
            word = word + sentence[i];
        }
    }

    return 0;
}
