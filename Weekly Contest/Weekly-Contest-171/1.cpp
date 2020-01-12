#include <iostream>
#include <math.h>

int hasZero(int n) {
	int i = 1;
	while (n > 0)
	{
		if (n % 10 == 0)
			return i;
		n = n / 10;
		i++;
	}
	return 0;
}

int main(int argc, char *argv[]) {
	int n;
	std::cin >> n;

	int m = 1;
	while (hasZero(m) > 0 || hasZero(n-m) > 0) {
		m++;
	}

	std::cout << m << ' ' << n - m << std::endl;
	system("pause");
}