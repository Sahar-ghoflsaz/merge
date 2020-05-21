#include <iostream>
using namespace std;

int searchA(int *outarray, int n, int number){

    for( int i=0 ; i<n ; i++){
        if(outarray[i] == number) return i;
    }
    return -1;
}

int main(){

    int n;
    cin>> n;
    int *FirstArray = new int [n];

    for( int i=0 ; i<n ; i++){

       cin >> FirstArray[i];
    }

    int m;
    cin>> m;
    int *SecondArray = new int [m];

    for( int i=0 ; i<m ; i++){

       cin >> SecondArray[i];
    }

    int *OutputArray = new int [n+m];

    for( int i=0 ; i<n+m ; i++){

        OutputArray[i] = 0;
    }

    int flag=0;
    int counter= 0;

    for( int i=0 ; i<n ; i++){

        flag = searchA(OutputArray, counter, FirstArray[i]);
        if(flag == -1){
            OutputArray[counter] = FirstArray[i];
            counter++;
        }
    }

    for( int i=0 ; i<m ; i++){

        flag = searchA(OutputArray, counter, SecondArray[i]);
        if(flag == -1){
            OutputArray[counter] = SecondArray[i];
            counter++;
        }
    }

    for( int i=0 ; i<counter ; i++){

        cout<< OutputArray[i]<<"  ";
    }

    delete [] FirstArray;
    delete [] SecondArray;
    delete [] OutputArray;

  return 0;

}
