#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <iomanip>
#include <fstream>

#include "orton3.h"
#include "mx.h"

using namespace std;

int main(int argc, char* argv[])
{
  std::ifstream in;
  if (argc > 1) {
      in.open(argv[1]);
      std::cin.rdbuf(in.rdbuf());
    }

  std::ofstream out;
  if (argc > 2) {
      out.open(argv[2]);
      std::cout.rdbuf(out.rdbuf());
    }

  std::string uloha;
  std::getline(std::cin,uloha);
  while (!uloha.empty() && (std::isspace(uloha[0]) || uloha[0] == '#'))
    uloha.erase(0,1);

  cout << "# Orton3 - " << uloha << "\n\n";

  int    m1{},nz{},m2{},n1{},n2{},defect{},type{},e{},c{},m,n,e1,i,j,k;
  double tol1{},tol2{},magn{}; //,v; switch SS:=LAB;
  // LAB:
  std::cin >> m1   >> nz   >> m2
           >> n1   >> n2   >> defect
           >> type >> e    >> c
           >> tol1 >> tol2 >> magn;
  m = m1+nz+m2; n = n1+n2; e1 = e*n1;

  bool change = (c==1);

  std::cout << ""  << m1   << " " << nz  << " "   <<  m2
            << " " << n1   << " " << n2  << " "  << defect
            << " " << type << " " << e   << " "  << c
            << "   # m1 nz m2 n1 n2 defect type e c \n"
            << ""  << tol1 << " " << tol2 << " " <<  magn
            << "         # tol1 tol2 magn \n\n";

  Mx A;
  A.read(m+defect,n+defect,type==1);
  if (e1 != 0)
    {
      A.appendE0(e1);
      m2 += e1;
    }

  for (int i=1;  i<=A.rows(); i++)
    {
      for (int j=1; j<=A.cols(); j++) std::cout << setw(2) << A(i,j) << " ";
      if (i==1)std::cout << "  # vstupni matice";
      std::cout << "\n";
    }

  Orton3 orton3;
  orton3.run(A,m1,nz,m2,n1,n2,defect,tol1,tol2,magn,change);

  A.write();

  return 0;
}
