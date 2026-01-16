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
                if (isdigit(c)) {
                    return false;
                } else if(c == '!' & c == '@' & c == '$' & c == '%' & c == '&' & c == '*') {
                    return false;
                        } else {
                            continue;
                }
                return true;
            }
            return true;
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
                if (score >= 0 & score <= 10) {
                    break;
                } else {
                    continue;
                } 
                }
        }
        void max(double score) {
            //dang phat trien
        }
        void min(double score) {

        }
};
int main() {
    list<candidate_attribute> candidates;
    int choice;
    while (true) {
    cout<<"------Menu Candidate management ------"<<endl;
    cout<<"1. Add more candidates"<<endl;
    cout<<"2. Display the list of candidates."<<endl;
    cout<<"3. Search for candidates"<<endl;
    cout<<"4. Remove candidate"<<endl;
    cout<<"5. Sort candidates by score"<<endl;
    cout<<"6. Exit"<<endl;  
    cin>>choice;
    if (choice >= 6 & choice <= 0) {
        cout<<"Try again!";
        continue;
    } else {
        break;
    }
    }
    switch (choice) {
        case 1: {
            //dang phat trien
            break;
        }
        case 2: {
            //dang phat trien
            break;
        }
        case 3: {
            //dang phat trien
            break;
        }
        case 4: {
            //dang phat trien
            break;
        }
        case 5: {
            //dang phat trien
            break;
        }
        case 6: {
            break;
        }
    }
}