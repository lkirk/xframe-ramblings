#include <iostream>
#include "xtensor/xarray.hpp"
#include "xtensor/xmath.hpp"
#include "xtensor/xio.hpp"

int main(int argc, char* argv[])
{
    xt::xarray<double> arr1
      {1.0, 2.0, 3.0};

    xt::xarray<unsigned int> arr2
      {4, 5, 6, 7};

    arr2.reshape({4, 1});

    xt::xarray<double> res = xt::pow(arr1, arr2);

    std::cout << res;
    return 0;
}
