#include<bits/stdc++.h>
using namespace std;

int GetMaxBit(vector<int> &v, int left, int right) {
    int maxElement = *max_element(v.begin(), v.end());
    //cout<<maxElement<<endl;

    int bits =0;
    while(maxElement) {
        maxElement /= 10;
        bits++;
    }
    //cout<<bits<<endl;
    return bits;
}

void RadixSort(vector<int> &v, int left, int right) {
    int bits = GetMaxBit(v, left, right);
    int *tmp = new int[right-left+1];
    int *cnt = new int[10];
    int radix = 1;
    for(int i = 0 ; i< bits; i++) {

        for(int j = 0; j < 10; j++) {
            cnt[j] = 0;
        }
        for(int j = left; j<=right; j++) {
            int k = v[j] / radix % 10;
            cnt[k]++;
        }

        for(int j = 1; j< 10; j++) {
            cnt[j] = cnt[j-1] + cnt[j];
        }


        for(int j = right; j >=left; j--) {
            int k = v[j] / radix % 10;
            tmp[cnt[k]-1] = v[j];
            cnt[k] --;
        }
        for(int j = left; j <=right; j++) {
            v[j] = tmp[j];
        }


        radix = radix * 10;
    }
    delete[] tmp;
    delete[] cnt;
}

int main() {
   vector<int> v{61, 52, 43, 34, 22, 11, 101};

   RadixSort(v, 0, v.size()-1);

    for(auto i : v) {
        cout<<i<<endl;
    }
    return 0;
}

