#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <limits>

#define MAX_MAP_SIZE 10000000

template <typename K, typename V>

class Map{

	public: 
		Map(){}

		~Map(){
			delete[] map_values;
		}
		
		void clear(){
			delete[] map_values;

			map_values = new map_pair[MAX_MAP_SIZE];
		}
		
		V get(K key){
			std::size_t key_hash = std::hash<K>()(key);
			key_hash %= MAX_MAP_SIZE;
			int index = static_cast<int>(key_hash);
			V value = map_values[index].valueObject;

			return value;
		}

		void put(K key, V value){
			std::size_t key_hash = std::hash<K>()(key);
			key_hash %= MAX_MAP_SIZE;
			int index = static_cast<int>(key_hash);
			map_values[index].keyObject = key;
			map_values[index].valueObject = value;
		}

	private:
		struct map_pair{
			K keyObject;
			V valueObject;
		};
		
		typedef struct map_pair map_pair;

		map_pair* map_values = new map_pair[MAX_MAP_SIZE];
};


