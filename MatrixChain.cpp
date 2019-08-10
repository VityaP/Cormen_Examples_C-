#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <limits>
using namespace std;

int INF = std::numeric_limits<int>::max();

struct myPair{
	int first;
	int second;
};

int MatrixChain(vector<myPair>& nums,vector< vector<int> >& table,int startPos,int endPos){
	
	if( startPos == endPos){
		return 0;
	}
	if( table[startPos][endPos] == INF ){
		for(int k = startPos; k < endPos; ++k){
			int temp = MatrixChain(nums,table,startPos,k) + MatrixChain(nums,table,k + 1,endPos) ;
			temp += nums[startPos].first * nums[k].second * nums[endPos].second;
			if ( temp < table[startPos][endPos]){
				table[startPos][endPos] = temp;
			}
		}
	}
	return table[startPos][endPos];
	
}


int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	vector<myPair> nums(n);
	vector< vector<int> > table(n + 1,vector<int>(n + 1,INF));
	for(int i = 0; i < n; ++i){
		cin >> nums[i].first >> nums[i].second ;
	}
	int answer = MatrixChain(nums,table,0,n - 1);
	cout << answer;
}
