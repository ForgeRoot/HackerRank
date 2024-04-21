#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <sstream>
#include <fstream>
#include <utility>

#include <parser.hpp>
#include <tag.hpp>

using namespace std;

bool is_openening_tag(const string& line) {
    return !line.empty() && line[0] == '<' && line[1] != '/';
}

bool is_closing_tag(const string& line) {
    return line.size() >= 2 && line[0] == '<' && line[1] == '/';
}

std::unordered_map<std::string, std::string> get_attributes(const string& line) {
    std::unordered_map<std::string, std::string> attributes;
    std::istringstream iss(line);
    bool isAttributeName = true;
    bool isAttributeValue = false;

    std::string key;
    std::string value;
    std::string temp;

    while (iss >> temp) {
        if (temp[0] == '<' || temp[0] == '>') {
            continue;
        } else if (isAttributeName) {
            key = temp;
            isAttributeName = false;
        } else if (temp == "=" && !isAttributeName) {
            isAttributeValue = true;
        } else if (isAttributeValue && !temp.empty() && temp.back() !='>') {
            value = temp;
            attributes[key] = value;
            isAttributeName = true;
        } else if (isAttributeValue && !temp.empty() && temp.back() == '>') {
            value = temp.substr(0, temp.size() - 1);
            attributes[key] = value;
            break;
        } else {
            std::cout << "WTF!" << std::endl;
        }
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


std::pair<std::vector<std::string>, std::vector<std::string>> readFromStdin() {
    std::vector<std::string> hrmlLines(numberOfLines);
    std::vector<std::string> queries(numberOfQueries);

    for (int i = 0; i < numberOfLines; i++) {
        std::getline(std::cin, hrmlLines[i]);
    }

    for (int i = 0; i < numberOfQueries; i++) {
        std::getline(std::cin, queries[i]);
    }

    return {hrmlLines, queries}; // Return the read content
}

std::pair<vector<string>, string> splitQuery(const string& query){
    vector<string> tags;
    string attrName;
    stringstream ss(query);
    string item;

    while (getline(ss, item, '~')){
        if(ss.peek() == '~') {
            attrName = item;
        }

    }
}

int main() {
    auto [hrmlLines, queries] = readFromFile(inputFileName);

    if (hrmlLines.empty() || queries.empty()) {
        std::cerr << "Error reading from file: " << inputFileName << std::endl;
        return 1;
    }

    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> hrmlTags;
    std::vector<string> tagStack;

    //print out the hrml lines
    for (const auto& line: hrmlLines) {
        if (is_openening_tag(line)) {
            std::string tag_name = get_tag_name(line);
            auto attibutes = get_attributes(line);
            hrmlTags[tag_name] = attibutes;
            tagStack.push_back(tag_name);

        } else if (is_closing_tag(line)) {
            tagStack.pop_back();
        }
    }
    if (tagStack.empty()) {
        for (const auto& query: queries) {
            
        }
        cout << "Correct implementation of stack" << endl;
            for (const auto& tag: hrmlTags) {
                std::cout << "Tag: " << tag.first << std::endl;
                for (const auto& attribute: tag.second) {
                    std::cout << "      Attribute: " << attribute.first << " = " << attribute.second << std::endl;
                }
            }

    }
    
    return 0;
}