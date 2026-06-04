#include <iostream>
using namespace std;
#include <stack>
#include <string>
#include <map>

class PostfixExp {
    public:
    string toScan;
    stack<int> myStack;
    PostfixExp(string toScan_){
        toScan = toScan_;
    }
    int operate(int a, int b, char op){
        if (op == '+'){
            return a+b;
        }
        else if(op == '-'){
            return a-b;
        }
        else if (op == '*'){
            return a*b;
        }
        else if (op == '/'){
            return a/b;
        }
        else {
            cout << "Unsupported Operand";
            return 1;
        }
    }
    int evaluate(){
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
            int num = cchar - '0';
            Tape = Tape.substr(1);
            if ((cchar >= '0' && cchar <= '9')){
                myStack.push(num);
            }
            else if(PrecedenceAssocMap.at(cchar)) {
                int op1, op2;
                if (!myStack.empty()){
                    op2 = myStack.top();
                    myStack.pop();
                }
                else cout << "Invalid!" <<endl;
                if (!myStack.empty()){
                    op1 = myStack.top();
                    myStack.pop();
                } 
                else cout << "Invalid!" <<endl;
                int result = this->operate(op1, op2, cchar);
                myStack.push(result);
            }
        }
        return myStack.top();
    }
};

int main(){
    cout << "Input your required postfix expression." << endl;
    string inpString;
    cin >> inpString;
    PostfixExp inf = PostfixExp(inpString);
    cout << "The input postfix expression was: " << inf.toScan << endl;
    int result = inf.evaluate();
    cout << inpString << "=" << result << endl;
}