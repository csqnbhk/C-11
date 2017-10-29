/**************************************************************************
      function:该文件主要测试一下chrono库的使用(全部内容来自"深入应用
	           C++11代码优化与工程级应用"该书）
	  author：Demon
	  Time:2017/10/29
****************************************************************************/
#include<windows.h>
#include<iostream>
#include<chrono>
#include<ctime>
#include<iomanip>
using namespace std;
using namespace std::chrono;
//●●●●●●●1. 记录时长的duration
//●●●●●●●2.时钟clock
//●●●●●●●3.时间点time point
//using days_type = duration<int, ratio<60 * 60 * 24>>;

//●●●●●●4.计时器
/*
class Timer 
{
public:
	Timer():m_begin(high_resolution_clock::now()){}
	void reset() { m_begin = high_resolution_clock::now(); }

	template<typename Duration=milliseconds>
	int64_t elapsed() const {
		return duration_cast<Duration>(high_resolution_clock::now() - m_begin).count();
	}
public:
	int64_t elapsed_nano() const
	{
		return elapsed<nanoseconds>();
	}
	int64_t elapsed_micro() const 
	{
		return elapsed<microseconds>();
	}
	int64_t elapsed_seconds() const
	{
		return elapsed<seconds>();
	}
	int64_t elapsed_minutes() const
	{
		return elapsed<minutes>();
	}
	int64_t elapsed_hours() const
	{
		return elapsed<hours>();
	}
private:
	time_point<high_resolution_clock> m_begin;

};
*/

int main()
{
	
	//★★★★★★1.duration
	/*chrono::hours h(1);
	chrono::minutes m(2);
	chrono::seconds s(3);
	chrono::milliseconds ms(4);
	chrono::microseconds mcs(5);
	chrono::nanoseconds ns(6);
	cout << h.count() << endl;
	cout << m.count() << endl;
	cout << s.count() << endl;*/

	//★★★★★★2.clocks(system_clock,steady_clock,high_resolution_clock(其实就是前面两个的别名））
	/*chrono::system_clock::time_point t1=chrono::system_clock::now();
	Sleep(100);
	chrono::system_clock::time_point t2 = chrono::system_clock::now();
	cout << "t2-t1=" << (t2 - t1).count() << endl;*/
	//system_clock和std::put_time结合使用
	/*auto t = chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	cout << std::put_time(std::localtime(&t), "%Y-%m-%d %X") << endl;*/

	//★★★★★★3.time point
	/*time_point<system_clock, days_type> today = time_point_cast<days_type>(system_clock::now());
	cout << today.time_since_epoch().count() << endl;*/

	//测试一下
	/*Timer t;
	Sleep(1000);
	cout << t.elapsed_nano() << endl;
	cout << t.elapsed_micro() << endl;
	cout << t.elapsed() << endl;
	cout << t.elapsed_seconds() << endl;
	cout << t.elapsed_minutes() << endl;
	cout << t.elapsed_hours() << endl;*/
	return 0;
}