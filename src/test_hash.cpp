#include "hash_map.h"
#include <string>

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

  getval1 = the_map.get(test1);
  getval2 = the_map.get(test2);
  getval3 = the_map.get(test5);
	std::cout << "Test 1: " << getval1 << std::endl;
	std::cout << "Test 2: " << getval2 << std::endl;
	std::cout << "Test 3: " << getval3 << std::endl;

	Map<int, char> new_map;
	
  int new1 = 10;
  char new2 = 'c';
  int new3 = 598;
  char new4 = 'd';
	new_map.put(new1, new2);
	new_map.put(new3, new4);

	char get1 = new_map.get(new1);
	char get2 = new_map.get(new3);
  char get3 = new_map.get(5);

	std::cout << "Get1: " << get1 << std::endl;
	std::cout << "Get2: " << get2 << std::endl;
	std::cout << "Get3: " << get3 << std::endl;

  Map<int, int> even_newer;

  int fir = 9;
  int sec = 5;

  even_newer.put(fir,sec);
  int check = even_newer.get(fir);

  std::cout << "check " << check << std::endl;
  std::cout << "check2 " << even_newer.get(65) << std::endl;

}
