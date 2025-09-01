#include <iostream>
#include <vector>
using namespace std;

long long int N, M;

vector<long long int> trees;
long long int maxx;

long long int sum(long long h){
    long long int r = 0;
    for(auto tree:trees){
        if(tree-h > 0) r+= tree-h;
    }
    return r;
}

long long int param(long int start, long int end){
    long long int mid = (start + end) / 2;
    long long int tmp= sum(mid);
    //cout << "tmp: " << tmp << endl;

    if(tmp == M || start==end){
        return mid;
    }
    else if (tmp > M){
        return param(mid + 1, end);
    }
    else{ // tmp < M
        return param(start, mid-1);
    }
}

int main(){
    cin >> N >> M;
    for (int i=0; i<N; i++){
        long long int tree;
        cin >> tree;
        trees.push_back(tree);
        if (i == 0) maxx = tree;
        else if (tree > maxx) maxx = tree;
    }

    // 가능한 절단기 높이 : 0~ 제일 큰 나무(max)
    long long low = 0, high = maxx;
    long long ans = 0;
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long total = sum(mid);
        if (total >= M) { 
            ans = mid; 
            /* 이거 다음에는 어차피 
            탐색 범위가 절단기 높아지는거니까
            ans = mid로 해놓고 계속계속 가면 되는거지
            */       
            low = mid + 1;
        }
        else { 
            high = mid - 1;
        }
    }

    cout << ans << endl;
}