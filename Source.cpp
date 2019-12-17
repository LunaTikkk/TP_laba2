#include <iostream>
#include <fstream>
#include <string>

const int N = 100;
using namespace std;

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "ru");
	ifstream F;
	F.open("text.txt", ios::in);

	if (!F.is_open()) {
		F.close();
		return 1;
	}

	bool flag = false;
	char c;

	do {
		c = F.get();

		if (c == EOF)
			break;

		if (c == '\n')
			cout << c;

		if (c == '\"' && flag == false)
			flag = true;
		else if (c == '\"' && flag == true) {
			flag = false;
			cout << c << " ";
		}

		if (flag == true)
			cout << c;

	} while (c != EOF);

	cout << endl;
	F.close();
	system("pause");
	return 0;
}
