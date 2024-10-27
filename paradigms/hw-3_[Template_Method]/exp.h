#ifndef EXP_H
#define EXP_H

#include "accumulator.h"

class Exp : public Accumulator
{
private:
    unsigned    mIter;
    double      mX;
    double      mEps;
    double      mTerm;
public:
    Exp(double x, double eps)
        : mX(x)
        , mEps(eps)
    {
        mTerm = 1;
        mIter = 0;
    }
    double next() override
    {
        if (mTerm < mEps)
        {
            return -1;
        }
        double result = mTerm;
        mTerm *= mX / ++mIter;
        return result;
    }
};

#endif /* EXP_H */