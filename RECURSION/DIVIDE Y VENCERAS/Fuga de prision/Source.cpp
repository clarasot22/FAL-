
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

char fugaPrision(const vector<char>& v, int ini, int fin) {


    char preso = ' ';
    int medio = (fin + ini) / 2;
    
    if (fin - ini == 1) {
        if (v[fin] - v[ini] > 1) {
             return static_cast<char>(v[ini] + 1); 
        }
        //return ' ';
    }
    else {

        if (v[medio] - v[ini] > medio - ini)  return static_cast<char>( fugaPrision(v, ini, medio));
     
        else if (v[fin] - v[medio + 1] > fin - (medio)) 
            return static_cast<char>(fugaPrision(v, medio, fin));
        


    }

    
   
}

void resuelveCaso() {

    vector<char> v;
    char a, b, c;

    cin >> a >> b;

    for (int i = 0; i < (b - a); i++) {
        cin >> c;
        v.push_back(c);

    }

    cout << fugaPrision(v,0,v.size()-1) << "\n";

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
