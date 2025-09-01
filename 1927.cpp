#include <iostream>
#include <queue>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);    
    priority_queue<int, vector<int>, greater<int>> pq;

    int N;
    cin >> N;
    int x;
    for (int i=0; i<N; i++){
        cin >> x;
        if(x == 0){
            if (pq.empty()){
                cout << 0 << "\n";
            }
            else{
                int t = pq.top();
                cout << t << "\n";
                pq.pop();
            }
            
        }
        else{
            pq.push(x);
        }
    }
}