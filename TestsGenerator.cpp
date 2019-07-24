#include<iostream>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<fstream>
#include<cstring>
using namespace std;
int main(){
	
	int n = 100;
	
	ofstream mystream;
	mystream.open("test.txt");
	if( !mystream ){
		cout << "Can't open file\n";
	}
	
	srand(time(NULL));
	for(int i = 0; i < n ; ++i ){
		mystream << ( ( rand() % 1000 ) - 500 ) << "\t";
	}
	
	mystream.close();
	
	return 0;
}
