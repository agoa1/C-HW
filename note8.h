#include <string>

class userdata
{
  std::string user_name;
  int user_id;
  std::string user_phonenumber;

public:
  userdata(std::string & input_name, int input_id, std::string input_phonenumber); // this is constructor
  ~userdata(){}; // this is destructor
  int get_id();
  std::string get_name();
  std::string get_phonenumber();

};

userdata::userdata(std::string & input_name, int input_id, std::string input_phonenumber)
{
  user_name = input_name;
  user_id = input_id;
  user_phonenumber = input_phonenumber;
}

int userdata::get_id()
{
  return user_id;
}

std::string userdata::get_name()
{
  return user_name;
}

std::string userdata::get_phonenumber()
{
  return user_phonenumber;
}