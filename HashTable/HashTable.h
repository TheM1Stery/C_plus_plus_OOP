#pragma once
#include "Pair.h"
#include <vector>


template<typename K, typename T> class HashTable
{
	std::hash<K> hash_function;
	size_t m_size;
	size_t max_load_factor = 1;
	std::vector<std::vector<Pair<K,T>>> buckets;
	size_t bucket_id(const K& key) const
	{
		return hash_function(key) % buckets.size();
	}
	bool is_prime(size_t number)
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

	/*HashTable(std::initializer_list<Pair<K, T>> list)
	{
		number_of_buckets = 8;
		


		m_size = list.size();
	}*/


	
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
		
		buckets.resize(count);
		
		for (int i = 0; i < pairs.size(); i++) // rehash
		{
			size_t index = bucket_id(pairs[i].first);
			buckets[index].emplace_back(pairs[i].first, pairs[i].second);
		}
		
	}

	void insert(const Pair<K,T>& pair)
	{
		if (m_size + 1 > max_load_factor * buckets.size())
		{
			size_t num = next_prime(buckets.size() * 2);
			rehash(num);
			//rehash(buckets.size() * 8);
		}
		size_t index = bucket_id(pair.first);
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

	size_t load_factor()
	{
		return m_size / buckets.size();
	}

	
};
	
