#pragma once
#include <vector>

//https://leetcode.com/problems/richest-customer-wealth

class Solution {
public:
    int maximumWealth(std::vector<std::vector<int>>& accounts) {
        int richestWealth = 0;
        for(int i = 0; i < accounts.size(); i++){
            int customerWealth = 0;
            for(int j = 0; j < accounts[i].size(); j++){
                customerWealth+= accounts[i][j];
            }
            if(customerWealth > richestWealth)
                richestWealth = customerWealth;
        }
        return richestWealth;
    }
};
