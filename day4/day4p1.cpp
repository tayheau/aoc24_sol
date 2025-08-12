#include <fstream>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

/**
 * Counts occurrences of the string "XMAS" in a 2D matrix of characters.
 * This function searches for the pattern "XMAS" in all eight possible directions
 * (horizontal, vertical, and diagonal) starting from each 'X' character in the matrix.
 *
 * @param matrix Reference to a 2D vector of strings representing the character grid. Each string corresponds to a row in the grid.
 * @return The total number of times the string "XMAS" is found in the matrix.
 */
int findXMAS(vector<string> &matrix) {
  int count = 0;
  string checkList = "XMAS";
  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix[0].size(); ++j) {
      if (matrix[i][j] == 'X') {
        for (int rowNav = -1; rowNav < 2; ++rowNav) {
          for (int colNav = -1; colNav < 2; ++colNav) {
            bool isValid = true;
            for (int c = 1; c < 4; ++c) {
              int row = i + rowNav * c;
              int col = j + colNav * c;
              if (0 <= row && row < matrix.size() && 0 <= col &&
                  col < matrix[0].size() && matrix[row][col] == checkList[c]) {
              } else {
                isValid = false;
                break;
              }
            }
            count += isValid;
          }
        }
      }
    }
  }
  return count;
};

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cerr << "Usage: " << argv[0] << " <filename.txt>\n";
    return 1;
  }
  ifstream file(argv[1]);
  if (!file) {
    cerr << "Error could not open the file " << argv[1] << "\n";
    return 1;
  }

  string line;
  vector<string> matrix;

  while (std::getline(file, line)) {
    matrix.push_back(line);
  }

  while (std::getline(file, line)) {
    matrix.push_back(line);
  }
  cout << findXMAS(matrix) << "\n";
};
