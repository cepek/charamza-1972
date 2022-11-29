#include "mx.h"
#include <iostream>
#include <iomanip>

Mx::Mx()
{
  rows_ = cols_ = 0;
  mem_ = nullptr;
}

Mx::~Mx()
{
  free();
}

void Mx::free()
{
  for (int i=1; i<=rows_; i++)
    {
      double* r = mem_[i];
      delete[] r;
    }

  delete[] mem_;
  mem_ = nullptr;
  cols_ = rows_ = 0;
}

void Mx::reset(int r, int c)
{
  if (rows_ > 0) free();

  mem_ = new double*[r+1];
  for (int i=1; i<=r; i++) mem_[i] = new double[c+1];

  rows_ = r;
  cols_ = c;
}

double& Mx::operator()(int i, int j)
{
  return mem_[i][j];
}

void Mx::read(int m, int n, bool transp)
{
  if (rows_ != m || cols_ != n) reset(m,n);

  if (transp) std::swap(m,n);
  double d;
  for (int i=1; i<=m; i++)
    for (int j=1; j<=n; j++)
      {
        std::cin >> d;
        if (transp) mem_[j][i]=d; else mem_[i][j]=d;
      }
}

void Mx::write() const
{
  using std::cout;
  using std::setw;
  using std::setprecision;

  const int maxcol=4;
  int first_col=0;

  //cout << "\n";
  while (first_col < cols_)
    {
      cout << "\n";

      for (int c=1; c<=maxcol && first_col+c<=cols_; c++)
        {
          cout << setw(17) <<  first_col+c << " ";
        }
      cout << "\n\n";

      cout.setf(std::ios::scientific);
      for (int r=1; r<=rows_; r++)
        {
          cout << setw(4) << std::right << r  << "   ";
          for (int c=1; c<=maxcol && first_col+c<=cols_; c++)
            {
              cout << setw(17) << setprecision(9)
                   << mem_[r][first_col+c] << " ";
            }
          cout << "\n";
        }

      first_col += maxcol;
    }
}

void Mx::appendE0(int e1)
{
  if (e1 == 0) return;

  double** new_mem = new double*[rows()+1+e1];
  for (int r=1; r<=rows(); r++) new_mem[r] = mem_[r];
  delete[] mem_;
  mem_ = new_mem;

  for (int t=1; t<=e1; t++)
    {
      double* new_row = new double[cols()+1];
      for (int c=1; c<=cols(); c++)
        {
          new_row[c] = 0.0;
        }
      new_row[t] = 1.0;
      mem_[rows()+t] = new_row;
    }

  rows_ += e1;
}
