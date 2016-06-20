#include "Datum.h"

namespace Database
{

template<class T>
Datum<T>::Datum(T value)
	: DataNode(), value(value)
{
}

template<class T>
Datum<T>::Datum(const std::string &identifier, DataNode *parent, DataNode *rightSibling, T value)
	: DataNode(identifier, parent, rightSibling), value(value)
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
T Datum<T>::getValue()
{
	return value;
}

}
