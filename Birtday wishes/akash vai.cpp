#include <iostream>
#include <string>
using namespace std;

int main() {
    int i, j, rows = 23;
    string name = "HappyBirthday Akash Vai";
    int len = name.length();
    int stars, spaces;

    stars = 1;
    spaces = rows / 2;

    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= spaces; j++) {
            cout << " ";
        }

        for (j = 1; j <= stars; j++) {
            if (i == rows / 2 + 1) {
                cout << name[j - 1];
            } else {
                cout << "*";
            }
        }

        cout << endl;

        if (i < rows / 2 + 1) {
            spaces--;
            stars += 2;
        } else {
            spaces++;
            stars -= 2;
        }
    }
    return 0;
}
