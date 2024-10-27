#include <iostream>
#include <memory>
#include "exp.h"
#include "scalar_product.h"

int main()
{
    Exp exp(2, 1./3);
    std::cout << "Exp: " << exp.accumulate() << std::endl;

    ScalarProduct sc({3, 5, 7, 1}, {3, 2, 1, 4});
    std::cout << "Scalar Product: " << sc.accumulate() << std::endl;

    return 0;
}