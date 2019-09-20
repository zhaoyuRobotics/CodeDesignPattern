#include "singleton.h"
#include "QDebug"

/*****************************************************************************************************************
-File name    : 单例模式(参照:https://zhuanlan.zhihu.com/p/33102022)
-Author       : 赵宇
-Time         : 2018.07.04
-
-Description  :
-             <1> static修饰的数据成员和成员函数(称为静态数据成员和静态成员函数),它们不会像普通数据成员一样每一个对象都有一份，所有该类的对象共享一个static数据成员或成员函数
-                 (静态共享:因为只在静态区存储唯一的值)
-
-             <2> static修饰的类成员属于类，不属于对象.因此static类成员函数是没有this指针的，this指针是指向本对象的指针。正因为没有this指针，所以static类成员函数
-                 不能访问非static的类成员，只能访问 static修饰的类成员.
-
-             <3> 同理，在C++中规定volatile和const不能用来修饰没有this指针的成员(参照:https://blog.csdn.net/alwaysslh/article/details/2246005),所以在程序员小灰
-                 中讲到的(参照:https://zhuanlan.zhihu.com/p/33102022)static前面加volatile也是不能实现的，只能主动规避其存在的线程同时创建问题.
-
-             <4> 利用C++11 中的 atomic 可以规避不同线程同时访问私有数据成员时数据的不同步性(对于多核cpu，线程如果在不同的cpu上，那么他们的缓存文件不同可能导致最后的读取数据不同)
-
-             <5> static修饰的变量先于对象存在，所以static修饰的变量要在类外初始化(类型 类名：：变量名 = 值)
-
-
-
********************************************************************************************************************/



//在类中声明static变量或者函数时，初始化时使用作用域运算符来标明它所属类
singleton* singleton::instance = NULL;

//QMutex::Recursive，在这个模式下，一个线程可以多次锁同一个互斥量。需要注意的是，调用lock()多少次锁，就必须相应的调用unlock()一样次数解锁。
//QMutex::NonRecursive(默认)，在这个模式下，一个线程只能锁互斥量一次。
QMutex singleton::m_mutex(QMutex::Recursive);


singleton *singleton::getInstance()
{
    if(instance == NULL)
    {
        // locker 是局部变量，在离开函数作用域时，mutex肯定会被解锁。
        QMutexLocker locker(&m_mutex);
        if(instance == NULL)
        {
            std::cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&  create" <<std::endl;
            instance = new singleton();
        }
    }
    return instance;
}






void singleton::DestoryInstance()
{
    if (instance != NULL)
    {
        // locker 是局部变量，在离开函数作用域时，mutex肯定会被解锁。
        QMutexLocker locker(&m_mutex);
        if (instance != NULL)
        {
            std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  delete" <<std::endl;
            delete instance;
            instance = NULL;
        }
    }
}


/**
 * @brief 共享数据 写
 *
 *
 *
 *
 */
void singleton::setMemberVariable(quint64 m_data)
{
//    QDateTime current_date_time =QDateTime::currentDateTime();
//    QString current_date =current_date_time.toString("hh:mm:ss.zzz");
//    std::cout  <<"  write time： "<< current_date.toStdString() << std::endl;

    struct timeval stCurTime2;
    gettimeofday(&stCurTime2, NULL);

    /** m_readWriteLock 锁在函数结束后释放 **/
    //QWriteLocker locker(&m_readWriteLock);
    QMutexLocker locker(&m_testmutex);
    std::cout << "Write time: " << stCurTime2.tv_sec << "s, " << stCurTime2.tv_usec << "us" <<"  thread id： "<<QThread::currentThreadId()<< std::endl;
    m_sharedata = m_data;
}




/**
 * @brief 共享数据 读
 * QreadWriteLock是一个读写锁，主要用来同步保护需要读写的资源
 * QreadWriteLock 比 QMutex效率高的方面在于：当你想多个读线程可以同时读取资源，
 * 但是只能有一个写线程操作资源，而其他线程必须等待写线程完成时，这时候用这个读写锁就很有用了。
 *
 */
quint64 singleton::getMemberVariable()
{
//    QDateTime current_date_time =QDateTime::currentDateTime();
//    QString   current_date =current_date_time.toString("hh:mm:ss.zzz");
//    std::cout <<"  read time： "<< current_date.toStdString() <<std::endl;

   struct timeval stCurTime2;
   gettimeofday(&stCurTime2, NULL);

   // m_readWriteLock 锁在函数结束后释放
   //QReadLocker locker(&m_readWriteLock);
   QMutexLocker locker(&m_testmutex);
   std::cout << "Read time: " << stCurTime2.tv_sec << "s, " << stCurTime2.tv_usec << "us" <<"  thread id： "<<QThread::currentThreadId()<< std::endl;
   return m_sharedata;
}








singleton::singleton()
{
    m_sharedata = 1;
}

