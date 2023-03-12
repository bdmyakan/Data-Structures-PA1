#include "PartOne.hpp"
#include <iostream>
#include <stdio.h>
#include<math.h> // for pow in 1.3

using namespace std;

// Function calls

// Question 1.2 Addition, subtraction and multiplication functions of matrices

// add matrices function
// passed by reference

template <size_t row1, size_t column1, size_t row2, size_t column2>
int** add_matrices(int (&matrix1)[row1][column1], int (&matrix2)[row2][column2]){
    
    cout << __func__ << endl;
    // we will create output matrix by allocating memory then we will fill the values.
    int** output_matrix;
    output_matrix = (int **) malloc(row1*sizeof(int *));
    for(int i=0;i<column1;i++)
        output_matrix[i] = (int *) malloc(column1*sizeof(int));

    // write matrix 1 data
    cout<<"Matrix 1"<<endl;
    for (size_t i = 0; i < row1; ++i){
        cout << i << ": ";
        for (size_t j = 0; j < column1; ++j){
            cout << matrix1[i][j] << '\t';
        }
        cout<<endl;
    }
    // write matrix 2 data
    cout<<"Matrix 2"<<endl;
    for (size_t i = 0; i < row2; ++i){
        cout << i << ": ";
        for (size_t j = 0; j < column2; ++j){
            cout << matrix2[i][j] << '\t';
            }
            cout << endl;
        }
    // check if rows are equal else write the statement
    if(row1==row2){
        //check if columns are equal else write the statement
        if(column1==column2){
            //if rows and columns are equal than create output matrix and add the values
            for (size_t i=0 ; i < row1; i++){
                for(size_t j=0; j<column1; j++){
                    output_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
                }
            }
            //write the output matrix to console
            cout<<"Output Matrix"<<endl;
            for (size_t i = 0; i < row1; ++i){
                cout << i << ": ";
                for (size_t j = 0; j < column1; ++j){
                    cout << output_matrix[i][j] << '\t';
                }
                cout<<endl;
            }
        }
        
        else{
            cout<<"Can't be done. Columns of given matrices are not equal to each other."<<endl;
        }
        
    }
    else{
        cout<<"Can't be done. Rows of given matrices are not equal to each other."<<endl;
        }
    return output_matrix;
    }
    
    

// subtract matrices function
// pass by reference

template <size_t row1, size_t column1, size_t row2, size_t column2>
int** subtract_matrices(int (&matrix1)[row1][column1], int (&matrix2)[row2][column2]){
    cout << __func__ << endl;
    // we will create output matrix by allocating memory then we will fill the values then return it at the end.
    int** output_matrix;
    output_matrix = (int **) malloc(row1*sizeof(int *));
    for(int i=0;i<column1;i++)
        output_matrix[i] = (int *) malloc(column1*sizeof(int));

    // write matrix 1 data
    cout<<"Matrix 1"<<endl;
    for (size_t i = 0; i < row1; ++i){
        cout << i << ": ";
        for (size_t j = 0; j < column1; ++j){
            cout << matrix1[i][j] << '\t';
        }
        cout<<endl;
    }
    // write matrix 2 data
    cout<<"Matrix 2"<<endl;
    for (size_t i = 0; i < row2; ++i){
        cout << i << ": ";
        for (size_t j = 0; j < column2; ++j){
            cout << matrix2[i][j] << '\t';
            }
            cout << endl;
        }
    // check if rows are equal else write the statement
    if(row1==row2){
        //check if columns are equal else write the statement
        if(column1==column2){
            //if rows and columns are equal than create output matrix and subtract the values
            for (size_t i=0 ; i < row1; i++){
                for(size_t j=0; j<column1; j++){
                    output_matrix[i][j] = matrix1[i][j] - matrix2[i][j];
                }
            }
            //write the output matrix to console
            cout<<"Output Matrix"<<endl;
            for (size_t i = 0; i < row1; ++i){
                cout << i << ": ";
                for (size_t j = 0; j < column1; ++j){
                    cout << output_matrix[i][j] << '\t';
                }
                cout<<endl;
            }
        }
        
        else{
            cout<<"Can't be done. Columns of given matrices are not equal to each other."<<endl;
        }
        
    }
    else{
        cout<<"Can't be done. Rows of given matrices are not equal to each other."<<endl;
        }
    return output_matrix;
    }



// multiply matrices function
// pass by reference

template <size_t row1, size_t column1, size_t row2, size_t column2>
int** multiply_matrices(int (&matrix1)[row1][column1], int (&matrix2)[row2][column2]){
    cout << __func__ << endl;
    // we will create output matrix by allocating memory then we will fill the values then return it at the end.
    int** output_matrix;
    output_matrix = (int **) malloc(row1*sizeof(int *));
    for(size_t i=0;i<column2;i++)
        output_matrix[i] = (int *) malloc(column2*sizeof(int));
    
    for (size_t i=0 ; i < row1; i++){
        for(size_t j=0; j<column1; j++){
            output_matrix[i][j] = 0;
        }
    }

    // write matrix 1 data
    cout<<"Matrix 1"<<endl;
    for (size_t i = 0; i < row1; ++i){
        cout << i << ": ";
        for (size_t j = 0; j < column1; ++j){
            cout << matrix1[i][j] << '\t';
        }
        cout<<endl;
    }
    // write matrix 2 data
    cout<<"Matrix 2"<<endl;
    for (size_t i = 0; i < row2; ++i){
        cout << i << ": ";
        for (size_t j = 0; j < column2; ++j){
            cout << matrix2[i][j] << '\t';
            }
            cout << endl;
        }
    // check if column1 and row2 are equal else write the statement
    if(column1==row2){
            
            for (size_t i=0 ; i < row1; i++){
                for(size_t j=0; j<column2; j++){
                    for(size_t k =0; k<column1; k++){
                        output_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
                    }
                    }
            }
        //write the output matrix to console
        cout<<"Output Matrix"<<endl;
        for (size_t i = 0; i < row1; ++i){
            cout << i << ": ";
            for (size_t j = 0; j < column2; ++j){
                cout << output_matrix[i][j] << '\t';
            }
            cout<<endl;
        }
    }
    else{
        cout<<"Can't be done. Column number of first matrix is not equal to row number of second."<<endl;
        }
    return output_matrix;
    }

//Q1.2 End

//Q1.3 Find determinant of matrix
template <size_t size>
int determinant(int (&matrix)[size][size]){
    int cofactor_matrix[size][size]={0};
    int maxi=0,maxj=0,max=0;
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            if(matrix[i][j] != 0){
                maxi = i;
                maxj = j;
            }
        }
    }
    if(maxi<maxj)
        max = maxj;
    else
        max = maxi;
    
    int det = 0;
    //initialize the determinant value with 0
    if(max==1){
        det = matrix[0][0];
    }
    else if(max==2){
        det = matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0];
    }
    else{
        for(int point=0; point<size; point++){
            int c_i = 0;
            for (int i=1; i<size; i++){
                int c_j = 0;
                for (int j=0; j<size; j++){
                    if (j!=point){
                        cofactor_matrix[c_i][c_j] = matrix[i][j];
                        c_j++;
                        }
                    }
                    c_i++;
                }
                det = det + (pow(-1, point) * matrix[0][point] * determinant(cofactor_matrix));
            }
            
        }
        
    return det;
}



//Function calls end





int main(){
// Q1.1
    Matrix<5> m1;
    m1.get_element(3, 3);
    m1.set_element(4, 2, 2);
    m1.get_element(4, 2);
    m1.get_element(2,1);
    
// Q1.2
    int a[2][5] = {{0,1,2,3,4},{5,6,7,8,9}};
    int b[2][5] = {{2,3,5,7,11},{-10,0,10,20,30}};
    int c[5][3] = {{0,2,4},{3,6,9},{4,8,12},{5,10,15},{6,12,18}};
    
    int** output_matrix1;
    int** output_matrix2;
    int** output_matrix3;
    
    output_matrix1 = add_matrices(a, b);

    for (int i = 0; i < 2; ++i){
        cout << i << ": ";
        for (int j = 0; j < 5; ++j){
            cout << output_matrix1[i][j] << '\t';
            
        }
        cout<<endl;
    }

    output_matrix2 = subtract_matrices(a, b);
    
    for (int i = 0; i < 2; ++i){
        cout << i << ": ";
        for (int j = 0; j < 5; ++j){
            cout << output_matrix2[i][j] << '\t';
        }
    cout<<endl;
}

    output_matrix3 = multiply_matrices(a,c);
    
    for (int i = 0; i < 2; ++i){
        cout << i << ": ";
        for (int j = 0; j < 3; ++j){
            cout << output_matrix3[i][j] << '\t';
        }
    cout<<endl;
}
    
//Q1.3
    
    int t[3][3] = {{3,2,2},{1,5,1},{5,7,9}};
    int g=0;
    
    g = determinant(t);
    cout<<g<<endl;
    return 0;
}




    

    
    


