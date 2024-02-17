#include <BoolVector.hpp>

static size_t myDel(const size_t& a,const size_t& b) {
	if (a % b == 0)return a / b;
	return (a / b) + 1;
}
void BoolVector::tryIncrease(const size_t& index)
{
	if (index < length)return;
	size_t newCapacity = myDel(index, 8);
	auto newEntry = new unsigned char[newCapacity];
	std::copy(entry, entry + capacity, newEntry);
	delete[]entry;
	entry = newEntry;
	capacity = newCapacity;
}

BoolVector::BoolVector() : length(0),capacity(0){
	entry = new unsigned char[0];
}
bool BoolVector::get(const size_t& index) const
{
	if (index >= length)throw std::exception();
	unsigned char ch = entry[index / 8];
	unsigned char ost = index % 8;
	auto bit = static_cast<unsigned char>(pow(2, (7-ost)));
	return (ch & bit) == bit;
}
void BoolVector::set(const size_t& index, const bool& value)
{
	if (index >= length)throw std::exception();
	unsigned char& ch = entry[index / 8];
	unsigned char ost = index % 8;
    auto bit = static_cast<unsigned char>(pow(2, 7-ost));
	ch = ch & (255 - bit);
	if (!value)return;
	ch += bit;

}
void BoolVector::append(const bool& b)
{
	tryIncrease(++length);
	set(length - 1, b);
}
void BoolVector::insert(const size_t& index, const bool& value)
{
	if (index >= length)throw std::exception();
	tryIncrease(++length);
	for (size_t i = length-1; i > index; i--) {
		set(i, get(i - 1));
	}
	set(index, value);
}
void BoolVector::erase(const size_t& index, const size_t& len)
{
	if (index >= length || index+len >= length)throw std::exception();
	for (size_t i = index; i < length - len; i++) {
		set(i, get(i + len));
	}
	length -= len;
}
size_t BoolVector::getLength() const
{
	return length;
}
std::string BoolVector::toString() const
{
	std::string exp;
	for (size_t i = 0; i < length; i++) {
		exp += std::to_string(get(i));
	}
	return exp;
}
BoolVector::~BoolVector()
{
	delete[] entry;
}
