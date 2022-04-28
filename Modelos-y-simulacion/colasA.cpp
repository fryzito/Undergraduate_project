#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<cstring>
#include<algorithm>
#include<sstream>
#define ll long long
#define VI vector<int>
#define REPN(i,x,y) for(int i=x;i<y;i++)
#define REP(i,y) REPN(i,0,y)
#define REPR(i,y,x) for(int i=y;i>=x;i--)
#define CLR(A,x) memset(A,x,sizeof(A))
#define INF (1<<30)
#define eps (1e-9)
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define pb push_back
#define mp make_pair
#define sqr(x) (x)*(x)
#define dbg(x) cout << #x << " = " << x << endl
#define dbg2(x,y)cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl
#define S(x)scanf("%d\n",&x)
#define P(x)printf("%d\n",x);
#define f first
#define s second
#define MAXN 100005
using namespace std;
string i2s(int x) { stringstream ss; ss << x; return ss.str();}
int s2i(string str) { istringstream ss(str);int nro; ss >> nro; return nro;}
#define E 2.718281828
int main(){
  printf("*************************Problema 1 ******************************\n");
  double mu,lamda;
  mu = (1.0/3.0);
  lamda = 0.25;
  double p = lamda/mu;
  double p0=pow(p,0)*(1-p);
  printf("p0=%lf\n",p0);

  double p1=pow(p,1)*(1-p);
  dbg(p1);
  double sum=0;
  for(int i=0;i<=2;i++)
    sum+=pow(p,i)*(1-p);
  printf("por lo menos 3 = %lf\n",1-sum);
  // La longitud media de la fina de espera
  double lq=(pow(p,2)/(1-p));
  printf("Longitud media de la fila de espera  = %lf\n",lq);  
  //  Tiempo medio de espera en la fila.
  double wq=lq/lamda;
  printf("Tiempo medio de espera  = %lf\n",wq);  
  // probabilidad de que un client este mas de 5 minutos en  la pasteleria
  double w = (1.0/(mu-lamda));
  printf("Tiempo medio de espera  = %lf\n",w);
  // Probabilidad de que un cliente este mas de 3 minutos a la espera para comenzar a ser atendido
  double wq3 = p*(exp(-3/w));
  printf("Probabilidad de un cliente a la espera de ser atendido = %lf\n",wq3);
  printf("Pregunta nro 2:\n");
  // Propietario
  mu=0.729;
  lamda= 15.0/60.0;
  double wq2 = ((lamda/mu)/(mu-lamda));
  printf("Duracion media del atendimiento del cliente %lf\n",wq2);
  // ******************************************************************************


  printf("*************************Problema 2 ******************************\n");
  mu = (1.0/3.0);
  lamda = 0.25;
  p = lamda/(2*mu);
  p0=pow(p,0)*(1-p);
  
  printf("p0=%lf\n",p0);
  p0=pow(p,0)*(1-p);
  //  printf("p0=%lf\n",p0);

  p1=pow(p,1)*(1-p);
  dbg(p1);
  sum=0;
  for(int i=0;i<=2;i++)
    sum+=pow(p,i)*(1-p);
  printf("por lo menos 3 = %lf\n",1-sum);
  // La longitud media de la fina de espera
  lq=(pow(p,2)/(1-p));
  printf("Longitud media de la fila de espera  = %lf\n",lq);  
  //  Tiempo medio de espera en la fila.
  wq=lq/lamda;
  printf("Tiempo medio de espera  = %lf\n",wq);  
  // probabilidad de que un client este mas de 5 minutos en  la pasteleria
  w = (1.0/(mu-lamda));
  printf("Tiempo medio de espera  = %lf\n",w);
  // Probabilidad de que un cliente este mas de 3 minutos a la espera para comenzar a ser atendido
  wq3 = p*(exp(-3/w));
  printf("Probabilidad de un cliente a la espera de ser atendido = %lf\n",wq3);
  printf("Pregunta nro 2:\n");
  // Propietario
  mu=0.729;
  lamda= 15.0/60.0;
  wq2 = ((lamda/mu)/(mu-lamda));
  printf("Duracion media del atendimiento del cliente %lf\n",wq2);
  // problema nro dos

  return 0; 
}
