#include <iostream>
#include <ctime>
using namespace std;
int main(){
	int cash = 1000;
	int betCash,betNumber;
	bool userinput = true;
	cout << "Welcome to my Roulette game! You start with $1000 cash." << endl;
	while(true){
	while(userinput){
		cout << "Type in amount to bet: ";
		cin >> betCash;
		if(betCash > cash){cout << "Bet is higher than user's cash. Try again..."<<endl;}
		else if(betCash < 1){cout << "Invalid number. Try again..."<<endl;}
		else{userinput=false;}
	}
	cash -= betCash;
	userinput = true;
	while(userinput){
		cout << "0-36 Number Bets || 37 Red || 38 Black || 39 Even || 40 Odd || 41 1 to 18 || " << endl;
		cout << "42 19 to 36 || 43 Lower Row || 44 Middle Row || 45 Upper Row || 46 Lower Column || 47 Middle Column || 48 Upper Column" << endl;
		cout << "Type in your choice of bet: ";
		cin>>betNumber;
		if(betNumber > 48 || betNumber < 0){cout<<"Invalid input. Try again..."<<endl;}
		else{userinput = false;};
	}
	int multiplier = 1;
	if(betNumber < 36){multiplier = 35;}
	else if(betNumber > 36 && betNumber < 41){multiplier = 2;}
	else if(betNumber > 40){multiplier = 3;}
	else{cout << "Error encountered with choice of bet!"<<endl;}	
	srand(time(0));
	int random = rand() % 36;
	cout << "The Number is " << random << endl;
	int red[] = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
	bool isZero,isEven,win,isRed,isBlack,isUpper,isLower,isMiddle,low,mid,high;
	int wincash = 0;
	if(random == 0){isZero = true;}
	for(int i = 0;i<18;i++){
		if(random == red[i]){isRed = true;}
	}
	if(!isRed){isBlack=true;}
	if(random % 3 == 0){isUpper = true;}
	else if((random + 1) % 3 == 0){isMiddle = true;}
	else{isLower=true;}
	if(random % 2 == 0){isEven = true;}
	if(random < 13){low = true;}
	else if(random < 25){mid = true;}
	else{high = true;}
	if(multiplier == 35 && random == betNumber){win = true;}
	else if(betNumber == 37 && isRed){win = true;}
	else if(betNumber == 38 && isBlack){win = true;}
	else if(betNumber == 39 && isEven){win = true;}
	else if(betNumber == 40 && !isEven){win = true;}
	else if(betNumber == 41 && random < 19){win = true;}
	else if(betNumber == 42 && random > 18){win = true;}
	else if(betNumber == 43 && low){win = true;}
	else if(betNumber == 44 && mid){win = true;}
	else if(betNumber == 45 && high){win = true;}
	else if(betNumber == 46 && isLower){win = true;}
	else if(betNumber == 47 && isMiddle){win = true;}
	else if(betNumber == 48 && isUpper){win = true;}
	else { win = false;}
	if(win){
		wincash = betCash * multiplier;
		cash += wincash;
		cout << "Congratulations! You have won " << wincash << " dollars. You now have " << cash << " dollars."<<endl;
	} 
	else{
		cout << "Unfortunately, you lost your " << betCash << " dollars. You now have " << cash << " dollars."<<endl;
	}
	if(cash == 0){cout<<"You ran out of money..."<<endl;return 0;}
	userinput = true;
	}
	return 0;
}
