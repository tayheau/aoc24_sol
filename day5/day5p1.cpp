#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdio.h>
#include <string>

using namespace std;

vector<int> parseOrders(const string &input) {
  vector<int> numbers;
  istringstream iss(input);
  int num;
  char sep;

  while (iss >> num) {
    numbers.push_back(num);
    if (!(iss >> sep)) {
      break;
    }
  }
  return numbers;
}

bool isCorrect(vector<int> &ins, const map<pair<int, int>, bool> &rules) {
	int temp;
  for (int i = 0; i < ins.size(); ++i) {
    for (int j = i + 1; j < ins.size(); ++j) {
      auto it = rules.find(pair(ins[i], ins[j]));
      if (it != rules.end() && it->second == false) {
				return false;
      }
    }
  }
  return true;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cerr << "Usage: " << argv[0] << " <filename.txt>\n";
  }
  ifstream file(argv[1]);
  if (!file) {
    cerr << "Error reading " << argv[1] << "\n";
  }
  string line;
  vector<int> ins;
  int a, b;
  char sep;
	int tot = 0;
  map<pair<int, int>, bool> rules;

  while (getline(file, line)) {
    if (line.empty()) {
      break;
    }
    istringstream iss(line);
    iss >> a >> sep >> b;
    rules[pair(a, b)] = true;
    rules[pair(b, a)] = false;
    cout << "[" << a << "," << b << "]\n";
  }

  while (getline(file, line)) {
    ins = parseOrders(line);
		if(isCorrect(ins, rules)){
			// cout  << ins[ins.size()/2] << "\n";
			tot += ins[ins.size()/2];
		}
  }
	cout<<tot<<"\n";
}
