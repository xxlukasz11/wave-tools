#pragma once

template<typename T>
class Parameter {
public:
	using ValueType = T;
	T getValue() const;

protected:
	Parameter(const T value);
	
private:
	T mValue;
};

template<typename T>
inline Parameter<T>::Parameter(const T value) : mValue(value) {
}

template<typename T>
inline T Parameter<T>::getValue() const {
	return mValue;
}
