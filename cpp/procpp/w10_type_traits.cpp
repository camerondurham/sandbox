#include <type_traits>

template <typename T>
class I
{
	static_assert(std::is_integral<T>::value, "Not an int!");
};

template <typename T>
class F
{
	static_assert(std::is_floating_point<T>::value, "Not a floating point!");
};


template <typename T>
class A
{
	static_assert(std::is_array<T>::value, "Not an array!");
};

template <typename T>
class Fun
{
	static_assert(std::is_function<T>::value, "Not a function!");
};

/*
 *
 * More examples:
	std::is_floating_point // Is it a float?
	std::is_array // Is it an array?
	std::is_function // Is it a function?
	std::is_class // Is it a class?
	std::is_pod // Is it plain-old data?
	std::is_abstract // Is it an abstract class?
	std::is_same // Are the two types the same?
	std::is_default_constructible // Does it have a default constructor?
	std::has_virtual_destructor // Is the destructor virtual?
*
*/

template<typename T>
void Write(T inData, uint32_t inBitCount = sizeof(T) * 8)
{
	static_assert(std::is_arithmetic<T>::value ||
			std::is_enum<T>::value,
			"Generic Write only supports primitive data types" );
	WriteBits(&inData, inBitCount);
}
