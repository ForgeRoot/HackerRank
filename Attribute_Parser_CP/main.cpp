#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <map>
#include <stack>

using namespace std;

map<string, map<string, string>> tagDatabase;

vector<string> read_contents_from_file(const std::string& filename) {
    std::ifstream cin(filename);
    std::vector<std::string> contents;
    std::string line;

    while (std::getline(cin, line)) {
        contents.push_back(line);
    }

    return contents;
}

std::vector<std::string> read_contents_from_cin() {
    std::vector<std::string> contents;
    std::string line;

    while (std::getline(std::cin, line)) {
        if (line.empty()) // Stop if an empty line is entered
            break;
        contents.push_back(line);
    }

    return contents;
}

int main() {

    std::ifstream cin("C:/Code/HackerRank/Attribute_Parser_CP/Test_input/input.txt");

    int n, q;
    cin >> n >> q;
    cin.ignore();
    

    stack<string> tag_stack;
    string current_path;
    string line;

    for (int i = 0; i < n; ++i){
        getline(cin, line);
        if (line[1] != '/'){
            line = line.substr(1, line.size() - 2);

            stringstream ss (line);
            string tag_name;
            ss >> tag_name;

            if(!tag_stack.empty()){
                current_path += "." + tag_name;
            } else {
                current_path = tag_name;
            }

            string attribute_name, eq, attribute_value;
            map<string, string> attributes;
            while (ss >> attribute_name >> eq >> attribute_value){
                attribute_value = attribute_value.substr(1, attribute_value.length() - 2);
                attributes[attribute_name] = attribute_value;
            }

            tagDatabase[current_path] = attributes;
            tag_stack.push(tag_name);
        } else {
            if (!tag_stack.empty()){
                string closed_tag = tag_stack.top();
                tag_stack.pop();
                size_t pos = current_path.rfind("." + closed_tag);
                if (pos != string::npos){
                    current_path = current_path.substr(0, pos);
                } else {
                    current_path = "";
                }
            }
        }
    }

    for (int i = 0; i < q - 1; ++i){
        string query;
        getline(cin, query);

        size_t tilde_pos = query.find('~');
        string tag_path = query.substr(0, tilde_pos);
        string attr_name = query.substr(tilde_pos + 1);


        if (tagDatabase.count(tag_path) && tagDatabase[tag_path].count(attr_name)) {
            cout << tagDatabase[tag_path][attr_name] << endl;
        } else {
            cout << "Not Found!" << endl;
        }
    }

    return 0;
}
