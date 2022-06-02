#ifndef BOOKWORK_H
#define BOOKWORK_H

#include <string>
#include <Book.h>

using namespace std;

//业务类

class BookWork
{
    public:
        BookWork();         //无参构造函数

        void initialBook(int=0);   //初始化图书
        void queryAllBook();        //显示所有图书
        void queryBookByString(const string&); //查找图书
        int tellBookPosition(const string&);   //定位图书记录
        bool insertBook(Book);                  //插入图书
        bool updateBook(Book,int);              //更新图书：更新第n条记录
        bool deleteBook(int);                   //删除图书：删除第n条记录
};

#endif // BOOKWORK_H
