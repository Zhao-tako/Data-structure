#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int right1 = m-1, right2 = n-1;
        int prev = m+n-1;
        while(right2>=0 && right1>=0){
            if(nums1[right1]>=nums2[right2]){
                nums1[prev] = nums1[right1];
                right1--;
            }
            else{
                nums1[prev] = nums2[right2];
                right2--;
            }
            prev--;
        }
        if(right2>=0){
            while(right2>=0){
                nums1[prev] = nums2[right2];
                prev--;
                right2--;
            }
        }
        return;
    }
};

int main(){
    vector<int> x1{1,2,3,7};
    vector<int> x2{};
    Solution s1;
    s1.merge(x1,4,x2,0);
    auto it = x1.begin();
    while(it!=x1.end()){
        cout << *it << " ";
        it++;
    }
    return 0;
}