//TODO: Format the input 
#include <iostream>
#include <utility>
#include <vector>
#include <sstream>
#include <ostream> 

/* Use for input format (boost library required) */
//#include "CPP_Exercises/boost_library/boost/algorithm/string.hpp"
//#include "CPP_Exercises/boost_library/boost/algorithm/string/split.hpp"

using namespace std;

void CicleLenghtAlgorithm(int A, int B)
{
    cout << A << " " << B << " ";
    int total = 0;
    int current = 0;
    int maximum = 0;

    for (int i = A; i <= B; i++)
    {
        current = i;
        total = 0;
        while(current != 1)
        {
            if (current%2 != 0)
            {
                current = current*3 + 1;
                total++;
            }
            else
            {
                current = current/2;
                total++;
            }
        }

        total++;
        if (total > maximum)
        {
            maximum = total; 
        }
    }

    cout << maximum;
}

int main(int argc, char *argv[])
{

    pair <int, int> values;
    bool condition;

#pragma region Input_Section

    do{

        cout << "Input first value: ";
        cin >> values.first;
        cout << "Input second value: ";
        cin >> values.second;

    #pragma region Formated_Input
        /*
        string input;

        cout << "Input values: ";
        cin >> input;

        stringstream ss(input);
        char temp;
        ss >> values.first >> temp >> values.second;

        cout << values.first << " " << values.second << endl;

        */
    #pragma endregion Formated_Input

        condition = (values.first > 0 && values.first < 10000) &&
                    (values.second > 0 && values.second < 10000);

        if (condition == true)
        {
            cout << "Output value: " << values.first << " " << values.second << endl;
        }
        else
        {
            cout << "Error! Invalid Value" << endl;
        }
        
    } while (condition == false);

#pragma endregion Input_Section

    CicleLenghtAlgorithm(values.first, values.second);
    cout << endl;

    return 0;
}