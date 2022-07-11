#include<iostream>
#include<utility>
#include<cmath>

using namespace std;

//An intergrate function that can either ouput the nth fib number or index of a fib
int getFibNumOrIndex(const int n, const string mode = "fib"){
    if (n<= 1) return n;
    int i = 0, j = 1, k = 1, result = 1;
    if (mode == "fib"){
        for(k = 1; k<n; ++k){//find nth fib number;
            result = i + j;
            i = j;
            j = result;
        }
        return result;
    }
    else if (mode == "index") {//find Index Of given fib number
        while (result < n){
            result = i + j;
            i = j;
            j = result;
            ++k;
        }
        return k;
    }

    return -1;//mode is invalid
}

//check if an int is perfect square
bool checkPerfectSquare(const int x){
    int r = sqrt(x);
    return (r * r == x);
}

//check if an int is fibonacci number;
bool checkFibnum(int n){

    return checkPerfectSquare(5 * n * n + 4 ) ||checkPerfectSquare( 5 * n * n -4);
}

//check if a given number is fib number and the closet index n in the fib squence
pair<bool, int> validFib(int n){
    if (checkFibnum(n)) return make_pair(true, getFibNumOrIndex(n, "index"));
    int l = n - 1;
    int r = n + 1;
    while(!checkFibnum(l) && !checkFibnum(r)){
        l = l - 1;
        r = r + 1;
    }
    if (checkFibnum(l) && checkFibnum(r)){
        if (n - l < r- n) return make_pair(false, getFibNumOrIndex(l,"index"));
        else return make_pair(false, getFibNumOrIndex(r,"index"));
    }
    else if (checkFibnum(l)) return make_pair(false, getFibNumOrIndex(l,"index"));
    return make_pair(false, getFibNumOrIndex(r,"index"));
}

int main(){
    int i = 13;
    auto result = validFib(6);
    cout<<result.first<< ','<<result.second <<endl;
    cout<<getFibNumOrIndex(7, "index")<<endl;
    return 0;
}