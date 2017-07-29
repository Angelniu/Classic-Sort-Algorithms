#include<bits/stdc++.h>
using namespace std;
void InsertionSort(vector<int> &v, int left, int right) {

   for(int i = left+1; i < right; i++) {
        int tmp = v[i];
        int j = i-1;
        for(; j>=left && v[j] > tmp; j--) {
                v[j+1] = v[j];
        }
        v[j+1] = tmp;

    }
}

int main() {
    vector<int> v{6, 5, 4, 3, 2, 1};

    InsertionSort(v, 0, v.size());

    for(auto i : v) {
        cout<<i<<endl;
    }
    return 0;
}
