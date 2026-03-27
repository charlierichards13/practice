#include <iostream>
#include <vector>
#include <limits>

using namespace std;

vector<double> inputNumbers() {
    vector<double> nums;
    int vector_size;
    double num;

    while (true) {
        cout << "You can use these numbers to perform a number of operations" << endl;
        cout << "this menu was made by charlie richards as a practice for sorting and dynamic allocation, these tools actually may be useful lol" << endl;
        cout << "How many numbers do you want to store? ";
        cin >> vector_size;
        cout << endl;

        if (cin.fail() || vector_size <= 0) {
            cout << "The number of values must be a valid positive integer, such as 2 or 3." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    for (int k = 0; k < vector_size; k++) {
        while (true) {
            cout << "Enter number " << k + 1 << ": ";
            cin >> num;

            if (cin.fail()) {
                cout << "Invalid input. Please enter a number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                nums.push_back(num);
                break;
            }
        }
    }

    return nums;
}

vector<double> sortArray(vector<double> nums) {
    // using bubble sort (O(n^2)) worst case
    for (int i = 0; i < nums.size() - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < nums.size() - 1 - i; j++) {
            if (nums[j] > nums[j + 1]) {
                double temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }

    return nums;
}

double findAverage(const vector<double>& nums) {
    double sum = 0;

    for (double value : nums) {
        sum += value;
    }

    return sum / nums.size();
}

double findMedian(const vector<double>& nums) {
    vector<double> sortedNums = sortArray(nums);
    int size = sortedNums.size();

    if (size % 2 == 1) {
        return sortedNums[size / 2];
    } else {
        return (sortedNums[size / 2 - 1] + sortedNums[size / 2]) / 2.0;
    }
}

int main() {
    vector<double> test = inputNumbers();
    int choice;

    while (true) {
        cout << "\n========== MENU ==========" << endl;
        cout << "1. Sort the array" << endl;
        cout << "2. Perform addition or subtraction" << endl;
        cout << "3. Perform multiplication or division" << endl;
        cout << "4. Find average" << endl;
        cout << "5. Find median" << endl;
        cout << "6. Enter new numbers" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid menu choice. Please enter a number from 1 to 7." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1) {
            vector<double> sorted = sortArray(test);
            cout << "\nSorted values: ";
            for (int i = 0; i < sorted.size(); i++) {
                cout << sorted[i];
                if (i != sorted.size() - 1) {
                    cout << ", ";
                }
            }
            cout << endl;
        }
        else if (choice == 2) {
            int subChoice;
            cout << "\nEnter 1 for addition or 2 for subtraction: ";
            cin >> subChoice;

            if (cin.fail() || (subChoice != 1 && subChoice != 2)) {
                cout << "Invalid choice." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (subChoice == 1) {
                double sum = 0;
                for (double value : test) {
                    sum += value;
                }
                cout << "Result of addition: " << sum << endl;
            } else {
                double result = test[0];
                for (int i = 1; i < test.size(); i++) {
                    result -= test[i];
                }
                cout << "Result of subtraction: " << result << endl;
            }
        }
        else if (choice == 3) {
            int subChoice;
            cout << "\nEnter 1 for multiplication or 2 for division: ";
            cin >> subChoice;

            if (cin.fail() || (subChoice != 1 && subChoice != 2)) {
                cout << "Invalid choice." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (subChoice == 1) {
                double product = 1;
                for (double value : test) {
                    product *= value;
                }
                cout << "Result of multiplication: " << product << endl;
            } else {
                double result = test[0];
                bool canDivide = true;

                for (int i = 1; i < test.size(); i++) {
                    if (test[i] == 0) { // so we dont break the program
                        cout << "Division by zero is not allowed." << endl;
                        canDivide = false;
                        break;
                    }
                    result /= test[i];
                }

                if (canDivide) {
                    cout << "Result of division: " << result << endl;
                }
            }
        }
        else if (choice == 4) {
            cout << "\nAverage: " << findAverage(test) << endl;
        }
        else if (choice == 5) {
            cout << "\nMedian: " << findMedian(test) << endl;
        }
        else if (choice == 6) {
            cout << "\nEntering new numbers...\n" << endl;
            test = inputNumbers();
        }
        else if (choice == 7) {
            cout << "thank you for trying out my program!" << endl;
            cout << "\nExiting program. Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please enter a number from 1 to 7." << endl;
        }
    }

    return 0;
}
