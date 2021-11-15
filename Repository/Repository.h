#pragma once



#include <initializer_list>

#ifdef VECTOR
#include <vector>

template<typename F> class Repository
{
	std::vector<F> files;
public:
	Repository() = default;
	Repository(std::initializer_list<F> list)
	{
		files = list;
	}

	size_t capacity() const
	{
		return files.capacity();
	}

	size_t size() const
	{
		return files.size();
	}

	F& operator[](size_t index)
	{
		return files[index];
	}

	const F& operator[](size_t index) const
	{
		return files[index];
	}

	void pop_back()
	{
		files.pop_back();
	}

	void erase(size_t index)
	{
		files.erase(files.begin() + index);
	}

	void push_back(const F& file)
	{
		files.push_back(file);
	}

	void push_back(F&& file)
	{
		files.push_back(std::move(file));
	}

	template<typename... args> void  emplace_back(args&&... arguments)
	{
		files.emplace_back(std::forward<args>(arguments)...);
	}

	Repository& operator= (std::initializer_list<F> list)
	{
		files = list;
		return *this;
	}
	

};

#endif




#ifdef LLIST
#include <list>
template<typename F>class Repository
{
	std::list<F> files;
public:
	Repository() = default;

	Repository(std::initializer_list<F> list)
	{
		files = list;
	}
	size_t size() const
	{
		return files.size();
	}
	size_t capacity()
	{
		return files.max_size();
	}

	F& operator[](size_t index)
	{
		typename std::list<F>::iterator it = files.begin();
		for (int i = 0; i < index && it != files.end(); i++)
		{
			++it;
		}
		return *it;
	}

	const F& operator[](size_t index) const
	{
		typename std::list<F>::const_iterator it = files.begin();
		for (int i = 0; i < index && it != files.end(); i++)
		{
			++it;
		}
		return *it;
	}

	void pop_back()
	{
		files.pop_back();
	}

	void push_back(const F& file)
	{
		files.push_back(file);
	}

	void push_back(F&& file)
	{
		files.push_back(std::move(file));
	}

	void erase(size_t index)
	{
		typename std::list<F>::iterator it = files.begin();
		for (int i = 0; i < index && it != files.end(); i++)
		{
			++it;
		}
		files.erase(it);
	}


	template<typename... args> void emplace_back(args... arguments)
	{
		files.emplace_back(std::forward<args>(arguments)...);
	}

	Repository& operator= (std::initializer_list<F> list)
	{
		files = list;
		return *this;
	}
	



};


#endif


#ifdef RAW

template<typename F> class Repository
{
	F* files;
	size_t m_capacity;
	size_t m_size;
public:
	Repository() : files(nullptr), m_capacity(0), m_size(0) {}

	Repository(const Repository& cpy)
	{
		m_capacity = cpy.m_capacity;
		m_size = cpy.m_size;
		files = new T[m_capacity];
		for (int i = 0; i < m_size; i++)
		{
			files[i] = cpy.files[i];
		}
	}

	Repository(Repository&& move)
	{
		m_capacity = move.m_capacity;
		m_size = move.m_size;
		files = move.files;

		files = nullptr;
		m_capacity = 0;
		m_size = 0;
	}

	Repository(std::initializer_list<F> list)
	{
		files = new T[list.size()];
		int i = 0;
		for (auto& item : list)
		{
			files[i++] = item;
		}
		m_capacity = m_size = list.size();
	}

	size_t size() const
	{
		return m_size;
	}

	size_t capacity() const
	{
		return m_capacity;
	}

	F& operator [](size_t index)
	{
		return files[index];
	}

	const F& operator[](size_t index) const
	{
		return files[index];
	}

	void pop_back()
	{
		if (m_size != 0)
		{
			files[m_size - 1].~F();
			m_size--;
		}
	}

	void erase(size_t index)
	{
		if (m_size == 0)
		{
			return;
		}
		for (int i = index; i < m_size - 1; i++)
		{
			files[i] = files[i + 1];
		}
		files[m_size].~F();
		m_size--;
	}







	~Repository()
	{
		delete[] files;
	}
};


#endif
