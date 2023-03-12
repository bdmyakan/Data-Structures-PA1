#include "PartTwo.hpp"

Disc::Disc(int d){
    diameter = d;
}

Hanoi::Hanoi(int n){
    if(n>20)
        cout<<"Please give n up to 20"<<endl;
    else{
        for(int i=0 ; i<n; i++){
            Rod0[i] = Disc(n-i);
        }
        number_of_discs=n;
    }
}


int Hanoi::TheLastIndice (int rod){
    int n=0;
    int i = 19;
    int r;


    if (rod == 0){
        for(    ; i>=0 ; i--){
            r = Rod0[i].diameter;
            if (r != 0){
                n = i;
                break;
            }
                
            
        }
    }
    if (rod == 1){
        for(    ; i>=0 ; i--){
            r = Rod1[i].diameter;
            if (r != 0){
                n = i;
                break;
            }
        }
    }
    if (rod == 2){
        for(    ; i>=0 ; i--){
            r = Rod2[i].diameter;
            if (r != 0){
                n = i;
                break;
            }
        }
    }

    return n;
}

int Hanoi::TheLastIndiceDiameter(int rod){
    int dia = 0;
    int index = TheLastIndice(rod);
    if (rod == 0){
        dia = Rod0[index].diameter;
    }
    if (rod == 1){
        dia = Rod1[index].diameter;
    }
    if (rod == 2){
        dia = Rod2[index].diameter;
    }
    return dia;
}

void Hanoi::move(int from, int to){

    if(from>3 || from<0 || to<0 || to>3 )
        cout<< "The rod indices given are wrong. Give them from 0 to 2"<<endl;
    else if(from == to)
        cout<< "The rod indices are same."<<endl;
        
    else
    {

        int indexfrom,indexto;
        int diafrom,diato;
        indexfrom = TheLastIndice(from);
        indexto = TheLastIndice(to);
        diafrom = TheLastIndiceDiameter(from);
        diato = TheLastIndiceDiameter(to);
        if(indexfrom<20 && indexto<20 && diafrom>0){
            if(diafrom<diato || diato == 0){
                if(diato>0)
                    indexto=indexto+1; // if there is no disc on rod we will put directly but if there is discs on rod then we need to increment our index by 1
                
                if(from == 0 && to == 1){
                    Rod1[indexto].diameter = diafrom;
                    Rod0[indexfrom].diameter = 0;
                }
                
                else if(from == 0 && to == 2){
                    Rod2[indexto].diameter = diafrom;
                    Rod0[indexfrom].diameter = 0;
                }
                    
                else if(from == 1 && to ==0){
                    Rod0[indexto].diameter = diafrom;
                    Rod1[indexfrom].diameter = 0;
                }
                    
                else if(from == 1 && to ==2){
                    Rod2[indexto].diameter = diafrom;
                    Rod1[indexfrom].diameter = 0;
                }
                
                else if(from == 2 && to ==0){
                    Rod0[indexto].diameter = diafrom;
                    Rod2[indexfrom].diameter = 0;
                }
                
                else if(from == 2 && to ==1){
                    Rod1[indexto].diameter = diafrom;
                    Rod2[indexfrom].diameter = 0;
                }
                cout <<"Disc " << diafrom << " is moved from Rod "<< from << " to Rod "<< to <<endl;
            }
            else
                cout<< "This move is not possible." <<endl;
        }
    }
}



