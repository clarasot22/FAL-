
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

bool indicePastoso(const vector<int>& v,int& indice) {

    bool pastoso = false;
    int sum=0, i= v.size()-1;

    while (!pastoso && i >= 0){
        if (v[i] == sum) {
            indice = i;
            pastoso = true;
        }
        sum += v[i];
        i--;
    }

    return pastoso;
}

void resuelveCaso() {

    int n, a;
    vector<int> v;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }

    int indice = n;
    if (indicePastoso(v, indice)) cout << "Si " << indice << endl;
    else cout << "No" << endl;

   
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
