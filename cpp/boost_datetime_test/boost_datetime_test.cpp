#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>

namespace bpt = boost::posix_time;
namespace bdt = boost::date_time;

using namespace std;

int main(int argc, char* argv[])
{
   struct tm t;
   bpt::ptime pt(bpt::second_clock::local_time());
   t = to_tm(pt);
   cout << pt << endl;
   return 0;
}

