
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

int segmentoMasLargo(const vector<int>& v, int n) {

    int cont = 1, cont2 = 1;

    if (n == 0) return 0;

    for (int i = 0; i < n - 1; i++) {

        if (abs(v[i] - v[i + 1])==1) {
            cont2++;
        }
       
        if (cont2 > cont) {
            cont = cont2;
        }

        if (abs(v[i] - v[i + 1]) != 1) {
            cont2 = 1;
        }

    }

    
    return cont;
}

void resuelveCaso() {

    int n, a;
    vector<int> v;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    cout << segmentoMasLargo(v, n) << endl;
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
