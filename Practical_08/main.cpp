
#include <iostream>
using namespace std;

class Settings {
private:
    int volume;

    // Private constructor
    Settings() {
        volume = 50;
    }

public:
    // Single instance
    static Settings& getInstance() {
        static Settings obj;
        return obj;
    }

    void setVolume(int v) {
        volume = v;
    }

    void showVolume() {
        cout << "Volume: " << volume << endl;
    }
};

int main() {

    // First call
    Settings& s1 = Settings::getInstance();

    cout << "First Object:" << endl;
    s1.showVolume();

    // Change volume
    s1.setVolume(80);

    // Second call
    Settings& s2 = Settings::getInstance();

    cout << "\nSecond Object:" << endl;
    s2.showVolume();

    // Check same object
    if (&s1 == &s2) {
        cout << "\nBoth are the same object." << endl;
    }

    return 0;
}
