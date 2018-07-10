#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int maxArea(vector<int>& height) {
    int left, right, area;
    if (height.size()<2) {
      return -1;
    }
    left=0;
    right=height.size()-1;
    area=(height[left]<height[right]?height[left]*(right-left):height[right]*(right-left));
    while(right-left)
    {
      height[left] < height[right] ? left++ : right--;
      area = max(area, (height[left] < height[right]
                            ? height[left] * (right - left)
                            : height[right] * (right - left)));
    }
    return area;
  }
};

int main() { return 0; }