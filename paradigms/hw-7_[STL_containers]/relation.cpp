#include <set>
#include <iostream>

struct Pair
{
	int	first_;
	int second_;
	Pair(int first, int second):
	first_(first), second_(second){}
	bool operator<(const Pair& other)const
	{
		return first_ < other.first_
				||
				first_ == other.first_ && second_ < other.second_;
	}
};

const int n = 5;

typedef std::set<Pair>					Relation;
typedef Relation::iterator			Iterator;
typedef Relation::const_iterator	CIterator;

bool isReflexive(const Relation& alpha) 
{
	for(int i = 1; i <= n; i++)
		if( alpha.find(Pair(i, i)) == alpha.end() )
			return false;
	return true;
}

Relation reversion(const Relation& alpha)
{
    Relation reversed;
	for (auto i = 1; i <= n; ++i)
	{
		for (auto j = 1; j <= n; ++j)
		{
			if (alpha.find(Pair(i, j)) == alpha.end())
				reversed.insert(Pair(i, j));
		}
	}
    return reversed;
}

Relation operator*(const Relation& alpha, const Relation& beta)
{
    Relation result;
    for (const auto& p1 : alpha)
    {
        for (const auto& p2 : beta)
        {
            if (p1.second_ == p2.first_)
            {
                result.insert(Pair(p1.first_, p2.second_));
            }
        }
    }
    return result;
}

void print(const Relation& alpha) 
{
	for(CIterator it = alpha.begin(); it != alpha.end(); it++)
		std::cout << it->first_ << ", " << it->second_ << std::endl;
	std::cout << std::endl;
}

int main() 
{
	std::cout << "alpha RELATION:" << std::endl;
	Relation alpha;
	alpha.insert(Pair(1, 1)); alpha.insert(Pair(1, 3)); alpha.insert(Pair(1, 4));
	alpha.insert(Pair(2, 1)); alpha.insert(Pair(2, 2)); alpha.insert(Pair(2, 4));
	alpha.insert(Pair(3, 1)); alpha.insert(Pair(3, 3));
	alpha.insert(Pair(4, 1)); alpha.insert(Pair(4, 3)); alpha.insert(Pair(4, 5));
	alpha.insert(Pair(5, 2)); alpha.insert(Pair(5, 5));

	print(alpha);
	
	std::cout << "IS alpha REFLEXIVE?" <<std::endl;
	std::cout << isReflexive(alpha) << std::endl << std::endl;

	std::cout << "Reversion of alpha:" << std::endl;
    Relation alpha_reversed = reversion(alpha);
    print(alpha_reversed);

    std::cout << "alpha * alpha_reversed:" << std::endl;
    print(alpha * alpha_reversed);

	return 0;
}

