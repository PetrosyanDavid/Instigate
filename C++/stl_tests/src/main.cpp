#include <iostream>
#include <vector>
#include <list>
#include <cassert>
#include <numeric>
#include <algorithm>
#include <iterator>
//https://www.techiedelight.com/graph-implementation-using-stl/

int main()
{
    std::vector<int> v(10);
    std::iota(v.begin(), v.end(), 11);

    std::vector<int> v1(15);
    std::iota(v1.begin(), v1.end(), 100);
    
    std::vector<int> v2(15);

    std::list<double> l(2*v.size());
    std::copy_backward(v.begin(), v.end(), l.end());
    //assert(equal(v.begin(), v.end(), l.begin()));
    std::copy(l.begin(), l.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    //std::swap (v,v1);
    //std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    //std::cout << std::endl;
    //std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, " "));
    //std::cout << std::endl;

    std::swap_ranges (v.begin(),v.begin()+7, v1.begin());
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::transform(v.begin(), v.end(), v1.begin(), v2.begin(), std::plus<int>());
    std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::replace (v2.begin(), v2.end(), 0, 5);
    std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::replace_copy (v.begin(), v.end(), v2.begin()+5, 105, 777);
    std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

}
