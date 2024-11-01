/*
You are using a waffle maker machine to make a delicious blueberry waffle. One side of your waffle is covered in blueberries, while the other side is plain. Initially, 
the cooking pan of the waffle maker lies horizontally, and the blueberries are on the top side of the waffle. Once started, the cooking pan will rotate at a constant 
speed for a fixed duration, then stop. The cooking time is set so that when the waffle maker stops, the cooking pan will not be in a vertical position.

If the cooking pan is not horizontal after this time, the waffle maker will return to a horizontal position via the smallest rotation possible. Therefore, the waffle 
maker will rotate less than

degrees, either forward or backward, until the cooking pan is horizontal again.

The pan rotates at a rate of 180 degrees every
seconds, and stops after seconds. You don’t want to take out your waffle with its blueberry side down. Therefore you’d like to figure out whether the blueberry side 
of the waffle is up or down after the cooking pan returns to a horizontal position.
*/

#include <iostream>
using namespace std;

int main() {
    // input for the number of seconds the pan takes to spin 180 degrees and the number of seconds the pan is rotating before it stops and rotates to the closest side. 

    int r = 0;
    int f = 0;

    while (r <= 1 && f <= 100000) {
        cout << "Please enter a number of seconds for the pan to rotate 180 degrees, and the number of seconds the pan will cook for. Separate the two numbers with a space. \n";
        cin >> r >> f;
    }
    
    cout << "Rotation time: " << r << "  Cook time: " << f << "\n";

    // math for calculating if the blueberry side of the waffle will be up or down
    string side;
    if (f % r == 0) {
        side = "up";
    } else {
        side = "down";
    }

    // output
    cout << "The waffle finishes cooking with the blueberry side " << side << ".\n";
    return 0;
}