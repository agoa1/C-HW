#include<iostream>

using namespace std;

int main()
{
  int a;
  int b;
  int subtraction;
  int addition;
  int division;
  int multiplication;
  int rem;
  bool iszero;

cout <<"input a";
cin >> a ;
cout <<"input b";
cin >> b ;

  addition = a + b;
  multiplication = a * b;
  subtraction = a - b;

  if ( b != 0 ) {
    division = a / b ;
      rem = a % b ;
    iszero = false;
   }
   else {
     iszero = true;
   }
   cout << "The sum of the a and b is " << addition << endl;
   cout << "The difference of the a and b is " << subtraction << endl;
   cout << "The multiplication of the a and b is " << multiplication << endl;

   if (iszero) {
     cout << "The division of a and b cannot be divide by zero" << endl;
   }
   else {
     cout << "The division of the a and b is " << division << "and the remainder is "<< rem<< endl;
     //cout << "The Remainder of the a and b is " << rem << endl;
   }

  return 0;
}