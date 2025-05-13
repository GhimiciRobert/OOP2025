#include<iostream>
#include<tuple>
using namespace std;

template<typename K, typename V>
class Map
{
private:
	struct entry {
		K key;
		V value;
	};
	entry* entries;
	int size;
	int cap;
	
	void resize()
	{
		cap *= 2;
		entry* aux = new entry[cap];
		for (int i = 0;i < size;i++)
		{
			aux[i] = entries[i];
		}
		delete[] entries;
		entries = aux;
	}
public:
	Map() : size(0), cap(10), entries(new entry[cap]) {};
	~Map() {
		delete[] entries;
	}
	
	V& operator[](const K& key) {
		for (int i = 0;i < size;i++)
		{
			if (entries[i].key == key)
				return entries[i].value;
		}
		if (size == cap)
			resize();
		entries[size].key = key;
		entries[size].value = V();
		size++;
		return entries[size - 1].value;
	}

	void Set(K key, V value) {
		(*this)[key] = value;
	}

	bool Get(const K& key, V& value) {
		for (int i = 0;i < size;i++)
		{
			if (entries[i].key == key)
			{
				value = entries[i].value;
				return true;
			}
		}
		return false;
	}

	int Count() {
		return size;
	}

	void Clear() {
		delete[] entries;
		size = 0;
		cap = 10;
		entries = new entry[cap];
	}

	bool Delete(const K& key) {
		for (int i = 0; i < size; i++) {
			if (entries[i].key == key) {
				for (int j = i; j < size - 1; j++) {
					entries[j] = entries[j + 1];
				}
				size--;
				return true;
			}
		}
		return false;
	}
	bool Includes(const Map<K, V>& aux) {
		for (int i = 0;i < aux.size;i++)
		{
			int ok = 0;
			for (int j = 0;j < size;j++)
			{
				if (aux.entries[i].key == entries[j].key)
				{
					ok = 1;
					break;
				}
			}
			if (!ok)
				return false;
		}
		return true;
	}
	
	

	struct iterator {
		Map<K, V>& map;
		int index;
		iterator(Map<K, V>& m, int i) :map(m), index(i) {};
		auto operator*() {
			return tuple<K&, V&, int>(map.entries[index].key, map.entries[index].value, index);
		}
		bool operator!=(iterator& m) {
			return (index != m.index);
		}
		iterator& operator++() {
			++index;
			return *this;
		}
	};
	iterator begin() {
		return iterator(*this, 0);
	}
	iterator end() {
		return iterator(*this, size);
	}

};
int main()
{
	Map<int, const char*> map;
	map[10] = "C++";
	map[20] = "test";
	map[30] = "Poo";
	for (auto [key, value, index] : map)
	{
		cout << "index:" << index << ",key:" << key << ",value:" << value << endl;
	}
	map[20] = "result";
	for (auto [key, value, index] : map)
	{
		cout << "index:" << index << ",key:" << key << ",value:" << value << endl;
	}
	return 0;
}