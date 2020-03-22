#include "xframe/xio.hpp"
#include "xframe/xvariable.hpp"
#include "xtensor/xrandom.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    using coordinate_type = xf::xcoordinate<xf::fstring>;
    using variable_type = xf::xvariable<double, coordinate_type>;
    using data_type = variable_type::data_type;

    // Creation of the data
    data_type data = xt::eval(xt::random::rand({6, 3}, 15., 25.));
    data(0, 0).has_value() = false;
    data(2, 1).has_value() = false;

    // Creation of coordinates and dimensions
    auto time_axis = xf::axis({"2018-01-01", "2018-01-02", "2018-01-03", "2018-01-04", "2018-01-05", "2018-01-06"});
    auto city_axis = xf::axis({"London", "Paris", "Brussels"});
    auto coord = xf::coordinate({{"date", time_axis}, {"city", city_axis}});
    auto dim = xf::dimension({"date", "city"});

    // Creation of the variable
    auto var = variable_type(data, coord, dim);
    std::cout << var << std::endl;

    return 0;
}
