#include <iostream>
using namespace std;
#include <stack>
#include <string>
#include <map>

class PairedParanthesis {
    public:
    string toScan;
    stack<char> myStack;
    PairedParanthesis(string toScan_){
        toScan = toScan_;
    }
    bool check(){
        string Tape = toScan;
        while (!Tape.empty()){
            if (!myStack.empty()) cout << "Current Stack Top = " << myStack.top() <<endl;
            char cchar = char(Tape[0]);
            Tape = Tape.substr(1);

            if (cchar == '(' || cchar == '{' || cchar == '['){
                myStack.push(cchar);
            }
            else if (cchar == ')'){
                if (!myStack.empty() && myStack.top()=='(') {
                    myStack.pop();
                    continue;
                }
                else return 1;
            }
            else if (cchar == '}'){
                if (!myStack.empty() && myStack.top()=='{') {
                    myStack.pop();
                    continue;
                }
                else return 1;
            }
            else if (cchar == ']'){
                if (!myStack.empty() && myStack.top()=='[') {
                    myStack.pop();
                    continue;
                }
                else return 1;
            }
        }
        if (myStack.empty()) return 0;
        else return 1;
    }
};

int main(){
    cout << "Input yout required infix string." << endl;
    string inpString;
    cin >> inpString;
    PairedParanthesis inf = PairedParanthesis(inpString);
    cout << "The input infix string was: " << inf.toScan << endl;
    int check = inf.check();
    if (check == 1){
        cout << "Test failed!" << endl;
    }
    else cout << "Test Passed!" << endl;
}