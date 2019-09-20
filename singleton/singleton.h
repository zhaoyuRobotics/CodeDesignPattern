#ifndef SINGLETON_H
#define SINGLETON_H

#include <QObject>
#include <QMutex>
#include <QMutexLocker>
#include <QReadWriteLock>
#include <QReadLocker>
#include <QWriteLocker>

#include <QThread>

#include <time.h>
#include <sys/time.h>
#include <iostream>
#include <stdlib.h>
#include <QDateTime>

class singleton
{
public:
    // 静态成员函数
    static singleton *getInstance();

    // 单例 - 主动释放
    static void DestoryInstance();

    // 写数据
    void setMemberVariable(quint64 m_data);
    
    // 读数据
    quint64 getMemberVariable();

private:
    singleton();
    static singleton *instance;
    static QMutex m_mutex;
    
    // 共享数据读写操作锁
    QReadWriteLock m_readWriteLock;
    QMutex m_testmutex;

    // 共享数据
    quint64 m_sharedata;
};





#endif // SINGLETON_H
