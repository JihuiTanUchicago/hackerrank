#include <cmath>
#include <cstdio>
#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

string get_next_str(string input_str, int index){
    int start = index;
    string result = "";
    while(start < input_str.size() && input_str[start] != ' ' && input_str[start] != '>'){
        if(input_str[start] != '"'){
            result += input_str[start];
        }
        start += 1;
    }
    return result;
}

tuple<string,string> get_tag_and_key(string input_str){
    string tag = "";
    int start = 0;
    while(input_str[start] != '~'){
        tag += input_str[start];
        start += 1;
    }
    string key = input_str.substr(start+1);
    return make_tuple(tag, key);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    unordered_map<string, unordered_map<string, string>> value_storage;  
    int N,Q; cin >> N >> Q; cin.ignore();
    vector<string> vec;
    for(int i = 0; i < N; i++){
        string input_str; getline(cin, input_str);
        //cout << "input_str: " << input_str << endl;
        if(input_str[1] != '/'){
            string tag_str = get_next_str(input_str, 1);
            //cout << "tag_str: " << tag_str << endl;
            vec.push_back(tag_str);
            int start = 2 + tag_str.size();
            //cout << "values start at: " << start << endl;
            string concat_tag_str = "";
            for(int i = 0; i < vec.size(); i++){
                if(i < vec.size()-1){
                    concat_tag_str += vec[i]+".";
                }else{
                    concat_tag_str += vec[i];
                }
            }
            tag_str = concat_tag_str;
            string next_str = ""; string val = "";
            while(start < input_str.size()){
                next_str = get_next_str(input_str, start);
                //cout << "next_str: " << next_str << endl;
                value_storage[tag_str][next_str] = "";
                start += next_str.size() + 3;
                //cout << "val index starts at: " << start << endl;
                val = get_next_str(input_str, start);
                //cout << "val: " << val << endl;
                value_storage[tag_str][next_str] = val;
                start += val.size() + 3;
                //cout << "next_str starts at: " << start << endl;
            }
        }else{
            vec.pop_back();
        }
    }
    for(int i = 0; i < Q; i++){
        string input_str; getline(cin, input_str);
        //cout << "input_str: " << input_str << endl;
        string tag, key;
        tie(tag, key) = get_tag_and_key(input_str);
        if(value_storage[tag].find(key) == value_storage[tag].end()){
            cout << "Not Found!" << endl;
        }else{
            cout << value_storage[tag][key] << endl;
        }
    }
    
    return 0;
}
