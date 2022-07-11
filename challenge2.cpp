#include <iostream>
#include<queue>
#include<unordered_map>
#include<utility>

using namespace std;
char topFreqElement(const string s){
    auto hashmap = unordered_map<char, pair<int, int>>{};
    auto maxpq = priority_queue<pair<int, int>>{};
    auto minpq = priority_queue<pair<int,int> , vector<pair<int, int>>, greater<pair<int, int>>>{};
    int n = s.size();
    for (int i  = 0; i<n; ++i){
        if (hashmap.find(tolower(s[i])) == hashmap.end()){
            hashmap.insert({(tolower(s[i])), make_pair(1, i)});
            continue;
        }
        ++hashmap[tolower(s[i])].first;
    }
    for (auto const h : hashmap){
        maxpq.push(h.second);
    }
    auto max_freq = maxpq.top().first;
    while (max_freq == maxpq.top().first && !maxpq.empty()){
        auto tmp1 = maxpq.top().first;
        auto tmp2 = maxpq.top().second;
        minpq.push(make_pair(tmp2, tmp1));
        maxpq.pop();
    }
    return tolower(s[minpq.top().first]);
}

int main(){
    string a = "abacabbcc";
    cout <<topFreqElement(a) <<endl;
    return 0;
}
