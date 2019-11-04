#include<iostream>
#include<boost/thread/mutex.hpp>
#include<boost/thread.hpp>

using namespace std;
boost::mutex mu;
void fn()
{
	boost::lock_guard<boost::mutex> lg(mu);
	cout << "fn" << boost::this_thread::get_id() << endl;
}
int main()
{
	cout << "Hello boost\n";
	boost::thread t1(fn);
	t1.join();
	return 0;
}
