
/*@ <answer>
 *
 * Nombre y Apellidos:Clara Sotillo Sotillo
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>
void rescateAereo(const vector<int>& v, int& ini, int& fin, int n, int max) {

    int cont1=0, cont2=0, ini2=-1, fin2=-1;

    for (int i = 0; i < n; i++) {

        if (v[i] > max) {
            if (cont2 == 0) ini2 = i;

            cont2++;
            fin2 = i;
        }
        else {
            if (cont2 != 0) {
                if (cont2 > cont1) {
                    cont1 = cont2;
                    ini = ini2;
                    fin = fin2; 
                }
                cont2 = 0;
                ini2 = -1;
                fin2 = -1;
            }
            
        }

    }

    if (cont2 != 0) {
        if (cont2 > cont1) {
            cont1 = cont2;
            ini = ini2;
            fin = fin2;
        }
       
    }
    

}

 void resuelveCaso() {

     int n, max, a, ini=-1, fin=-1;
     vector<int> v;

     cin >> n >> max;

     for (int i = 0; i < n; i++) {
         cin >> a;
         v.push_back(a);
     }

     rescateAereo(v, ini, fin, n, max);

     cout << ini << " " << fin << endl;

}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
