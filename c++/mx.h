#ifndef MX_H
#define MX_H


class Mx
{
public:
  Mx();
  ~Mx();

  int rows() const { return rows_; }
  int cols() const { return cols_; }

  void reset(int r, int c);
  double& operator()(int i, int j);
  void read(int m, int n, bool transp);
  void appendE0(int e1);
  void write() const;

private:
  double rows_, cols_;
  double** mem_;

  void free();
};

#endif // MX_H
