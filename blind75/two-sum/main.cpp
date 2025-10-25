#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target)
{
    std::unordered_map<int, int> differenceMap;

    for (int i = 0; i < nums.size(); i++)
    {
        int difference = target - nums[i];
        if (differenceMap.count(nums[i]) == 0)
        {
            differenceMap[difference] = i;
        } else {
            return {differenceMap[nums[i]], i};
        }
    }

    return {0, 0};
}

int main()
{
    int target = 7;
    std::vector<int> nums = {5,6,3,4};

    std::vector<int> result = twoSum(nums, target);

    std::cout << result[0] << ", " << result[1];
    std::cout << std::endl;
}