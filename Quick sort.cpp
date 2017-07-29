#include<bits/stdc++.h>
using namespace std;
int Partition(vector<int> &v, int left, int right) {
    int mid = left + (right - left) / 2;
    int pivot = v[mid];
    while(left <= right) {
         while(v[left] < pivot) {
            left++;
        }
        while(v[right] > pivot) {
            right--;
        }
        if(left <= right) {
            swap(v[left], v[right]);
            left++;
            right--;
        }
    }
    return left;

}

int Partition2(vector<int> &v, int left, int right) {
    int pivot = v[(left+right) / 2];
    swap(v[(left+right) / 2], v[right]);
    int index = left;
    for(int i = left; i <right; i++){
        if(v[i] <= pivot) {
            swap(v[i], v[index]);
            index++;
        }
    }
    swap(v[index], v[right]);
    return index;
}
void QuickSort(vector<int> &v, int left, int right) {
    if(left < right) {
        int index = Partition2(v, left, right);
        QuickSort(v, left, index-1);
        QuickSort(v, index+1, right);
        //int index = Partition(v, left, right);
        //QuickSort(v, left, index-1);
        //QuickSort(v, index, right);
    }
}

int main() {
    vector<int> v{6, 5, 4, 3, 2, 1};

    QuickSort(v, 0, v.size()-1);

    for(auto i : v) {
        cout<<i<<endl;
    }
    return 0;
}

