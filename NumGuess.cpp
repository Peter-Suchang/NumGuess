//File name: NumGuess.cpp

#include <iostream> 
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	char judge; //whether to start the game
	int chance = 7; //the number of chances remaining
	int number[3]; //three automatically generated different numbers
	int guess[3]; //three numbers guessed by the user
	int A, B; //A: the number of right numbers in right place; B: the number of right numbers in wrong place
	int total = 0, win = 0, lose = 0; //times of playing, winning, and losing respectively
	
	cout << "Start the game? (Y/N)" << endl;
	cin >> judge;
	while (judge == 'Y'){
		srand(time(NULL));
		number[0] = rand() % 10;
		do number[1] = rand() % 10;
		while (number[1] == number[0]);
		do number[2] = rand() % 10;
		while (number[2] == number[0] || number[2] == number[1]); //Generate three different random positive integers between 0 and 9.
		
		for (chance = 7; chance >= 1; chance--){
			cout << "Please enter the numbers you guess." << endl;
			cin >> guess[0] >> guess[1] >> guess[2];
			A = (number[0] == guess[0]) + (number[1] == guess[1]) + (number[2] == guess[2]); //The number of right numbers in right place.
			B = (number[0] == guess[1]) + (number[0] == guess[2]) + (number[1] == guess[0]) + (number[1] == guess[2])
				+ (number[2] == guess[0]) + (number[2] == guess[1]); //The number of right numbers in wrong place.
			cout << A << 'A' << B << 'B' << endl;
			
			if (A == 3){
				cout << "Bravo! You've got the right answer." << endl;
				total++;
				win++;
				break; //Three right numbers in right place mean winning.
			}
		    
			if (chance == 1 and A != 3){
		        cout << "What a pity! Your chances are used up. The right number is " << number[0] << number[1] << number[2] << endl; 
				total++;
				lose++; //The player loses the game if chances run out.
			}
		}
		cout << "Play again?（Y/N）" << endl;
		cin >> judge; //Judge whether to start the game again.
	}
	cout << "You've played " << total << " round(s), winning " << win << " time(s), and losing " << lose << " time(s)."; //Statistical data.
	return 0;
}
