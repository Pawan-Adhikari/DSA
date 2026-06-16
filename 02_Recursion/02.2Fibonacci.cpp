#include <iostream>
using namespace std;

int fib(int n, int a=0, int b=1){
    if (n==1){
        return a;
    }
    else if (n==2){
        return b;
    }
    else{
        return fib(n-1, b, a+b);
    }
}

int main(){
    int N;
    cout << "Enter your number: ";
    cin >> N;

    cout << "fib(" << N << ")= " << fib(N)<<endl;
    return 0;
}
