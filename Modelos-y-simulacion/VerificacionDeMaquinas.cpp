#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
#define dbg(x) cout << #x<<"="<<x<<endl
int main(){
  int n=3;
  map<int,double> mapa;
  vector<string> v;
  string s="";
  for(int mask=0;mask<(1<<n);mask++){
    s="";
    for(int j=0;j<n;j++) {
      if(mask&(1<<j)) {
	s = "1 "+s;
      }
      else {
	s = "0 "+s;
      }
    }
    v.push_back(s);
  }
  mapa[0]=0.9;
  mapa[1]=0.1;
  map<int,int> mapa2;
  mapa2[1]=10;
  mapa2[2]=20;
  mapa2[3]=50;
  vector<pair<int,double> > vec;
  for(int i=0;i<v.size();i++) {
    cout << v[i];
    double multi=1;
    int suma=0;
    int cont=0;
    for(int j=0;j<s.size();j++)
      if(isdigit(v[i][j])){
	cont++;
	if(v[i][j]=='1'){
	  cout << "  0.1";
	  multi*=mapa[1];
	  suma+=mapa2[cont];
	}
	else{
	  cout << "  0.9";
	  multi*=mapa[0];
	}
      }
    cout << "  " << multi;
    cout << "  " << suma;
    vec.push_back(make_pair(suma,multi));
    putchar('\n');    
  }
  double sump=0;
  double sum40=0;
  for(int i=0;i<vec.size();i++) {
    if(vec[i].first<60)
      sump+=vec[i].second;
    if(vec[i].first>40)
      sum40+=vec[i].second;
  }
  cout << "suma de menores 60 es: " << sump << endl;
  cout << "suma de mayores 40 es: " << sum40 << endl;
  return 0;
}
