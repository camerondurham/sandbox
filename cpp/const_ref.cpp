const int &ret(int &x) { return x; }
int main() {
  int x = 1;
  x = ret(x);
  int y = ret(x);
  const int z = ret(x);
  const int &x1 = ret(x);

  // int& x2 = ret(x); // COMPILE ERROR
  int c = ret(x);
  c++;
}
