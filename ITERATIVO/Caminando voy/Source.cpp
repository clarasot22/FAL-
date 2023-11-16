
/*@ <answer>
 *
 * Nombre y Apellidos: Clara Sotillo Sotillo
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

bool esApto(const vector<int>& v, int d, int n) {

    int ini = 0;
    bool condicion = true;
    for (int i = 0; i < n-1; i++)
    {
        if (v[i] >= v[i + 1])ini = i;
        if ((v[i + 1] - v[ini]) > d) condicion = false;
    }

    return condicion;
}

bool resuelveCaso() {

    int d, n, a;
    vector<int> v;
    cin >> d >> n;

    if (!std::cin)  // fin de la entrada
        return false;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }

    if (esApto(v, d, n))cout << "APTA" << endl;
    else cout << "NO APTA" << endl;


    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
