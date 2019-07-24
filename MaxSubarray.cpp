/* 	_MaxSubarray_
	time O(N*log(N))
	memory O(N)
*/

#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>
#include<fstream>

struct compact{
	int low ;
	int high ;
	int sum ;
	compact(){
		low = 0;
		high = 0;
		sum = 0;
	}
	void init(const int &l,const int &h,const int &s){
		low = l;
		high = h;
		sum = s;
	}
	compact &operator=(const compact &ob){
		this->low = ob.low;
		this->high = ob.high;
		this->sum = ob.sum;
		return *this;
	}
	friend bool operator<=(const compact &lhs,const compact &rhs){
		if( lhs.sum < rhs.sum ){
			return true;
		}
		return false;
	}
	friend bool operator>=(const compact &lhs,const compact &rhs){
		if( lhs.sum > rhs.sum ){
			return true;
		}
		return false;
	}
};

const int negInfinity = std::numeric_limits<int>::min();


template<class X>
compact FindMaxCrossingSubarray(const std::vector<X>& nums,int low,int mid,int high){
	int lsum = negInfinity;
	int sum = 0;
	int maxleft;
	for (int i = mid ; i >= low; --i){
		sum = sum + nums[i];
		if (sum > lsum ){
			lsum = sum;
			maxleft = i;
		}
	}
	int rsum = negInfinity;
	sum = 0;
	int maxright;
	for (int i = mid + 1; i <= high; ++i){
		sum = sum + nums[i];
		if ( sum > rsum ){
			rsum = sum;
			maxright = i;
		}
	}
	compact answer;
	answer.init(maxleft, maxright, lsum + rsum);
	return answer;
}

template<class X>
compact FindMaxSubarray(const std::vector<X>& nums,int low,int high){
	compact answer;
	if( high == low){
		answer.init(low,high,nums[low]);
	}
	else{
		int mid = (low + high) /2;
		compact lAnswer ,rAnswer ,cAnswer;
		lAnswer = FindMaxSubarray(nums,low,mid);
		rAnswer = FindMaxSubarray(nums,mid + 1,high);
		cAnswer = FindMaxCrossingSubarray(nums,low,mid,high);
		if ( lAnswer >= rAnswer && lAnswer >= cAnswer){
			answer = lAnswer;
		}
		if ( rAnswer >= lAnswer && rAnswer >= cAnswer){
			answer = rAnswer;
		}
		if( cAnswer >= lAnswer && cAnswer >= rAnswer){
			answer = cAnswer;
		}
	}
	return answer;
}

int main(){
	
	time_t start = time(NULL);
	std::ifstream fin("test.txt");
	if ( !fin ){
		std::cout << "Can't open file\n";
		return 1;
	}
	int n = 100;
	std::vector<int> g(n,0);
	for(int i = 0; i < n ; ++i ){
		fin >> g[i]; 
	}
	compact check;
	check = FindMaxSubarray(g,0,n-1);
	std::cout << "\n" << check.sum;
	std::cout << "\n" << check.low;
	std::cout << "\n" << check.high;
	std::cout << "\n" ;
	time_t end = time(NULL);
	start = end - start;
	std::cout << start << "\t" ;
	fin.close();
	
	return 0;
}
