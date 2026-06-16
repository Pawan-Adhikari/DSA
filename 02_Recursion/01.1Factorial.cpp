#include <iostream>
using namespace std;

int factorial(int n){
    if (n==0 || n==1){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}

int main(){
    int N;
    cout << "Enter your number: ";
    cin >> N;

    cout << N << "!= " << factorial(N)<<endl;;
    return 0;
}
