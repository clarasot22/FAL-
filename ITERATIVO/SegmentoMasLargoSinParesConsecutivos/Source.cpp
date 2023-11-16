
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

int resolver(const vector<int>& v, int k, int n) {

    int tam = 0;
    int pares = 0;
    int iniNew = 0;

    for (int i = 0; i < n; i++)
    {
        if (v[i] % 2 == 0) {
            pares++;
            if (pares > k) {
                iniNew = i - (k - 1);
                pares = k;
            }
        }
        else {
            pares = 0;
        }
        tam = max(tam, (i - iniNew + 1));
    }
    return tam;



}

void resuelveCaso() {

    int n, k, a;

    cin >> n >> k;

    vector<int> v;

    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }

    cout << resolver(v, k, n) << endl;
    
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
