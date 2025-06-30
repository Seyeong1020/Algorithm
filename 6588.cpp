#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>

std::vector<int> prime;

void makePrimeArr(){
    int n = 1000001;
    prime.assign(n, 0);
    for (int i =2; i<= sqrt(n); i++){
        if (prime[i]==0){
            for (int j =2; i*j<n; j++){
                prime[i*j]  = 1;
            }
        }
    }
}

void solve(int n){
    std::vector<int>::iterator iter;

    for (iter = prime.begin()+3; *iter<(n/2); iter+=2){
        if (*iter==0 && prime[n-(iter-prime.begin())]==0){
            printf("%d = %d + %d\n", n, iter-prime.begin(), n-(iter-prime.begin()));
            return;
        }
    }
}

int main(){
    makePrimeArr();

    int N;
    while(1){
        scanf("%d", &N);
        if (N == 0) break;
        solve(N);
    }
    return 0;
}