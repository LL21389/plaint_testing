#include <iostream>
#include<queue>
#include<unordered_map>
#include<utility>

using namespace std;
//O(nlogn) method, since we need to return the first occurance char when multiple max exist, 
//index of char also need to be track;
char topFreqElement(const string s){
    auto hashmap = unordered_map<char, pair<int, int>>{};
    auto maxpq = priority_queue<pair<int, int>>{};
    auto minpq = priority_queue<int , vector<int>, greater<int>>{};
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
        minpq.push(maxpq.top().second);
        maxpq.pop();
    }
    return tolower(s[minpq.top()]);
}

int main(){
    string a = "abacabbcc";
    cout <<topFreqElement(a) <<endl;
    return 0;
}

