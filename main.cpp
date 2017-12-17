#include "stdafx.h"
#include <iostream>
using namespace std;
void input_mas(unsigned int  mas[4][4]) {

	for (unsigned int i=0; i < 4; i++) {
		for (unsigned int j=0; j < 4; j++) {
			cin >> mas[i][j];
		}
	}
}
void output_mas(unsigned int mas[4][4]) {
	cout << endl;
	for (unsigned int i = 0; i<4; ++i) {
		for (unsigned int j = 0; j<4; ++j) {
			if (mas[i][j] == 0) {
				cout << '*' << ' ';
			}
			else {
				cout << mas[i][j] << " ";
			}
		}
		cout << endl;
	}
}

void sdvig_vniz(unsigned int mas[4][4]) {
	{
		for (unsigned int j = 0; j < 4; j++) {
			for (unsigned int i = 3; i > 0; i--)
				if (mas[i][j] == 0) {
					for (int k = i - 1; k > -1; k--) {
						if (mas[k][j] != 0) {
							mas[i][j] = mas[k][j];
							mas[k][j] = 0;
						}
					}
				}
		}
		for (unsigned int j = 0; j < 4; j++) {
			for (unsigned int i = 3; i > 0; i--) {
				if (mas[i][j] == mas[i - 1][j]) {
					mas[i][j] += mas[i - 1][j];
					mas[i - 1][j] = 0;
				}
			}
		}
		for (unsigned int j = 0; j < 4; j++) {
			for (unsigned int i = 3; i > 0; i--) {
				if (mas[i][j] == 0) {
					for ( int k = i - 1; k > -1; k--) {
						if (mas[k][j] != 0) {
							mas[i][j] = mas[k][j];
							mas[k][j] = 0;
							break;
						}
					}
				}
			}
		}
	}
}
void sdvig_vverh(unsigned int mas[4][4]) {
	for (unsigned int j = 0; j < 4; j++) {
		for (unsigned int i = 0; i < 4; i++) {
			if (mas[i][j] == 0) {
				for ( unsigned int k = i + 1; k < 4; k++) {
					if (mas[k][j] != 0) {
						mas[i][j] = mas[k][j];
						mas[k][j] = 0;
						break;
					}
				}
			}
		}
	}
	for (unsigned int j = 0; j<4; j++) {
		for (unsigned int i = 0; i<4; i++) {
			if (mas[i][j] == mas[i + 1][j]) {
				mas[i][j] += mas[i + 1][j];  
				mas[i + 1][j] = 0;           
			}
		}
	}
	for (unsigned int j = 0; j<4; j++) {
		for (unsigned int i = 0; i < 4; i++) {
			if (mas[i][j] == 0) {
				for (unsigned int  k = i + 1; k < 4; k++) {
					if (mas[k][j] != 0) {
						mas[i][j] = mas[k][j];
						mas[k][j] = 0;
						break;
					}
				}
			}
		}
	}
}

void sdvig_vlevo(unsigned int mas[4][4]) {
	for (unsigned int i = 0; i < 4; i++) {
		for (unsigned int j = 0; j < 3; j++) {
			if (mas[i][j] == 0) {
				for (unsigned int k = j + 1; k <= 3; k++) {
					if (mas[i][k] != 0) {
						mas[i][j] = mas[i][k];
						mas[i][k] = 0;
						break;
					}
				}
			}
		}
	}

	for (unsigned int i = 0; i<4; i++) {
		for (unsigned int j = 0; j<3; j++)
			if (mas[i][j] == mas[i][j + 1]) {
				mas[i][j] += mas[i][j + 1];
				mas[i][j + 1] = 0;
			}
	}

	for (unsigned int i = 0; i<4; i++) {
		for (unsigned int j = 0; j<3; j++)
			if (mas[i][j] == 0) {
				for (unsigned int  k = j + 1; k <= 3; k++) {
					if (mas[i][k] != 0) {
						mas[i][j] = mas[i][k];
						mas[i][k] = 0;
						break;
					}
				}
			}
	}
}

void sdvig_vpravo(unsigned int mas[4][4]) {
	for (unsigned int i = 0; i<4; i++) {
		for (unsigned int j = 3; j>0; j--)
			if (mas[i][j] == 0) {
				for (unsigned int k = j - 1; k >= 0; k--) {
					if (mas[i][k] != 0) {
						mas[i][j] = mas[i][k];
						mas[i][k] = 0;
						break;
					}
				}
			}
	}

	for (unsigned int i = 0; i<4; i++) {
		for (unsigned int j = 3; j>0; j--)
			if (mas[i][j] == mas[i][j - 1]) {
				mas[i][j] += mas[i][j - 1];
				mas[i][j - 1] = 0;
			}
	}

	for (unsigned int i = 0; i<4; i++) {
		for (unsigned int j = 3; j>0; j--)
			if (mas[i][j] == 0) {
				for (int k = j - 1; k >= 0; k--) {
					if (mas[i][k] != 0) {
						mas[i][j] = mas[i][k];
						mas[i][k] = 0;
						break;
					}
				}
			}
	}
}

int main()
{
	unsigned int mas[4][4];
	int ex;
	input_mas(mas);
	output_mas(mas);
	char op;
	while (cin>>op ) {
		switch (op) {
			case 'j': {
				sdvig_vniz(mas);
				output_mas(mas);
				break;
			}
			case 'k': {
				sdvig_vverh(mas);
				output_mas(mas);
				break;
			}
			case 'h': {
				sdvig_vlevo(mas);
				output_mas(mas);
				break;
			}
			case 'l': {
				sdvig_vpravo(mas);
				output_mas(mas);
				break;
			}
			case 'q': {
				break;
			}
			default: {
				cout << " Nepravelney simvol" << endl; break;
			}

		}
	}
	if (op == 'q') {
		return -1;

	}
    return 0;
}
