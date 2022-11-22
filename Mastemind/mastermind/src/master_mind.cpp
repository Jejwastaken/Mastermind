#include "master_mind.h"

bool isValidNrSequence(int colorSequence, int nrColors, int lenghtGuess)
{
    int count = 0;
    bool valid = true;
    while (colorSequence > 0 && valid)
    {
        if (colorSequence % 10 > nrColors)
        {
            valid = false;
        }
        count++;
        colorSequence /= 10;
    }
    return valid && count == lenghtGuess;
}

int nrOfOcurrences(int puzzle, int guess)
{
    int matches = 0;
    while (guess > 0)
    {
        if (puzzle % 10 == guess % 10)
        {
            matches++;
        }
        puzzle /= 10;
        guess /= 10;
    }
    return matches;
}

int randomColorSequence(int lengthPuzzle, int nrColors)
{
    if (lengthPuzzle == 1)
        return rand() % nrColors + 1;
    return (rand() % nrColors + 1) + 10 * randomColorSequence(lengthPuzzle - 1, nrColors);
}

int generateRandomPuzzle(int lengthPuzzle, int nrColors)
{
    srand(time(0));
    return randomColorSequence(lengthPuzzle, nrColors);
}

void play()
{
    int length, colors;

    do
    {
        cout << "↓ Choose the length of the puzzle ↓" << endl;
        cin >> length;
        cout << endl;
        cout << "↓ Choose the number of colors ↓" << endl;
        cin >> colors;

        if (length >= 3 && length <= 6 && colors >= 2 && colors <= 9)
            break;

        cout << "you did NOT FOLLOW THE ROOOLS\n"
             << endl;

    } while (true);

    int tries = (length + colors) * (6 / 5);
    int puzzle = generateRandomPuzzle(length, colors), guess;

    while (puzzle != guess && tries > 0)
    {
        cout << "Number of tries: " << tries << endl;

        cout << "Give me your best guess ;) " << endl;
        cin >> guess;
        while (cin.fail())
        {
            cout << "This is not a number DUMMY!" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> guess;
        }

        if (!isValidNrSequence(guess, colors, length))
        {
            cout << "The sequence is not valid!!! \n"
                 << endl;
        }

        else if (puzzle == guess)
        {
            cout << "CONGRADULIONS!!! \n"
                 << endl;
        }
        else
        {
            cout << "Your sequence has " << nrOfOcurrences(puzzle, guess) << " matches. \n"
                 << endl;
        }

        tries--;
    }

    if (tries == 0)
    {
        cout << "You ran out of tries F0000000L!\n puzzle: "
             << puzzle
             << endl;
    }
}

int main()
{

    cout << "!!!MASTER MIND!!! \n \n To start playing choose the lenght of the puzzle and the number of colours you want.\n "
         << "The size of the puzzle has to be between 3 e 6. \n The number of colours has to be between 2 e 9. \n"
         << endl;

    play();

    return 0;
}