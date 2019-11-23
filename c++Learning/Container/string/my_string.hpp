#ifndef MY_STRING_HEAD
#define MY_STRING_HEAD
#include<iostream>
#include<cctype>
#include<cstring>
#include<cstdlib>
#include<memory>
#include<string>
class my_string {
	char *data;
	unsigned len;
public:
	enum CLEAR_MODE{
		ALL,
		SET_ZERO
	};
	//construct
	explicit my_string(const char *data = NULL);
	my_string(const my_string& rhs);
	my_string& operator= (const my_string& rhs);
	my_string(my_string&& rhs);
	explicit my_string(char&& rhs);
	my_string& operator= (my_string&& rhs);
	//destruct
	virtual ~my_string();
	//function/method
	unsigned length() const;
	unsigned size() const;
	char* c_str() const;
	void clear(CLEAR_MODE mode = ALL);
	friend std::ostream& operator<< (std::ostream& out, const my_string& rhs);
	friend std::istream& operator>> (std::istream& in, my_string& rhs);
	my_string operator+ (const my_string& rhs);
	my_string& operator+= (const my_string& rhs);
};
#endif //MY_STRING_HEAD
