#include<vector>
#include<memory>
#include<iostream>

template <typename TKey, typename TValue>
class Dictionary
{
private:
	std::vector<std::pair<TKey, TValue>>* backingArray;
	int maxSize;

public:
	int Count;

	void deleteMe() {
		std::unordered_map<int> map;
	}


	Dictionary(int startingArraySize)
		:backingArray{new std::vector<std::pair<TKey, TValue>>[startingArraySize]}, Count{ 0 }, maxSize{startingArraySize}
	{
	}

	TValue Get(TKey key)
	{
		std::hash<TKey> hash;
		int keyHash = hash(key) % maxSize;
		
		throw new
	}

	bool Set(TKey key, TValue value)
	{
		std::hash<TKey> hash;
		int keyHash = hash(key) % maxSize;
		for (int i = 0; i < backingArray[keyHash].size(); i++)
		{
			if(backingArray[keyHash].at(i).first == key)
			{
				return false;
			}
		}
		backingArray[keyHash].push_back(std::pair<TKey, TValue>(key, value));
		Count++;
		return true;
	}
};
