#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Animal {
	int height;
	int weight;

	string name;

	int yearOfBirth;
};

/* PROGRAM LOGIC */
void getDataByPropeties(vector<Animal> creature)
{
	int specifyYear, specifyHeight;

	cout << "Enter animal height(cm) and year separated with space: ";
	cin >> specifyHeight >> specifyYear;

	cout << "All data about animal that are taller than " << specifyHeight << " and were bord later " << specifyYear << endl;
	for (int i = 0; i < creature.size(); i++) {
		if ((creature[i].height > specifyHeight) && (creature[i].yearOfBirth > specifyHeight)) {
			printStruct(creature, i);
		}
	}
}

void getDataByName(vector<Animal> creature)
{
	string specifyName;

	cout << "Enter animal name: ";
	getline(cin, specifyName);

	for (int j = 0; j < specifyName.length(); j++)
		specifyName[j] = tolower(specifyName[j]);

	for (int i = 0; i < creature.size(); i++) {
		string animalName = creature[i].name;
		for (int j = 0; j < animalName.length(); j++)
			specifyName[j] = tolower(animalName[j]);

		if (animalName == specifyName)
			printStruct(creature, i);
	}
}

/* INTERFACE */
void route(int route, vector<Animal> creature)
{
	switch (route) {
		case 1:	
		{
			getDataByPropeties(creature);
			break;
		}
		case 2: 
		{
			getDataByName(creature);
			break;
		}
		case 3:
		{
			for (int i = 0; i < creature.size(); i++) {
				printStruct(creature, i);
			}
			break;
		}
		default: 
			cout << "You gave the wrong number";
	}
}

void printMenu(vector<Animal> animal)
{
	int choise = 0;
	cout << "MAIN MENU\n";

	cout << "1.Output all data about animal that are taller than the specified height and were born later than a specified year" << endl;
	cout << "2.Output all animals with specify name" << endl;
	cout << "3.Output data about all animals" << endl;

	cout << "Your choise: ";
	cin >> choise;
	
	return route(choise, animal);
}

void printStruct(vector<Animal> animal, int index)
{
	cout << "Data about " << animal[index].name << endl;

	cout << "Height: " << animal[index].height << endl;
	cout << "Weight: " << animal[index].weight << endl;
	cout << "Year of birth: " << animal[index].yearOfBirth << endl;
	cout << endl;
};

int main()
{
	vector<Animal> creature;
	Animal temp;

	cout << "All the meaningns you write about the animal" << endl;
	for (int i = 0; i < 2; i++) {
		cout << "Write about " << i + 1 << " animal\n";

		cout << "Enter height: ";
		cin >> temp.height;
		creature.push_back(temp);

		cout << "Enter weight: ";
		cin >> temp.weight;
		creature.back().weight = temp.weight;

		cout << "Enter name: ";
		cin >> temp.name;
		creature.back().name = temp.name;

		cout << "Enter year of birth: ";
		cin >> temp.yearOfBirth;
		creature.back().yearOfBirth = temp.yearOfBirth;

		cout << endl;
	}

	printMenu(creature);
}

