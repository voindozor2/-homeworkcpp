#pragma once
#include <set>
#include <vector>
#include "Intersection_of_two_arrays.h"

//https://leetcode.com/problems/intersection-of-two-arrays/

//349. Intersection of Two Arrays
//Solved
//Easy
//Topics
//premium lock icon
//Companies
//Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.
//
// 
//
//Example 1:
//
//Input: nums1 = [1,2,2,1], nums2 = [2,2]
//Output: [2]
//Example 2:
//
//Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//Output: [9,4]
//Explanation: [4,9] is also accepted.
// 
//
//Constraints:
//
//1 <= nums1.length, nums2.length <= 1000
//0 <= nums1[i], nums2[i] <= 1000

std::vector<int> Solution::intersection(std::vector<int>& nums1, std::vector<int>& nums2)
{
    std::set<int> uniqueInts;
    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            if (nums1[i] == nums2[j])
            {
                uniqueInts.insert(nums1[i]);
            }
        }
    }
    std::vector<int> myVector;
    for (int key : uniqueInts)
    {
        myVector.push_back(key);
    }

    return myVector;
}
