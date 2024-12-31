#include<iostream>
#include<vector>

using namespace std;

void mergesort(vector <int> &arr, int start, int end){
      if(start >= end){
            return;
      }
      // int mid = (start + end)/2; // this may cause integer overflow
      int mid = start + (end - start) / 2;
      mergesort(arr, start, mid);
      mergesort(arr, mid+1, end);

      // now merge 
      int pLeft = start;
      int pRight = mid + 1;

      // 1 3 5 12   2 4 6
      vector<int> temp;
      while(pLeft <= mid && pRight <= end) {
            if (arr[pLeft] < arr[pRight]) {
                  temp.push_back(arr[pLeft]);
                  pLeft++;
            } else {
                  temp.push_back(arr[pRight]);
                  pRight++;
            }
      }

      while (pLeft <= mid) {
            temp.push_back(arr[pLeft]);
            pLeft++;
      }

      while (pRight <= end) {
            temp.push_back(arr[pRight]);
            pRight++;
      }

      // 4 3 2 1 -9 -10
      // 1 -9 -10
      // 1 -9, -10
      //-9 1, -10
      // tamp -10, -9, 1
      //
      int idx = 0;
      for (int i = start; i <= end; i++) {
            arr[i] = temp[idx];
            idx++;
      }

      return;
}

int main(){
      vector<int> arr  = {7, -10, 14, 12, 16};
      // arr.push_back(13);
      mergesort(arr, 0, arr.size() - 1);

      for(int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
      }
      cout << endl;
}