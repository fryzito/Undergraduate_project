#include <cstdio>
#include <algorithm>
usinf namespace std;
int main(){
  int A[4] = {1,2,3,4};
  do{
    printf("%d %d %d %d\n",A[0],A[1],A[2],A[3]);
  } while(next_permutation(A,A+4));
  return 0;
}
