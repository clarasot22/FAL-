
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

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
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
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

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
