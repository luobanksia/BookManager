#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book
{
    public:
        Book(); //无参构造
        Book(char[],char[],char[],double,char[]); //有参构造

        //setter成员函数
        void setBookid(char[]);
        void setBookname(char[]);
        void setAuthor(char[]);
        void setPrice(double);
        void setPublish(char[]);
        //getter成员函数
        char* getBookid();
        char* getBookname();
        char* getAuthor();
        double getPrice();
        char* getPublish();
        //其他成员函数
        void showBook(); //输出一条记录
        string getBookString(); //取得图书信息字符串

        //析构函数
        virtual ~Book();

    private:
        char bookid[50];   //图书编号
        char bookname[50]; //图书名称
        char author[50];   //图书作者
        double price;      //图书价格
        char publish[50];  //出版社名称
};

#endif // BOOK_H
