#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <chrono>
#include <iterator>
using namespace std;
class thisinh {
    private:
        int id;
        string ten;
        int phongthi;
        double diemthi;
    public:
        bool isValidName(string ten) {
                if (ten.empty()) return false;
                for(char c : ten) {
                    if(isdigit(c)) {
                        return false;
                    }
                }
                return true;
            }
        void input(int index) {
            cout<<"Please enter the information for the following candidate "<<index+1<<":"<<endl;
            cout<<"Registration number:" << endl;
            cin>>id;
            cin.ignore();
            cout<<"Full name:" << endl;
            do {
                getline(cin, ten);
                if(!isValidName(ten)) {
                    cout<<"Invalid name!"<<endl;
                    cout<<"Please re-enter the full name:"<<endl;
                }
            } while (!isValidName(ten));
            cout<<"Examination room:" << endl;
            cin>>phongthi;
            cout<<"Exam scores:" << endl;
            cin>>diemthi;
        }
        void display() {
            cout<<"Registration number: "<<id<<endl;
            cout<<"Full name: "<<ten<<endl;
            cout<<"Examination room: "<<phongthi<<endl;
            cout<<"Exam scores: "<<diemthi<<endl;
        }
    };
int main() {
    int choice;
    bool tieptuc = true;
    while(tieptuc) {
    cout<<"------Menu Candidate management ------"<<endl;
    cout<<"1. Add more candidates"<<endl;
    cout<<"2. Display the list of candidates."<<endl;
    cout<<"3. Search for candidates"<<endl;
    cout<<"4. Remove candidate"<<endl;
    cout<<"5. Sort candidates by score"<<endl;
    cin>>choice;
    if (choice <= 0 || choice > 5) {
        cout<<"Invalid selection!"<<endl;
        return 0;
    }
    list<thisinh> danhsachthisinh;
    switch(choice) {
        case 1: {
            int n;
            cout<< "Number of candidates to add to the list: "<<endl;
            cin>>n;
            do{
                for (int i = 0; i < n; i++) {
                thisinh candidates;
                candidates.input(i);
                danhsachthisinh.push_back(candidates);
                cout<<"Successfully added candidate number "<<i+1<<endl;
                }
            } while (danhsachthisinh.size() == n-1);
            break;
        }
        case 2: {
            for (int i = 0; i < danhsachthisinh.size(); i++) {
                auto it = danhsachthisinh.begin();
                advance(it, i);
                it->display();
                return 0;
            }          
            break;  
    }
}
}
}