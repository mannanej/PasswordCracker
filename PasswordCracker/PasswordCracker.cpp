#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;
bool boolNumbers = false;
bool boolLowerCase = false;
bool boolUpperCase = false;
bool boolSpecial = false;
char numbers[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char lowerCase[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
                              'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char upperCase[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
                              'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char special[30] = { '`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+', '[', '{'
                          ,']', '}', '|', ';', ':', '"', ',', '<', '.', '>', '/', '?'};

void specific() {

    std::string password, answer, nums, low, cap, spec;
    long long int tries = 0;

    cout << "What is your password: \n";
    cin >> password;

    cout << "Does Your Password Contain Numbers? y/n?\n";
    cin >> nums;

    if (nums == "y") {
        boolNumbers = true;
    }
    else if (nums == "n") {
        boolNumbers = false;
    }
    cout << "Does Your Password Contain Lower Case Letters? y/n?\n";
    cin >> low;

    if (low == "y") {
        boolLowerCase = true;
    }
    else if (low == "n") {
        boolLowerCase = false;
    }
    cout << "Does Your Password Contain Upper Case Letters? y/n?\n";
    cin >> cap;

    if (cap == "y") {
        boolUpperCase = true;
    }
    else if (cap == "n") {
        boolUpperCase = false;
    }
    cout << "Does Your Password Contain Special Characters? y/n?\n";
    cin >> spec;

    if (spec == "y") {
        boolSpecial = true;
    }
    else if (spec == "n") {
        boolSpecial = false;
    }

    auto start = high_resolution_clock::now();

    for (int i = 0; i < password.size(); i++) {
        if (boolNumbers) {
            for (int j = 0; j < 10; j++) {
                if (password.at(i) == numbers[j]) {
                    answer.push_back(numbers[j]);
                    cout << "Checking Character: " << numbers[j] << " At Position: " << i << "\n";
                    tries++;
                    break;
                }
                else {
                    cout << "Checking Character: " << numbers[j] << " At Position: " << i << "\n";
                    tries++;
                }
            }
        }
        if (boolLowerCase) {
            for (int k = 0; k < 26; k++) {
                if (password.at(i) == lowerCase[k]) {
                    answer.push_back(lowerCase[k]);
                    cout << "Checking Character: " << lowerCase[k] << " At Position: " << i << "\n";
                    tries++;
                    break;
                }
                else {
                    cout << "Checking Character: " << lowerCase[k] << " At Position: " << i << "\n";
                    tries++;
                }
            }
        }
        if (boolUpperCase) {
            for (int l = 0; l < 26; l++) {
                if (password.at(i) == upperCase[l]) {
                    answer.push_back(upperCase[l]);
                    cout << "Checking Character: " << upperCase[l] << " At Position: " << i << "\n";
                    tries++;
                    break;
                }
                else {
                    cout << "Checking Character: " << upperCase[l] << " At Position: " << i << "\n";
                    tries++;
                }
            }
        }
        if (boolSpecial) {
            for (int p = 0; p < 30; p++) {
                if (password.at(i) == special[p]) {
                    answer.push_back(special[p]);
                    cout << "Checking Character: " << special[p] << " At Position: " << i << "\n";
                    tries++;
                    break;
                }
                else {
                    cout << "Checking Character: " << special[p] << " At Position: " << i << "\n";
                    tries++;
                }
            }
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "" << "\n";
    cout << "Your Password Must Be: " << answer << " After A Total Of: " << tries << " Checks!\n";
    cout << "This Process Took ~" << duration.count() << "ms!";
    cout << "" << "\n";
}

void bruteForce() {

    boolNumbers = true;
    boolLowerCase = true;
    boolUpperCase = true;
    boolSpecial = true;
}

int main() {

    while (true) {
        std::string password;
        int process;
        cout << "Welcome to the Password Cracker!\nHow would you like us to guess your password?\n";
        cout << "1: Get Specific\n2: Brute Force\n";
        cout << "Choice: ";
        cin >> process;

        while (cin.fail()) {
            cout << "Please Enter A Number..." << "\n";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> process;
        }

        if (process == 1) {
            specific();
        }
        else if (process == 2) {
            cout << " " << "\n";
            printf("What is your password: \n");
            cin >> password;
            bruteForce();
        }
        else {
            cout << " " << "\n";
            printf("Invalid Input! Try Again...\n");
            cout << " " << "\n";
        }
    }
}