#include<iostream>
#include<vector>

using namespace std;

//Another solution for challenge 2, O(n+m) time complexity, however if we
//assume character is bound to ASCII code, m will become constant 128, in
//this case is more efficient than my previous solution
char topFreqElement(const string s){
    auto count = vector<int>(128, 0);
    auto index_track = vector<int>(128,0);
    auto top_freq = 0;
    for (int i = 0; i<s.size();++i){
        ++count[(int)tolower(s[i])];
        if (count[(int)tolower(s[i])] == 1){
            index_track[(int)tolower(s[i])] = i;
        }
        top_freq = max(top_freq, count[(int)tolower(s[i])]);
    }
    int res = s.size()+1;
    for (int i = 0; i<128; ++i){
        if (count[i] == top_freq) res = min(res, index_track[i]);
    }
    return tolower(s[res]);
}

int main(){
    string a = "CaabAbbcc";
    cout << topFreqElement(a) <<endl;
    return 0;
}