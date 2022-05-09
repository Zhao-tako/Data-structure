#include <iostream>
#include <vector>
#include <array>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret{};
        unordered_multiset<int> s;

        // construct a hash table based on x1
        int n1 = nums1.size();
        for(int i = 0; i < n1; i++){
            s.emplace(nums1[i]);
        }
    
        // main step
        int n2 = nums2.size();
        for(int i = 0; i < n2; i++)
        {
            auto it = s.find(nums2[i]);
            if(it != s.end() ){ // find the target
                ret.push_back(nums2[i]);
                s.erase(it);
            }
        }
        return ret;
    }
};

int main(){
    vector<int> x1 = {9,4,9,8,4};
    vector<int> x2 = {9,8,4,9,5,7,9};
    vector<int> ret{};
    unordered_multiset<int> s;

    Solution s1;
    ret = s1.intersect(x1,x2);
    // // construct a hash table based on x1
    // int n1 = x1.size();
    // for(int i = 0; i < n1; i++){
    //     s.emplace(x1[i]);
    // }
    
    // // main step
    // int n2 = x2.size();
    // for(int i = 0; i < n2; i++)
    // {
    //     auto it = s.find(x2[i]);
    //     if(it != s.end() ){ // find the target
    //         ret.push_back(x2[i]);
    //         s.erase(it);
    //     }
    // }
    deque<int> my{1,2,3};
    queue<int> my_queue(my);
    for(auto it = ret.begin(); it!=ret.end(); it++)
        cout<<*it<<" ";
    return 0;

}