#include <list>
#include <iostream>

struct Monomial
{
	double	coef_;
	int		exp_;
	Monomial(){}
	Monomial(double coef, int exp): coef_(coef), exp_(exp) {}
};

typedef std::list<Monomial>						Polynomial;
typedef Polynomial::iterator					Iterator;
typedef Polynomial::const_iterator				CIterator;

Polynomial operator+(const Polynomial& first, const Polynomial& second)
{
	Polynomial result;
	CIterator it1 = first.begin();
	CIterator it2 = second.begin();

	while (it1 != first.end() && it2 != second.end())
	{
		if(it1->exp_ > it2->exp_)
		{
			result.push_back(*it1++);
			continue;
		}

		if(it1->exp_ < it2->exp_)
		{
			result.push_back(*it2++);
			continue;
		}

		if(it1->coef_ + it2->coef_)
			result.push_back(Monomial(it1->coef_ + it2->coef_, it1->exp_));
		
		it1++; 
		it2++;
	}
	while(it1 != first.end() )
		result.push_back(*it1++);

	while(it2 != second.end() )
		result.push_back(*it2++);
	
	return result;
}

Polynomial operator*(const Polynomial& first, const Polynomial& second)
{
    Polynomial result;

    for (CIterator it1 = first.begin(); it1 != first.end(); ++it1)
    {
        Polynomial temp;
        for (CIterator it2 = second.begin(); it2 != second.end(); ++it2)
        {
            temp.push_back(Monomial(it1->coef_ * it2->coef_, it1->exp_ + it2->exp_));
        }
        result = result + temp;
    }

    return result;
}

Polynomial derivative(const Polynomial& p)
{
    Polynomial result;

    for (CIterator it = p.begin(); it != p.end(); ++it)
    {
        if (it->exp_ != 0)
            result.push_back(Monomial(it->coef_ * it->exp_, it->exp_ - 1));
    }

    return result;
}

void print(const Polynomial& p)
{
	for(CIterator it = p.begin(); it != p.end();it++)
		std::cout << "coef=" << it->coef_ <<", exp=" << it->exp_ << std::endl;
	std::cout << std::endl;
}


int main()
{
	std::cout << "FIRST POLYNOMIAL:" << std::endl;
	Polynomial first;
	first.push_back(Monomial(7, 5));
	first.push_back(Monomial(-3, 2));
	first.push_back(Monomial(5, 1));
	print(first);

	std::cout << "SECOND POLYNOMIAL:" << std::endl;
	Polynomial second;
	second.push_back(Monomial(4, 3));
	second.push_back(Monomial(3, 2));
	second.push_back(Monomial(-10, 0));
	print(second);

	std::cout << "THE SUM IS:" << std::endl;
	print(first + second);

	std::cout << "THE PRODUCT IS:" << std::endl;
	print(first * second);
	
	std::cout << "THE DERIVATIVE OF FIRST IS:" << std::endl;
	print(derivative(first));
	
	std::cout << "THE DERIVATIVE OF second IS:" << std::endl;
	print(derivative(second));

	return 0;
}

