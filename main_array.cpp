#include <iostream>
#include <string>
#include <cctype>
#include <limits>

using namespace std;

const int MAX_CANDIDATES = 100;

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

    void input(candidate_attribute arr[], int current_size, int index) {
        cout << "Entering information for candidate " << index << ".\n";
        bool isDuplicate;
        do {
            isDuplicate = false;
            cout << "Enter the id of student: ";
            cin >> id;
            for (int i = 0; i < current_size; i++) {
                if (arr[i].getId() == id) {
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
    candidate_attribute candidate_arr[MAX_CANDIDATES];
    int current_size = 0;

    while (true) {
        if (current_size == 0) {
            int n;
            cout << "Enter number of candidates: ";
            if (!candidate_attribute::readInt(n)) continue;
            if (n > MAX_CANDIDATES) n = MAX_CANDIDATES;
            
            for (int i = 0; i < n; i++) {
                candidate_arr[current_size].input(candidate_arr, current_size, current_size + 1);
                current_size++;
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
                    if (current_size >= MAX_CANDIDATES) {
                        cout << "List is full!\n";
                        break;
                    }
                    int numToAdd;
                    cout << "Enter number of candidates to add: ";
                    if (!candidate_attribute::readInt(numToAdd)) break;
                    
                    for (int i = 0; i < numToAdd && current_size < MAX_CANDIDATES; i++) {
                        candidate_arr[current_size].input(candidate_arr, current_size, current_size + 1);
                        current_size++;
                    }
                    break;
                }
                case 2:
                    cout << "\n--- Candidate List ---\n";
                    for (int i = 0; i < current_size; i++) candidate_arr[i].display();
                    break;

                case 3: {
                    string searchID;
                    cout << "Enter ID to search: ";
                    cin >> searchID;
                    bool found = false;
                    for (int i = 0; i < current_size; i++) {
                        if (candidate_arr[i].getId() == searchID) {
                            candidate_arr[i].display();
                            found = true;
                            break;
                        }
                    }
                    if (!found) cout << "Not found\n";
                    break;
                }
                case 4: {
                    if (current_size == 0) break;
                    double maxScore = candidate_arr[0].getScore();
                    for (int i = 1; i < current_size; i++) {
                        if (candidate_arr[i].getScore() > maxScore) maxScore = candidate_arr[i].getScore();
                    }
                    cout << "\n--- Candidate(s) with Highest Score (" << maxScore << ") ---\n";
                    for (int i = 0; i < current_size; i++) {
                        if (candidate_arr[i].getScore() == maxScore) candidate_arr[i].display();
                    }
                    break;
                }
                case 5: {
                    if (current_size == 0) break;
                    double minScore = candidate_arr[0].getScore();
                    for (int i = 1; i < current_size; i++) {
                        if (candidate_arr[i].getScore() < minScore) minScore = candidate_arr[i].getScore();
                    }
                    cout << "\n--- Candidate(s) with Lowest Score (" << minScore << ") ---\n";
                    for (int i = 0; i < current_size; i++) {
                        if (candidate_arr[i].getScore() == minScore) candidate_arr[i].display();
                    }
                    break;
                }
                case 6:
                    return 0;
            }
        }
    }
}