/* 	_MaxSubarray_
	time O(N)
	memory O(N)
*/

#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <fstream>

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

template<class X>
compact FindMaxSubarray(const std::vector<X>& nums,int low,int high){
	
	compact answer;
	
	int positiveSum = 0;
	int negativeSum = 0;
	
	int lFinalBound = low;
	int rFinalBound = low;
	int FinalSum = 0;
	
	int lCurrentBound = low;
	int rCurrentBound = low;
	int CurrentSum = 0;
	
	int i = low;
	while ( i <= high ){
		
		while( nums[i] < 0 && i <= high){
			negativeSum += nums[i];
			++i;
		}
		
		negativeSum *= -1;
		if ( negativeSum > positiveSum  ){
			lCurrentBound = i;
			CurrentSum = 0;
		}
		else{
			CurrentSum -= negativeSum;
		}
		negativeSum = 0;
		positiveSum = 0;
		if ( i > high){
			rCurrentBound = i;
			if ( CurrentSum > FinalSum ){
				lFinalBound = lCurrentBound;
				rFinalBound = rCurrentBound;
				FinalSum = CurrentSum;
			}
			break;
		}
		
		while( nums[i] >= 0 && i <= high){
			positiveSum += nums[i];
			++i;
		}
		CurrentSum += positiveSum;
		
		if ( i > high){
			rCurrentBound = i;
			if ( CurrentSum > FinalSum ){
				lFinalBound = lCurrentBound;
				rFinalBound = rCurrentBound;
				FinalSum = CurrentSum;
			}
			break;
		}

		rCurrentBound = i - 1;
		if ( CurrentSum > FinalSum ){
			lFinalBound = lCurrentBound;
			rFinalBound = rCurrentBound;
			FinalSum = CurrentSum;
		}
	}
	answer.init(lFinalBound, rFinalBound, FinalSum);
	return answer;
}

int main(){
	
	time_t start = time(NULL);
	std::ifstream fin("test.txt");
	if ( !fin ){
		std::cout << "Can't open file\n";
		return 1;
	}
	compact check;
	int n = 100;
	std::vector<int> g(n,0);
	for(int i = 0; i < n ; ++i ){
		fin >> g[i];
	}
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
