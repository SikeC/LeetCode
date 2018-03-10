#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        int tmp;
        vector<int> res;
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++){         
            for(vector<int>::iterator cursor = it+1; cursor != nums.end(); cursor++){
                if((*it+*cursor) == target){
                    tmp = it-nums.begin();
                    res.push_back(tmp);
                    tmp = cursor-nums.begin();
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
};

int main(){
    vector<int> num,res;
    Solution S;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    num.push_back(4);
    num.push_back(5);
    num.push_back(6);
    num.push_back(7);
    res = S.twoSum(num,5);
    for(vector<int>::iterator it = res.begin(); it != res.end(); it++){
        cout<<*it<<endl;
    }
    return 0;
}