

using namespace std;
#include <iostream>
#include <ctime>
#include <string>
# define ROWS 6
# define COLS 6
 
//Question 1- MinesWeeper

void getCharMat(char mat[ROWS][COLS]) {

	int	num = 0;
	srand((int)time(0));
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			num = rand() % 2;

			if (num == 0) {
				mat[i][j] = '*';
			}
			else
			{
				mat[i][j] = '.';
			}
		}
	}

}

void printCharMat(char mat[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			cout << mat[i][j] << " ";
		}

		cout << endl;
	}

}

bool isIn(char mat[ROWS][COLS], int i, int j) {

	bool flag = false;
	for (int k = 0; k < ROWS; k++)
	{
		for (int m = 0; m < COLS; m++)
		{
			if (i >= 0 && i < ROWS && j >= 0 && j < COLS) {
				flag = true;
			}
			else {
				flag = false;
			}
		}
	}
	return flag;
}


int num_of_neighbors(char mat[][COLS], int i, int j) {
	int bombs = 0;
	if (isIn(mat, i, j) == true) {

		if ((0 <= i) && (i < ROWS) && (0 <= j) && (j < COLS)) {

			if (i == 0 && j == 0) {
				if (mat[i + 1][j] == '*') {
					bombs++;
				}
				if (mat[i][j + 1] == '*') {
					bombs++;
				}
				if (mat[i + 1][j + 1] == '*') {
					bombs++;
				}
			}
			else if ((i > 0) && (i < ROWS - 1) && (j == 0)) {
				if (mat[i - 1][j] == '*') {
					bombs++;
				}
				if (mat[i - 1][j + 1] == '*') {
					bombs++;
				}
				if (mat[i][j + 1] == '*') {
					bombs++;
				}
				if (mat[i + 1][j + 1] == '*') {
					bombs++;
				}
				if (mat[i + 1][j] == '*') {
					bombs++;
				}
			}
			else if ((i > 0) && (i < ROWS - 1) && (j == COLS - 1)) {
				if (mat[i - 1][j] == '*') {
					bombs++;
				}
				if (mat[i - 1][j - 1] == '*') {
					bombs++;
				}
				if (mat[i][j - 1] == '*') {
					bombs++;
				}
				if (mat[i + 1][j - 1] == '*') {
					bombs++;
				}
				if (mat[i + 1][j] == '*') {
					bombs++;
				}
			}
			else if ((i == 0) && (j == COLS - 1)) {
				if (mat[i][j - 1] == '*') {
					bombs++;
				}
				if (mat[i + 1][j - 1] == '*') {
					bombs++;
				}
				if (mat[i + 1][j] == '*') {
					bombs++;
				}
			}
			else if ((i == ROWS - 1) && (j == 0)) {
				if (mat[i - 1][j] == '*') {
					bombs++;
				}
				if (mat[i - 1][j + 1] == '*') {
					bombs++;
				}
				if (mat[i][j + 1] == '*') {
					bombs++;
				}
			}
			else if ((i == ROWS - 1) && (j == COLS - 1)) {
				if (mat[i - 1][j] == '*') {
					bombs++;
				}
				if (mat[i][j - 1] == '*') {
					bombs++;
				}
				if (mat[i - 1][j - 1] == '*') {
					bombs++;
				}
			}
			else {
				if (mat[i - 1][j - 1] == '*') {
					bombs++;
				}
				if (mat[i - 1][j] == '*') {
					bombs++;
				}
				if (mat[i - 1][j + 1] == '*') {
					bombs++;
				}
				if (mat[i][j - 1] == '*') {
					bombs++;
				}
				if (mat[i][j + 1] == '*') {
					bombs++;
				}
				if (mat[i + 1][j - 1] == '*') {
					bombs++;
				}
				if (mat[i + 1][j] == '*') {
					bombs++;
				}
				if (mat[i + 1][j + 1] == '*') {
					bombs++;
				}
			}
		}
	}
	return bombs;
}



void Game(char mat[][COLS]) {
	char mat1[ROWS][COLS];
	for (int k = 0; k < ROWS; k++) {
		for (int m = 0; m < COLS; m++) {
			mat1[k][m] = mat[k][m];
		}
	}
	for (int k = 0; k < ROWS; k++) {
		for (int m = 0; m < COLS; m++) {
			int num = num_of_neighbors(mat1, k, m);
			if (mat1[k][m] == '.') {
				if (num == 0) {
					mat[k][m] = '0';
				}
				if (num == 1) {
					mat[k][m] = '1';
				}
				if (num == 2) {
					mat[k][m] = '2';
				}
				if (num == 3) {
					mat[k][m] = '3';
				}
				if (num == 4) {
					mat[k][m] = '4';
				}
				if (num == 5) {
					mat[k][m] = '5';
				}
				if (num == 6) {
					mat[k][m] = '6';
				}
				if (num == 7) {
					mat[k][m] = '7';
				}
				if (num == 8) {
					mat[k][m] = '8';
				}
			}
		}
	}
}
//Question 2- A string containing the organs of string a. But non-occurrences in b.
string diff(string a, string b) {
	string words_diff = " ";
	for (int i = 0; i < a.length(); i++)
	{
		if (b.find(a[i]) == -1) {
			words_diff = words_diff + a[i] + " ";
		}

	}
	return words_diff + " ";
}

//Question 3- A function that accepts two strings a and b,
//and returns a string containing the common organs of string a and b string.

string common(string a, string b) {
	string sum = " ";
	int index = 0;
	for (int i = 0; i < a.length(); i++)
	{
		for (int j = 0; j < b.length(); j++) {
			if (a[i] == b[j]) {
				sum = sum + a[i] + "  ";
			}
		}
	}

	return sum + " ";
}


int main() {
	int Number=-1;
	while (Number!= 0) {
		cout << "Menu:" << endl;
		cout << "0.  Exit" << endl;
		cout << "1.  Game MinesWeeper" << endl;
		cout << "2.  Display different string" << endl;
		cout << "3.  Display common string" << endl;
		cin >> Number;


		if (Number == 1)
		{
			cout << "This your Game!!!" << endl;
			char mat[ROWS][COLS];
			getCharMat(mat);
			printCharMat(mat);
			Game(mat);
			cout << "" << endl;
			printCharMat(mat);
			cout << "" << endl;

			cout << endl;

		}
		if (Number == 2)
		{

			string c = "abcd";
			string d = "abvd";
			cout << diff(c, d) << "     " << endl;

		}
		if (Number == 3)
		{
			string a = "abcfgvk";
			string b = "cbadvm";
			cout << common(a, b) << "     " << endl;


		}
	}


}
