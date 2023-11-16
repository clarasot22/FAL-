
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

int curvaConcava(const vector<int>& v, int ini, int fin) {

    if (ini - fin == 0) return v[ini];
    else {
        int medio = (ini + fin) / 2;

        if (v[medio] < v[medio + 1]) return curvaConcava(v, ini, medio);
        else return curvaConcava(v, medio + 1, fin);
    }

}

bool resuelveCaso() {

    int n, a;
    vector<int>v;
    cin >> n;

    if (!cin)
        return false;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }

    cout << curvaConcava(v, 0, n - 1) << endl;

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
