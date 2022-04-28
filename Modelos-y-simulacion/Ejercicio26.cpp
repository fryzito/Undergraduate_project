#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int main(){
  int A[4] = {1,2,3,4};
  map<int,int> mapa;
  do{
    printf("%d %d %d %d\n",A[0],A[1],A[2],A[3]);
    int cont=0;
    for(int i=1;i<=4;i++)
      if(i==A[i-1])
	cont++;
    mapa[cont]++;
  } while(next_permutation(A,A+4));
    putchar('\n');
    for(int i=0;i<=4;i++)
      printf("%d ",mapa[i]);
    putchar('\n');
    for(int i=0;i<=4;i++)
      printf("%lf ",(double)mapa[i]/24.0);
    putchar('\n');
  return 0;
}
