#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int k;
vector<char> inequality;

void find_max(){
    vector<int> num = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    string maxx = "";
    for (int i=0; i<k; i++){
        if(inequality[i]=='<'){
            int count = 0;
            for (int j=i; j<k; j++){
                if(inequality[j]=='<') count++;
                else if(inequality[j]=='>') break;
            }
            maxx+=to_string(num[num.size()-1-count]);
            num.erase(num.end()-1-count);
        }
        else if(inequality[i]=='>'){
            maxx += to_string(num.back());
            num.pop_back();
        }
        else{
            printf("wrong input\n");
            return;
        }
    }
    maxx += to_string(num.back());
    cout << maxx << endl;
}

void find_min(){
    vector<int> num = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    string minn = "";
    for (int i=0; i<k; i++){
        if(inequality[i]=='<'){
            minn += to_string(num[0]);
            num.erase(num.begin());
        }
        else if(inequality[i]=='>'){
            int count = 0;
            for (int j=i; j<k; j++){
                if(inequality[j]=='>') count++;
                else if(inequality[j]=='<') break;
            }
            minn+=to_string(num[count]);
            num.erase(num.begin()+count);
        }
        else{
            printf("wrong input\n");
            return;
        }
    }
    minn += to_string(num[0]);
    cout << minn << endl;

}

int main(){
    scanf("%d", &k);
    inequality.resize(k);
    char c;
    for (int i=0; i<k; i++){
        scanf(" %c", &inequality[i]);
    }

    
    find_max();
    find_min();
}