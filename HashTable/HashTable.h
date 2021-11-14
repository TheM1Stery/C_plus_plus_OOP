#pragma once
#include "Pair.h"
#include <vector>
#include <cmath>

template<typename K, typename T> class HashTable
{
	std::hash<K> hash_function;
	size_t m_size;
	double m_max_load_factor = 1;
	std::vector<std::vector<Pair<K,T>>> buckets;
	size_t bucket_id(const K& key) const
	{
		return hash_function(key) % buckets.size();
	}
	bool is_prime(size_t number) // Есть такая хитрость, что когда количество корзин является простым числом, то колизии происходят меньше, но когда я это делаю то происходит много выделений
	{
		if (number <= 1) return false;
		if (number <= 3) return true;
		if (number % 2 == 0 || number % 3 == 0)
		{
			return false;
		}
		for (long long i = 5; i <= sqrt(number); i += 6)
		{
			if (number % i == 0 || number % (i + 2) == 0)
			{
				return false;
			}
		}
		return true;
		
	}

	size_t next_prime(size_t number)
	{
		while (true)
		{
			if (is_prime(number))
			{
				return number;
			}
			number++;
		}
	}
	
public:
	HashTable()
	{
		buckets.resize(8);
		m_size = 0;
	}

	explicit HashTable(double max_f) : HashTable()
	{
		m_max_load_factor = max_f;
	}

	HashTable(std::initializer_list<Pair<K, T>> list) : HashTable()
	{
		for (auto& item : list)
		{
			insert({ item.first, item.second });
		}
	}


	
	void rehash(size_t count)
	{
		std::vector < Pair<K, T>> pairs;
		pairs.reserve(m_size);
		for (int i = 0; i < buckets.size(); i++) // copy pairs to rehash them later(down below)
		{
			for (int j = 0; j < buckets[i].size(); j++)
			{
				pairs.push_back(buckets[i][j]);
			}
		}
		buckets.clear(); // при очищении корзин, память на 50% меньше пожирается лол, магия

		buckets.resize(count);
		
		for (int i = 0; i < pairs.size(); i++) // rehash
		{
			size_t index = bucket_id(pairs[i].first);
			buckets[index].emplace_back(pairs[i].first, pairs[i].second);
		}
		
		
	}

	void insert(const Pair<K,T>& pair)
	{
		size_t index = bucket_id(pair.first);
		for (int i = 0; i < buckets[index].size(); i++)
		{
			if (buckets[index][i].first == pair.first)
			{
				return;
			}
		}
		if (m_size + 1 > m_max_load_factor * buckets.size())
		{
			/*size_t num = next_prime(buckets.size() * 2);
			rehash(num);*/
			size_t num = (buckets.size() == 8 || buckets.size() == 64 ? buckets.size() * 8 : buckets.size() * 2);
			rehash(num);
		}
		index = bucket_id(pair.first);
		buckets[index].emplace_back(pair.first, pair.second);
		m_size++;
	}

	T& operator[](const K& key)
	{
		size_t index = bucket_id(key);
		for (int i = 0; i < buckets[index].size(); i++)
		{
			if (buckets[index][i].first == key)
			{
				return buckets[index][i].second;
			}
		}
		insert({key,0});
		index = bucket_id(key);
		for (int i = 0; i < buckets[index].size(); i++)
		{
			if (buckets[index][i].first == key)
			{
				return buckets[index][i].second;
			}
		}
	}

	T& at(const K& key)
	{
		size_t index = bucket_id(key);
		for (int i = 0; i < buckets[index].size(); i++)
		{
			if (buckets[index][i].first == key)
			{
				return buckets[index][i].second;
			}
		}
		throw std::out_of_range("Element not found in the table");
	}


	const T& at(const K& key) const
	{
		size_t index = bucket_id(key);
		for (int i = 0; i < buckets[index].size(); i++)
		{
			if (buckets[index][i].first == key)
			{
				return buckets[index][i].second;
			}
		}
		throw std::out_of_range("Element not found in the table");
	}
	
	size_t empty() const
	{
		return m_size == 0;
	}
	


	size_t size() const 
	{
		return m_size;
	}
	
	size_t bucket_count() const
	{
		return buckets.size();
	}

	double load_factor() const 
	{
		return static_cast<double>(m_size) / buckets.size();
	}

	double max_load_factor() const
	{
		return m_max_load_factor;
	}

	std::vector<K> keys() const
	{
		std::vector<K> keys;
		for (auto& item : buckets) 
		{
			for (auto& item2 : item)
			{
				keys.push_back(item2.first);
			}
		}
		return keys;

	}


	
};
	
