
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
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
