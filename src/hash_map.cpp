#include <iostream>
#include <string>
#include <vector>
#include <cstddef>



template <typename K, typename V>

class Map{

	public: 
		Map(){}

		~Map(){}

	struct map_pair{
		K keyObject;
		V valueObject;
	};
	
	typedef struct map_pair map_pair;
	typedef unsigned long long uint_64;

	//std::vector<map_pair> map_values;
	map_pair map_values[sizeof(int)];
	int valueListIdx = 0;

	void clear(){}


	V get(K key){
		std::cout << "Called get\n";

		std::size_t key_hash = std::hash<K>()(key);
		key_hash %= sizeof(int);

		int index = static_cast<int>(key_hash);

		std::cout << "Hash in get " << key_hash << "\n";

	  return map_values[index].valueObject;
	}

	void put(K key, V value){
		map_pair newPair;
		newPair.keyObject = key;
		newPair.valueObject = value;

		std::cout << newPair.valueObject << "\n";

		std::size_t key_hash = std::hash<K>()(key);
		//auto it = map_values.begin();
		key_hash %= sizeof(int);
		int index = static_cast<int>(key_hash);
		map_values[index] = newPair;
		//map_values.insert(it, index, newPair);

		std::cout << "put Done\n"; 
	}

};

//need to add check so that duplicate hashes are dealt with, need to change arrary to vector for resizeability

int main(){

	//Map <int, std::string>map;
	Map <int, std::string>map;

	int test = 489496465;
	std::string test2 = "teste";

	int sec = 496841235;
	std::string te = "Correlation";

	map.put(test, test2);
	map.put(sec, te);
	std::string tap = map.get(test);
	std::string ta = map.get(sec);
	std::cout << tap << "\n";
	std::cout << ta << "\n";
}
