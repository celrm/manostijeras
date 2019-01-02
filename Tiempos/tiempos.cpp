#include <bits/stdc++.h>
#include "algoritmos.h"
using namespace std;

typedef vector<int> vi;
typedef vector<vi> mat;

const int PRECISION = 20;
const int REPETICIONES = 100;

using Clock = chrono::steady_clock;
using milisegundos = chrono::duration<double,milli>;
// Cada ejecucion se repite varias veces para que
// la medicion del tiempo sea mas fiable.

void resuelveCaso (stringstream & salida) {
// Formato de la salida de los tiempos
  salida.setf(ios::fixed);
  Clock::duration tiempo_total = Clock::duration::zero();
  Clock::duration periodo;

  ifstream entrada("entrada.txt");

  int g,t,m;
  entrada >> g >> t >> m;
  while (!(g==0&&t==0&&m==0)) {
    mat gigas(t+1,vi(m));

    for (int i = 0; i < t+1; i++) {
      for (int j = 0; j < m; j++)
        entrada >> gigas[i][j];
      sort(gigas[i].rbegin(), gigas[i].rend());
    }
    for (size_t w = 0; w < REPETICIONES; w++) {
      int sol = INT_MAX;
      int solparcial = 0;
      vi gigasxtema(t,0);

      Clock::time_point inicio = Clock::now();
      // sol = formapolinomica(g,gigas);
      rec(g,sol,solparcial,0,gigasxtema,gigas); // Código a medir
      periodo = Clock::now() - inicio;
      tiempo_total += periodo;
    }
    double tiempo = milisegundos(tiempo_total / (double) REPETICIONES).count();
    tiempo_total = Clock::duration::zero();
    salida << " & " << tiempo;
    entrada >> g >> t >> m;
  }
  entrada.close();
}

int main () {
  ofstream salida;
  salida.open("salida.txt");
  stringstream ss;
  resuelveCaso(ss);
  string aux;
  while (!ss.eof()) {
    getline (ss, aux);
    salida << aux;
  }
  salida.close();
  return 0;
}
