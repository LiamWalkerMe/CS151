#include <iostream>
using namespace std;

int main() {
    
    string word1 = "aab";
    string word2 = "abc";

    int count;

    for (char x : word1) {
        cout << "Character from first word: " << x << endl;
        for (char y : word2) {
            cout << "Compared to: " << y << endl;
            if (x == y) {
                count++;
                cout << "Match found!" << endl;
                break;
            }
        }
    }
    if(count == word1.size()) {
        cout << "This is an Anagram!";
    } else {
        cout << "Not an Anagram.";
    }


    return 0;
}