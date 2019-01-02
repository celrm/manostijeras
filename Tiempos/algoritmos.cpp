#include <bits/stdc++.h>
#include "algoritmos.h"
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

void rec(int const& g, int & sol, int & solparcial, int i, vi & gigasxtema, mat const& gigas) {
  if(i==gigasxtema.size()) {
    final(g,sol,solparcial,0,gigasxtema,gigas);
  }
  else {
    int acc = 0; int accsol = 0;
    rec(g,sol,solparcial,i+1,gigasxtema,gigas);
    for (size_t j = 0; j < gigas[i].size(); j++) {
      gigasxtema[i] += gigas[i][j]; acc += gigas[i][j];
      solparcial++; accsol++;
      rec(g,sol,solparcial,i+1,gigasxtema,gigas);
    }
    gigasxtema[i] -= acc;
    solparcial -= accsol;
  }
}

void final1(int const& g, int & sol, int solparcial, int j, vi & gigasxtema, mat const& gigas) {
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
      final1(g,sol,solparcial,j+1,gigasxtema,gigas);
      if(gigas[gigasxtema.size()][j] > 0) {
        gigasxtema[i] += gigas[gigasxtema.size()][j];
        final1(g,sol,solparcial+1,j+1,gigasxtema,gigas);
        gigasxtema[i] -= gigas[gigasxtema.size()][j];
      }
    }
  }
}

void rec1(int const& g, int & sol, int & solparcial, int i, vi & gigasxtema, mat const& gigas) {
  if(i==gigasxtema.size()) {
    final1(g,sol,solparcial,0,gigasxtema,gigas);
  }
  else {
    int acc = 0; int accsol = 0;
    rec1(g,sol,solparcial,i+1,gigasxtema,gigas);
    int j = 0;
    while (j < gigas[i].size() && gigas[i][j] > 0) {
      gigasxtema[i] += gigas[i][j]; acc += gigas[i][j];
      solparcial++; accsol++;
      rec1(g,sol,solparcial,i+1,gigasxtema,gigas);
      j++;
    }
    gigasxtema[i] -= acc;
    solparcial -= accsol;
  }
}

void final2(int const& g, int & sol, int solparcial, int j, vi & gigasxtema, mat const& gigas) {
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
      final2(g,sol,solparcial,j+1,gigasxtema,gigas);
      if(gigasxtema[i] < g) {
        if(gigas[gigasxtema.size()][j] > 0) {
          gigasxtema[i] += gigas[gigasxtema.size()][j];
          final2(g,sol,solparcial+1,j+1,gigasxtema,gigas);
          gigasxtema[i] -= gigas[gigasxtema.size()][j];
        }
      }
    }
  }
}

void rec2(int const& g, int & sol, int & solparcial, int i, vi & gigasxtema, mat const& gigas) {
  if(i==gigasxtema.size()) {
    final2(g,sol,solparcial,0,gigasxtema,gigas);
  }
  else {
    int acc = 0; int accsol = 0;
    rec2(g,sol,solparcial,i+1,gigasxtema,gigas);
    int j = 0;
    while (j < gigas[i].size() && gigas[i][j] > 0 && gigasxtema[i] < g) {
      gigasxtema[i] += gigas[i][j]; acc += gigas[i][j];
      solparcial++; accsol++;
      rec2(g,sol,solparcial,i+1,gigasxtema,gigas);
      j++;
    }
    gigasxtema[i] -= acc;
    solparcial -= accsol;
  }
}

void final3(int const& g, int & sol, int solparcial, int j, vi & gigasxtema, mat const& gigas) {
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
        final3(g,sol,solparcial,j+1,gigasxtema,gigas);
        if(gigasxtema[i] < g) {
          if(gigas[gigasxtema.size()][j] > 0) {
            gigasxtema[i] += gigas[gigasxtema.size()][j];
            final3(g,sol,solparcial+1,j+1,gigasxtema,gigas);
            gigasxtema[i] -= gigas[gigasxtema.size()][j];
          }
        }
      }
    }
  }
}

void rec3(int const& g, int & sol, int & solparcial, int i, vi & gigasxtema, mat const& gigas) {
  if(solparcial < sol) {
    if(i==gigasxtema.size()) {
      final3(g,sol,solparcial,0,gigasxtema,gigas);
    }
    else {
      int acc = 0; int accsol = 0;
      rec3(g,sol,solparcial,i+1,gigasxtema,gigas);
      int j = 0;
      while (j < gigas[i].size() && gigas[i][j] > 0 && gigasxtema[i] < g) {
        gigasxtema[i] += gigas[i][j]; acc += gigas[i][j];
        solparcial++; accsol++;
        rec3(g,sol,solparcial,i+1,gigasxtema,gigas);
        j++;
      }
      gigasxtema[i] -= acc;
      solparcial -= accsol;
    }
  }
}

void final4(int const& g, int & sol, int solparcial, int j, vi & gigasxtema, mat const& gigas) {
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
        final4(g,sol,solparcial,j+1,gigasxtema,gigas);
        if(gigasxtema[i] < g) {
          if(gigas[gigasxtema.size()][j] > 0) {
            gigasxtema[i] += gigas[gigasxtema.size()][j];
            final4(g,sol,solparcial+1,j+1,gigasxtema,gigas);
            gigasxtema[i] -= gigas[gigasxtema.size()][j];
          }
        }
      }
    }
  }
}

void rec4(int const& g, int & sol, int & solparcial, int i, vi & gigasxtema, mat const& gigas) {
  if(solparcial < sol) {
    if(i==gigasxtema.size()) {
      final4(g,sol,solparcial,0,gigasxtema,gigas);
    }
    else {
      int acc = 0; int accsol = 0;
      rec4(g,sol,solparcial,i+1,gigasxtema,gigas);
      int j = 0;
      while (j < gigas[i].size() && gigas[i][j] > 0 && gigasxtema[i] < g) {
        gigasxtema[i] += gigas[i][j]; acc += gigas[i][j];
        solparcial++; accsol++;
        rec4(g,sol,solparcial,i+1,gigasxtema,gigas);
        j++;
      }
      gigasxtema[i] -= acc;
      solparcial -= accsol;
    }
  }
}

int formapolinomica(int const& g, mat const& gigas) {
  int sol = 0;
  for (size_t i = 0; i < gigas.size()-1; i++) {
    int acc = 0;
    int j = 0;
    while(j < gigas[i].size() && acc < g) {
      acc += gigas[i][j];
      sol++;
      j++;
    }
    if (acc < g) return INT_MAX;
  }
  return sol;
}
