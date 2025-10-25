/*
Given an integer array `nums`, return an array `output` where `output[i]` is the product of all the elements of `nums` except `nums[i]`.

Each product is guaranteed to fit in a 32-bit integer.

Follow-up: Could you solve it in O(n) time without using the division operation?
*/

#include <iostream>
#include <vector>

// Naive solution (not O(n))
std::vector<int> naiveProductExceptSelf(std::vector<int>& nums)
{
    std::vector<int> products;
    for (auto& i : nums)
    {
        products.push_back(1);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if (i != j)
            {
                products[i] *= nums[j];
            }
        }
    }

    return products;
}

// O(n) solution
std::vector<int> productExceptSelf(std::vector<int>& nums)
{
    std::vector<int> products(nums.size(), 1);

    products[0] = 1;
    // Fill with product of elements to the left of products[i]
    for (int i = 1; i < nums.size(); i++)
    {
        products[i] = products[i-1] * nums[i-1];   
    }
    // Multiply prefix products with postfix products
    int postfixProduct = 1;
    // Since there are no elements to the right of the last one, start with second to last
    for (int i = nums.size()-2; i >= 0; i--)
    {
        postfixProduct *= nums[i+1];
        products[i] *= postfixProduct;
    }

    return products;
}

int main()
{
    std::vector<int> nums1 = {1, 2, 4, 6};
    std::vector<int> products1 = naiveProductExceptSelf(nums1);

    std::vector<int> nums2 = {-1, 0, 1, 2, 3};
    std::vector<int> products2 = productExceptSelf(nums2);

    std::cout << "products1: ";
    for (auto& prod : products1)
    {
        std::cout << prod << std::endl;
    }

    std::cout << "products2: ";
    for (auto& prod : products2)
    {
        std::cout << prod << std::endl;
    }
}