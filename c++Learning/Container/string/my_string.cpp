#include "my_string.hpp"
/*
    //construct
    my_string(char *data = NULL);
    my_string(const my_string& rhs);
    my_string& operator= (const my_string& rhs);
    my_string(my_string&& rhs);
    my_string& operator= (my_stirng& rhs);
    //destruct
    ~my_string();
*/
//construct
my_string::my_string(const char *d)
{
	if(d == NULL)
	{
		len = 0;
		data = nullptr;
	}
	else
	{
		len = strlen(d);
		data = new char[len + 1];
		strcpy(data, d);
	}
}

my_string::my_string(const my_string& rhs)
{
	len = rhs.len;
	if(len == 0)
		data = nullptr;
	else
	{
		data = new char[len + 1];
		strcpy(data, rhs.data);
	}
}

my_string& my_string::operator= (const my_string& rhs)
{
	if(this != &rhs)
	{
		delete [] data;
		len = rhs.len;
		if(len == 0)
			data = nullptr;
		else
		{
			data = new char[len + 1];
			strcpy(data, rhs.data);
		}
	}
	return *this;
}

my_string::my_string(my_string&& rhs) : len(rhs.len), data(rhs.data)
{
	rhs.len = 0;
	rhs.data = NULL;
}

my_string& my_string::operator= (my_string&& rhs)
{
	if(this != &rhs)
	{
		len = rhs.len;
		data = rhs.data;
		rhs.clear(my_string::SET_ZERO);
	}
	return *this;
}

//destruct
my_string::~my_string()
{
	len = 0;
	delete [] data;
}
//function/method
/*	unsigned length() const;
	unsigned size() const;
	char* c_str() const;*/
unsigned my_string::length() const {
	return len;
}

unsigned my_string::size() const {
	return len;
}

char* my_string::c_str() const {
	return data;
}

//void clear(CLEAR_MODE mode = ALL);
void my_string::clear(my_string::CLEAR_MODE mode)
{
	len = 0;
	if(mode == my_string::ALL)
	{
		delete [] data;
	}
	else if(mode == my_string::SET_ZERO)
	{
		data = NULL;
	}
}
std::ostream& operator<< (std::ostream& out, const my_string& rhs)
{
	if(rhs.length())
		out << rhs.data;
	return out;
}
/*std::istream& my_string::operator>> (std::istream& in, my_string& rhs)
{
	char c;
	while(in && in.get(c) && !std::isSpace(c))
	{

	}
}*/
//my_string operator+ (const my_string& rhs);
my_string my_string::operator+ (const my_string& rhs)
{
	if(rhs.len == 0) return *this;
	if(len == 0) return rhs;
	char *tdata = new char[len + rhs.len + 1];
	strcpy(tdata, data);
	strcat(tdata, rhs.data);
	my_string res = my_string(tdata);
	delete [] tdata;
	return res;
}
//my_string& operator+= (const my_string& rhs);
my_string& my_string::operator+= (const my_string& rhs)
{
	*this = std::move(*this + rhs);
	return *this;
}
