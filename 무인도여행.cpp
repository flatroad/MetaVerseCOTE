#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> m;
int num;
int max_x;
int max_y;

void find(int x, int y) {
	if (x < 0 || y < 0 || x >= max_x || y >= max_y)
		return;
	if (m[x][y] == 'X') {
		return;
	}
	else {
		num = num + (m[x][y] - 48);
		m[x][y] = 'X';
		find(x + 1, y);
		find(x, y + 1);
		find(x - 1, y);
		find(x, y - 1);
	}
}

vector<int> solution(vector<string> maps) {
	vector<int> answer;
	int x, y = 0;
	m = maps;
	max_x = m.size();
	for (int i = 0; i < max_x; i++) {
		max_y = m[i].size();
		for (int j = 0; j < max_y; j++) {
			num = 0;
			if (m[i][j] != 'X') {
				find(i, j);
				answer.push_back(num);
			}
		}
	}
	if (answer.empty()) {
		answer.push_back(-1);
	}
	sort(answer.begin(), answer.end());
	return answer;
}