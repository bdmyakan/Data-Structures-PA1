#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

class Disc{
    private:
        
    public:
        int diameter;
        Disc(int d = 0); //diameter 0 for no disc
};

class Hanoi{
    private:

    public:
        Disc Rod0[20];
        Disc Rod1[20];
        Disc Rod2[20];
        int number_of_discs;
        Hanoi(int number_of_discs);
        int TheLastIndice(int rod);
        int TheLastIndiceDiameter(int rod);
        void move(int from, int to); //move a disc from one rod to another
};


