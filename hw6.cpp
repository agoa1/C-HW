#include "note8.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class user : public userdata {
	std::string zip_code;
	std::string blood_type;
	std::string address;

public:
	user(
		std::string &input_name,
		std::string input_id,
		std::string input_phonenumber,
		std::string input_zip_code,
		std::string input_blood_type,
		std::string input_address)
	  : userdata(input_name, std::stoi(input_id), input_phonenumber) {

  	zip_code = input_zip_code;
    blood_type = input_blood_type;
    address = input_address;

	 }
	
	std::string get_zip_code() {
	  return zip_code;
	}
	 
	std::string get_blood_type() {
	  return blood_type;
	}
	
	std::string get_address() {
	  return address;
	}
	
	std::string getString() {
	  return get_name() +"\n"+ std::to_string(get_id()) +"\n"+ get_phonenumber() +"\n"+ get_zip_code() +"\n"+ get_blood_type() +"\n"+ get_address();
	}
};

void initEntryList(std::vector<user>& list) {
  std::string name;
  std::string age;
  std::string number;
  std::string zipCode;
  std::string bloodType;
  std::string address;
  
  std::string file;
  std::fstream fileReader;
  
  for(int i = 0; i < 5; i++) {
    std::cout << "Please enter a file name";
    std::cin >> file;
    fileReader.open(file);
    
    std::getline(fileReader, name);
    std::getline(fileReader, age);
    std::getline(fileReader, number);
    std::getline(fileReader, zipCode);
    std::getline(fileReader, bloodType);
    std::getline(fileReader, address);
    
    fileReader.close();
    
    list.push_back(user(name, age, number, zipCode, bloodType, address));
    
    std::cout << list[i].get_name() << " added to the list" << std::endl;
  }
}

void listToFiles(std::vector<user>& list) {
  std::ofstream fileWriter;
  for(int i = 0; i < 3; i++) {
    fileWriter.open("new_"+list[i].get_name()+".txt");
    fileWriter <<list[i].getString();
    fileWriter.close();
  }
}

int main() {
	std::vector<user> list;
	initEntryList(list);
	listToFiles(list);
}