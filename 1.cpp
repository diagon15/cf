#include <bits/stdc++.h>
using namespace std;


class Trie {
    public:
    Trie* next[26];
    bool endofstr;
    Trie(){
        for(int i = 0; i < 26; ++ i) next[i] = NULL;
        endofstr = false;
    }

    int addTrie(char ch){
        int idx = ch - 'a';
        if(next[idx] == NULL) next[idx] = new Trie();
        return idx;
    }
};

class Encrypter {
public:

    vector<char> keys;
    map<char, int> mp;
    map<string, vector<char>> mp2;
    vector<string> values, dictionary;
    Trie *t;

    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        this->keys = keys;
        this->values = values;
        this->dictionary = dictionary;

        for(int i = 0; i < keys.size(); ++ i){
            mp[keys[i]] = i;
            // cout << mp[keys[i]] << " " << keys[i] << endl;
            mp2[values[i]].push_back(keys[i]);

        }

        t = new Trie();
        Trie *p;
        for(int i = 0; i < dictionary.size(); ++ i){
            p = t;
            for(int j = 0; j < dictionary[i].size(); ++ j){
                int idx = p->addTrie(dictionary[i][j]);
                p = p->next[idx];
            }
            p->endofstr = true;
        }

    }

    string encrypt(string word1) {
        int n = word1.size();
        string res = "";
        for(int i = 0; i < n; ++ i){
            if(mp.find(word1[i]) != mp.end()){
                res += values[mp[word1[i]]];
            }
        }
        return res;
    }

    int decrypt(string &word2, int index = 0, Trie *p = NULL, map<pair<int, Trie *>, int> &mp4 = map<pair<int, Trie *>, int>)
    {
        if(index == 0) p = t;
        if(index >= word2.size() and p->endofstr == true) return 1;
        if(index >= word2.size()) return 0;
        if(mp4.find({index, p}) != mp4.end()){
            return mp4[{index, p}];
        }
        if(p == NULL) return 0;
        int res = 0;
        string str = word2.substr(index, 2);
        for(auto &u: mp2[str]){
            int idx = u - 'a';
            if(p->next[idx] != NULL){
                res += decrypt(word2, index + 2, p-> next[idx]);
            }
        }
        return mp4[{index, p}] = res;
    }
// private:

};


/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */

int main(){

    vector<char> keys{'a', 'b', 'c', 'd'};
    vector<string> values { "ei", "zf", "ei", "am" };
    vector<string> dictionary{"abcd", "acbd", "adbc", "badc", "dacb", "cadb", "cbda", "abad"};
    string word1 = "abcd";
    string word2 = "eizfeiam";
    Encrypter *obj = new Encrypter(keys, values, dictionary);
    // cout << obj->mp['c'] << endl;
    string param_1 = obj->encrypt(word1);
    int param_2 = obj->decrypt(word2);

    cout << param_1<< endl;
    cout << param_2 << endl;


    return 0;
}