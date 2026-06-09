#include <iostream>
using namespace std;

int sum(int n){
    if (n==0){
        return 0;
    }
    else if (n==1){
        return 1;
    }
    else{
        return n+sum(n-1);
    }
}

int main(){
    int N;
    cout << "Enter your number: ";
    cin >> N;

    cout << "TotalSum(" << N << ")= " << sum(N);
    return 0;
}