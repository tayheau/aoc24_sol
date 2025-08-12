#include <algorithm>
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/**
 * Checks if the input string consists only of 'M' or 'S' characters
 * and that the first and third characters are different,
 * as well as the second and fourth characters so that it forms a X-MAS.
 *
 * @param input A string of length 4 expected to contain 'M' or 'S' only.
 * @return true if the conditions are met; false otherwise.
 */
bool checkString(const string &input) {
  return std::all_of(input.begin(), input.end(),
                     [](char c) { return c == 'M' || c == 'S'; }) &&
         input[0] != input[2] && input[1] != input[3];
}

/**
 * Counts the number of cross patterns in the given matrix.
 * A cross pattern is detected around cells containing 'A' where
 * the four diagonal neighbors form a string that satisfies `checkString`.
 *
 * @param matrix A 2D vector of strings representing the matrix.
 * @return The count of cross patterns found.
 */
int crossPattern(const vector<string> &matrix) {
  int count = 0;
  vector<pair<int, int>> coordinates = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
  for (int i = 1; i < matrix.size() - 1; ++i) {
    for (int j = 1; j < matrix[0].size() - 1; ++j) {
      if (matrix[i][j] == 'A') {
        string cross;
        for (auto [a, b] : coordinates) {
          cross += matrix[i + a][j + b];
        }
        count += checkString(cross);
      }
    }
  }
  return count;
}

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

  cout << crossPattern(matrix) << "\n";
};
