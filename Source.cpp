#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
// start at userCut point and run and get last values. Insert them at the front
using namespace std;
void CutVector(vector<string>& userRestaurants, int userSlice) {
	vector<string> userFood;
	vector<string> tempVal;
	for (unsigned int i = userSlice; i < userRestaurants.size(); ++i) {     // Grab from beyond cut to end
		userFood.push_back(userRestaurants.at(i));
	}
	for (unsigned int i = 0; i < userSlice; ++i) {							// Grab from beginnning
		userFood.push_back(userRestaurants.at(i));
	}
	userRestaurants = userFood;		//Equal them together
	cout << endl;
	return;
}
void AddRest(vector<string>& userRestaurants) {
	string restName;
	bool isThere = false;
	cout << "What is the name of the restaurant you want to add?" << endl;
	cin.ignore();
	getline(cin, restName);

	for (unsigned int i = 0; i < userRestaurants.size(); ++i) {

		if (userRestaurants.at(i) == restName) {    //check if vector name matches
			isThere = true;
		}
		else {
			isThere = false;
		}


	}
	if (isThere == false) {

		userRestaurants.push_back(restName);   // add vector
		cout << restName << " has been added." << endl;
		cout << "Enter your selection: " << endl;
		//cin >> userOptions;

	}
	else {

		cout << "That restaurant is already in the list, you can not add it again." << endl;  //Same name detected
		cout << "Enter your selection: " << endl;
		//cin >> userOptions;

	}
	return;
}
void RemoveRest(vector<string>& userRestaurants) {
	string restName;
	bool isPresent = false;
	int index;
	cout << "What is the name of the restaurant you want to remove?" << endl;
	cin.ignore();
	getline(cin, restName);
	for (unsigned int i = 0; i < userRestaurants.size(); ++i) {

		if (userRestaurants[i] == restName) {
			isPresent = true;

			index = static_cast<int>(i);
			//cout << index;

		}


	}
	if (isPresent == true) {

		userRestaurants.erase(userRestaurants.begin() + index);
		cout << restName << " has been removed." << endl;
		cout << "Enter your selection: " << endl;
		//cin >> userOptions;
	}
	if (isPresent == false) {

		cout << "That restaurant is not in the list, you can not remove it." << endl;
		cout << "Enter your selection: " << endl;
		//cin >> userOptions;
	}
	return;
}
void Options() {
	cout << "Please select one of the following options: " << endl;
	cout << "quit - Quit the program" << endl;
	cout << "display - Display all restaurants" << endl;
	cout << "add - Add a restaurant" << endl;
	cout << "remove - Remove a restaurant" << endl;
	cout << "cut - \"Cut\" the list of restaurants" << endl;
	cout << "shuffle - \"Shuffle\" the list of restaurants" << endl;
	cout << "battle - Begin the tournament" << endl;
	cout << "options - Print the options menu" << endl;
	cout << "Enter your selection: " << endl;
	return;
}
void Display(vector<string>& userRestaurants) {
	cout << "Here are the current restaurants:" << endl;
	for (unsigned int i = 0; i < userRestaurants.size(); ++i) {

		cout << "\t" << "\"" << userRestaurants.at(i) << "\"" << endl;

	}
	cout << "Enter your selection: " << endl;
	return;
}
bool PowerOfTwo(int numberToCheck) {
	return (numberToCheck & (numberToCheck - 1)) == 0;

}
void Shuffle(vector<string>& userRestaurants) {
	int userHalf = userRestaurants.size() / 2;
	vector<string> shuffleVector;
	vector<string> shakeVector;
	vector<string> totalVector;
	for (unsigned int i = userHalf; i < userRestaurants.size(); ++i) {     //Grab the last half
		shuffleVector.push_back(userRestaurants.at(i));

	}
	for (unsigned int i = 0; i < userHalf; ++i) {						// Grab the first half
		shakeVector.push_back(userRestaurants.at(i));
	}

	for (unsigned int i = 0; i < shakeVector.size(); ++i) {				//Shuffle dem Bois
		totalVector.push_back(shuffleVector.at(i));
		totalVector.push_back(shakeVector.at(i));
	}
	userRestaurants = totalVector;

	return;
}
void BattleRoyale(vector<string>& userRestaurants) {
	int roundNum = 1;;
	int userChoice;
	int temp = 0;
	int userHalf = userRestaurants.size() / 2;
	vector<string> vec1;
	vector<string> vec2;

	//bool PowerOfTwo(vector<string> &userRestaurants);
	if (PowerOfTwo(userRestaurants.size()) == false) {
		cout << "The current tournament size (" << (userRestaurants.size()) << ") is not a power of two (2, 4, 8...)." << endl;
		cout << "A battle is not possible. Please add or remove restaurants." << endl;
	}
	else {




		for (unsigned int i = 0; i < userRestaurants.size(); ++i) {
			vec1.push_back(userRestaurants.at(i));
		}
		temp = vec1.size();
		while (temp > 2) {
			cout << "round: " << roundNum << endl;
			for (unsigned int i = 0; i < (vec1.size() / 2); ++i) {
				cout << "Type \"1\" if you prefer " << vec1.at(i * 2) << "  " << "or" << endl;
				cout << "Type \"2\" if you prefer " << vec1.at((i * 2) + 1) << endl;
				cin.ignore();
				cin >> userChoice;
				cout << "Choice: " << endl;
				while (cin.fail() || (userChoice != 1 && userChoice != 2)) {
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "invalid choice" << endl;
					cout << "Type \"1\" if you prefer " << vec1.at(i * 2) << " or" << endl;
					cout << "Type \"2\" if you prefer " << vec1.at((i * 2) + 1) << endl;
					cout << "Choice:" << endl;
					//	cin.ignore();

					cin >> userChoice;
				}
				if (userChoice == 1) {
					vec1.at(i) = vec1.at(i * 2);
				}
				if (userChoice == 2) {
					vec1.at(i) = vec1.at((i * 2) + 1);
				}


			}
			++roundNum;
			vec1.resize(vec1.size() / 2);



			if (vec1.size() == 1) {
				cout << "The winning restaurant is " << vec1.at(0) << "." << endl << endl;
				break;
			}
		}

	}
	return;
}
int main() {
	string userOptions;
	string option;
	//string userRestaurants = "FIX ME";
	string restName;
	int numRuns = 0;
	bool isThere = false;
	bool isPresent = false;
	int index = 0;
	int userCut = 0;
	vector <string> userRestaurants;
	//vector <string> userFood;
	cout << "Welcome to the restaurant battle!  Enter \"options\" to see options." << endl;
	cout << "Enter your selection:" << endl;
	cin >> userOptions; // Take user option
	while (numRuns < 10000) {
		//cout << "Enter your selection:" << endl;
		if (userOptions != "options" && userOptions != "quit" && userOptions != "display" && userOptions != "add" && userOptions != "remove" && userOptions != "shuffle" && userOptions != "battle" && userOptions != "cut") {
			cout << "Invalid Selection" << endl << endl;
			cout << "Please select one of the following options: " << endl;
			cout << "quit - Quit the program" << endl;
			cout << "display - Display all restaurants" << endl;
			cout << "add - Add a restaurant" << endl;
			cout << "remove - Remove a restaurant" << endl;
			cout << "cut - \"Cut\" the list of restaurants" << endl;
			cout << "shuffle - \"Shuffle\" the list of restaurants" << endl;
			cout << "battle - Begin the tournament" << endl;
			cout << "options - Print the options menu" << endl;
			cout << "Enter your selection: " << endl;
			cin >> userOptions;
			//cout << "Please select one of the following options: " << endl;

			//cin >> userOptions;

		}
		
		if (userOptions == "quit") {
			cout << "Goodbye!";
			return 0;					//quit the program
		}

		if (userOptions == "display") {

			Display(userRestaurants); //Call function
			cin >> userOptions;
		}
		if (userOptions == "add") {

			AddRest(userRestaurants); //Call Function
			cin >> userOptions;  //What's next

		}
		if (userOptions == "remove") {

			RemoveRest(userRestaurants);   //call function
			cin >> userOptions;    // next up
		}
		if (userOptions == "options") {

			Options();					//call function
			cin >> userOptions;			// I got next
		}
		if (userOptions == "cut") {
			cout << "How many restaurants should be taken from the top and put on the bottom? ";
			cin.ignore();
			cin >> userCut;

			int maxRestaurant = static_cast<int>(userRestaurants.size());
			while (cin.fail() || userCut > maxRestaurant || userCut < 0) {
				//if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				//}
				cout << "The cut number must be between 0 and " << maxRestaurant << endl;
				cout << "How many restaurants should be taken from the top and put on the bottom? ";
				cin >> userCut;
			}
			CutVector(userRestaurants, userCut);  //Call function
			cout << "Enter your selection: " << endl;
			cin >> userOptions;							//Next is Here
		}
		if (userOptions == "shuffle") {
			if (PowerOfTwo(userRestaurants.size()) == true) {
				Shuffle(userRestaurants);
			}
			else {
				cout << "The current tournament size (" << (userRestaurants.size()) << ") is not a power of two (2, 4, 8...)." << endl;
				cout << "A shuffle is not possible. Please add or remove restaurants." << endl;
			}
			cout << "Enter your selection: " << endl;
			cin >> userOptions;
		}
		if (userOptions == "battle") {
			BattleRoyale(userRestaurants);

			cout << "Enter your selection: " << endl;
			cin >> userOptions;
		}
		++numRuns;


	}
}