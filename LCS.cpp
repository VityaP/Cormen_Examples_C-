#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <limits>
using namespace std;

int INF = std::numeric_limits<int>::infinity();

int lcs(vector< vector<int> >& table ,string& first,string& second,int firstIndex,int secondIndex){
	
	if ( table[firstIndex][secondIndex] == INF){
	
		if ( firstIndex * secondIndex != 0 ){
			
			string s1 = first.substr(0,firstIndex - 1);
			string s2 = second.substr(0,secondIndex - 1);
			
			if( first.back() == second.back() ){
				table[firstIndex][secondIndex] = 1 + lcs(table,s1,s2,firstIndex - 1,secondIndex - 1) ;
			}
			else{
				int temp1 = lcs(table,s1,second,firstIndex - 1,secondIndex);
				int temp2 = lcs(table,first,s2,firstIndex,secondIndex - 1);
				if (temp1 > temp2){
					table[firstIndex][secondIndex] = temp1;
				}
				else{
					table[firstIndex][secondIndex] = temp2;
				}
			}
		}
		else{
			if( firstIndex == 0 && secondIndex == 0){
				table[firstIndex][secondIndex] = 0;
			}
			else{
				if ( firstIndex == 0 ){
					string s2 = second.substr(0,secondIndex - 1);
					table[firstIndex][secondIndex] = lcs(table,first,s2,firstIndex,secondIndex - 1);
				}
				else{
					string s1 = first.substr(0,firstIndex - 1);
					table[firstIndex][secondIndex] = lcs(table,s1,second,firstIndex - 1,secondIndex);
				}
			}
		}
	
	}
	
	return table[firstIndex][secondIndex];
}
 
int main(){
	
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	
	string s1,s2;
	cout << "Type first string : ";
    cin >> s1 ;
    cout << "\nType second string : ";
    cin >> s2;
    cout << "\n";
    
    int s1Size = s1.length();
    int s2Size = s2.length();
    vector< vector<int> > table(s1Size + 1,vector<int>(s2Size + 1,INF));
    
    cout << lcs(table,s1,s2,s1Size,s2Size) << "\n";
    
	return 0;
}
