#include <iostream>
#include <vector>
using namespace std;

vector <double> merge(vector<double> a, vector<double> b) {
    vector<double> c;
    while (a.size() > 0 && b.size() > 0) {
        if (a[0] < b[0]) {
            c.push_back(b[0]);
            b.erase(b.begin());
        }
        else {
            c.push_back(a[0]);
            a.erase(a.begin());
        }
    }

    while (a.size() > 0) {
        c.push_back(a[0]);
        a.erase(a.begin());
    }

    while (b.size() > 0) {
        c.push_back(b[0]);
        b.erase(b.begin());
    }

    return c;
}

vector<double> mergesort(vector<double> a, int n) {  //T(n) = O(n*log n) En el mejor y peor de los casos
   if (n == 1) {
       return a;
    }

    int middle = n / 2;

    vector<double> arregloIzq;
    vector<double> arregloDer;

    for (int i = 0; i < middle; i++)
        arregloIzq.push_back(a[i]);
    for (int j = 0; j < n-middle ; j++)
        arregloDer.push_back(a[middle + j]);
                                                            //Función que divide
    arregloIzq = mergesort(arregloIzq, arregloIzq.size());  //# veces: n/2
    arregloDer = mergesort(arregloDer, arregloDer.size());  //# veces: n/2
                                                           //Función que ordena
    return merge(arregloIzq, arregloDer);                  //# veces: n

}

void printVect(vector<double> i) {
    for (double x : i)
        cout << x << " ";
}

int main()
{
    vector<double> input1{ 5,2,9,1,7,4,6 }; //Caso de prueba 1: Lista longitud media completamente desordenada
    vector<double> input2{ 7,6,5,4,3,2,1}; //Caso de prueba 2: Lista longitud media completamente ordenada
    vector<double> input3{ 15,10,25,5,20,30,35,40,45,1,50,2 }; //Caso de prueba 3: Lista longitud larga medio desordenada
    vector<double> input4{ 8,3,6,1,4 }; //Caso de prueba 4: Lista longitud chica medio desordenada

    vector<double> expected1{ 9,7,6,5,4,2,1 };
    vector<double> expected2{ 7,6,5,4,3,2,1 };
    vector<double> expected3{ 50,45,40,35,30,25,20,15,10,5,2,1 };
    vector<double> expected4{ 8,6,4,3,1};

    vector<vector<double>> inputs{ input1, input2, input3, input4 };
    vector<vector<double>> expectedOuts{ expected1, expected2, expected3, expected4 };

    cout << "--- MERGE SORT ---" << endl;

    for (int i = 0; i < inputs.size(); i++) {
        cout << "CASO " << i + 1<< ":" << endl;
        cout << "Input: ";
        printVect(inputs[i]);
        cout << "\nExpected Output: ";
        printVect(expectedOuts[i]);
        vector<double> res = mergesort(inputs[i], inputs[i].size()); //Llama a mergesort()
        if (expectedOuts[i] == res) {
            cout << "\nActual Output: ";
            printVect(res);
            cout << "\n- PRUEBA EXITOSA -" << endl;
        }
        else {
            cout << "\nActual Output: ";
            printVect(res);
            cout << "\n- PRUEBA FALLIDA - " << endl;
        }
        cout << "\n------------------------------" << endl;
    }

}
