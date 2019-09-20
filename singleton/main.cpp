#include <QCoreApplication>
#include <singleton.h>
#include <mythread.h>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyThread *m_thread1 = new MyThread(2);
    MyThread *m_thread2 = new MyThread(3);

    m_thread1->start();
    m_thread2->start();

    while(m_thread1->isRunning())
    {
        while (m_thread2->isRunning()) {
            ;
        }
    }

    // 回收单例资源
    singleton::getInstance()->DestoryInstance();

    return a.exec();
}

