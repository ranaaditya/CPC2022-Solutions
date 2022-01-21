/**
 * @file Question2.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2022-01-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<bits/stdc++.h>
using namespace std;
/**
 * @brief Decreasing Monotonous Queue will be used.
 * 
 * Time Complexity: O(N)
 * 
 * Space Complexity: O(N) (worst case)
 * 
 * @param temperatures 
 * @return vector<int> 
 */
vector<int> Solution(vector<int> temperatures) {
    int numberOfDays = temperatures.size();
    vector<int> nextHighTemperatures(numberOfDays, 0);
    deque<int> indices;
    indices.push_back(numberOfDays-1);
    
    for(int i = numberOfDays-2; i >= 0; i--) {
        
        while( !indices.empty() && temperatures[indices.back()] <= temperatures[i]) {
            indices.pop_back();
        }

        if(!indices.empty())
        nextHighTemperatures[i] = indices.back() - i;

        indices.push_back(i);
    }

    return nextHighTemperatures;
}

// space optimized solution O(1)
vector<int> optimizedSolution(vector<int> temperatures) {
    int length = temperatures.size();
    vector<int> nextHighTemperature(length, 0);
    int maxTemperature = 0;

    for(int i = length-1; i >= 0; i--) {
        int currentTemperature = temperatures[i];

        if(currentTemperature >= maxTemperature){
            maxTemperature = currentTemperature;
            continue;
        }

        int days = 1;
        while(temperatures[i + days] <= currentTemperature) {
            days += nextHighTemperature[i + days];
        }

        nextHighTemperature[i] = days;
    }

    return nextHighTemperature;
}

int main() {
    vector<int> input = {78, 76, 77, 89, 75, 78, 84, 100};
    auto output = optimizedSolution(input);

    for (auto x : output)
    cout << x << ", ";

    cout << endl;

    return 0;
}