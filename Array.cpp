#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i != vec.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

//1. Two Sum
vector<int> TwoSum(vector<int> &numbers, int target){
    //solution 1
    // int size = numbers.size();
    // for(int i=0; i<size-1; i++){
    //     for(int j=i+1; j<size; j++){
    //         if(numbers[i]+numbers[j] == target) return {i,j};
    //     }
    // }
    // return {};

    //solution 2
    int size = numbers.size();
    sort(numbers.begin(), numbers.end());
    int left = 0;
    int right = size - 1;
    if(numbers[0]>target) return {};
    
    while(left<right && numbers[left]<target){
        if(numbers[left]+numbers[right]> target) right--;
        else if(numbers[left]+numbers[right]< target) left++;
        else return {left, right};
    }
    return {};

    //Solution 3
    // int size = numbers.size();
    // unordered_map<int, int> map_number;
    // for(int i=0;i<size;i++){
    //     int remain = target - numbers[i];
    //     if(map_number.count(remain) != 0){
    //         return {i, map_number[remain]};
    //     }
    //     map_number[numbers[i]] = i;
    // }
    // return {};
}

//2. Median of 2 sorted array
double MedianValue(vector<int> &nums1, vector<int> &nums2){
    vector<int> sortedArray;
    for(auto num:nums1){
        sortedArray.push_back(num);
    }
    for(auto num:nums2){
        sortedArray.push_back(num);
    }
    sort(sortedArray.begin(), sortedArray.end());
    int size = sortedArray.size();
    if(size%2==1){
        return sortedArray[size/2];
    }
    else{
        double temp = (sortedArray[size/2] + sortedArray[size/2-1])/2;
        return temp;
    }
}
int main(){
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};
    double result;
    result = MedianValue(nums1, nums2);
    cout<<result;
    
    return 0;
}