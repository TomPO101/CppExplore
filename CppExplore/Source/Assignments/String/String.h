#pragma once

#include <iostream>
#include <cstring>


namespace Utilities
{

using std::cout;
using std::endl;

#define MIN_CAPICITY 15

class String
{
	friend std::ostream& operator<<(std::ostream& out, const String& s);
	/*friend String operator+(const String& left, const String& right);
	friend String& operator+=(String& left, const String& right);*/

public:
	// Constructors --------------------------------------------------------------
	String(const char* data, size_t capacity = MIN_CAPICITY);
	explicit String(const String& source);
	~String(void);
	

	// Operators ------------------------------------------------------------------
	String& operator=(const String& rightOperand);


	// Getters / Setters ----------------------------------------------------------
	const char* c_str() const;
	char*& data(void);
	size_t capacity(void) const;
	size_t size(void) const;


	// General Methods ------------------------------------------------------------
	void clear(void);
	void reserve(const size_t n = 0);
	void shrink_to_fit(void);

private:
	// Private Helper methods -----------------------------------------------------
	void Copy(const String& str)
	{
		if (this != &str)
		{
			delete[] m_Data;
			m_Size = str.size();
			m_Capacity = str.capacity();
			m_Data = new char[str.capacity()] {}; // perform deep copy			
			std::strcat(m_Data, str.c_str());
		}
	}

	// Private Getters / Setters --------------------------------------------------
	size_t& capacity(void);

private:
	size_t m_Capacity;
	size_t m_Size;
	char* m_Data{ nullptr };
};




// Constructors ------------------------------------------------------------------

inline String::String(const char* data, size_t capacity)
	: m_Capacity{ capacity }, m_Size{ 0 }
{
	m_Size = std::strlen(data);

	const size_t sizePlusNulT{ m_Size + 1 };

	if (sizePlusNulT > capacity)
		m_Capacity = sizePlusNulT;

	this->data() = new char[this->capacity()] {};

	std::strcpy(m_Data, data);
}

inline String::String(const String& source)
{
	Copy(source);
}

inline String::~String()
{
	delete[] m_Data;
	m_Data = nullptr;
}


// Getters / Setters ----------------------------------------------------------

inline const char* String::c_str() const
{
	return m_Data;
}

inline char*& String::data(void)
{
	return m_Data;
}

inline size_t String::capacity(void) const
{
	return m_Capacity;
}

inline size_t String::size(void) const
{
	return m_Size;
}


// Private Getters / Setters ----------------------------------------------------------

inline size_t& String::capacity(void)
{
	return m_Capacity;
}


// General Methods ----------------------------------------------------------

inline void String::clear(void)
{
	for (size_t i{}; i < m_Size; ++i)
	{
		m_Data[i] = 0;
	}
	m_Size = 0;
}

inline void String::reserve(const size_t n)
{
	// n should include the null terminator

	if (n > m_Capacity)
	{
		char* temp{ m_Data };		

		m_Data = new char[n] {};

		std::strcpy(m_Data, temp);

		delete[] temp;

		m_Capacity = n;
	}
	else
	{
		// shrink to fit the size
		shrink_to_fit();
	}
}

inline void String::shrink_to_fit(void)
{
	size_t newCap{ m_Size + 1 };
	
	if (newCap < MIN_CAPICITY)
		newCap = MIN_CAPICITY;


	char* temp{ m_Data };	

	m_Data = new char[newCap] {};

	std::strcpy(m_Data, temp);

	delete[] temp;	

	m_Capacity = newCap;
}


// Operators ----------------------------------------------------------

inline String& String::operator=(const String& rightOperand)
{
	Copy(rightOperand);
	return *this;
}

inline std::ostream& operator<<(std::ostream& out, const String& s)
{
	out << "String Info\n"
		<< "Size: " << s.size() << endl
		<< "Capacity: " << s.capacity() << endl
		<< "Data: " << s.c_str() << endl;
	return out;
}

//inline String operator+(const String& left, const String& right)
//{
//	String tmp(left);
//	tmp += right;
//	return tmp;
//}
//
//inline String& operator+=(String& left, const String& right)
//{
//	std::strcat(left.m_Data, right.m_Data);
//	return left;
//}

}