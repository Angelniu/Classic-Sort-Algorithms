#include<bits/stdc++.h>
using namespace std;

void SelectionSort(vector<int> &v, int left, int right) {

    for(int i = left; i < right; i++) {
        int min_tmp = v[i];
        int pos = i;
        for(int j = i+1; j< right; j++) {
            if(min_tmp > v[j]) {
                min_tmp = v[j];
                pos = j;
            }
        }
        swap(v[i], v[pos]);

    }
}
int main() {
    vector<int> v{6, 5, 4, 3, 2, 1};

    SelectionSort(v, 0, v.size());

    for(auto i : v) {
        cout<<i<<endl;
    }
    return 0;
}

