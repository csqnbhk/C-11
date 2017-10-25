/**************************************************************************************

               function:该文件用来测试一下"深入应用C++11代码优化与工程级应用"第五章，
			            回顾一下所学的知识点。做个记录。(全部内容均来自该书）
			   author：Demon
			   Time:2017/10/25
****************************************************************************************/
#include<iostream>
#include<windows.h>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<atomic>
#include<list>
using namespace std;
//int Max(int a,int b)
//{
//	std::this_thread::sleep_for(std::chrono::seconds(3));//线程睡眠
//	if (a > b)
//	{
//		cout << "a>b" << endl;
//		return a;
//	}
//	else
//	{
//		cout << "b>a" << endl;
//		return b;
//	}
//	
//}

///////std::mutex使用

//std::mutex g_lock;
//void func()
//{
//	g_lock.lock();
//	cout << "enter thread,thread id:" << std::this_thread::get_id() << endl;
//	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
//	g_lock.unlock();
//}

//////std::recursive_mutex（递归锁，同一线程可多次获取该互斥量）

//struct Complex
//{
//	std::recursive_mutex mutex;
//	int i;
//	Complex() :i(0) {}
//
//	void mul(int x)
//	{
//		
//		std::lock_guard<std::recursive_mutex> lock(mutex);
//		cout << "mul()运行" << endl;
//		i *= x;
//	}
//	void div(int x)
//	{
//		std::lock_guard<std::recursive_mutex> lock(mutex);
//		cout << "div()运行" << endl;
//		i /= x;
//	}
//	void both(int x, int y)
//	{		
//    	std::lock_guard<std::recursive_mutex> lock(mutex);
//		cout << "both运行" << endl;
//		mul(x);
//		div(y);
//	}
//};

//////std::time_mutex 带超时锁的使用

//std::timed_mutex t_mutex;
//void work()
//{
//	std::chrono::milliseconds timeout(100);
//	while (true)
//	{
//		if (t_mutex.try_lock_for(timeout))
//		{
//			cout << std::this_thread::get_id() << ":do work with the mutex" << endl;
//			std::chrono::milliseconds sleepDuration(3000);
//			std::this_thread::sleep_for(sleepDuration);
//			t_mutex.unlock();
//			std::this_thread::sleep_for(sleepDuration);
//		}
//		else
//		{
//			cout << std::this_thread::get_id() << ":do work without mutex" << endl;
//			std::chrono::milliseconds sleepDuration(1000);
//			std::this_thread::sleep_for(sleepDuration);
//		}
//
//	}
//
//}

//////互斥量和条件变量的结合使用（同步队列的实现）

//class SyncQueue
//
//{
//public:
//	SyncQueue():m_maxSize(2)
//	{
//		
//	}
//public:
//	void Put(int const &x)
//	{
//		int temp = x;
//		std::unique_lock<std::mutex> locker(m_mutex);
//		m_notFull.wait(locker, [this] { return !this->Full();});
// 		m_queue.push_back(x);
//		cout << "压入数据:" << x << endl;
//		m_notEmpty.notify_one();
//
//    }
//	void Take(int &x)
//	{
//		std::unique_lock<std::mutex> locker(m_mutex);
//		m_notEmpty.wait(locker, [this] { return !m_queue.empty();});
//		x = m_queue.front();
//		m_queue.pop_front();
//		cout << "获取数据:" <<x<< endl;
//		m_notFull.notify_one();
//	}
//
//public:
//	bool Full()
//	{
//		return m_queue.size()==m_maxSize;
//	}
//
//private:
//	std::list<int> m_queue;
//	std::mutex   m_mutex;
//	std::condition_variable m_notEmpty;
//	std::condition_variable m_notFull;
//	int m_maxSize;
//
//};
//
//void PutWork()
//{
//	static int i = 0;
//	while (true)
//	{
//
//		a.Put(i);
//		i++;
//		Sleep(1000);
//	}
//	
//}
//void TakeWork()
//{
//	static int j = 0;
//	while (true)
//	{
//		a.Take(j);
//		Sleep(3000);
//	}
//
//}

//////std::atomic<T> 原子变量

//std::atomic<int> a=0;
//void Add()
//{
//	while (a < 8889999)
//     ++a;
//}

//////std::call_once/once_flag使用

//std::once_flag once;
//void do_once()
//{
//	std::call_once(once, []{ cout << "Called once" << endl;});
//}

int main()
{
	//1.1线程的创建(注意:线程函数要在线程对象的作用域内运行完(此时线程对象没有和线程函数detach），否则会出错）
	/*
	std::thread t(Max, 2, 4);
	cout << "线程ID:" << t.get_id() << endl;
	cout << "CPU核心数:" << std::thread::hardware_concurrency() << endl;
	*/
	//t.join();   //阻塞线程直到线程运行完
	//t.detach();//分离线程对象和线程函数，以后不可以再使用该线程对象去管理线程函数（不希望线程阻塞执行）


	//1.2 互斥量（用于线程同步）,四种

	//sdt::mutex
	//std::timed_mutex
	//std::recursive_mutex
    //std::recursive_mutex

    //////std::mutex 使用
	/*std::thread t1(func);
	std::thread t2(func);
	std::thread t3(func);*/

	//////std::recursive_mutex 使用
	/*
	Complex complex;
	complex.both(12,6);
	*/

	//////std::timed_mutex 带超时锁的使用
	/*
	std::thread t1(work);
	std::thread t2(work
	*/
	


	///////1.3 条件变量（用于线程通信），两种

	//condition_variable     配合std::unique_lock<std::mutex>进行wait
	//condition_variable_any 和任意带有lock，unlock语义的mutex配合使用，比较灵活，但效率比condition_variable较差一点
	
	///////1.4条件变量和互斥量的结合使用（特别注意，一定不要死锁）
	/*
	std::thread t1(PutWork);
	std::thread t2(TakeWork);
	*/

	//////1.5 原子变量的使用（std::atomic<T>)

	//std::thread t1(Add);
	//std::thread t2(Add);
	//t1.join();
	//t2.join();
	//std::cout<< "a=" << a.load() << endl;//(没做线程同步，会导致数据不准确)只是测试
	

	///////1.6 call_once/once_flag 的使用

	/*
	std::thread t1(do_once);
	std::thread t2(do_once);
	std::thread t3(do_once);
	*/

	while (1);
	return 0;
}