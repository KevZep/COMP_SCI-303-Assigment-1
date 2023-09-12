#include "header.h"

int main() {
  ifstream inFile;
  string chooice1;
  int size1, size2, choice2, indexC, tempNum;
  // indexC will be the user choice number depending for each question
  vector<vector<int>> v1;
  // v1 = has the numbers stored in a vector

  // start of the program
  cout << "Welcome! In this program, you be able to print, change, remove, add "
          "a number to an array. All array have to be the same lenght such as "
          "10 numbers per array."
       << endl;
  cout << "Enter the file name you wanna use: ";
  // TO test the program, enter data.txt.
  cin >> chooice1;

  // To test the program, enter 10 and 3. This makes the program print each line
  // to look how it is on the txt file. Numbers will vary, please be careful. If
  // you got a file that has 10 lines with 20 numbers each, enter 20 and 10 in
  // that order to avoid issues
  cout << "Enter the how many numbers are in the array: ";
  cin >> size1;
  cout << "Enter the how many arrays are in the file: ";
  cin >> size2;
  int def1 = size1;
  int def2 = size2;

  inFile.open(chooice1);
  if (!inFile.is_open()) {
    cout << "Error opening file\n";
    return 1;
  }
  // gets the array setup and prints the results
  getMatrix(inFile, v1, size1, size2);
  cout << "Here's your arrays:" << endl;
  printMatrix(v1, size1, size2);
  while (true) {
    cout << "What would you like to do?" << endl;
    cout << "1) Find a number's index place\n2) Change a value with the index "
            "place\n3)Add a new value at the end of an array\n4)Remove a value "
            "from an array\n0) To Quit\n";
    cin >> choice2;

    if (choice2 == 1) {
      cout << "What index will you be using: " << endl;
      cin >> indexC;
      checkInd(v1, indexC, def2, def1);
    } else if (choice2 == 2) {
      cout << "What index will you be using: " << endl;
      cin >> indexC;
      changeInd(v1, indexC, def1, def2, tempNum);
      cout << "Here's the new array changes:\n";
      printMatrix(v1, def1, def2);
    } else if (choice2 == 3) {
      cout << "Which row you wanna add (starts from 0) and what value: \n";
      cin >> indexC;
      int newNum;
      cin >> newNum;
      addToArr(v1, indexC, newNum);
      cout << "Here's the new array changes:\n";
      printMatrix(v1, size1, size2);
    } else if (choice2 == 4) {
      cout << "Which number index you wanna remove: \n";
      cin >> indexC;
      subToArr(v1, indexC, def2);
      cout << "Here's the new array changes:\n";
      printMatrix(v1, size1, size2);
    } else if (choice2 == 0) {
      break;
    }
  }
  cout << "Have a good day\n";
}