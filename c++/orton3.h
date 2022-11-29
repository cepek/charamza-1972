#ifndef ORTON3_H
#define ORTON3_H

#include "mx.h"
#include <vector>

class Orton3
{
  int    m1, nz ,m2, n1, n2, defect;
  double tol1, tol2 ,magn;
  bool   change;

  int    m, n, nmax;
  int    /*i,*/ i1, jlast, lmin, lmax;
  double norm;

  std::vector<int> index, indort;
  std::vector<double> norms, colj, colk;

  unsigned long x;   // see random()

  void   max   (const std::vector<double>& ar,
                int lbound, int ubound, double& maxel, int& imax);
  void   lincom(int prodlb, int produb, int comblb, int combub);
  void   euclid(int i1, int i2);
  double random(double a, double b, long x0=0);
  void   ort   (Mx& A, int colmin, int colmax, bool b4, bool b5);

public:
  Orton3();
  void run(Mx& A, int m1, int nz, int m2, int n1, int n2,int defect,
           double tol1, double tol2, double magn, bool change);
};

#endif // ORTON3_H
