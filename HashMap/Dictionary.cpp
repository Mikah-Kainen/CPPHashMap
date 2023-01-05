#include<vector>
#include<memory>
#include<iostream>
#include<exception>

template <typename TKey, typename TValue>
class Dictionary
{
private:
	std::vector<std::pair<TKey, TValue>>* backingArray;
	int maxSize;

	void Resize()
	{
		Count = 0;
		maxSize = maxSize * 2;
		std::vector<std::pair<TKey, TValue>>* oldArray = backingArray;
		backingArray = new std::vector<std::pair<TKey, TValue>>[maxSize];
		for (int i = 0; i < maxSize / 2; i ++)
		{
			for (int x = 0; x < oldArray[i].size(); x ++)
			{
				Set(oldArray[i][x]);
			}
		}
		delete[] oldArray;
	}

public:
	int Count;

	Dictionary(int startingArraySize)
		:backingArray{new std::vector<std::pair<TKey, TValue>>[startingArraySize]}, Count{ 0 }, maxSize{startingArraySize}
	{
	}

	TValue Get(TKey key)
	{
		std::hash<TKey> hash;
		int keyHash = hash(key) % maxSize;
		for (int i = 0; i < backingArray[keyHash].size(); i++)
		{
			if (backingArray[keyHash].at(i).first == key)
			{
				return backingArray[keyHash].at(i).second;
			}
		}
		throw std::invalid_argument("Key not contained in the map");
	}

	bool Set(TKey key, TValue value)
	{
		return Set(std::pair<TKey, TValue>(key, value));
	}

	bool Set(std::pair<TKey, TValue> pair) //returns false if a value was overidden
	{
		std::hash<TKey> hash;
		int keyHash = hash(pair.first) % maxSize;
		for (int i = 0; i < backingArray[keyHash].size(); i++)
		{
			if (backingArray[keyHash].at(i).first == pair.first)
			{
				backingArray[keyHash].at(i).second = pair.second;
				return false;
			}
		}
		if (Count >= maxSize)
		{
			Resize();
		}
		keyHash = hash(pair.first) % maxSize;
		backingArray[keyHash].push_back(pair);
		Count++;
		return true;
	}

	bool Remove(TKey key, TValue value)
	{
		return Remove(std::pair<TKey, TValue>(key, value));
	}

	bool Remove(std::pair<TKey, TValue> pair)
	{
		std::hash<TKey> hash;
		int keyHash = hash(pair.first) % maxSize;
		for (int i = 0; i < backingArray[keyHash].size(); i++)
		{
			if (backingArray[keyHash].at(i).first == pair.first)
			{
				if (backingArray[keyHash].at(i).second == pair.second)
				{
					backingArray[keyHash].erase(backingArray[keyHash].begin() + i);
					Count = Count - 1;
					return true;
				}
				return false;
			}
		}
		return false;
	}
};
