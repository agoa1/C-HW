#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

vector<int> toVector(string line);
bool binarySearch(const vector<int>& array, const int& findInArray);
void printVector(vector<int>& array);

int main(int argc, char **argv) {
	fstream dataSets;
	dataSets.open(argv[1]);
	string set;
	int find;
	
	getline(dataSets, set);
	
	vector<int> values = toVector(set);
	cout << "Raw Data: "; printVector(values);
	std::sort(values.begin(), values.end());
	
	cout << "what number should I look for?" << endl;
	cin >> find;
	cout << ((binarySearch(values, find))? "Yes that value is in the array": "not in the array")<< endl;
	dataSets.close();
}

vector<int> toVector(string line) {
	vector<int> output;

	do {
		output.push_back(stoi(line));
		line = (line.find_first_of(" ") > 0)
			? line.substr(line.find_first_of(" ") + 1)
			: line;
	} while (line.find_first_of(" ") != string::npos);

	return output;
}

bool binarySearch(const vector<int>& array, const int& findInArray) {
  vector<int> output;
  int highSearchIndex = array.size()-1, lowSearchIndex = 0;
  int midSearchIndex;

  while(highSearchIndex >= lowSearchIndex) {
    midSearchIndex = lowSearchIndex + (highSearchIndex - lowSearchIndex)/2;

    if(array[midSearchIndex] == findInArray) return true;

    if(array[midSearchIndex] > findInArray) {
      highSearchIndex = midSearchIndex - 1;
    } else if (array[midSearchIndex] < findInArray) {
      lowSearchIndex = midSearchIndex + 1;
    } else {
       cout << "error" << endl;
    }
  }
  return false;
}

void printVector(vector<int>& array) {
  for(auto value = array.begin(); value !=array.end(); ++value) {
    cout << *value << ' ';
  }
  cout << endl;
}