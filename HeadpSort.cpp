#include<bits/stdc++.h>
using namespace std;


void Max_Heapify(vector<int> &v, int left, int right) {
    int dad = left;
    int son = dad*2+1;
    while(son <= right) {
        if(son+1 <=right && v[son] < v[son+1]) {
            son++;
        }
        if(v[son] < v[dad]) return;
        else {
            swap(v[son], v[dad]);
            dad = son;
            son = dad *2+1;
        }
    }
}

void HeapSort(vector<int> &v, int left, int right) {

    for(int i = left + (right-left)/2  - 1; i >=0; i--) {
         Max_Heapify(v, i, right-1);
    }
    for(int i = right-1; i >=0; i--) {
        swap(v[left], v[i]);
        Max_Heapify(v, left, i-1);
    }

}


int main() {
   vector<int> v{6, 5, 4, 3, 2, 1};

   HeapSort(v, 0, v.size());

    for(auto i : v) {
        cout<<i<<endl;
    }
    return 0;
}

