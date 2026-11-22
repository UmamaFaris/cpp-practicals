
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// Student Class
class Student {
public:
    int id;
    string name;
    float marks;
};

int main() {

    Student s[3];

    // Student Details
    s[0] = {101, "Aman", 85.5};
    s[1] = {102, "Rahul", 90.0};
    s[2] = {103, "Sameer", 78.5};

    // Writing records into CSV file
    ofstream fout("students.csv");

    if (!fout) {
        cout << "File could not be opened!" << endl;
        return 1;
    }

    fout << "ID,Name,Marks\n";

    for (int i = 0; i < 3; i++) {
        fout << s[i].id << ","
             << s[i].name << ","
             << s[i].marks << "\n";
    }

    fout.close();

    cout << "Student records saved successfully!" << endl;

    // Reading records from CSV file
    ifstream fin("students.csv");

    if (!fin) {
        cout << "File not found!" << endl;
        return 1;
    }

    string line;

    cout << "\nStudent Records:" << endl;

    getline(fin, line); // Skip header

    while (getline(fin, line)) {

        stringstream ss(line);
        string id, name, marks;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, marks, ',');

        if (id.empty() || name.empty() || marks.empty()) {
            cout << "Invalid record!" << endl;
            continue;
        }

        cout << "ID: " << id
             << " Name: " << name
             << " Marks: " << marks << endl;
    }

    fin.close();

    // File Position Functions
    fstream file("position_demo.txt",
                 ios::in | ios::out | ios::trunc);

    file << "HELLO";

    cout << "\nFile Position Demonstration:" << endl;

    // tellp()
    cout << "Write Position: " << file.tellp() << endl;

    // seekp()
    file.seekp(0);
    file.put('Y');

    // tellg() and seekg()
    file.seekg(0);

    char ch;
    file.get(ch);

    cout << "First Character: " << ch << endl;
    cout << "Read Position: " << file.tellg() << endl;

    file.seekg(1);
    file.get(ch);

    cout << "Second Character: " << ch << endl;

    file.close();

    return 0;
}
