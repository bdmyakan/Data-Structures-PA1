#include <iostream>
#include <stdio.h>

using namespace std;

// Question 1.1

    // Template Class Definition

template <int N> class Matrix{
    private:
        double data[N][N];
    public:
        int const SIZE = N;
        Matrix();
        void get_element(int row, int column);
        void set_element(int row, int column, int input);
        
};

    // Template Class Definition End


    // Class Function Calls

template <int N> Matrix<N>::Matrix(){
    cout << "Constructor Called" << endl;
    // since N the size is defined while creating elements from template there is no need to take input size
    // we just create the identical matrix with respect to N and out it in data matrix
    for (int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i==j)            // if row and column is equal then the data is 1 to make the matrix identical
                data[i][j]=1;
            else                // else data is 0
                data[i][j]=0;
            
        }
    }
}

template <int N> void Matrix<N>::get_element(int row, int column){
    if(row<SIZE & column<SIZE){
        // if the given row and column is in the limits of matrix then the data in that place is written
        cout<<"The selected element in the Matrix is: "<<data[row][column]<<endl;
    }
    else
        // else error statement is written
        cout<<"Given indices are exceed the size"<<endl;
}

template <int N> void Matrix<N>::set_element(int row, int column, int input){
    if(row<SIZE & column<SIZE){
        // if the given row and column is in the limits of matrix then the data given is written to data
        data[row][column] = input;
    }
    else
        // else error statement is written
        cout<<"Given indices are exceed the size"<<endl;
}


    // Class Function Calls End

// Question 1.1 template class END



