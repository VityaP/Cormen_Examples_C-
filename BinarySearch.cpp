#ifndef _BinarySearch_
/* 	_BinarySearch_
	time O(log(N))
	memory O(N)
*/
#define _BinarySearch_
#include <vector>
#include <iostream>

template <class X> 
bool BinarySearch( std::vector<X> &data, X value,int start,int end){
	
	int mid = (start + end)/2;
	if ( data[mid] == value ){
		return true;
	}
	if ( start == end){
		return false;
	}
	if( data[mid] < value ){
		return BinarySearch(data, value, mid + 1, end);
	}
	if( data[mid] > value){
		return BinarySearch(data, value, start, mid - 1);
	}
	
	return false;
	
}

#endif


#include<iostream>
#include<ctime>
#include<cstdlib>
#include<algorithm>
int main(){
		
	int n = 9;
	std::vector<int> g(n,0);
	srand(time(NULL));
	for(int i = 0; i < n ; ++i ){
		g[i] = rand() % 1000;
	}
	g[5] = 655;
	for(int i = 0; i < n ; ++i ){
		std::cout << g[i] << "\t";
	}
	std::sort(g.begin() , g.end());
	std::cout << "\n";
	bool flag = false;
	flag = BinarySearch(g,655,0,n-1);
	std::cout << "flag is " << flag << "\n";
	
}
