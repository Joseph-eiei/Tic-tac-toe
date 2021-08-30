#include <bits/stdc++.h>
using namespace std;

#define dd double
#define ll long long
#define ar array

int main() {

	cout << "Enter size for the game(NxN) => ";
	int n, r, c;
	cin >> n;
	string arr[n][n];
	for(int i = 0; i<n; ++i)
		for(int a = 0; a<n; ++a)
			arr[i][a] = ".";

//{ down, right, up, left, upleft, downright, upright, downleft};
	int da[8] = { 1, 0, -1, 0, -1, 1, -1, 1 };
	int dj[8] = { 0, 1, 0, -1, -1, 1, 1, -1 };

	for(int i = 0; i<n*n; ++i){
		if(i%2 == 0){
			cout << "Player x turn. Enter empty location (r, c): ";
			cin >> r >> c;
			if(r > n || c > n){
				cout << "Invalid input. Try again\n";
				--i;
				continue;
			}
			if(arr[r-1][c-1] == "."){
				arr[r-1][c-1] = "x";
				for(int a = 0; a<n; ++a){
					for(int j = 0; j<n; ++j)
						cout << arr[a][j];
					cout << '\n';
				}
				for(int way = 0; way<8; ++way){
					int cnt = 0, pos = r-1, pos2 = c-1;

					for(int rnd = 0; rnd<n; ++rnd){
						int next_pos = (pos+da[way]) % n, next_pos2 = (pos2+dj[way]) % n;
						if (next_pos < 0)
							next_pos += n;
						if (next_pos2 < 0)
							next_pos2 += n;

						if(arr[pos][pos2] == arr[next_pos][next_pos2]){
							++cnt;
							pos = next_pos, pos2 = next_pos2;
						}else
							break;
					}
					if(cnt == n){
						cout << "Player x won" << endl;
						return 0;
					}
				}
			}else{
				cout << "Invalid input. Try again\n";
				--i;
				continue;
			}
		}else{
			cout << "Player o turn. Enter empty location (r, c): ";
			cin >> r >> c;
			if(r > n || c > n){
				cout << "Invalid input. Try again\n";
				--i;
				continue;
			}
			if(arr[r-1][c-1] == "."){
				arr[r-1][c-1] = "o";
				for(int a = 0; a<n; ++a){
					for(int j = 0; j<n; ++j)
						cout << arr[a][j];
					cout << '\n';
				}
				for(int way = 0; way<8; ++way){
					int cnt = 0, pos = r-1, pos2 = c-1;

					for(int rnd = 0; rnd<n; ++rnd){
						int next_pos = (pos+da[way]) % n, next_pos2 = (pos2+dj[way]) % n;
						if (next_pos < 0)
							next_pos += n;
						if (next_pos2 < 0)
							next_pos2 += n;

						if(arr[pos][pos2] == arr[next_pos][next_pos2]){
							++cnt;
							pos = next_pos, pos2 = next_pos2;
						}else
							break;
					}
					if(cnt == n){
						cout << "Player o won" << endl;
						return 0;
					}
				}
			}else{
				cout << "Invalid input. Try again\n";
				--i;
				continue;
			}
		}
	}
}
