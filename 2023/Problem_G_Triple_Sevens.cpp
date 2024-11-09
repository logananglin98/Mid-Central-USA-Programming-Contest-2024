#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    std::ifstream file("Problem_G_input.txt");

    string line;
    int n;
    int sevens = 1;
    int o = 777;

    while(getline(file, line)) {
        int space = line.find(" ");
        if (space == -1) {
            n = stoi(line);
        } else {
            sevens = 0;
            for (int i = 0; i < 1 + (n - 1) * 2; i++) {
                if (line[i] == '7') {
                    sevens++;
                }
            }
        }
        if (sevens < 1) {
            o = 0;
            break;
        }
    }

    file.close();

    std::ofstream output("Problem_G_output.txt");

    output << o;

    output.close();

    return 0;
}