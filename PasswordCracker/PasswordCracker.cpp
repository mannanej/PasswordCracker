#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;
int state = 0;
string multiThreadAnswer = "";
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
    cout << "This Process Took ~" << duration.count() << "ms!\n" << "\n";
}

void bruteForce() {

    std::string password, answer;
    long long int tries = 0;

    cout << "What is your password: \n";
    cin >> password;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < password.size(); i++) {
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

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "" << "\n";
    cout << "Your Password Must Be: " << answer << " After A Total Of: " << tries << " Checks!\n";
    cout << "This Process Took ~" << duration.count() << "ms!\n" << "\n";
}

void testChar(char c, int threadNumber) {

    char nextChar{};
    bool found = false;

    for (int j = 0; j < 10; j++) {
        if (c == numbers[j]) {
            found = true;
            nextChar = numbers[j];
            break;
        }
    }

    if (found == false) {
        for (int k = 0; k < 26; k++) {
            if (c == lowerCase[k]) {
                found = true;
                nextChar = lowerCase[k];
                break;
            }
        }
    }

    if (found == false) {
        for (int l = 0; l < 26; l++) {
            if (c == upperCase[l]) {
                found == true;
                nextChar = upperCase[l];
                break;
            }
        }
    }

    if (found == false) {
        for (int p = 0; p < 30; p++) {
            if (c == special[p]) {
                found == true;
                nextChar = special[p];
                break;
            }
        }
    }
    
    while (threadNumber != state) {
        // Wait
    }
    multiThreadAnswer.push_back(nextChar);
    state++;
}

void multiThread() {

    std::string password, answer;
    long long int tries = 0;

    cout << "What is your password: \n";
    cin >> password;

    auto start = high_resolution_clock::now();

    std::vector<std::thread> threads(password.length());

    for (int i = 0; i < password.length(); i++) {
        std::thread th(testChar, password.at(i), i);
        threads.push_back(std::move(th));
    }

    for (std::thread & th : threads) {
        if (th.joinable()) {
            th.join();
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "" << "\n";
    cout << "Your Password Must Be: " << multiThreadAnswer << "\n";
    cout << "This Process Took ~" << duration.count() << "ms!\n" << "\n";
    multiThreadAnswer = "";
    state = 0;
}

int main() {

    while (true) {
        std::string password;
        int process;
        cout << "Welcome to the Password Cracker!\nHow would you like us to guess your password?\n";
        cout << "1: Get Specific\n2: Brute Force\n3: Multithread Brute Force\n";
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
            bruteForce();
        }
        else if (process == 3) {
            multiThread();
        }
        else {
            cout << " " << "\n";
            printf("Invalid Input! Try Again...\n");
            cout << " " << "\n";
        }
    }
}