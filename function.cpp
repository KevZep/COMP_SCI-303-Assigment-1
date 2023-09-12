#include "header.h"

// makes the array initially
void getMatrix(ifstream &inFile, vector<vector<int>> &v1, int size1,
               int size2) {
  vector<int> row;
  int temp;

  for (int r = 0; r < size2; r++) {
    row.clear(); // LOOK HERE KEVEN >:/
    for (int c = 0; c < size1; c++) {
      inFile >> temp; // read 3 values
      row.push_back(temp);
    }
    v1.push_back(row); // push onto v1
  }
}

// Prints the vector to look like an array
void printMatrix(vector<vector<int>> &v1, int size1, int size2) {
  for (int r = 0; r < size2; r++) {
    for (auto c = v1[r].begin(); c != v1[r].end(); c++) {
      cout << setw(5) << right << *c; // read 3 values
    }
    cout << endl;
  }
  cout << endl;
}

// Check the number index placement

// old code
/*void checkInd(vector<vector<int>> &v1, int indexC, int size1, int size2) {
  transForm(v1, indexC, size1, size2);
  //cout << size2 << " " << size1 << " "<< v1[1][10]<<endl;
  if (size1 >=0 && size2 >= 0){
    cout << "The number in the index " << indexC << " is " << v1[size2][size1]
<< endl; } else { cout << "Error. Index out of range\n";
  }
}*/

// Def. CODE
void checkInd(vector<vector<int>> &v1, int indexC, int size1, int size2) {
  int transformedSize1 = -1, transformedSize2 = -1;

  // Check if the index is valid and transform it
  if (indexC >= 0 && indexC < size1 * size2) {
    transForm(v1, indexC, transformedSize1, transformedSize2);

    // Check if the transformed indices are valid
    if (transformedSize1 >= 0 && transformedSize2 >= 0) {
      cout << "The number at index " << indexC << " is "
           << v1[transformedSize2][transformedSize1] << endl;
    } else {
      cout << "Error. Transformation error\n";
    }
  } else {
    cout << "Error. Index out of range\n";
  }
}

// Replace the user number to a new one
void changeInd(vector<vector<int>> &v1, int indexC, int size1, int size2,
               int &tempNum) {
  int transformedSize1 = -1, transformedSize2 = -1;

  // Check if the index is valid and transform it
  if (indexC >= 0 && indexC < size1 * size2) {
    transForm(v1, indexC, transformedSize1, transformedSize2);

    // Check if the transformed indices are valid
    if (transformedSize1 >= 0 && transformedSize2 >= 0) {
      int newVal;
      cout << "What would the new value be: \n";
      cin >> newVal;
      tempNum = v1[transformedSize2][transformedSize1];
      v1[transformedSize2][transformedSize1] = newVal;
      cout << "The number " << tempNum << " is now " << newVal << endl;
    } else {
      cout << "Error. Transformation error\n";
    }
  } else {
    cout << "Error. Index out of range\n";
  }
  // transForm(v1, indexC, size1, size2);
}

// Add a number at the end of an array that the user chooce
void addToArr(vector<vector<int>> &v1, int indexC, int newNum) {
  v1[indexC].push_back(newNum);
}

// Removes/Replace the number the user choose
void subToArr(vector<vector<int>> &v1, int indexC, int size2) {
  int tempo = -1; // Initialize tempo to -1

  // Check if the index is valid and transform it
  if (indexC >= 0 && indexC < size2 * v1[0].size()) {
    transForm(v1, indexC, tempo, size2);

    // Check if the transformed index is valid
    if (tempo >= 0 && tempo < v1[size2].size()) {
      // Subtract 1 from the element at the transformed index
      v1[size2][tempo] = 0;
    } else {
      cout << "Error. Invalid transformation index\n";
    }
  } else {
    cout << "Error. Index out of range\n";
  }
}

// converts a index number to a vector of a vector numbers to find the correct
// number
/*void transForm(vector<vector<int>> &v1, int indexC, int &size1, int &size2) {
  int i = 0, j = -1, k = -1;
  for (int r = 0; r < v1.size(); r++) {
    for (int c = 0; c <= v1[r].size(); c++) {
      if (i == indexC) {
        j = r;
        k = c;
        //cout << j << " " << k << endl;
        //cout <<v1[j][k];
        break;
      } else if (i > indexC) {
        j = -1;
        k = -1;
        break;
      }
      i++;
    }
    if (i == indexC) {
      break;
    }
  }
  if (j == -1 || k == -1) {
    cerr << "Element not found for index " << indexC << endl;
  }
  //cout << j << " " << k << endl;
  size2 = j;
  size1 = k;
}*/
void transForm(vector<vector<int>> &v1, int indexC, int &size1, int &size2) {
  int i = 0;
  size2 = -1;
  size1 = -1;

  for (int r = 0; r < v1.size(); r++) {
    for (int c = 0; c < v1[r].size(); c++) {
      if (i == indexC) {
        size2 = r;
        size1 = c;
        return; // Found the element, no need to continue searching
      }
      i++;
    }
  }
}
