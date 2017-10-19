#include <iostream>
using namespace std;

int main()
{
	
	int matrix[4][4], i = 0, j = 0, k = 0;
	char sdvig;

	for (i = 0; i<4; ++i) {
		for (j = 0; j<4; ++j) {
			cin >> matrix[i][j];
		}
	}
	
	for (i = 0; i<4; ++i) {
		for (j = 0; j<4; ++j) {
			if (matrix[i][j] == 0) {
				cout << '*' << ' ';
			}
			else {
				cout << matrix[i][j] << " ";
			}
		}
		cout << endl;
	}
	while (cin >> sdvig) {
		if (sdvig == 'q') {                                   // q - выход
			break;
		}
    
		if (sdvig == 'j') {                                   //j - сдвинуть вниз
			for (j = 0; j<4; ++j) {
				for (i = 3; i >= 0; --i) {
					if (matrix[i][j] != 0) {
						for (k = i - 1; k >= 0; --k) {
							if (matrix[k][j] != 0) {
								if (matrix[k][j] == matrix[i][j]) {
									matrix[i][j] = matrix[i][j] + matrix[k][j];
									matrix[k][j] = 0;
								}
								break;
							}
						}
						while (matrix[i + 1][j] == 0) {
							if (i<3) {
								matrix[i + 1][j] = matrix[i][j];
								matrix[i][j] = 0;
								i = i + 1;
							}
							else { break; }
						}
						i = k;
					}
				}
			}
		}
    
		if (sdvig == 'k') {                                    // k - сдвинуть наверх
			for (j = 0; j<4; ++j) {
				for (i = 0; i<4; ++i) {
					if (matrix[i][j] != 0) {
						for (k = i + 1; k<4; ++k) {
							if (matrix[k][j] != 0) {
								if (matrix[k][j] == matrix[i][j]) {
									matrix[i][j] = matrix[i][j] + matrix[k][j];
									matrix[k][j] = 0;
								}
								break;
							}
						}
						while (matrix[i - 1][j] == 0) {
							if (i>0) {
								matrix[i - 1][j] = matrix[i][j];
								matrix[i][j] = 0;
								i = i - 1;
							}
							else { break; }
						}
						i = k;
					}
				}
			}
		}
    
		if (sdvig == 'h') {                                      //h - сдвинуть влево
			for (i = 0; i<4; ++i) {
				for (j = 0; j<4; ++j) {
					if (matrix[i][j] != 0) {
						for (k = j + 1; k<4; ++k) {
							if (matrix[i][k] != 0) {
								if (matrix[i][k] == matrix[i][j]) {
									matrix[i][j] = matrix[i][j] + matrix[i][k];
									matrix[i][k] = 0;
								}
								break;
							}
						}
						while (matrix[i][j - 1] == 0) {
							if (j>0) {
								matrix[i][j - 1] = matrix[i][j];
								matrix[i][j] = 0;
								j = j - 1;
							}
							else { break; }
						}
						j = k;
					}
				}
			}
		}
    
		if (sdvig == 'l') {                                 //l - сдвинуть вправо
			for (i = 0; i<4; ++i) {
				for (j = 3; j >= 0; --j) {
					if (matrix[i][j] != 0) {
						for (k = j - 1; k >= 0; --k) {
							if (matrix[i][k] != 0) {
								if (matrix[i][k] == matrix[i][j]) {
									matrix[i][j] = matrix[i][j] + matrix[i][k];
									matrix[i][k] = 0;
								}
								break;
							}
						}
						while (matrix[i][j + 1] == 0) {
							if (j<3) {
								matrix[i][j + 1] = matrix[i][j];
								matrix[i][j] = 0;
								j = j + 1;
							}
							else { break; }
						}
						j = k;
					}
				}
			}
		}
    
		for (i = 0; i<4; ++i) {
			for (j = 0; j<4; ++j) {
				if (matrix[i][j] == 0) {
					cout << '*' << ' ';
				}
				else {
					cout << matrix[i][j] << " ";
				}
			}
			cout << endl;
		}
	}
}


