#include <cmath>
#include <iostream>

using namespace std;

struct functor_base
{
    virtual double operator() (double x) const = 0;
    virtual ~functor_base() = default;
};


double finite_difference(const functor_base& f, double x, double h)
{
    return (f(x + h) - f(x))/h;
}

class para_sin_plus_cos : public functor_base
{
public:
    para_sin_plus_cos(double p) : alpha{p} {}    

    virtual double operator() (double x) const override
    {
        return sin(alpha*x) + cos(x);
    }

private:
    double alpha;
};


int main()
{
    para_sin_plus_cos sin_1{1.0};
    std::cout << finite_difference(sin_1, 1.0, 0.001) << std::endl;
}