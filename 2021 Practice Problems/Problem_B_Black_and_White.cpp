/*
Black and White is a Chinese children’s game played in rounds. During each round, the children who are playing all put their hands in either face-up (“White”) or face-down (“Black”). If all the children but one make the same choice, then the “odd one out” sits out for the rest of the game. Play continues until there are only two children left.

Each child independently chooses whether to put their hand face-up with their own fixed probability. What is the expected number of rounds that such a game will last?
Input

The first line contains a single integer ( 2 <= n <= 20), which is the number of children.

Each of the next
lines contains a single real number ( 0.1 <= n <= 0.9 ). These are the probabilities for each child that they will put their hand in face-up. The probabilities will have at most three digits after the decimal point.
Output

Output a single real number, which is the expected number of rounds. The result must be accurate to within an absolute or relative error of 10^6.
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    // Get int input for number of children between 2 and 20
    int children = 0;
    while (children < 2 || children > 20) {
        cout << "Enter a number of children playing Black and White between 2 and 20 including 2 and 20.\n";
        cin >> children;
    }


    // Get input probabilities for each child
    vector<double> probabilities(children);
    for (int i = 0; i < children; i++) {
        cout << "Enter the probability that child " << (i + 1) << " will choose to put their hand in face up between 0.1 and 0.9.\n";
        cin >> probabilities[i];
    }


    // Math for estimating the number of rounds
    double expectedRounds = 0.0;
    int n = children;
    while (n > 2) {
        double totalOddProbability = 0.0;

        for (int i = 0; i < n; ++i) {
            // Case 1: ith child is face-up, others face-down
            double probFaceUp = probabilities[i];
            for (int j = 0; j < n; ++j) {
                if (i != j) probFaceUp *= (1 - probabilities[j]);
            }

            // Case 2: ith child is face-down, others face-up
            double probFaceDown = 1 - probabilities[i];
            for (int j = 0; j < n; ++j) {
                if (i != j) probFaceDown *= probabilities[j];
            }

            totalOddProbability += probFaceUp + probFaceDown;
        }

        // Update expected rounds based on probability for this round
        expectedRounds += 1.0 / totalOddProbability;
        n -= 1;
    }



    // Output the expected number of rounds
    cout << "Expected number of rounds: " << expectedRounds;

    return 0;
}