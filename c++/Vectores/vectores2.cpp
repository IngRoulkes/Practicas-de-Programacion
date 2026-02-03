#include<iostream>
#include<vector>

using namespace std;

int main(){

    vector<int> numeros (5);

    vector<char> letras{'a', 'b', 'c'};

    vector<double> numeros2{23.2, 23.5, 23.5, 23.7};

    vector<int> tamaño(5, 10);

    cout << "Vectores con for" <<endl;

    for( int i=0; i<5; i++){

        cout << numeros[i] << endl;
    }

    for( int i=0; i<3; i++){

        cout << letras[i] << endl;
    }

    for( int i=0; i<4; i++){

        cout << numeros2[i] << endl;
    }

    cout << "vectores con while"<<endl;

    int i = 0;
    while(i<numeros2.size()){

        cout << numeros2[i] << endl;

        i++;
        
        cout << i << endl;

    }

    int x = 0;
    while(x<tamaño.size()){

        cout << tamaño[x] << endl;

        x++;
        
        cout << x << endl;

    }


    return 0;
}