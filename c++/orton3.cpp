#include "orton3.h"
#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

Orton3::Orton3()
{
  x = 21345759609;  // see random()
}

void Orton3::max(const std::vector<double>& ar,
                 int lbound, int ubound, double& maxel, int& imax)
{
  maxel = 0.0;
  imax  = lbound;
  for (int i=lbound; i<=ubound; i++)
    if (std::abs(ar[i]) > maxel)
      {
        maxel = std::abs(ar[i]);
        imax  = i;
      }
}

void Orton3::lincom(int prodlb, int produb, int comblb, int combub)
{
  double prod = 0.0;
  for (int i=prodlb; i<=produb; i++) prod = prod + colj[i]*colk[i];
  for (int i=comblb; i<=combub; i++) colk[i] = colk[i] - prod*colj[i];
}

void Orton3::euclid(int i1, int i2)
{
  i1 = i1;

  norm = 0.0;
  for (int i=i1; i<=i2; i++) norm = norm + colk[i]*colk[i];
  norm = std::sqrt(norm);
}

double Orton3::random(double a, double b, long x0)
{
  /*  Algorithm 133
   *  Peter G. Behrenz, Matematikmaskinnämnden, Stockholm, Sweden
   *  https://doi.org/10.1145/368996.368971
   */
  // static unsigned long x  {21345759609}; ... replaced by attribute x
  const  unsigned long m35{34359738368}, m36{68719476736}, m37{137438953472};

  if (x0 != 0) x = x0;

  x = 5*x;
  if (x >= m37) x = x-m37;
  if (x >= m36) x = x-m36;
  if (x >= m35) x = x-m35;

  return double(x)/m35*(b-a)+a;
}

void::Orton3::ort(Mx& A, int colmin, int colmax, bool b4, bool b5)
{
  cout.setf(std::ios::scientific);
  cout.precision(10);

  int /*i,*/ /*j,*/ /*jj,*/ jmax, /*k,*/ rub;
  double maxim, normax;
  bool b2, b3;

  b3 = true;
  rub = n1;

  for (int i=colmin; i<=colmax; i++)
    {
      cout << "\nCOLUMN NO.: " << setw(4) << i << endl;
      int k = i;
      b2 = true;
      if (!b3) goto lab8;
lab1: cout << "TRY COL. NO." << setw(4) << k << endl;
      if (norms[k] >= 0)
        {
          cout << "SMALL NORM\n";
          goto lab4;
        }
      for (int j=1; j<=m; j++) colk[j] = A(j,k);
      if (indort[k] != 0) goto lab3;
      int j_maxim;
      max(colk, 1, m1+nz, maxim, j_maxim);
      cout << "ABSMAX[" << setw(4) << j_maxim << "," << setw(4) << k << "]="
           << setw(17) << maxim<< endl;
      if (maxim == 0)
        {
          cout << "ZERO COLUMN\n";
          if (!b4 && i==k) goto lab11;
          norms[k] = 0.0;
          goto lab4;
        }
      if (std::abs(magn - 1.0) > 0.1)
        {
          if (magn > 1.0 && j_maxim > m1) maxim = maxim*magn;
          if (magn < 1.0 && j_maxim < m1) maxim = maxim/magn;
        }
      for (int j=1; j<=m; j++) colk[j] = colk[j]/maxim;
lab3: jmax = b5 ? i-1 : n1;
      for (int j=indort[k]+1; j<=jmax; j++)
        {
          if (j != jlast) for (int jj=1; jj<=m; jj++) colj[jj] = A(jj,j);

          if (j > nz) lincom(1,m1,1,m);
          else
            {
              if (b2 || b4) lincom(lmin,lmax,1,m);
              else          lincom(1,m1,lmin,lmax);
             }

          indort[k] = indort[k]+1;
          jlast = j;
        }
      if (b4) euclid(lmin,lmax);
      else    euclid(1,m1);
      cout << "NORM[" << setw(4) << k << "]=" << setw(17) << norm << endl;
      if (norm > tol1) goto lab12;
      cout << "<TOL\n";
      if (!change)
        {
          if (norm<tol2)
            {
              cout << "<TOLMIN\n";
              goto lab10;
            }
          if (!b2) goto lab13;
          if (nz != 0) goto lab6;
          goto lab7;
        }
      if (!b2) goto lab13;
      if (!b3)
        {
          cout << "GENERATED COL. IS LIN. DEP.\n";
          goto lab9;
        }
      norms[k] = norm;
      for (int j=1; j<=m; j++) A(j,k) = colk[j];
      if (i1 != 0) goto lab5;
lab4: if (k < rub)
        {
          k = k + 1;
          goto lab1;
        }
      i1 = i - 1;
      cout << "RUBBISH\n";
lab5: i1 = i1 + 1;
      if (i1 <= n1)
        {
          if (indort[i1] == i-1 || norms[i1] < tol2) goto lab5;
          for (int j=1; j<=m; j++) colk[j] = A(j,i1);
          k = i1;
          cout << "UPDATE COL. NO. " << k << endl;
          goto lab3;
        }
      i1 = 0;
      max(norms,i,n1,normax,k); rub= k;
      cout << "BEST COL. NO. " << k << " WITH NORM " << normax << endl;
      if (normax >= tol2)
        {
          for (int j=1; j<=m; j++) colk[j] = A(j,k);
          if (!b4)
            {
lab6:         for (int j=m1+1; j<=m1+nz; j++) colk[j] = 0.0;
lab7:         b2 = false;
              cout << "REPEATED ORTHOG.\n";
            }
          else
            {
              cout << "<TOLMIN\n";
              b3 = false;
lab8:         if (nz != 0 && b4)
                {
                  n = n + 1;
                  rub = k = n1 = n1 + 1;
                  index[n] = n1;

                  jlast = 0;

                  for (int j=1; j<=m; j++) A(j,n) = A(j,n1);
                  m = m + 1;
                  m2 = m2 + 1;
                  for (int j=1; j<=n; j++) A(m,j) = 0.0;
                  cout << "REPLACE " << n1 << " --> " << n << endl;
                  index[n1] = -n1;
                  cout << "GENERATED COL. NO. " << k << endl;
lab9:             for (int j=1; j<=m-1; j++) colk[j] = 0.0;
                  for (int j=m1+1; j<=m1+nz; j++)
                    {
                      colk[j] = random(-1.0,1.0,0);
                      cout << j << " " << colk[j] << endl;
                    }
                  colk[m] = 1.0;
                }
              else
                {
lab10:          for (int j=1; j<=m1+nz; j++) A(j,i) = colk[j] = 0.0;
lab11:            cout << "LIN. DEP. COL. NO. " << index[i] << endl;
                  if (!b5) goto lab13;
                  for (int j=m1+nz+1; j<=m; j++)
                    {
                      cout << j << " ";
                      cout << (b3 ? colk[j] : A(j,i));
                      cout << endl;
                    }
                  goto lab14;
                }
            }
        }
        indort[k] = 0;
        goto lab3;
lab12:  if (!b4 && b2 and nz!=0) goto lab6;
lab13:  if (!b5) norm = maxim == 0.0 ? 1.0 : 1.0/maxim;
        if (i != k)
          {
            if (i != k) for (int j=1; j<=m; j++) A(j,k) = A(j,rub);
            int j_lokalni=index[k]; index[k]=index[rub]; index[rub]=index[i];
            index[i]=j_lokalni; norms[k]=norms[rub]; norms[rub]=norms[i];
            indort[k]=indort[rub]; indort[rub]=indort[i];
            rub = rub==k ? i : rub-1;
          }
        for (int j=1; j<=m; j++) A(j,i) = colk[j]/norm;
lab14:  if (i != index[i]) cout << "PARENT COL. NO." << index[i] << endl;
    } // i
} // ort

void Orton3::run(Mx& A, int p_m1, int p_nz, int p_m2, int p_n1, int p_n2,int p_defect,
                 double p_tol1, double p_tol2, double p_magn, bool p_change)
{
  m1 = p_m1; nz = p_nz; m2 = p_m2; n1 = p_n1; n2 = p_n2; defect = p_defect;
  tol1 = p_tol1; tol2 = p_tol2; magn = p_magn;
  change = p_change;

  m = m1+ nz + m2;
  n = n1+ n2;
  nmax = n + defect;

  index .resize(1+nmax);       // 1 based indexing
  indort.resize(1+nmax);
  norms .resize(1+nmax);
  colj  .resize(1+m+defect);
  colk  .resize(1+m+defect);

  /*i_ =*/ i1 = jlast = lmin = lmax = 0;
  norm = 0.0;

  cout << "\n" << "PROCEDURE O R T O N 3\n";


  lmin = 1; lmax = m1 + nz;
  if (nz == 0) magn = 1.0;

  for (int i=1; i<=nmax; i++)
    {
      indort[i] = 0;
      norms[i] = -1.0;
      index[i] = i;
    }
  i1 = jlast = 0;
  norm = random(-1.0, 1.0, 21348759609);
  if (magn > 1.0) { tol1 = tol1/magn; tol2 = tol2/magn; }

  if (nz != 0)
    {
      change = true;
      lmin= m1 + 1;
      cout << "\nTOL   = " << tol1 << "\nTOLMIN= " << tol2 << "\n";
      ort(A, 1, nz, true, true);
    }

  tol1 = tol1*magn;
  tol2 = tol2*magn;
  cout << "\nTOL   = " << tol1 << "\nTOLMIN= " << tol2 << "\n";

  for (int i=nz+1; i<=n1; i++) norms[i] = -1.0;
  ort(A, nz+1, n1, false, true); change = false;
  ort(A, n1+1, n, false, false);
  cout << endl;
}
