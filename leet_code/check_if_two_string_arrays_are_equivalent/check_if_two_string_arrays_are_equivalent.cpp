#include <string>
#include <vector>
#include "check_if_two_string_arrays_are_equivalent.h"

//https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

//1662. Check If Two String Arrays are Equivalent
//Solved
//Easy
//Topics
//premium lock icon
//Companies
//Hint
//Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.
//
//A string is represented by an array if the array elements concatenated in order forms the string.
//
// 
//
//Example 1:
//
//Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
//Output: true
//Explanation:
//word1 represents string "ab" + "c" -> "abc"
//word2 represents string "a" + "bc" -> "abc"
//The strings are the same, so return true.
//Example 2:
//
//Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
//Output: false
//Example 3:
//
//Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
//Output: true
// 
//
//Constraints:
//
//1 <= word1.length, word2.length <= 103
//1 <= word1[i].length, word2[i].length <= 103
//1 <= sum(word1[i].length), sum(word2[i].length) <= 103
//word1[i] and word2[i] consist of lowercase letters.


bool Solution::arrayStringsAreEqual(std::vector<std::string>& word1, std::vector<std::string>& word2)
{
    std::string string_word1 = "";
    std::string string_word2 = "";

    for (int i = 0; i < word1.size(); i++)
    {
        string_word1 += word1[i];
    }

    for (int j = 0; j < word2.size(); j++)
    {
        string_word2 += word2[j];
    }

    return string_word1 == string_word2;
}
