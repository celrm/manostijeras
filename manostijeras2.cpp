#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> mat;

void final(int const& g, int & sol, int solparcial, int j, vi & gigasxtema, mat const& gigas) {
  if(j==gigas[gigasxtema.size()].size()) {
    if(solparcial < sol) {
      bool good = true;
      for (size_t i = 0; i < gigasxtema.size() && good; i++) {
        if(gigasxtema[i] < g) good = false;
      }
      if(good) sol = solparcial;
    }
  }
  else {
    for (size_t i = 0; i < gigasxtema.size(); i++) {
      final(g,sol,solparcial,j+1,gigasxtema,gigas);
      if(gigasxtema[i] < g) {
        if(gigas[gigasxtema.size()][j] > 0) {
          gigasxtema[i] += gigas[gigasxtema.size()][j];
          final(g,sol,solparcial+1,j+1,gigasxtema,gigas);
          gigasxtema[i] -= gigas[gigasxtema.size()][j];
        }
      }
    }
  }
}

void rec(int const& g, int & sol, int & solparcial, int i, vi & gigasxtema, mat const& gigas) {
  if(i==gigasxtema.size()) {
    final(g,sol,solparcial,0,gigasxtema,gigas);
  }
  else {
    int acc = 0; int accsol = 0;
    rec(g,sol,solparcial,i+1,gigasxtema,gigas);
    int j = 0;
    while (j < gigas[i].size() && gigas[i][j] > 0 && gigasxtema[i] < g) {
      gigasxtema[i] += gigas[i][j]; acc += gigas[i][j];
      solparcial++; accsol++;
      rec(g,sol,solparcial,i+1,gigasxtema,gigas);
      j++;
    }
    gigasxtema[i] -= acc;
    solparcial -= accsol;
  }
}

bool func() {
  int g,t,m;
  cin >> g >> t >> m;
  if (g==0&&t==0&&m==0) return false;

  mat gigas(t+1,vi(m));

  for (int i = 0; i < t+1; i++) {
  for (int j = 0; j < m; j++)
    cin >> gigas[i][j];
  sort(gigas[i].rbegin(), gigas[i].rend());
  }

  int sol = INT_MAX;
  int solparcial = 0;
  vi gigasxtema(t,0);
  rec(g,sol,solparcial,0,gigasxtema,gigas);
  cout << sol << '\n';
  return true;
}

int main() {
  while (func());
	return 0;
}
