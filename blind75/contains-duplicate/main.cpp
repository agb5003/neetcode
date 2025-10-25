#include <iostream>
#include <vector>
#include <set>

bool hasDuplicate(std::vector<int>& nums)
{
    // Convert the vector into a set and compare sizes. If the sizes are different there are
    // duplicate elements in the vector.
    std::set numSet(nums.begin(), nums.end());

    return (nums.size() != numSet.size());
}

int main()
{
    std::vector<int> nums1 = {1,2,3,4};
    std::vector<int> nums2 = {2,2,3,4};
    
    std::cout << hasDuplicate(nums1) << ", " << hasDuplicate(nums2) << '\n';    
}