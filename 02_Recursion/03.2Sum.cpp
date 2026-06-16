#include <iostream>
using namespace std;

int sum(int n, int result=0){
    if (n==0){
        return result;
    }
    else if (n==1){
        return result+1;
    }
    else{
        return sum(n-1, n+result);
    }
}

int main(){
    int N;
    cout << "Enter your number: ";
    cin >> N;

    cout << "TotalSum(" << N << ")= " << sum(N)<<endl;
    return 0;
}