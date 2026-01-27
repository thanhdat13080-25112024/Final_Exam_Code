#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <limits>
#include <algorithm>

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
        if (!(cin >> x)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter an integer." << endl;
            return false;
        }
        return true;
    }

    static bool readDouble(double& x) {
        if (!(cin >> x)) {
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
                cout << "Invalid score! (0-10)\n";
                continue;
            }
            cout << "Import successful\n\n";
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

    while (true) {
        if (candidate_list.empty()) {
            int n;
            cout << "Enter number of candidates: ";
            if (!candidate_attribute::readInt(n)) continue;
            for (int i = 0; i < n; i++) {
                candidate_attribute c;
                c.input(candidate_list, i + 1);
                candidate_list.push_back(c);
            }
        } else {
            cout << "\n------Menu Candidate management ------\n";
            cout << "1. Add new candidate\n";
            cout << "2. Display the list of candidates\n";
            cout << "3. Search for candidates by ID\n";
            cout << "4. Display candidate(s) with the highest score\n";
            cout << "5. Display candidate(s) with the lowest score\n";
            cout << "6. Exit\n";
            cout << "Enter choice: ";

            if (!candidate_attribute::readInt(choice) || choice < 1 || choice > 6) {
                cout << "Invalid choice!\n";
                continue;
            }

            switch (choice) {
                case 1: {
                    int numToAdd;
                    cout << "Enter number of candidates to add: ";
                    if (!candidate_attribute::readInt(numToAdd)) break;
                    for (int i = 0; i < numToAdd; i++) {
                        candidate_attribute c;
                        c.input(candidate_list, candidate_list.size() + 1);
                        candidate_list.push_back(c);
                    }
                    break;
                }
                case 2:
                    cout << "\n--- Candidate List ---\n";
                    for (const auto& c : candidate_list) c.display();
                    break;

                case 3: {
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
                    break;
                }
                case 4: {
                    double maxScore = candidate_list.front().getScore();
                    for (const auto& c : candidate_list) {
                        if (c.getScore() > maxScore) maxScore = c.getScore();
                    }
                    cout << "\n--- Candidate(s) with Highest Score (" << maxScore << ") ---\n";
                    for (const auto& c : candidate_list) {
                        if (c.getScore() == maxScore) c.display();
                    }
                    break;
                }
                case 5: {
                    double minScore = candidate_list.front().getScore();
                    for (const auto& c : candidate_list) {
                        if (c.getScore() < minScore) minScore = c.getScore();
                    }
                    cout << "\n--- Candidate(s) with Lowest Score (" << minScore << ") ---\n";
                    for (const auto& c : candidate_list) {
                        if (c.getScore() == minScore) c.display();
                    }
                    break;
                }
                case 6:
                    return 0;
            }
        }
    }
}