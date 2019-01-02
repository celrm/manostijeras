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
      gigasxtema[i] += gigas[gigasxtema.size()][j];
      final(g,sol,solparcial+1,j+1,gigasxtema,gigas);
      gigasxtema[i] -= gigas[gigasxtema.size()][j];
    }
  }
}

void rec(int const& g, int & sol, int solparcial, int i, int j, vi & gigasxtema, mat const& gigas) {
  if(i==gigasxtema.size()) {
    final(g,sol,solparcial,0,gigasxtema,gigas);
  }
  else if (j==gigas[i].size()) {
    rec(g,sol,solparcial,i+1,0,gigasxtema,gigas);
  }
  else {
    rec(g,sol,solparcial,i,j+1,gigasxtema,gigas);
    gigasxtema[i] += gigas[i][j];
    rec(g,sol,solparcial+1,i,j+1,gigasxtema,gigas);
    gigasxtema[i] -= gigas[i][j];
  }
}

bool func() {
  int g,t,m;
  cin >> g >> t >> m;
  if (g==0&&t==0&&m==0) return false;

  mat gigas(t+1,vi(m));

  for (int i = 0; i < t+1; i++)
  for (int j = 0; j < m; j++)
    cin >> gigas[i][j];

  int sol = INT_MAX;
  vi gigasxtema(t);
  rec(g,sol,0,0,0,gigasxtema,gigas);
  cout << sol << '\n';
  return true;
}

int main() {
  while (func());
	return 0;
}
