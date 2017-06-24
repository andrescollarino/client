#pragma once

namespace Memory
{
	template<class T>
	void Delete(T& value)
	{
		if(value != nullptr)
		{
			delete value;
			value = nullptr;
		}
	}

	template<class T>
	void DeleteArray(T& value)
	{
		if(value != nullptr)
		{
			delete[] value;
			value = nullptr;
		}
	}
};

