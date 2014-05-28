#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const string morse[30] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..", "..--", "---.", ".-.-", "----" };

int calc(const char * st) {
    cout << st << endl;
    string s ;
    char tmp[405] = {0};
    for (const char * p = st; *p != '\0'; p++) {
        if (*p == '_') { s = morse[26]; }
        else if (*p == '.') { s = morse[27]; }
        else if (*p == ',') { s = morse[28]; }
        else if (*p == '?') { s = morse[29]; }
        else s = morse[*p-'A'];

        cout << " | " << s;
    }

    cout << endl;
}

int main() {
    int n = 0;
    cin >> n;
    const char * st;
    string s;

    for (int i=0; i<n; i++) {
        cin >> s;
        st = s.c_str();
        calc(st);
    }

    return 0;
}
