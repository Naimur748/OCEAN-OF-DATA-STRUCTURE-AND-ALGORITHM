#include <iostream>
using namespace std ;

int main(){

    //2D array declaraion (3 rows and 4 columns)
    int array[3][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    //Acessing and printing 2D Array Elements
    for(int i=0; i<3; i++){

        for(int j=0; j<4; j++){

            cout<<"array[ "<< i <<"]["<< j <<"]= " <<array[i][j]<<endl;
        }
    }



    int threeDarray[2][3][4] = {
       {

        {13,14,15,16},
        {17,18,19,20},
        {21,22,23,24}

        },

        {
            {25,26,27,28},
            {29,30,31,32},
            {33,35,36,37}
        }
    };

    for(int k=0; k<2; k++){

        for(int l=0; l<3; l++){

            for(int n=0; n<4; n++){

                cout<<threeDarray[k][l][n]<<endl;
            }
        }
    }
    

    return 0;

}