#include <iostream>
using namespace std;
#include <stack>
#include <string>
#include <map>

class Infix {
    public:
    string toScan;
    stack<char> myStack;
    Infix(string toScan_){
        toScan = toScan_;
    }
    string toPostfix(){
        string Tape = toScan;
        string outString = "";
        std::map<char, int> PrecedenceAssocMap = {
            {'+', 1},
            {'-', 1},
            {'*', 2},
            {'/', 2}
        };
        while (!Tape.empty()){
            if (!myStack.empty()) cout << "Current Stack Top = " << myStack.top() <<endl;
            char cchar = char(Tape[0]);
            Tape = Tape.substr(1);
            if ((cchar >= 'A' && cchar <= 'Z') || (cchar >= 'a' && cchar <= 'z')){
                outString += cchar;
            }
            else if (cchar == '('){
                myStack.push(cchar);
            }
            else if (cchar == ')'){
                char dchar;
                if (!myStack.empty()) {
                    dchar = myStack.top();
                    myStack.pop();
                }
                while (dchar != '('){
                    outString+= dchar;
                    if (!myStack.empty()){
                        dchar = myStack.top();
                        myStack.pop();
                    }
                }
            }
            else {
                while (!myStack.empty() && myStack.top()!='('  && PrecedenceAssocMap.at(cchar) <= PrecedenceAssocMap.at(myStack.top())){
                    if (!myStack.empty()) {
                        outString += myStack.top();
                        myStack.pop();
                    }
                }
                myStack.push(cchar);
            }
        }
        while (!myStack.empty()){
            char current_char = myStack.top();
            myStack.pop();
            outString += current_char;
        }
        return outString;
    }
};

int main(){
    cout << "Input yout required infix string." << endl;
    string inpString;
    cin >> inpString;
    Infix inf = Infix(inpString);
    cout << "The input infix string was: " << inf.toScan << endl;
    string outString = inf.toPostfix();
    cout << "The infix string in postfix is : " << outString << endl;
}