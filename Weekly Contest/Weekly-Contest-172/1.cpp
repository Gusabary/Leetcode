#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;

	if (n / 1000 == 6) {
		cout << n + 3000;
		return 0;
	}
	if ((n / 100) % 10 == 6) {
		cout << n + 300;
		return 0;
	}
	if ((n / 10) % 10 == 6) {
		cout << n + 30;
		return 0;
	}
	if (n % 10 == 6) {
		cout << n + 3;
		return 0;
	}
	cout << n;

	system("pause");
}