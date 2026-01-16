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
                if (isdigit(c)) {
                    return false;
                }
                if(c == '!' || c == '@' || c == '$' || c == '%' || c == '&' || c == '*') {
                    return false;
                }
            }
            return true;
        }
        void input() {
            cout<<"Enter the id of student: "<<endl;
            cin>>id;
            while (isValidName(name)) {                                     // 
                cout<<"Enter the full name of student: "<<endl;             // 
                cin.ignore();                                               //                                         
                getline(cin, name);                                         //     error               
                if (!isValidName(name)) {                                   // 
                    cout<<"Invalid name!"<<endl;                            //
                    continue;                                               //
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
        void display() {
            cout<<"ID: "<<id<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Room: "<<room<<endl;
            cout<<"Score: "<<score<<endl;
        }
        
};
int main() {
    int choice;
    list<candidate_attribute> candidate_list;
    while (true) {
        cout<<"------Menu Candidate management ------"<<endl;
        cout<<"1. Add more candidates"<<endl;
        cout<<"2. Display the list of candidates."<<endl;
        cout<<"3. Search for candidates"<<endl;
        cout<<"4. Remove candidate"<<endl;
        cout<<"5. Sort candidates by score"<<endl;
        cout<<"6. Exit"<<endl;
        cin>>choice;
        if (choice < 0 || choice > 6) {
            cout<<"Invalid choice! Please re-enter your choice."<<endl;
            continue;
        } else {
            break;
        }
    }
    switch (choice) {
        case 1: {

        }
    }
}