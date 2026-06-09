#include <iostream>
using namespace std;

int fib(int n){
    if (n==1){
        return 0;
    }
    else if (n==2){
        return 1;
    }
    else{
        return fib(n-1) + fib(n-2);
    }
}

int main(){
    int N;
    cout << "Enter your number: ";
    cin >> N;

    cout << "fib(" << N << ")= " << fib(N);
    return 0;
}
