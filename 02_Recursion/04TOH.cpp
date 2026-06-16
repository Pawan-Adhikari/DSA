#include <iostream>
using namespace std;

void TOH(int count, char src='A', char dest='C', char aux='B'){
    if (count==1){
        cout << "Move from "<< src << " to " << dest << "." <<endl;
    }
    else{
        TOH(count-1, src, aux, dest);
        TOH(1, src, dest, aux);
        TOH(count-1, aux, dest, src);
    }
}

int main(){
    int N;
    cout << "Enter your ring count: ";
    cin >> N;
    cout << "Perform following moves:" << endl;
    TOH(N);
    cout << "TOH Solved!" << endl;
}