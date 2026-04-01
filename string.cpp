#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Hello World";
    string sub = "World";

    if (s.find(sub) != string::npos) {
        cout << "Substring আছে!" << endl;
    } else {
        cout << "নেই!" << endl;
    }
  int pos = s.find("World");
cout << "Position: " << pos << endl; // Output: 6
}

