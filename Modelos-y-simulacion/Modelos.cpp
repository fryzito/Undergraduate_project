#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
using namespace std;
#define sqr(x) x*x
#define dbg(x)cout<<#x<<"="<<x<<endl
string nro2string(long long n){
  stringstream ss;
  ss<<n;
  return ss.str();
}
double string2double(string n){
  istringstream ss(n);
  double nro;
  ss >> nro;
  return nro;
}
int string2nro(string n){
  istringstream ss(n);
  long long nro;
  ss >> nro;
  return nro;
}
int numdigitos(long long n){
  int cont=0;
  while(n!=0){
    n/=10;
    cont++;
  }
  return cont;
}
int main(){
  long long semilla = 10;
  int m = 1; //NumeroDigitos
  int n = 10;
  printf("semilla inicial %lld\n",semilla);
  printf("valor de n = %d\n",m);
  for(int i=0;i<n;i++) {
    semilla = sqr(semilla);
    string s = nro2string(semilla);
    if(s.size()%2==0) {
      int inicio = s.size()/2;
      inicio-=m;
      string s2=s.substr(inicio,2*m);
      int nro= string2nro(s2);
      s2 = "0."+s2;
      double nro2 = string2double(s2);
      printf("%lf\n",nro2);
      semilla=nro;
    } else {
      s = '0'+s;

      int inicio=s.size()/2;
      inicio-=m;
      string s2=s.substr(inicio,2*m);
      int nro = string2nro(s2);;
      s2 = "0."+s2;
      double nro2 = string2double(s2);
      printf("%lf\n",nro2);
      semilla=nro;      
    }
  }
  return 0;
}
