#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int N = 30;

const string morse[N] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..", "..--", "---.", ".-.-", "----" };

void reverse(int *n, int len) {
    int tmp;
    for (int i=0; i<len/2; i++) {
        tmp = n[i];
        n[i] = n[len-1-i];
        n[len-1-i] = tmp;
    }
}

char find(string code) {
    for (int i=0; i<N; i++) {
        if (code == "..--") { return '_'; }
        if (code == "---.") { return '.'; }
        if (code == ".-.-") { return ','; }
        if (code == "----") { return '?'; }
        if (code == morse[i]) {
            return i + 'A';
        }
    }
    return '!';
}

int decode(int no, char *s, int *n, int len) {
    int l = 0;
    char * p = s;
    char ret[len + 1];

    for (int i=0; i<len; i++) {
        l = n[i];
        char tmp[l+1];
        strncpy(tmp, p, l);
        tmp[l] = '\0';
        //cout << ':' << tmp << endl;
        //cout << ')' << l << endl;
        ret[i] = find(tmp);
        //cout << ret[i] << endl;
        p += l; 
    }
    ret[len] = '\0';
    cout << no << ": " << ret << endl;
}
int calc(const char * st, int no) {
    //cout << st << endl;
    string s ;
    char tmp[405] = {0};
    int len = strlen(st);
    int num[len];
    int i = 0;
    for (const char * p = st; *p != '\0'; p++) {
        if (*p == '_') { s = morse[26]; }
        else if (*p == '.') { s = morse[27]; }
        else if (*p == ',') { s = morse[28]; }
        else if (*p == '?') { s = morse[29]; }
        else s = morse[*p-'A'];
        if (p == st) {
            strcpy(tmp, s.c_str());
        } else {
            strcat(tmp, s.c_str());
        }
        num[i++] = strlen(s.c_str());
    }
    reverse(num, len);
    decode(no, tmp, num, len);
    return 0;
}

int main() {
    int n = 0;
    cin >> n;
    string st[n];

    for (int i=0; i<n; i++) {
        cin >> st[i];
    }

    for (int i=0; i<n; i++) {
        calc(st[i].c_str(), i+1);
    }

    return 0;
}
