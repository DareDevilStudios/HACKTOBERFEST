#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int x;
	    cin>>x;
	    if(x>=67 && x<=45000)
	        cout<<"YES\n";
	    else
	        cout<<"NO\n";
	}
	return 0;
}
