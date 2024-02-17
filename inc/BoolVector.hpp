#pragma once
#include <iostream>
#include <cmath>
#include <string>
class BoolVector {
private:
	unsigned char* entry;
	size_t length;
	size_t capacity;
	void tryIncrease(const size_t& index);
public:
	BoolVector();
	bool get(const size_t& index) const;
	void set(const size_t& index, const bool& value);
	void append(const bool& b);
	void insert(const size_t& index, const bool& value);
	void erase(const size_t& index,const size_t& len);
	size_t getLength() const;
	std::string toString() const;
	~BoolVector();
};