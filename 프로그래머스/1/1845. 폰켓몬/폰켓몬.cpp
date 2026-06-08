#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int n = nums.size();
    
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    
    return (nums.size() > n / 2 ? n / 2 : nums.size());
}