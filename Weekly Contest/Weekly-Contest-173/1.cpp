#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
	string s = "ababb";
	int ans = 0;

	int head = 0;
	int tail = s.size() - 1;
	while (true) {
		head = 0;
	 	tail = s.size() - 1;
		while (s[head] == ' ')
			head++;
		while (s[tail] == ' ')
			tail--;

		if (head > tail)
			break;

		if (head == tail) {
			ans++;
			break;
		}

		while (true)
		{
			if (s[head] == s[tail])
			{
				s[head] = ' ';
				s[tail] = ' ';
				head++;
				tail--;
			}
			else if (head != tail-1 && s[head] == s[tail-1]) {
				tail--;
				s[head] = ' ';
				s[tail] = ' ';
				head++;
				tail--;
			}
			else if (head+1 != tail && s[head+1] == s[tail]) {
				head++;
				s[head] = ' ';
				s[tail] = ' ';
				head++;
				tail--;
			}
			else
				break;
			if (head > tail)
				break;
			if (head == tail) {
				s[head] = ' ';
				break;
			}
		}

		ans++;
	}
	cout << ans << endl;

	system("pause");
}