#include<bits/stdc++.h>
using namespace std;

void Merge(vector<int> &v, int left, int mid, int right) {
    vector<int> *tmp = new vector<int>(right-left+1, 0);
        int s1= left;
        int s2 = mid+1;
        int index = 0;
        while(s1 <=mid && s2 <=right) {
            if(v[s1] < v[s2]) {
                (*tmp)[index] = v[s1];
                s1++;
            }
            else {
                (*tmp)[index] = v[s2];
                s2++;
            }
            index++;
        }

        while(s1 <=mid) {
            (*tmp)[index] = v[s1++];
            index++;
        }
        while(s2 <= right) {
            (*tmp)[index] = v[s2++];
            index++;
        }

        for(int i = right; i>=left; i--) {
            v[i] = (*tmp)[--index];
        }
        delete tmp;
}

void MergeSort(vector<int> &v, int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        MergeSort(v, left, mid);
        MergeSort(v, mid+1, right);
        Merge(v, left, mid, right);
    }
}

int main() {
   vector<int> v{6, 5, 4, 3, 2, 1};

   MergeSort(v, 0, v.size()-1);

    for(auto i : v) {
        cout<<i<<endl;
    }
    return 0;
}

