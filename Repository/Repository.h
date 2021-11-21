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

	size_t max_size() const
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

	void delete_file_back()
	{
		files.pop_back();
	}

	void delete_file(size_t index)
	{
		files.erase(files.begin() + index);
	}

	void add_file(const F& file)
	{
		files.push_back(file);
	}

	void add_file(F&& file)
	{
		files.push_back(std::move(file));
	}

	template<typename... args> void  create_and_add(args&&... arguments)
	{
		files.emplace_back(std::forward<args>(arguments)...);
	}

	Repository& operator= (std::initializer_list<F> list)
	{
		files = list;
		return *this;
	}
	

};



#elif defined(LLIST)

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
	size_t max_size()
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

	void delete_file_back()
	{
		files.pop_back();
	}

	void add_file(const F& file)
	{
		files.push_back(file);
	}

	void add_file(F&& file)
	{
		files.push_back(std::move(file));
	}

	void delete_file(size_t index)
	{
		typename std::list<F>::iterator it = files.begin();
		for (int i = 0; i < index && it != files.end(); i++)
		{
			++it;
		}
		files.erase(it);
	}


	template<typename... args> void create_and_add(args... arguments)
	{
		files.emplace_back(std::forward<args>(arguments)...);
	}

	Repository& operator= (std::initializer_list<F> list)
	{
		files = list;
		return *this;
	}
	



};





#elif defined(RAW_MEM)
template<typename F> class Repository
{
	F* files;
	size_t m_capacity;
	size_t m_size;
	void reserve(size_t size)
	{
		if (!size)
		{
			files = new F[size];
			m_capacity = size;
			return;
		}
		F* temp_arr = new F[size];
		for (int i = 0; i < m_size; i++)
		{
			temp_arr[i] = files[i];
		}
		delete[] files;
		files = temp_arr;
		m_capacity = size;
	}
public:
	Repository() : files(nullptr), m_capacity(0), m_size(0) {}

	Repository(const Repository& cpy)
	{
		m_capacity = cpy.m_capacity;
		m_size = cpy.m_size;
		files = new F[m_capacity];
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
		files = new F[list.size()];
		int i = 0;
		for (auto& item : list)
		{
			files[i++] = item;
		}
		m_capacity = m_size = list.size();
	}

	Repository& operator =(const Repository& cpy)
	{
		delete[] files;
		m_capacity = cpy.m_capacity;
		m_size = cpy.m_size;
		files = new F[m_capacity];
		for (int i = 0; i < m_size; i++)
		{
			files[i] = cpy.files[i];
		}
	}

	Repository& operator=(Repository&& move)
	{
		delete[] files;
		m_capacity = move.m_capacity;
		m_size = move.m_size;
		files = move.files;

		files = nullptr;
		m_capacity = 0;
		m_size = 0;
	}

	Repository& operator=(std::initializer_list<F> list)
	{
		delete[] files;
		files = new F[list.size()];
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

	size_t max_size() const
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

	void delete_file_back()
	{
		if (m_size != 0)
		{
			files[m_size - 1].~F();
			m_size--;
		}
	}

	void delete_file(size_t index)
	{
		if (m_size == 0)
		{
			return;
		}
		int i = 0;
		for (i = index; i < m_size - 1; i++)
		{
			files[i] = files[i + 1];
		}
		files[i].~F();
		m_size--;
	}

	void add_file(const F& file)
	{
		if (m_size >= m_capacity)
		{
			if (!m_capacity) m_capacity++;
			reserve(m_capacity * 2);
		}
		files[m_size] = file;
		m_size++;
	}

	void add_file(F&& file)
	{
		if (m_size >= m_capacity)
		{
			if (!m_capacity) m_capacity++;
			reserve(m_capacity * 2);
		}
		files[m_size] = std::move(file);
		m_size++;
	}

	template<typename... Args> void create_and_add(Args&&... arguments)
	{
		if (m_size >= m_capacity)
		{
			if (!m_capacity) m_capacity++;
			reserve(m_capacity * 2);
		}
		files[m_size] = F(std::forward<Args>(arguments)...);
		m_size++;
	}



	~Repository()
	{
		delete[] files;
	}
};


#endif
