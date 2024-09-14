#include <iostream>
using namespace std;

int main(){
    int sum = 0;
    int n;
    cout << "select n: ";
    cin >> n;
	if (n > 1){
		int prev1 = 0;
		int prev2 = 1;
		for(int i=1; i<n; i++){
			sum = prev1 + prev2;
			prev1 = prev2;
			prev2 = sum;
            cout << endl << sum;
		}
	}
	else if (n==1){
		sum = 1;
        cout << sum;
	}
	else{
		sum = 0;
        cout << sum;
	}
	
}