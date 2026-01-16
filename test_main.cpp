#include<iostream>
#include<list>
#include<string>
#include<cctype>
using namespace std;
class candidate_attribute {
    private:
        string id;
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
        void input() {
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
        void display(int index) {
            cout<<"Information of candidate "<<index+1<<endl;
            cout<<"ID: "<<id<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Room: "<<room<<endl;
            cout<<"Score: "<<score<<endl;
        }
        void find(string search_id) {
            cout<<"Enter the id to search: "<<endl;
            cin>>search_id;
            for (char c : id) {
                for (char d : search_id) {
                    if (c == d) {
                        cout<<"Found candidate with ID: "<<search_id<<endl;
                    }
                }
                
            }

        }
};
int main() {
    
}