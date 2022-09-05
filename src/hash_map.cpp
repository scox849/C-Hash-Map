#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <limits>

#define MAX_MAP_SIZE 10000000

template <typename K, typename V>

class Map{

	public: 
		Map(){
			initialize();
		}

		~Map(){
			free_all();
			free(map_values);
		}
		
		void clear(){
		}
		
		V get(K key){
			std::size_t key_hash = std::hash<K>()(key);
			key_hash %= MAX_MAP_SIZE;
			int index = static_cast<int>(key_hash);
			V value = map_values[index]->valueObject;

			return value;
		}

		void put(K key, V value){
			std::size_t key_hash = std::hash<K>()(key);
			key_hash %= MAX_MAP_SIZE;
			int index = static_cast<int>(key_hash);
			map_pair *newPair = map_values[index];
			newPair->keyObject = key;
			newPair->valueObject = value;
			map_values[index] = newPair;
		}

	private:
		struct map_pair{
			K keyObject;
			V valueObject;
		};
		
		typedef struct map_pair map_pair;

		//std::vector<map_pair> map_values;
		map_pair** map_values = (map_pair**)malloc(sizeof(map_pair) * MAX_MAP_SIZE);
		//int valueListIdx = 0;
		
		void initialize(){
			for(int i = 0; i < MAX_MAP_SIZE; i++){
				map_values[i] = (map_pair*)malloc(sizeof(map_pair));
			}
		}

		void free_all(){
			for(int i = 0; i < MAX_MAP_SIZE; i++){
				free(map_values[i]);
			}
		}

};

void add_more(Map<std::string, std::string> *the_map){
	
	std::string test1 = "key";
	std::string test2 = "c";
	std::string test3 = "value";
	std::string test4 = "d";
	std::string test5 = "lto";
	std::string test6 = "fsdat";

	the_map->put(test1, test3);
	the_map->put(test2, test4);
	the_map->put(test5, test6);


}


int main(){
	//Map <int, std::string>map;
	
	Map <std::string, std::string>mapi;

	std::string test = "a";
	std::string test2 = "tes_word";


	std::string sec = "b";
	std::string te = "Terminate";
	
	mapi.put(test, test2);
	mapi.put(sec, te);
	add_more(&mapi);
	std::string tap = mapi.get(test);
	std::string ta = mapi.get(sec);
	std::string key = mapi.get("key");
	std::string c = mapi.get("c");
	std::cout << "tap is " << tap << "\n";
	std::cout << "ta is " << ta << "\n";
	std::cout << "key is " << key << "\n";
	std::cout << "c is " << c << "\n";
}
