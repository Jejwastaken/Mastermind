#include <iostream>
using namespace std;


/*
 *   Generates a random master mind puzzle given the desired length and the number of individual colors of the puzzle.
 *   Requires lengthPuzzle > 0 && 1 < nrColors < 9
 */
int generateRandomPuzzle(int lengthPuzzle, int nrColors);


/*
 *   A bool function that verifies if the number introduced by the user is valid and outputs a message accordingly.
 */
bool isValidNrSequence(int colorSequence, int nrColors, int lengthGuess);


/*
 *   An int function used to compare the guess to the puzzle digits and give the player feedback on how many digits were correct.
 */
int nrOfOcurrences(int puzzle, int guess);


/*
 *   A Void procedure which is used to call other functions and play the game.
 */
void play(int nrColors, int lengthGuess, int puzzle, int guess);

//PedroSilva