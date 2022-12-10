#include<vector>
#include<memory>


template <typename TKey, typename TValue>
class Dictionary
{
private:
	std::vector<std::pair<TKey, TValue>>* backingArray;
	int currentIndex;
	int maxSize;

public:
	Dictionary(int startingArraySize)
		:backingArray{std::make_unique<std::vector<std::pair<TKey, TValue>>>(new std::vector<std::pair<TKey, TValue>>[startingArraySize])}, currentIndex{ 0 }, maxSize{startingArraySize}
	{
		
	}

	TValue Get(TKey key)
	{
		
	}

	bool Set(TKey key, TValue value)
	{
		int hash = std::hash<TKey>(key);
		for (int i = 0; i < backingArray[backingArray + hash].size(); i ++)
		{

		}
		backingArray[backingArray + hash].push_back(std::pair<TKey, TValue>(key, value));
	}
};
