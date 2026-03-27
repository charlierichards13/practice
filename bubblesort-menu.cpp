#include <iostream>
#include <vector>
#include <string>
#include <limits>


using namespace std;
int main () {
    
    vector<double> test;
    int vector_size;
    double num;
    
    
    while (true) {
    cout << "how many numbers do you want to sort? ";
    cin >> vector_size;
    cout << "" << endl;
        if (cin.fail() || vector_size <= 0) {
            cout << "The number of values to sort must be a valid positive integer e.g: 2 or 3" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } else {
        break;
    }
    }
    
    for (int k = 0; k < vector_size; k++ ) {
        while (true) {
            cout << "Enter number " << k + 1 << ": ";
            cin >> num;

            if (cin.fail()) {
                cout << "Invalid input. Please enter a number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                test.push_back(num);
                break;
            }
        }
    }
    
    
    cout << "sorting array..." << endl;
    
    for (int i = 0; i < test.size()-1; i++) {
        bool swap = false;
        for (int j = 0; j < test.size()-1 -i; j++) {
            
        if (test[j] > test[j+1]) {
            double x = test[j];
            
            test[j] = test[j+1];
            
            test[j+1] = x;
            
            swap = true;
            
            
            if (swap) {
                
            cout << "swapped " << test[j] << " with " << test[j+1] << endl;
            } 
            
        } else {
            swap = false;
            if (!swap) {
                cout << "no swap needed" << endl;
            }
        }
      }
    }
    
    cout << "" << endl;
    cout << "sorting complete, the sorted values are: ";
    
    for (double vals : test) {
        cout << vals << " ,";
    }
    
    
    
    return 0;
}
