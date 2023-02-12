#include <iostream>
#include <vector>

#define MAX_MAP_SIZE 32

template <typename K, typename V>

class Map {
public:
  Map() {}

  ~Map() {}

  /*
   Clears all values from the hashmap and resets the size of vectors to zero.
   */
  void clear() {
    for (int i = 0; i < MAX_MAP_SIZE; i++) {
      map_values[i].clear();
    }
  }

  /*
    Gets a value from the hashmap given a key,
          Index in arrary of vectors is retrieved from hash function on key.
          Vector at index is iterated over until equal keys are found.
          Value associated with key is returned.
  */
  V get(K key) {
    std::size_t key_hash = std::hash<K>()(key);
    key_hash %= MAX_MAP_SIZE;
    int index = static_cast<int>(key_hash);
    V value = V{};

    for (map_pair p : map_values[index]) {
      if (p.keyObject == key) {
        value = p.valueObject;
      }
    }

    return value;
  }

  /*
   Inserts a key value pair into the hashmap.
   Index in arrary of vectors is gained from hash funciton.
   Pair is appended to end of vector at index.
   */
  void put(K key, V value) {
    std::size_t key_hash = std::hash<K>()(key);
    key_hash %= MAX_MAP_SIZE;
    int index = static_cast<int>(key_hash);
    map_pair new_pair;

    new_pair.keyObject = key;
    new_pair.valueObject = value;
    map_values[index].push_back(new_pair);
  }

private:
  struct map_pair {
    K keyObject;
    V valueObject;
  };

  typedef struct map_pair map_pair;
  std::vector<map_pair>
      map_values[MAX_MAP_SIZE]; // array of vectors representing hashmap
};
