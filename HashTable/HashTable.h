#pragma once
#include "Pair.h"
#include <vector>


template<typename K, typename T> class HashTable
{
	std::hash<K> hash_function;
	size_t number_of_buckets;
	size_t m_size;
	size_t load_factor;
	size_t max_load_factor = 1;
	std::vector<std::vector<Pair<K,T>>> buckets;
	size_t bucket_id(const K& key)
	{
		return hash_function(key) % number_of_buckets;
	}
public:
	HashTable()
	{
		number_of_buckets = 8;
		buckets.reserve(8);
		buckets.assign(8, {});
		m_size = 0;
	}

	/*HashTable(std::initializer_list<Pair<K, T>> list)
	{
		number_of_buckets = 8;
		


		m_size = list.size();
	}*/



	void insert(const Pair<K,T>& pair)
	{
		size_t index = bucket_id(pair.first);
		buckets[index].push_back({ pair.first, pair.second });
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
	
	size_t size() const 
	{
		return m_size;
	}



	
};
	
