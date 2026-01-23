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
            if (name.empty()) return false;
            for (char c : name) {
                if (isdigit(c) || !isalpha(c)) return false;
            }
            return true;
        }
        void input() {
            cout<<"Enter the id of student: "<<endl;
            cin>>id;
            cout<<"Enter the full name of student: "<<endl; 
            cin.ignore();
            getline(cin, name);
            while (true) {
                if (!isValidName(name)) {                                
                    cout<<"Invalid name!"<<endl;
                    cout<<"Enter the full name of student: "<<endl;
                    getline(cin, name);
                    continue;                                          
                    break;
                }
                break;
            }
            cout<<"Enter the exam room number: "<<endl;
            cin>>room;
            while (true) {
                cout<<"Enter the score: "<<endl;
                cin>>score;
                if (score <= 10 && score >= 0) {
                    break;
                } else {
                    cout<<"Invalid score! Score must be between 0 and 10."<<endl;
                    continue;
                }
            }
            cout<<"Input successful!"<<endl;
        }
        void display() {
            cout<<"ID: "<<id <<" | ";
            cout<<"Name: "<<name <<" | ";
            cout<<"Room: "<<room <<" | ";
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
        cout<<"4. Sort candidates by score"<<endl;
        cout<<"5. Exit"<<endl;
        cin>>choice;
        if (choice < 0 || choice > 5) {
            cout<<"Invalid choice! Please re-enter your choice."<<endl;
            continue;
        } else {
            switch (choice) {
                case 1: {
                    cout<<"Enter the number of candidates to add: "<<endl;
                    int n;
                    cin>>n;
                    for (int i = 0; i < n ; i++) {
                        cout<<"Enter the information of candidate number "<<i+1<<":"<<endl;
                        candidate_attribute candidate;
                        candidate.input();
                        candidate_list.push_back(candidate);
                    }
                    continue;
                }   
                case 2: {
                    if (candidate_list.empty()) {
                        cout<<"The list is empty!"<<endl;
                    } else {
                        for (auto& candidate : candidate_list) {
                            candidate.display();
                        }
                    }
                    continue;
                }
                case 3: {

                }
                case 4: {
                    cout<<"------Menu Candidate management ------"<<endl;
                    cout<<"1. Sort max to min: "<<endl;
                    cout<<"2. Sort min to max: "<<endl;
                    int sort_choice;
                    cin>>sort_choice;
                    if (sort_choice == 1) {
                        
                }
                case 5: {
                    exit(0);
                }
            }
        }
    }
}
// Thiếu: case 3,4,5 trong switch, check trùng id, list trống ở case 2,3,4(trống thì thêm cout báo trống)