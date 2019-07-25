#ifndef _HeapMin_
/* 	_HeapMin_
	time O(n*log(N))
	memory O(N)
	//////////////////////////////////////////////////
	////	Be aware with initialization of array	//
	////	DON'T USE ARRAY[O]!!!					//
	//////////////////////////////////////////////////
	_HeapifyMin_
	time O(log(N))
	memory O(N)
*/
#define _HeapMin_
#include <vector>
#include <iostream>

template<class X>
void HeapifyMin(std::vector<X> &nums,int i){
	int Size = nums.size()-1;
	int index = i;
	if ( 2*i <= Size && nums[2*i] < nums[index] ){
		index = 2*i;
	}
	if ( 2*i + 1 <= Size && nums[2*i + 1] < nums[index] ){
		index = 2*i + 1;
	}
	if ( i != index ){
		X temp = nums[i];
		nums[i] = nums[index];
		nums[index] = temp;
		HeapifyMin(nums,index);
	}
	return;
}

template<class X>
void HeapMin(std::vector<X> &nums){
	//the problem is that vector nums
	//begin from the nums[0]
	//I suppose that we don't need it
	int Size = nums.size() - 1;
	for(int i = Size/2 ; i >= 1; --i){
		HeapifyMin(nums,i);
	}
}

#endif


#include<iostream>
#include<ctime>
#include<cstdlib>
int main(){
	
	time_t start = time(NULL);
	int n = 100000000;
	std::vector<int> g(n,0);
	srand(time(NULL));
	for(int i = 0; i < n ; ++i ){
		g[i] = rand() % 10;
	}
	
	HeapMin(g);
	
	bool flag = true;
	int Size = g.size() - 1;
	for(int i = 1; i < Size/2 ; ++i ){
		if ( g[i] > g[2*i] || g[i] > g[2*i + 1] ){
			flag = false;
			std::cout << i <<"\t";
		}
	}
	
	time_t end = time(NULL);
	start = end - start;
	std::cout << start << "\t" ;
	
	if (!flag){
		std::cout << "Not correct\n" ;
	}
	else{
		std::cout << "Correct\n";
	}
	
	return 0;
}
