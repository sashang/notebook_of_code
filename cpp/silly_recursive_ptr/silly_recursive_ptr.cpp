//silly program that demonstrates the use of templates to create 
//type that requires 10 *s to dereference.
#include <boost/shared_ptr.hpp>

using namespace boost;

template <int count>
class BP
{
   public:
   typedef shared_ptr< typename BP<count - 1>::inner_type > inner_type;
};

template <>
class BP<0>
{
   public:
   typedef int inner_type;
};

int
main(int argc, char** argv)
{
   BP<1>::inner_type p_1; //**p
   BP<10>::inner_type p_10; //10 *s needed to dereference!!!
   *p_1 = 1; //yes i know this is silly
   **********p_10 = 1;
}

