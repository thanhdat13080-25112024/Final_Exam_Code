#include<iostream>
#include<list>
#include<string>
#include<cctype>
using namespace std;
class candidate_attribute {
    private:
        int id;
        string name;
        string room;
        double score;
    public:
        bool isValidName(string name) {
            if (name.empty()) {
                return false;
            } 
            for (char c : name) {
                while (isdigit(c)) {
                    return false;
                }
                if(c == '!' || c == '@' || c == '$' || c == '%' || c == '&' || c == '*') {
                    return false;
                }
                return true;
            }
        }
        void input_func() {
            cout<<"Enter the id of student: "<<endl;
            cin>>id;
            while (isValidName(name)) {
                cout<<"Enter the full name of student: "<<endl;
                getline(cin, name);
                if (!isValidName(name)) {
                    cout<<"Invalid name!"<<endl;
            } else {
                break;
            }
            }
            cout<<"Enter the exam room number: "<<endl;
            cin>>room;
            while (true) {
                cout<<"Enter the score: "<<endl;
                cin>>score;
                if (score <= 0 || score >= 10) {
                    break;
                } 
                }
        }
};
int main() {
    
}