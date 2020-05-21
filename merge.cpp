#include <iostream>
using namespace std;

bool searchA(int* outarray, int n, int number)
{
    for (int i = 0; i < n; i++) 
        if (outarray[i] == number) 
            return false;
    
    return true;
}

int main() {

    int n = -1;
    while (n < 0)
    {
        cout << "Please enter a positive number for the size of the first array: ";
        cin >> n;
    }
    
    int* FirstArray = new int[n];

    cout << "\n\nEnter the first array's elemenct one by one: \n";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> FirstArray[i];
    }
        
 
    int m = -1;

    while(m < 0)
    {
        cout << "\nPlease enter a positive number for the size of the second array: ";
        cin >> m;
    }
    
    int* SecondArray = new int[m];


    cout << "\n\nEnter the second array's elemenct one by one: \n";

    for (int i = 0; i < m; i++) 
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> SecondArray[i];
    }

    int* OutputArray = new int[n + m];

    int counter = 0;

    for (int i = 0; i < n; i++) {
        if (searchA(OutputArray, counter, FirstArray[i]))
        {
            OutputArray[counter] = FirstArray[i];
            counter++;
        }
    }

    for (int i = 0; i < m; i++) {
        if (searchA(OutputArray, counter, SecondArray[i]))
        {
            OutputArray[counter] = SecondArray[i];
            counter++;
        }
    }

    cout << "\n\nHere is the result:\n";
    for (int i = 0; i < counter; i++) 
        cout << OutputArray[i] << "  ";

    cout << "\n\n=========================================================================\n\n";

    delete[] FirstArray;
    delete[] SecondArray;
    delete[] OutputArray;

    return 0;

}
