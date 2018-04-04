#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string Sum( string &value1, string &value2) {
  string sum = "";

  string numbers = (value1.length() >= value2.length())? value1 : value2;
  int all = numbers.length();

  int add = (value1.length() >= value2.length())? value2.length() : value1.length();


  int a = 0;
  int b;
  int c;
  int d;

  reverse(value1.begin(), value1.end());
  reverse(value2.begin(), value2.end());

  for(b = 0; b < add; b++) {
    c = (value1[b] - '0') + ( value2[b] - '0') + a;
    d = (c) % 10;
    sum.append(std::to_string(d));
    a = (c - d)/10;
  }

  if(value1.length() > value2.length()||value1.length() <= value2.length()) {

    for(b; b < all; b++) {
      c = (numbers[b] - '0') + a;
      d = (c) % 10;
      sum.append(std::to_string(d));
      a = (c - d)/10;
    }

  }

  if(a != 0) {sum.append(to_string(a));}

  reverse(sum.begin(), sum.end());

  return sum;

}

int main() {
  string value1, value2;

  
  cout << "Insert first number:" << endl;
 
  cin >> value1;
  
  cout << "Insert second number:" << endl;
  
  cin >> value2;

  cout <<" The sum of the numbers is: " << Sum(value1, value2) << endl;


  return 0;
}
