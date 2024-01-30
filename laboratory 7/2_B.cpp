#include <iostream>
#include <string>
#include <map>
#include <list>
using namespace std;

/// 2
struct Node {
    int pos = 0;
    char next = 0;
};


list<Node> code_LZ78(string s) {
    string buffer = "";
    map<string, int> dict = {};
    list<Node> ans;

    for(long long i = 0; i < s.length(); i++) {
        if(dict.find(buffer + s[i]) != dict.end()) {
            buffer += s[i];
        }
        else {
            ans.push_back({dict[buffer], s[i]});
            dict[buffer + s[i]] = dict.size();
            buffer = "";
        }
    }


    if(!buffer.empty()) {
        ans.push_back({dict[buffer], '\0'});
    }

    return ans;
}



int main () {
    string stroka; cin >> stroka;

    list<Node> ans = code_LZ78(stroka);

    for(Node x: ans ) {
        cout << x.pos << " " <<  x.next << "\n";
    }
}