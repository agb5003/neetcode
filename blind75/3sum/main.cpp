#include <vector>
#include <iostream>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int> nums)
{
    std::vector<std::vector<int>> output;
    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        int j = i + 1;
        int k = nums.size() - 1;

        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];

            if (sum < 0) j++;
            else if (sum > 0) k--;
            else
            {
                output.push_back({nums[k], nums[j], nums[i]});
                j++;
                while (nums[j] == nums[j-1] & j < k) j++;
            }
        }
    }
    return output;
}

int main()
{
    std::vector<int> nums = {0,0,0};

    std::vector<std::vector<int>> result = threeSum(nums);

    std::cout << '{';
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << '{';
        for (int j = 0; j < result[i].size(); j++)
        {
            std::cout << result[i][j];
            if (j != result[i].size()-1) std::cout << ", ";
        }
        if (i != result.size()-1) std::cout << "}, ";
        else std::cout << "}}";
    }
}