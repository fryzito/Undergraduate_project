#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#define dbg(x)cout<<#x<<"="<<x<<endl
bool b[100];
int p[100];
int main(){
  int q,h,l,bits;
  q=5;h=3;l=7;
  int nrobits=5;
  // inicializando el bits.
  for(int i=0;i<=nrobits;i++){
    b[i]=1;
  }
  //creando las potencias de dos
  p[0]=1;
  for(int i=1;i<=32;i++){
    p[i]=p[i-1]*2;
  }  
  
  // generando todos los bits
  for(int i=nrobits+1;i<=128;i++){
    b[i]=((b[i-h])+(b[i-q]))%2;
  }
  
  int y1;
  for(int i=1;i<=128;i+=l) {
    y1=0;
    for(int k=0;k<l;k++){
      y1+=b[i+k]*p[l-(k+1)];
    }
    //dbg(y1);
    int base = (1<<l);
    printf("%lf\n",(double)y1/base);
    //dbg(base);
  }
  // for(int i=0;i<20;i++){
  //   printf("%d ",p[i]);
  // }
  return 0;
}
