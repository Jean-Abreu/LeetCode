#include <iostream>
#include <vector>
#include <unordered_map>
//Problem: Given an array and a target value, find two values in the array that equal to target.
//Return should be of the indices of the two elements summed to equal the target.

//There is two approaches I will use for this problem. First, will be the brute force approach.
//To perform this, I will be using a nested for loop that almost simulates the sliding window technique.
//The issue with this algorithm in this context, is we potentially would need to explore n * n number of variables.

//The second approach I will be taking to solve this problem will be using a hash map. Although, we will not only use the hash map
//We will incorporate a hashing function that will check to see if our solution is in the map before adding the value. 
//This will allow us to solve this problem with a Big O time complexity of O(n)

//Brute force
// std::vector<int> twoSumBF(std::vector<int>& arr, int target){
//     for(int i = 0; i < arr.size(); i++){
//         for(int j = i + 1; j < arr.size(); j++){
//             if( arr[i] + arr[j] == target){
//                 return {i, j};
//             }
//         }
//     }
//     return {};
// }

//HashMap 
std::vector<int> twoSumHM(std::vector<int>& nums, int target){
    std::unordered_map<int, int> m; //Creating a map with (value, index)
    for(int i = 0; i < nums.size(); i++){
        int x = nums[i];
        int y = target - x;
        if(m.count(y)){
            return{m[y], i};
        }
        m[x] = i;
    }
    return {};
}

int main(){

    std::vector<int> arr = {1, 2, 3, 4, 5};
    int target = 9;

    //std::vector<int> result = twoSumBF(arr, target);
    std::vector<int> result = twoSumHM(arr, target);

    if(!result.empty()){
        std::cout << result[0] << ", " << result[1];
    } else {
        std::cout << "No pair found. ";
    }

    return 0;
}