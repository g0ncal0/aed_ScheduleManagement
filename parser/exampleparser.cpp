//
// Created by Filipe Correia on 12/10/2023.
//


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


void parse(){
    std::ifstream classes("../parser/classes.csv");
    std::string line;

    if (!classes.is_open()) {
        std::cout << "not ok";
        return;
    }
    std::vector<std::vector<std::string>> theList;

    while (getline(classes,line))
    {
        std::vector<std::string> attributes;
        std::istringstream iss(line);
        std::string attribute;
        while (getline(iss, attribute, ',')) {
            attributes.push_back(attribute);
        }
        theList.push_back(attributes);
    }
    classes.close();
    for (auto &lin : theList) {
        for(auto &el : lin){
            std::cout << el;
        }
        std::cout << "/n";
    }

}

int main(){
    parse();
    return 0;
}