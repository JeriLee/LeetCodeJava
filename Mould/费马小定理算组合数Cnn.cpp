////feima xiao dingli
//
//const long long mod = 1e9 + 7;
//const int CMAXN = 105;
//long long C[CMAXN][CMAXN];
//
//void init() {
//  for (int i = 0; i < CMAXN; ++i) {
//    for (int j = 0; j <= i; ++j) {
//      if (!j) C[i][j] = 1;
//      else C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
//    }
//  }
//}
//
//bool is_init = false;
//
//long long getC(int a, int b) {
//  if (is_init == false) {
//    is_init = true;
//    init();
//  }
//  return C[a][b];
//}