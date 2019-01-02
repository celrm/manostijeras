#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> mat;

void show(vi const& v) {
  for (size_t i = 0; i < v.size() - 1; i++) {
    cout << v[i] << ' ';
  }
  cout << v[v.size() - 1] << '\n';
}

void show(mat const& v) {
  cout << '\n';
  for (size_t i = 0; i < v.size(); i++) {
    show(v[i]);
  }
  cout << '\n';
}

int formapolinomica(int const& g, mat const& giga) {
  mat aux = giga;
  int sol = 0;
  for (size_t i = 0; i < aux.size()-1; i++) {
    sort(aux[i].rbegin(), aux[i].rend());
    int j = 0;
    int acc = 0;
    while(j < aux[i].size() && acc < g) {
      acc += aux[i][j];
      sol++;
      j++;
    }
    if (acc < g) return INT_MAX;
  }
  return sol;
}

void final(int const& g, int & sol, int solparcial, int j, vi & gigasxtema, mat const& gigas) {
  if(solparcial < sol) {
    if(j==gigas[gigasxtema.size()].size()) {
      bool good = true;
      for (size_t i = 0; i < gigasxtema.size() && good; i++) {
        if(gigasxtema[i] < g) good = false;
      }
      if(good) sol = solparcial;
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
}

void rec(int const& g, int & sol, int solparcial, int i, int j, vi & gigasxtema, mat const& gigas) {
  if(solparcial < sol) {
    if(i==gigasxtema.size()) {
      final(g,sol,solparcial,0,gigasxtema,gigas);
    }
    else if (j==gigas[i].size()) {
      rec(g,sol,solparcial,i+1,0,gigasxtema,gigas);
    }
    else {{
      rec(g,sol,solparcial,i,j+1,gigasxtema,gigas);
      if(gigasxtema[i] < g)
        if(gigas[i][j] > 0) {
          gigasxtema[i] += gigas[i][j];
          rec(g,sol,solparcial+1,i,j+1,gigasxtema,gigas);
          gigasxtema[i] -= gigas[i][j];
        }
        else {
          rec(g,sol,solparcial,i+1,0,gigasxtema,gigas);
        }
      }
    }
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

  int sol = formapolinomica(g,gigas);
  std::cout << sol << '\n';
  vi gigasxtema(t,0);
  rec(g,sol,0,0,0,gigasxtema,gigas);
  cout << sol << '\n';
  return true;
}

int main() {
  while (func());
	return 0;
}
