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

#include <file_reader.hpp>
#include <parser.hpp>
#include <tag.hpp>

using namespace std;




int main() {
    FileReader reader("C:/Code/HackerRank/Attribute_Parser/Test_input/input.txt");
    Parser hrml_parser;
    reader.loadLinesFromFile();
    std::vector<std::string> contents = reader.getContents();
    hrml_parser.parse(contents);
    return 0;
}
