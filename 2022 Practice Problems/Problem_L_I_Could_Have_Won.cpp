/*
“We will be closing in about 5 minutes. Thank you for visiting the ICPC gym today.”

With this announcement, Alice and Bob stopped playing their rock-paper-scissors marathon in the middle of the
th game. Each player scores a point if their throw beats the other player’s throw. Each game was played by the first-to-11 rule, meaning that whoever scores

points first wins the game. Today, Bob narrowly defeated Alice by a single game; he scored 11 points first in five games, while Alice only scored 11 points first 
in four games.

After carefully inspecting how each game was played, however, Alice realized that she could have won more games than Bob if they played under slightly different rules, 
such as first-to-5 or first-to-8, instead of the regular first-to-11.

Given the sequence of points scored by Alice and Bob, determine all values of such that Alice would have won more games than Bob under the first-to-k rule.

Both Alice and Bob start with zero points at the beginning of a game. As soon as one player reaches points, that player wins the game, and a new game starts. 
Alice wins a game if she scores points before Bob does. Neither player wins the game if it’s interrupted by the gym closing before either player reaches k points.


Input

The single line of input consists of a string of uppercase letters “A” or “B”, denoting who scored each point from the beginning of the rock-paper-scissors marathon. 
The length of the string is between 1 and 2000 letters, inclusive. “A” means Alice scored the point, “B” means Bob scored the point.


Output

On the first line, output the number of positive integers k for which a first-to-k rule would have made Alice win more games than Bob. If this number isn’t zero, 
on the next line output all such values of in increasing order, separated by spaces.
*/

#include <iostream>
using namespace std;

class RockPaperScissorsMarathon {
private:
    string progression;
    int alice_games_won = 0;
    int bob_games_won = 0;
    int first_to_rules_for_alice[4]; // Because there can only be 9 rounds, four is the most a player can get before they automatically lose
    int array_index = 0; // For selecting index in first_to_rules_for_alice[4] array

public: 
    RockPaperScissorsMarathon(string rounds) {
        /* Creates the marathon. Input will be a string of As and Bs representing which rounds were won by Alice and Bob. */
        progression = rounds;
    }

    void calculateFirstToRules() {
        /* After construction, this method goes through the progression string and determines which first-to rules would result in a win by Alice. */
        first_to_rules_for_alice[0] = -1;
        for ( int i = 0; i < progression.length(); i++ ) {
            if ( progression[i] == 'A' ) {
                alice_games_won++;
            } else {
                bob_games_won++;
            }
            if ( alice_games_won > 1 && alice_games_won > bob_games_won && first_to_rules_for_alice[array_index - 1] != alice_games_won) {
                first_to_rules_for_alice[array_index] = alice_games_won;
                array_index++;
            }
        }
    }

    int getK(int index) {
        /* Returns k values, which represent what first-to rules would result in Alice winning. */
        if (first_to_rules_for_alice[0] != -1) {
            return first_to_rules_for_alice[index];
        } else {
            return 0;
        }
    }

    int getArrayIndex() {
        /* Returns how many first-to rules would result in Alice winning. Only works if calculateFirstToRules has ran first. */
        return array_index;
    } 
};

int main() {
    // input a string of As and Bs for how each round will play out between 1 and 2000
    string round_scores = "";

    while ( 1 > round_scores.length() || 2000 < round_scores.length() ) {
        cout << "Enter a number of As and Bs. Each A will represent a score by Alice. Each B will represent a score by Bob.\n";
        cin >> round_scores;
    }
    RockPaperScissorsMarathon game(round_scores);


    // calculate the scores to reach so that Alice will win less than 10
    game.calculateFirstToRules();


    // // output the smallest number for the first-to-k rule that would result in Alice winning
    cout << "Lowest possible first-to rule: ";
    cout << game.getK(0) << "\n";

    // output all first-to-k rules that would result in alice winning
    cout << "All possible forst-to rules less than 10: ";
    int k_rules_length = game.getArrayIndex();
    for (int i = 0; i < k_rules_length; i++) {
        cout << game.getK(i);
        if (i < k_rules_length - 1) {
            cout << " ";
        }        
    }
    cout << "\n";
}
