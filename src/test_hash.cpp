#include "hash_map.h"



int main(){

	Map<std::string, std::string> the_map;
  
  std::string test1 = "key";
  std::string test2 = "c";
  std::string test3 = "value";
  std::string test4 = "d";
  std::string test5 = "lto";
  std::string test6 = "fsdat";

  the_map.put(test1, test3);
  the_map.put(test2, test4);
  the_map.put(test5, test6);

	std::string getval1 = the_map.get(test1);
	std::string getval2 = the_map.get(test2);
	std::string getval3 = the_map.get(test5);

	std::cout << "Test 1: " << getval1 << std::endl;
	std::cout << "Test 2: " << getval2 << std::endl;
	std::cout << "Test 3: " << getval3 << std::endl;
  the_map.clear();

	std::cout << "Test 1: " << getval1 << std::endl;
	std::cout << "Test 2: " << getval2 << std::endl;
	std::cout << "Test 3: " << getval3 << std::endl;
}
