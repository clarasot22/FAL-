
/*@ <answer>
 *
 * Nombre y Apellidos:Clara Sotillo Sotillo
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
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

/*
 cada d´ıgito en posici´on impar se multiplica por 3 y se le suma elmenor d´ıgito a su derecha 
 cada d´ıgito en posici´on par se multiplica por 2 y se le suma el mayor d´ıgito a su izquierda. 
*/

void codificarNumero(int n, int& pos, int& mayorI, int menorD, int& codigo) {


    if(n/10 == 0){
        
        codigo = n * 3 + menorD;
        mayorI = n;
        pos++;
    }
    else {

        int menor;
        if (n % 10 < menorD) {
            menor = n % 10;
            codificarNumero(n / 10, pos, mayorI, menor, codigo);
        }
        else
            codificarNumero(n/10, pos, mayorI, menorD, codigo);

        if (pos % 2 == 1) codigo += (n % 10) * 3 + menorD;
        if (pos % 2 == 0) codigo += + (n % 10) * 2 + mayorI;

        if (n % 10 > mayorI) mayorI = n % 10;
        pos++;
        

    }

}

void resuelveCaso() {

    int n, mayorI = 0, menorD, codigo=0,pos=1;

    cin >> n;

    menorD = n % 10;
    codificarNumero(n, pos, mayorI, menorD, codigo);
    cout << codigo<< endl;
    
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
