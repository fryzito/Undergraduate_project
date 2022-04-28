#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
int f(string s) {
  int id=s.find("SSS");
  if(id!=-1)
    return id;
  else
    return -1;
}
int main(){
  int mask=0;
  int n=8;
  int e=3;
  vector<string> v;
  for(int mask=0;mask<(1<<n);mask++) {
    string s="";
    for(int j=0;j<e;j++) {
      if(mask&(1<<j)){
	s="S"+s;
      } else {
	s="F"+s;
      }
    }
    if(mask>=(1<<e)-1) e++;
    v.pb(s);
  }
  int rpta;
  vector<pair<int,string> > vec;
  for(int i=0;i<v.size();i++){
    rpta=f(v[i]);
    if(rpta!=-1){
      cout << v[i] << " " << rpta+3 << endl;
      vec.pb(mp(rpta+3,v[i]));
    }
    else
      cout << v[i] <<" No se logra el objetivo " << endl;
  }
  sort(vec.begin(),vec.end());
  cout << " los menores valores son: " << endl;
  for(int i=0;i<vec.size();i++){
    cout << vec[i].s << " " << vec[i].f << endl;
  }
  return 0;
}
