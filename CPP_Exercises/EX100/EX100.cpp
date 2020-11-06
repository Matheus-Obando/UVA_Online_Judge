#include <iostream>
#include <utility>
#include <vector>
#include <sstream>
#include <ostream> 

using namespace std;

void CicleLenghtAlgorithm(int A, int B)
{
    cout << A << " " << B << " ";
    int total = 0;
    int current = 0;
    int maximum = 0;

    if (A <= B)
    {
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
    }

    else
    {
        for (int i = B; i <= A; i++)
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
    }
    
    cout << maximum;
}

int main(int argc, char *argv[])
{

    pair <int, int> values;
    vector<string> inputLines;
    bool condition;

#pragma region Input_Section

    do{

    
    #pragma region Formated_Input
        
        string input;

        getline(cin, input);

        if (input.empty())
        {
            break;
        }

        cin.clear();

        // Format input
        stringstream ss(input);

        ss >> values.first >> values.second;
        
    ////////

#pragma endregion Formated_Input

        condition = (values.first > 0 && values.first < 1000000) && (values.second > 0 && values.second < 1000000);

        if (condition == true)
        {
            inputLines.push_back(input);
        }
        else
        {
            break;
        }
        
    } while (condition != false);

#pragma endregion Input_Section

    while(!inputLines.empty())
    {
        stringstream ss(inputLines.front()); inputLines.erase(inputLines.begin());

        ss >> values.first >> values.second;
        
        CicleLenghtAlgorithm(values.first, values.second);
        cout << endl;
    }
    return 0;
}