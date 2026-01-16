#include<iostream>
#include<list>
#include<string>
#include<cctype>
#include<limits>
using namespace std;

class candidate_attribute {
private:
    string id;
    string name;
    string room;
    double score;

public:
    string getId() const { return id; }
    string getName() const { return name; }
    double getScore() const { return score; }

    bool isValidName(string name) {
        if (name.empty()) return false;
        for (char c : name) {
            if (!isalpha(c) && c != ' ') return false;
        }
        return true;
    }

    static bool readInt(int& x) {
        cin >> x;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return false;
        }
        return true;
    }

    static bool readDouble(double& x) {
        cin >> x;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return false;
        }
        return true;
    }

    void input(const list<candidate_attribute>& current_list, int index) {
        cout << "Entering information for candidate " << index << ".\n";
        bool isDuplicate;
        do {
            isDuplicate = false;
            cout << "Enter the id of student: ";
            cin >> id;
            for (const auto& candidate : current_list) {
                if (candidate.getId() == id) {
                    cout << "Error: This ID already exists!\n";
                    isDuplicate = true;
                    break;
                }
            }
        } while (isDuplicate);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter the full name of student:\n";
        getline(cin, name);

        while (!isValidName(name)) {
            cout << "Invalid name! Enter again:\n";
            getline(cin, name);
        }

        cout << "Enter the exam room number: ";
        cin >> room;

        while (true) {
            cout << "Enter the score: ";
            if (!readDouble(score) || score < 0 || score > 10) {
                cout << "Invalid score! (0–10)\n";
                continue;
            }
            cout<<endl<<"Import successful"<<endl<<endl;
            break;
        }
    }

    void display() const {
        cout << "ID: " << id
             << " | Name: " << name
             << " | Room: " << room
             << " | Score: " << score << endl;
    }
};

int main() {
    int choice;
    list<candidate_attribute> candidate_list;
    int n;
    cout << "Enter number of candidates: ";
    if (!candidate_attribute::readInt(n))
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < n; i++) {
        candidate_attribute c;
        c.input(candidate_list, i + 1);
        candidate_list.push_back(c);
    }

    while (true) {
        cout << "\n------Menu Candidate management ------\n";
        cout << "1. Display the list of candidates\n";
        cout << "2. Search for candidates\n";
        cout << "3. Sort candidates by score\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";

        if (!candidate_attribute::readInt(choice) || choice < 1 || choice > 4) {
            cout << "Invalid choice!\n";
            continue;
        }

        switch (choice) {
            case 1:
                if (candidate_list.empty()) {
                    cout << "The list is empty! Nothing to sort." << endl;
                    cout<<endl<<endl;
                    break;
                }
                for (const auto& c : candidate_list) c.display();
                cout<<endl<<endl;
                break;

            case 2: {
                string searchID;
                cout << "Enter ID to search: ";
                cin >> searchID;
                bool found = false;
                for (const auto& c : candidate_list) {
                    if (c.getId() == searchID) {
                        c.display();
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Not found\n";
                cout<<endl<<endl;
                break;
            }
            case 3:
                if (candidate_list.empty()) {
                    cout << "The list is empty! Nothing to sort." << endl;
                    cout<<endl<<endl;
                } else {
                    cout<<endl<<endl<<"---Sort Options----" << endl;
                    cout<<"1. Ascending by score" << endl;
                    cout<<"2. Descending by score" << endl;
                    cout<<"Enter choice: ";
                    int sortChoice;
                    if (!candidate_attribute::readInt(sortChoice) || (sortChoice != 1 && sortChoice != 2)) {
                        cout << "Invalid choice!" << endl;
                        break;
                    }
                    if (sortChoice == 1) {
                        candidate_list.sort([](const candidate_attribute& a, const candidate_attribute& b) {
                            return a.getScore() < b.getScore();
                        });
                    } else {
                        candidate_list.sort([](const candidate_attribute& a, const candidate_attribute& b) {
                            return a.getScore() > b.getScore();
                        });
                    }
                    for (const auto& candidate:candidate_list) {
                        candidate.display();
                    }
                    cout<<endl<<endl;
                }
                break;
            case 4:
                return 0;
        }
    }
}
