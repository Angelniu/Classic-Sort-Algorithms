#include<bits/stdc++.h>
using namespace std;

void BubbleSort(vector<int> &v, int left, int right) {
     for(int i = left; i < right; i++) {
        bool flag = false;
        for(int j = 0; j < right-i-1; j++) {
            if(v[j] > v[j+1]) {
                swap(v[j], v[j+1]);
                flag = true;
            }
        }
        if(!flag) break;
    }
}

int main() {
    vector<int> v{6, 5, 4, 3, 2, 1};

    BubbleSort(v, 0, v.size());

    for(auto i : v) {
        cout<<i<<endl;
    }
    return 0;
}
