#include <iostream>
#include <iomanip>
#include <cstring>
#include <Book.h>

//无参构造
Book::Book()
{
    strcpy(this->bookid,"");
    strcpy(this->bookname,"");
    strcpy(this->author,"");
    this->price = 0.00;
    strcpy(this->publish,"");
}
//有参构造
Book::Book(char bookid[],char bookname[],char author[],double price,char publish[])
{
    strcpy(this->bookid,bookid);
    strcpy(this->bookname,bookname);
    strcpy(this->author,author);
    this->price = price;
    strcpy(this->publish,publish);
}

//setter方法的实现
void Book::setBookid(char bookid[])
{
    strcpy(this->bookid,bookid);
}
void Book::setBookname(char bookname[])
{
    strcpy(this->bookname,bookname);
}
void Book::setAuthor(char author[])
{
    strcpy(this->author,author);
}
void Book::setPrice(double price)
{
    this->price = price;
}
void Book::setPublish(char publish[])
{
    strcpy(this->publish,publish);
}
//getter方法的实现
char* Book::getBookid()
{
    return bookid;
}
char* Book::getBookname()
{
    return bookname;
}
char* Book::getAuthor()
{
    return author;
}
double Book::getPrice()
{
    return price;
}
char* Book::getPublish()
{
    return publish;
}

//其他成员函数
//输出一条图书记录
void Book::showBook()
{
    cout<<setw(10)<<left<<bookid<<setw(30)<<left<<bookname;
    cout<<setw(20)<<left<<author<<setw(10)<<left<<price;
    cout<<setw(20)<<left<<publish<<endl;
}

//取得一条图书的信息字符串
string Book::getBookString()
{
    //定义信息字符串
    char bookString[200] = "";
    //生成信息字符串
    strcpy(bookString,bookid);
    strcat(bookString,bookname);
    strcat(bookString,author);
    strcat(bookString,publish);
    //返回信息字符串
    return string(bookString);
}

Book::~Book()
{
    //dtor
}
