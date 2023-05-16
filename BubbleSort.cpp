#include <iostream>

using namespace std;

struct NameAndSalary {
	double salary; 
	string name;
};

void printOut(NameAndSalary* input, int size) {
	for (int i= 0; i < size; i++) {
		cout << (*(input + i)).name << ", " << (*(input + i)).salary<<endl;
	}
}

void sortDesc(NameAndSalary* input, int size) {
	bool sortAgain = true;

	while (sortAgain) {

		sortAgain = false;

		for (int i = 0; i < (size - 1); i++) {
			if ((*(input + i)).salary < (*(input + i + 1)).salary) {
				sortAgain = true;
				NameAndSalary temp = (*(input + i));
				(*(input + i)) = (*(input + i + 1));
				(*(input + i + 1)) = temp;
			}
		}
	}
}

void sortAsc(NameAndSalary* input, int size) {
	bool sortAgain = true;

	while (sortAgain) {

		sortAgain = false;

		for (int i = 0; i < (size - 1); i++) {
			if ((*(input + i)).salary > (*(input + i + 1)).salary) {
				sortAgain = true;
				NameAndSalary temp = (*(input + i));
				(*(input + i)) = (*(input + i + 1));
				(*(input + i + 1)) = temp;
			}
		}
	}
}

int main(int argc, const char* argv[]) {
	NameAndSalary NAS[4] = {
		{100, "Kevin"},
		{2500, "John"},
		{2000, "Stanly"},
		{4500, "Melvin"}
	};

	cout << "Before processing: " << endl;
	printOut(NAS, 4);

	sortDesc(NAS, 4); 
	cout << "After descending sort: " << endl;
	printOut(NAS, 4);

	sortAsc(NAS, 4);
	cout << "After ascending sort: " << endl;
	printOut(NAS, 4);

	return 0;
}