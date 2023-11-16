
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
bool sumDivisible(int n, int& suma, int& i) {

    if (n/10==0) {

        suma = n % 10;
        i++;

    }
    else {
        if (sumDivisible(n / 10, suma, i)) {
            suma += n % 10;

            if (suma % i != 0) {

                return false;
            }
            i++;
        }
        else return false;
       
    }
    return true;
}


bool resuelveCaso() {

    int n, suma = 0, i=1;
     

    cin >> n;

    if (n == 0)
        return false;

    if (sumDivisible(n, suma, i)) cout << "SI\n";
    else cout << "NO\n";
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
