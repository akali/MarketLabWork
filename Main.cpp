#include <bits/stdc++.h>
#include "implementation.cpp"

using namespace std;

int main() {
	loadData();
	printMessage(helloMessage);
	int type; cin >> type;
	if (!type) {
		backend(type);
	} else {
		if (type == 1) {
			frontend(type);
		} else {
			WI();
			return 0;
		}
	}
	return 0;
}
