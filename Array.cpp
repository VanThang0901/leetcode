#include<iostream>
#include<vector>
#include<algorithm>

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

//Two Sum
vector<int> TwoSum(vector<int> &numbers, int target){
    // int size = numbers.size();
    // for(int i=0; i<size-1; i++){
    //     for(int j=i+1; j<size; j++){
    //         if(numbers[i]+numbers[j] == target) return {i,j};
    //     }
    // }
    // return {};
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
}

int main(){
    vector<int> nums = {2,7,11,15,16};
    vector<int> result;
    int target = 31;
    result = TwoSum(nums, target);
    cout<<result;

    return 0;

}