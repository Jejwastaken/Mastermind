# MasterMind

[comment]: # (## The Last Markdown Editor, Ever)
<!--- This is an HTML comment in Markdown -->
<!--- 
## Headers
hey-->


## Rules
![alt text](https://i.imgur.com/LtHXYc2.png)

In MasterMind the player must guess a code by placing pegs. The goal is to arrange different colored pegs in the correct order in a row. The resulting pattern must match the hidden code of the coder at the end.
## The Code
In this program we represent colors by digits and their order represents the combination of colors. The player wins if it guesses the right sequence before it runs out of tries.

The program will have 3 main variables:
* nrColors: variable limit for each digit in the player's guess;
* lengthGuess: variable maximum amount of digits in the player's guess;
* colorSequence: variable composed by the player's guess.

## Assumptions
* 0< lengthGuess <10;
* 1< nrColors <10;
* 0< colorSequence < nrColors.
