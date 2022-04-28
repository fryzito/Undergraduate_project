#include <cstdio>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
using namespace std;
#define dbg(x)cout<<#x<<"="<<x<<endl
int main(){
  int a=pow(7,5);
  int b=0;
  int m=pow(2,12)-1;
  int x0=445;
  int xn;
  printf("%lf\n",(double)x0/(double)m);//primer numero elemento
  for(int i=0;i<m;i++){
    xn = (a*x0 + b)%m;
    printf("%lf\n",(double)xn/(double)m);
    x0=xn;
  }
  return 0;
}
