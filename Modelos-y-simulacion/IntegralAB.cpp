#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
using namespace std;
#define sqr(x) x*x
#define dbg(x)cout<<#x<<"="<<x<<endl
#define dbg2(x,y)cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl
#define pb push_back
vector<double> Congruencial(int pa,int pb,int pm,int px0,int nro){
  int a=pa;
  int b=pb;
  int m=pm;
  int x0=px0;
  int xn;
  vector<double> v;
  printf("%lf\n",(double)x0/(double)m);//primer numero elemento
  for(int i=0;i<nro;i++){
    xn = (a*x0 + b)%m;
    v.pb((double)xn/(double)m);
    x0=xn;
  }
  return v;
}
double f1(double x){
  return x*log(x);
}
double f2(double x){
  return 1.0/(1.0+(x*x));
}
double B[5]={0.9179,0.6236,0.0613,0.1506,0.8763};
int main(){
  int a=2,b=4,n=10000;
  vector<double> Ar= Congruencial(pow(7,5),0,pow(2,12)-1,445,n);
  double x;
  double Integral=0;
  for(int i=0;i<n;i++){
    x=(double)a+((b-a)*Ar[i]);
    //dbg2(Ar[i],x);
    Integral=Integral+f1(x);
  }
  dbg(Integral);
  Integral = (b-a)*(Integral/n);
  printf("%lf\n",Integral);
  return 0;
}
