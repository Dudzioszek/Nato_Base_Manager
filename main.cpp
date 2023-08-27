//Stanislaw Dutkiewicz 263509
#include <iostream>
#include "Natobase.h"

using namespace std;

//basic interface
int main() {
    cout << "Welcome to the NATO base Program!\n";
    int genc = 0;
    Database Database;
    while (genc != 9) {
        cout << "\n\nPlease enter your operation:\n\n";
        cout << "\n1. Add the base";
        cout << "\n2. Display all the bases";
        cout << "\n3. Edit the base";
        cout << "\n4. Remove the base";
        cout << "\n5. Import the base from txt file";
        cout << "\n6. Export the base into txt file";
        cout << "\n7. Perform the comparison of the NATO base against the Russian divisions";
        cout << "\n8. Erase all bases";
        cout << "\n9. Exit\n\n";
        cin >> genc;
        switch (genc) {
            case 1: {
                Database.Read_data();
                break;
            }
            case 2: {
                Database.Print_data();
                break;
            }
            case 3: {
                Database.EditDB();
                break;
            }
            case 4: {
                Database.RemoveDB();
                break;
            }
            case 5: {
                Database.OpenDB();
                break;
            }
            case 6: {
                Database.SaveDB();
                break;
            }
            case 7: {
                Database.Compare();
                break;
            }
            case 8: {
                Database.Clear();
                break;
            }
            case 9: {
                genc = 9;
                break;
            }
        }
    }
    std::cout << "Thank you for using our program. Have a good day!" << endl;
    return 0;
}

