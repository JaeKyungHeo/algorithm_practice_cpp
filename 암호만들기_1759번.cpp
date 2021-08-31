#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int L, C;
pair<bool,char> words[26];
char word[26];
vector<char>wordss;
vector<string>ans;

bool Is_aeiou(char k) { return(k == 'a' || k == 'e' || k == 'i' || k == 'o' || k == 'u'); }

void solve(string w, int now, int j, int m) {
	if (j > 1 && m > 0 && j + m == L) {
		ans.push_back(w);
		return;
	}
	else if (now == 26) return;
	else {
		printf("3\n");
		if (words[now].first = true) {
			if (Is_aeiou(words[now].second) == true) {
				w += words[now].second;
				solve(w, now + 1, j, m + 1);
			}
			else {
				w += words[now].second;
				solve(w, now + 1, j + 1, m + 1);
			}
			w = w.substr(0, w.size() - 1);
		}
		solve(w, now + 1, j, m);
	}
}

void solve2(string w, int now, int j, int m) {

	if (j > 1 && m > 0 && j + m == L) {
		ans.push_back(w);
		return;
	}
	else if (C == now) return;
	else {
		string temp = w;
		if (Is_aeiou(wordss[now]) == true) {
			w += wordss[now];
			solve2(w, now + 1, j, m + 1);
		}
		else {
			w += wordss[now];
			solve2(w, now + 1, j + 1, m);
		}
		solve2(temp, now + 1, j, m);
	}
}

int main() {
	char k;
	scanf("%d %d", &L, &C);

	//for (int i = 0; i < 26; i++) {
	//	words[i].second = 'a' + i;
	//}

	//printf("c\n");
	//printf("%c\n",words[4].second);

	//for (int i = 0; i < C; i++) {
	//	scanf("%c", &k);
	//	words[k - 'a'].first = true;
	//	word[i] = k;
	//}
	//printf("%d\n", word[0]);
	//printf("%c\n", word[1]);
	//printf("%c\n", word[2]);
	//printf("%c\n", word[3]);
	//printf("%c\n", word[4]);
	//printf("%c\n", word[5]);
	char q;
	for (int i = 0; i < C; i++) {
		cin >> q;
		wordss.push_back(q);
	}
	
	sort(wordss.begin(), wordss.end());

	word[0] = 'a';
	word[1] = 'c';
	word[2] = 'i';
	word[3] = 's';
	word[4] = 't';
	word[5] = 'w';

	solve2("", 0, 0, 0);

	for (int i = 0; i < ans.size(); i++) {
		//printf("------%s\n", ans[i]);
		cout << ans[i] << endl;
	}


	//for(auto elem : ans)
	//	printf("%s\n", elem);

	return 0;
}