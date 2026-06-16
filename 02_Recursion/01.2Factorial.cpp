#include <iostream>
using namespace std;

int factorial(int n, int result=1){
    if (n==0 || n==1){
        return result;
    }
    else{
        return factorial(n-1, n*result);
    }
}

int main(){
    int N;
    cout << "Enter your number: ";
    cin >> N;

    cout << N << "!= " << factorial(N)<<endl;
    return 0;
}