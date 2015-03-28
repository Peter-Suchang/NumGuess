#include <iostream> 
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    char judge; //Used to determine whether to start the game.
	  int chance = 7; //The number of chances remaining.
	  int number_1, number_2, number_3; //Three automatically generated different numbers.
	  int guess_1, guess_2, guess_3; //Three numbers guessed by the user.
	  int A, B; //A: the number of right numbers in right place; B: the number of right numbers in wrong place.
	  int total = 0, win = 0, lose = 0; //Times of playing, winning, and losing respectively.
	
	  cout << "需要玩游戏吗（Y/N）？";
	  cin >> judge;
	  while (judge == 'Y'){
		    srand(time(NULL));
		    number_1 = rand() % 10;
		    do number_2 = rand() % 10;
		    while (number_2 == number_1);
		    do number_3 = rand() % 10;
		    while (number_3 == number_1 || number_3 == number_2); //Generate three different random positive integers between 0 and 9.
		
	    	for (chance = 7; chance >= 1; chance--){
		      	cout << "请输入你猜测的数字：";
		      	cin >> guess_1 >> guess_2 >> guess_3;
		      	A = (number_1 == guess_1) + (number_2 == guess_2) + (number_3 == guess_3); //The number of right numbers in right place.
		      	B = (number_1 == guess_2) + (number_1 == guess_3) + (number_2 == guess_1) + (number_2 == guess_3)
			        	+ (number_3 == guess_1) + (number_3 == guess_2); //The number of right numbers in wrong place.
		      	cout << A << 'A' << B << 'B' << endl;
			
		      	if (A == 3){
			        	cout << "恭喜，你猜对了" << endl;
			        	total++;
			        	win++;
			        	break; //Three right numbers in right place mean winning.
			      }
		   
			      if (chance == 1 and A != 3){
		            cout << "很遗憾，你没有在规定次数内猜对，答案是" << number_1 << number_2 << number_3 << endl; 
			        	total++;
			        	lose++; //The player loses the game if chances run out.
		  	    }
		    }
		    cout << "需要玩游戏吗（Y/N）？";
		    cin >> judge; //Judge whether to start the game again.
	 }
	cout << "你一共玩了" << total << "局，赢了" << win << "局，输了" << lose << "局"; //Statistical data.
	return 0;
}
