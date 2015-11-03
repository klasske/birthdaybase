#include <iostream>
#include <vector>

using namespace std;

bool showAgeBase(int age, int base) {

	// we want an age with 2 digits	
	size_t maxSize = 2;
	vector <int> ageRange;

	// find the format for our age 
	while(age > 0) {
        if(age%base > 9) return false;
        ageRange.push_back(age%base);
		age = (int) age / base;
	}

    // if we found an age in the twenties, we're done
	if (ageRange.size() == maxSize && ageRange.back() == 2) {
	
		cout << "In base " << base << " you would be ";
	    for (unsigned i = ageRange.size(); i-- > 0; ) cout << ageRange[i];
		cout << " years old." << endl;
		return true;
	}

    // nothing found yet
	return false;

}

void findPerfectBase(int age) {

	// start from 10. look at each base and check if it contains only digits

	int base = 11;
	int foundBetterBase = false;

	while (!foundBetterBase && base < 100) {
		foundBetterBase = showAgeBase (age, base);
		base ++;
	}

	if (!foundBetterBase) cout << "You must be really old. We couldn't find a better birthday base for you." << endl;	

}


int main (int argc, char *argv[]) {
	
	/* Based on your age, we attempt to find a base in which you are still in your twenties. */	


	int age;

	if (argc <= 1) {
		cout << "How old are you?" << endl;
		cin >> age;
	} else {
		age = atoi(argv[1]);
	}

	if(age > 29){
		findPerfectBase(age);
	} else {
		cout << "Base 10 works fine for you. You are too young to consider other bases." << endl;
	}

	return 0;

}
