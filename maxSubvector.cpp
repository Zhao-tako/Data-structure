#include <iostream>
#include <vector>
#include <algorithm>    
using namespace std;

int Partition(vector<int>& x, int left, int right){
    if(left==right) return x[left];
    else{
        int n = right-left;
        int leftmax,rightmax;
        if(n==1){
            leftmax = x[left];
            rightmax = x[right];
        }
        else{
            int mid = (left+right)/2;
            int thisLeft = x[mid], thisRight = x[mid+1];
            leftmax = x[mid];
            for(int i=mid-1; i>=left; i--){
                thisLeft += x[i];
                if(thisLeft>leftmax)
                    leftmax = thisLeft; 
            }

            rightmax = thisRight;
            for(int i = mid+2; i<=right; i++){
                thisRight += x[i];
                if(thisRight>rightmax)
                    rightmax = thisRight;
            }

        }
        
        int max1 = max(Partition(x,left,left+n/2 ),Partition(x,left+n/2+1,right));
        int max2 = max(max1,leftmax+rightmax);
        return max2;
    }
}
class Solution {
public:
    int maxSubArray(vector<int>& nums);
};

int Solution::maxSubArray(vector<int>& nums){
    int n = nums.size();
    return Partition(nums,0,n-1);
}



int main(){
    Solution s1;
    vector<int> nums {-2,1,-3,4,-1,2,1,-5,4};
    int ret = s1.maxSubArray(nums);
    cout<<ret;

    return 0;
}