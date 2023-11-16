
/*@ <answer>
 *
 * Nombre y Apellidos:Clara Sotillo Sotillo
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
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
int obtenerMinimoVector(const vector<int>& v, int ini, int fin) {

    
    if (ini - fin == 0) return v[ini];
    if (fin - ini == 1) {
        if (v[fin] < v[ini])return v[fin];
        else return v[ini];
    }
    else {
        int medio = (fin + ini) / 2;
        if (v[ini] < v[medio]) return obtenerMinimoVector(v, ini, medio);
        else return obtenerMinimoVector(v, medio, fin);

    }

}

bool resuelveCaso() {

    // leer los datos de la entrada
    int n, a;

    cin >> n;
    if (!cin)
        return false;

    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);

    }

    cout << obtenerMinimoVector(v, 0, n - 1) << endl;

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
