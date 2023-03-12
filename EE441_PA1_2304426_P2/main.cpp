#include "PartTwo.hpp"
#include<iostream>
using namespace std;


int MOVES[1048575][2]; // the array that holds the sequence of moves that defined in sequence and transferred to solve_hanoi
int i=0; // the number that holds the first indice of array
//Q1.1

void sequence(int num,int X,int Y,int Z){
  if(num>0){
    sequence(num-1, X, Z, Y);
      MOVES[i][0] = X;
      MOVES[i++][1] = Z;
    sequence( num-1, Y, X, Z);
  }
}

void solve_hanoi(Hanoi &game){
    int number_of_moves = pow(2,game.number_of_discs)-1;
    i = 0;
    sequence(game.number_of_discs,0,1,2);
    for(int k = 0 ; k<number_of_moves ; k++){
        game.move(MOVES[k][0], MOVES[k][1]);
    }
}


//Q1.1 End

//Q2.2
void print_backwards(char const *string)
{
   if (*string)
   {
       print_backwards(string+1);
       cout<<*string;
   }
}
//Q2.2 End

// Q2.3
bool is_prime(int n){
    
    if(n<2) return false;
    
    for (int i=2 ; i<n ; i++){
        if(n%i == 0) return false;
    }
    
    return true;
}

int nth_prime(int n){
    int i = 2;
    
    for(;n>0;i++){
        if(is_prime(i)) n--;
    }
    
    return i-1;
}

//Q2.3 End

//main function
int main(){
    //Q2.1
Hanoi a(2);
solve_hanoi(a);
    //Q2.1 End
    
    // Q2.2
    char c[] = "crunch brunch trunk drunk";
    print_backwards(c);
    cout<<endl;
    // Q2.2 End
    
    // Q2.3
    int p;
    p = nth_prime(3);
    cout<<p<<endl;
    //Q2.3 End
    
return 0;
}
