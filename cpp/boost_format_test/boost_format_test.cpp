#include <boost/format.hpp>
#include <iostream>
#include <iomanip>

using namespace boost;
using boost::io::group;
using namespace std;

int
main(int argc, char* argv[])
{
   cout << format("%1%") % group(hex, setfill('0'), setw(8), 0xab) << endl;
   return 0;
}
