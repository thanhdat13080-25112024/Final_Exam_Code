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
        void input(const list<candidate_attribute>& current_list) {
            bool isDuplicate;
            do {
                isDuplicate = false;
                cout << "Enter the id of student: " << endl;
                cin >> id;
                for (const auto& candidate : current_list) {
                    if (candidate.getId() == id) {
                        cout << "Error: This ID already exists! Please enter a unique ID." << endl;
                        isDuplicate = true;
                        break;
                    }
                }
            } while (isDuplicate);
            cout << "Enter the full name of student: " << endl;
            cin.ignore();
            getline(cin, name);
            while (true) {
                if (!isValidName(name)) {
                    cout << "Invalid name! (No numbers or special characters allowed)" << endl;
                    cout << "Enter the full name of student: " << endl;
                    getline(cin, name);
                    continue;
                }
                break;
            }
            cout << "Enter the exam room number: " << endl;
            cin >> room;
            while (true) {
                cout << "Enter the score: " << endl;
                cin >> score;
                if (score <= 10 && score >= 0) {
                    break;
                } else {
                    cout << "Invalid score! Score must be between 0 and 10." << endl;
                }
            }
            cout << "Input successful!" << endl;
        }
        void display() const {
            cout << "ID: " << id << " | ";
            cout << "Name: " << name << " | ";
            cout << "Room: " << room << " | ";
            cout << "Score: " << score << endl;
        }
};

int main() {
    int choice;
    list<candidate_attribute> candidate_list;
    while (true) {
        cout << "\n------Menu Candidate management ------" << endl;
        cout << "1. Add more candidates" << endl;
        cout << "2. Display the list of candidates." << endl;
        cout << "3. Search for candidates" << endl;
        cout << "4. Sort candidates by score" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        if (choice < 1 || choice > 5) {
            cout << "Invalid choice! Please re-enter your choice." << endl;
            continue;
        } else {
            switch (choice) {
                case 1: {
                    cout << "Enter the number of candidates to add: " << endl;
                    int n;
                    cin >> n;
                    for (int i = 0; i < n; i++) {
                        cout << "\n--- Enter information for candidate number " << i + 1 << " ---" << endl;
                        candidate_attribute candidate;
                        candidate.input(candidate_list);
                        candidate_list.push_back(candidate);
                    }
                    break;
                }
                case 2: {
                    if (candidate_list.empty()) {
                        cout << "The list is empty!" << endl;
                    } else {
                        cout << "\n--- Candidate List ---" << endl;
                        for (const auto& candidate : candidate_list) {
                            candidate.display();
                        }
                    }
                    break;
                }
                case 3: {
                    if (candidate_list.empty()) {
                        cout << "The list is empty! Nothing to search." << endl;
                    } else {
                        cout << "Enter the ID of the candidate to search: ";
                        string searchID;
                        cin >> searchID;
                        bool found = false;
                        for (const auto& candidate : candidate_list) {
                            if (candidate.getId() == searchID) {
                                cout << "\nCandidate Found:" << endl;
                                candidate.display();
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            cout << "No candidate found with ID: " << searchID << endl;
                        }
                    }
                    break;
                }
                case 4: {
                    if (candidate_list.empty()) {
                        cout << "The list is empty! Nothing to sort." << endl;
                    } else {
                        cout << "--- Sort Options ---" << endl;
                        cout << "1. Sort max to min" << endl;
                        cout << "2. Sort min to max" << endl;
                        int sort_choice;
                        cin >> sort_choice;
                        if (sort_choice == 1) {
                            candidate_list.sort([](const candidate_attribute& a, const candidate_attribute& b) {
                                return a.getScore() > b.getScore();
                            });
                            cout << "Sorted Max to Min successfully!" << endl;
                        }
                        else if (sort_choice == 2) {
                            candidate_list.sort([](const candidate_attribute& a, const candidate_attribute& b) {
                                return a.getScore() < b.getScore();
                            });
                            cout << "Sorted Min to Max successfully!" << endl;
                        }
                        else {
                            cout << "Invalid sort choice." << endl;
                        }
                        for (const auto& candidate : candidate_list) {
                            candidate.display();
                        }
                    }
                    break;
                }
                case 5: {
                    exit (0);
                }
            }
        }
    }
}
