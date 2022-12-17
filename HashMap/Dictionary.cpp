#include<vector>
#include<memory>
#include<iostream>
#include<stdexcept>

template <typename T>
class Enumerator
{
private:

public:
	T Value;

	Enumerator(T value)
		: Value{ value }
	{

	}
};

template <typename TKey, typename TValue>
class Dictionary
{
	using enumerator = Enumerator<TValue>*;

private:
	std::vector<std::pair<TKey, TValue>>* backingArray;
	int maxSize;

public:
	int Count;

	Dictionary(int startingArraySize)
		:backingArray{ new std::vector<std::pair<TKey, TValue>>[startingArraySize] }, Count{ 0 }, maxSize{ startingArraySize }
	{
	}

	enumerator Get(TKey key)
	{
		std::hash<TKey> hash;
		int keyHash = hash(key) % maxSize;
		std::vector<std::pair<TKey, TValue>> bucket = backingArray[keyHash];
		for (int i = 0; i < bucket.size(); i++)
		{
			if (bucket.at(i).first == key)
			{
				return new Enumerator<TValue>(bucket.at(i).second);
			}
		}
		return nullptr;
	}

	bool Set(TKey key, TValue value)
	{
		std::hash<TKey> hash;
		int keyHash = hash(key) % maxSize;
		for (int i = 0; i < backingArray[keyHash].size(); i++)
		{
			if (backingArray[keyHash].at(i).first == key)
			{
				return false;
			}
		}
		backingArray[keyHash].push_back(std::pair<TKey, TValue>(key, value));
		Count++;
		return true;
	}
};
