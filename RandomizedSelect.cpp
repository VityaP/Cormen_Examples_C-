#ifndef _RandomizedSelect_
/* 	
	_RandomizedSelect_
	time O(N)
	memory O(N)

*/
#define _RandomizedSelect_
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

template<class X>
inline int Partition(std::vector<X> &nums,const int &p,const int &r){
	
	X x = nums[r];
	int i = p - 1;
	
	for(int j = p; j <= r-1; ++j){
		if ( nums[j] < x){
			++i;
			X temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
		}
	}
	
	++i;
	X temp = nums[i];
	nums[i] = nums[r];
	nums[r] = temp;
	return i;
}


template<class X>
inline int RandomizedPartition(std::vector<X> &nums,const int &p,const int &r){
	
	int mod = (r - p);
	int index;
	int index1 = p + rand() % mod;
	int index2 = p + rand() % mod;
	if (nums[index1] < nums[index2]){
		index = index1;
	}
	else{
		index = index2;
	}
	X temp = nums[index];
	nums[index] = nums[r];
	nums[r] = temp;
	return Partition(nums,p,r);
	
}

template<class X>
int RandomizedSelect(std::vector<X>& nums,int p,int r,int i){
	if( p == r){
		return nums[p];
	}
	int q = RandomizedPartition(nums,p,r);
	int k = q - p + 1;
	if( i == k ){
		return nums[q];
	}
	else if( i < k ){
		return RandomizedSelect(nums,p,q - 1,i);
	}
	else{
		return RandomizedSelect(nums,q + 1,r,i - k);
	}
}


#endif


#include<iostream>
#include<ctime>
#include<cstdlib>
int main(){
	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	time_t start = time(NULL);
	int n = 100000000;
	std::vector<int> g(n,0);
	srand(time(NULL));
	for(int i = 0; i < n ; ++i ){
		g[i] = rand() % 40000000;
	}
	
	int ans = RandomizedSelect(g,0,n - 1,10000);

	std::cout << ans;
	std::cout << "\n";
	
	time_t end = time(NULL);
	start = end - start;
	std::cout << start << "\t" ;
	
	return 0;
}
