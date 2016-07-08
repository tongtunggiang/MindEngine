#include "Datum.h"

namespace RuleBased
{

template<class T>
Datum<T>::Datum(T value)
	: DataNode(), value(value)
{
}

template<class T>
Datum<T>::Datum(const std::string &identifier, DataNode *rightSibling, T value)
	: DataNode(identifier, rightSibling), value(value)
{
}

template<class T>
Datum<T>::~Datum()
{
}

template<class T>
void Datum<T>::setValue(T newValue)
{
	value = newValue;
}

template<class T>
T Datum<T>::getValue() const
{
	return value;
}

template<class T>
bool Datum<T>::isDatum()
{
	return true;
}

}
