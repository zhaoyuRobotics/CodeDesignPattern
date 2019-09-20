#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QMutex>
#include <QDebug>
#include <singleton.h>
#include <unistd.h>

// 全局锁
//static QMutex G_mutex;

class MyThread : public QThread
{
    Q_OBJECT

public:
    MyThread(quint8 tmp_times){m_times = tmp_times;}
    //~MyThread();

protected:
    void run()
    {
        quint64 tmp_variable = 0;

        for(int i=0;i<10;i++)
        {
            usleep(1000*500);

            //QMutexLocker locker(&G_mutex);

            std::cout << "+++++++++++++++++++++++++++++++" << std::endl;

            tmp_variable = singleton::getInstance()->getMemberVariable();

            qDebug() << "  share data： "<< tmp_variable <<" thread ID: "<<this->currentThreadId()<<" object address: "<<singleton::getInstance()<<endl;

            tmp_variable *= m_times;

            singleton::getInstance()->setMemberVariable(tmp_variable);

            std::cout << "-------------------------------"<<std::endl;
        }
    }

private:
    quint8 m_times; //倍数
};


#endif // MYTHREAD_H
