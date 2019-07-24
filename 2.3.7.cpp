#include<iostream>
#include <vector>
#include <ctime>
#include<algorithm>

bool BinarySearch(const std::vector<int>& nums, const int& target, const int& left, const int& right) {
	if (left == right){
		return false;
	}

	int mid = (left + right) / 2;
	if (nums[mid] == target){
		return true;
	} else if(nums[mid] < target ){
		return BinarySearch(nums, target, mid + 1, right);
	} else if(nums[mid] > target){
		return BinarySearch(nums, target, left, mid);
	}

	return false;
}

int main(){
    int n = 100;
	srand(time(NULL));
    std::vector<int> nums(n);
    for (int i = 0;i < n;++i) {
        nums[i] = rand() % 1000;
    }

    int target;
    std::cout << "What you want to find ?\n";
	std::cin >> target;

	std::sort(nums.begin(), nums.end());

	bool flag = false;
	for(int i = 0;i < n; ++i){
		flag = BinarySearch(nums, target - nums[i], 0, nums.size());
		if (flag){
			break;
		}
	}

	std::cout << "\nflag is " << flag << "\n";

	return 0;
}
