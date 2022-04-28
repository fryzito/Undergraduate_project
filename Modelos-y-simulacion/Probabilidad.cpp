#include <cstdio>
using namespace std;
int main(){

  for(int i=1;i<=20;i++) {
    printf("La probabilidad de que %d bits tengan acierto es %f \n",i,((double)i/20)* 0.9);
  }
}
