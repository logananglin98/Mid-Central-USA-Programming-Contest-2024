#include <iostream>
#include <fstream>
using namespace std;

int main() {
    std::ifstream file("Problem_J_input.txt");

    string line;

    int n;

    int m;

    if (getline(file, line)) {  // Read a line from the file
        // Find the position of the space between the two numbers
        size_t spacePos = line.find(' ');

        // Extract and convert the two parts to integers
        n = stoi(line.substr(0, spacePos));
        m = stoi(line.substr(spacePos + 1));
    }

    char grid[n][m];

    int row = 0;

    while (getline(file, line)) {
        std::cout << "Line: " << line << "\n";
        for (int i = 0; i < n; i++) {
            grid[row][i] = line[i];
        }
        row++;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j];
        }
        cout << "\n";
    }

    int flag_options = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '?' && i > 0 && j > 0) {
                if (grid[i][j - 1] != '?' && grid[i - 1][j - 1] != '?' && grid[i - 1][j] != '?') { 
                    
                }
            } else if (grid[i][j] == '?') {
                flag_options *= 3;
            }
        }
    }
    cout << "\nTest: " << flag_options;
}