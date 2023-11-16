
/*@ <answer>
 *
 * Nombre y Apellidos:Clara Sotillo Sotillo
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
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
void complementario(int& n, int& inv, int& comp, int& indice, int& ind2) {

    int resto;

    resto = n % 10;
    //n = n / 10;

    
    inv = (9 - resto) * indice + inv;
    comp = comp * 10 + (9 - resto);

    if (n / 10 == 0) {
        
        
    }
    else {
        n = n / 10;
        indice *= 10;
        
        complementario(n, inv, comp, indice, ind2);
        
        
    }


    
}

void resuelveCaso() {

    int n, inv=0, comp=0, indice = 1, ind2=0;

    cin >> n;

    complementario(n, inv, comp, indice, ind2);

    cout << inv << " " << comp << "\n";


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
