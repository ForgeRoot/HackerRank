#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool is_openening_tag(const string& line) {
    return line[0] == '<' && line[1] != '/';
}

bool is_closing_tag(const string& line) {
    return line[0] == '<' && line[1] == '/';
}

std::unordered_map<std::string, std::string> get_attributes(const string& line) {
    std::unordeed_map<std::string, std::string> attributes;
    std::istringstream iss(line);

    std::string word;

    while (iss >> word) {
        if (word[0] == '<' || word[0] == '>') {
            continue;
        }
        else if 
    }
    
    return attributes;

}

std::string get_tag_name(const string& line) {
    string tag_name;
    for (int i = 1; i < line.size(); i++) {
        if (line[i] == ' ' || line[i] == '>') {
            break;
        }
        tag_name += line[i];
    }
    return tag_name;
}


int main() {
    int numberOfLines, numberOfQueries;
    cin >> numberOfLines >> numberOfQueries;
    cin.ignore();

    vector<string> hrmlLines(numberOfLines);
    vector<string> queries(numberOfQueries);

    for (int i = 0; i < numberOfLines; i++) {
        string line;
        getline(cin, line);
        hrmlLines[i] = line;
    }

    for (int i = 0; i < numberOfQueries; i++) {
        string line;
        getline(cin, line);
        cin >> queries[i];
    }

    //print out the hrml lines
    for (const auto& line: hrmlLines) {
        if (is_openening_tag(line)) {
            std::string tag_name = get_tag_name(line);
            auto attibutes = get_attributes(line);

            cout << "Opening tag: " << get_tag_name(line) << endl;
        } else if (is_closing_tag(line)) {
            cout << "Closing tag: " << get_tag_name(line) << endl;
        }
    }
    
    return 0;
}