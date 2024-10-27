#ifndef ACCUMULATOR_H
# define ACCUMULATOR_H

class Accumulator
{
public:
    virtual double next() = 0;
    double accumulate()
    {
        double result = 0;
        double term = 0;
        while ((term = next()) != -1)
        {
            result += term;
        }
        return result;
    }
};

#endif /* ACCUMULATOR_H */