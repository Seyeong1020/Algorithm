#include <stdio.h>
#include <vector>

using namespace std;

vector<int>zero(41, -1);
vector<int>one(41, -1);
void fibo(int n){
    if (zero[n]!=-1 && one[n]!=-1) return;
    if(n==0){
        zero[0] = 1;
        one[0] = 0;
        return;
    }
    else if(n==1){
        zero[1] = 0;
        one[1] = 1;
        return;
    }
    fibo(n-1); fibo(n-2);
    zero[n] = zero[n-1] + zero[n-2];
    one[n] = one[n-1] + one[n-2];
}

int main(){
    int T;
    scanf("%d", &T);
    for (int i=0; i<T; i++){
        int N;
        scanf("%d", &N);
        fibo(N);
        printf("%d %d\n", zero[N], one[N]);
    }
}