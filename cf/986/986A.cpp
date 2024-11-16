#include <iostream>



using namespace std;


bool calculate_old(int n, int a, int b, string& s) {
  int x = 0, y = 0;
  bool finded = false;
  for (int i = 0; i < n; ++i) {
    char c = s[i];
    if (c == 'N')
      y += 1;
    if (c == 'S')
      y -= 1;
    if (c == 'E')
      x += 1;
    if (c == 'W')
      x -= 1;
    if (x == a && b == y) {
      finded = true;
      break;
    }
  }

  int x_loop = x;
  int y_loop = y;
  if (finded) {
    return true;
  }

  if (x_loop == a && y_loop == b) {
    return true;
  }

  x = 0, y = 0;

  for (int i = 0; i < n; ++i) {
    char c = s[i];
    if (c == 'N')
      y += 1;
    if (c == 'S')
      y -= 1;
    if (c == 'E')
      x += 1;
    if (c == 'W')
      x -= 1;

    if (x_loop == 0 && y_loop == 0)
      break;

    if (x_loop == 0) {
      if (a == x && (b - y) % y_loop == 0 && (b - y) / y_loop >= 0) {
        finded = true;
        break;
      }
    }
    else if (y_loop == 0) {
      if ((a - x) % x_loop == 0 && b == y && (a - x) / x_loop >= 0) {
        finded = true;
        break;
      }
    }
    else if ((a - x) % x_loop == 0 && (b - y) % y_loop == 0) {
      int bei = (a - x) / x_loop;
      int bei2 = (b - y) / y_loop;
      if (bei == bei2 && bei > 0) {
        finded = true;
        break;
      }
    }
  }

  return finded;
}

bool calculate_new(int n, int a, int b, string& s){
  int x = 0, y = 0;
  bool finded2 = false;
  for (int j = 1; j <= 1000 && !finded2; j++) {
    for (int i = 0; i < n; ++i) {
      char c = s[i];
      if (c == 'N')
        y += 1;
      if (c == 'S')
        y -= 1;
      if (c == 'E')
        x += 1;
      if (c == 'W')
        x -= 1;

      if (x == a && y == b) {
        finded2 = true;
        break;
      }
    }
  }
  return finded2;
}

int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    if (a == 0 && b == 0) {
      printf("YES\n");
      continue;
    }
    bool finded = calculate_old(n, a, b, s);
    //bool finded2 = calculate_new(n,a,b,s);

    //if (finded == finded2) {
      printf(finded ? "YES\n" : "NO\n");
    //}
    //else {
    //  cout << n << "_" << "_" << a << "_" << b << "_" << s << endl;
    //}
  }

  return 0;
}