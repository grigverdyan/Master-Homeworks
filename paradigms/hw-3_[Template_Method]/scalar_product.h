#ifndef SCALAR_PRODUCT_H
#define SCALAR_PRODUCT_H

#include "accumulator.h"

#include <vector>
class ScalarProduct : public Accumulator
{
private:
    std::vector<double> mX;
    std::vector<double> mY;
    unsigned mIter;
public:
    ScalarProduct(std::vector<double> x, std::vector<double> y)
        : mX(std::move(x))
        , mY(std::move(y))
    {
        mIter = 1;
    }

    double next() override
    {
        if(mIter >= mX.size())
        {
            return -1;
        }
        mIter++;
        return mX[mIter - 1] * mY[mIter - 1];
    }
};

#endif /* SCALAR_PRODUCT_H */
