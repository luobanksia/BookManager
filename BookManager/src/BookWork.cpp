#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <BookWork.h>
#include <book.h>

//业务类代码的具体实现

using namespace std;

//无参构造函数
BookWork::BookWork()
{  }

//业务1:初始化图书数据
void BookWork::initialBook(int n)
{
    //1：生成输出文件流
    ofstream fout("book.dat", ios_base::out|ios_base::binary);
    if(!fout.is_open())
    {
        cout<<"打开文件失败！"<<endl;
        fout.close();
        return;
    }

    //2：生成三条记录数
    if(n!=0)
    {
        //2.1：创建图书对象
        Book book;

        //2.2：保存图书信息
        //定义第一本图书
        book.setBookid((char*)"tu001");
        book.setBookname((char*)"C++面向对象程序设计");
        book.setAuthor((char*)"黄宝贵");
        book.setPrice(59);
        book.setPublish((char*)"清华大学出版社");
        fout.write((char*)(&book),sizeof(Book));  //保存第一条记录
        //定义第二本图书
        book.setBookid((char*)"tu002");
        book.setBookname((char*)"Java程序设计");
        book.setAuthor((char*)"刘小军");
        book.setPrice(45.88);
        book.setPublish((char*)"人民邮电出版社");
        fout.write((char*)(&book),sizeof(Book));  //保存第二条记录
        //定义第三本图书
        book.setBookid((char*)"tu003");
        book.setBookname((char*)"数据库系统原理");
        book.setAuthor((char*)"郭有强");
        book.setPrice(35.55);
        book.setPublish((char*)"清华大学出版社");
        fout.write((char*)(&book),sizeof(Book));  //保存第三条记录
    }
    cout<<endl<<"文件初始化成功!"<<endl;

    //3：关闭文件流
    fout.close();
}

//业务2：显示所有的图书
void BookWork::queryAllBook()
{
    //1:输出表头
    cout<<setw(10)<<left<<"图书编号"<<setw(30)<<left<<"图书名称";
    cout<<setw(20)<<left<<"图书作者"<<setw(10)<<left<<"图书价格";
    cout<<setw(20)<<left<<"出版社"<<endl;

    //2:创建输入文件流对象
    ifstream fin("book.dat",ios_base::in|ios_base::binary);
    if(!fin.is_open())
    {
        cout<<"文件打开失败！"<<endl;
        fin.close();
        return;
    }

    //3:循环遍历输出
    //3.1定义信息变量
    Book book;   //生成一本图书（用于保存提取的内容）
    fin.seekg(0,ios_base::end);
    int bookSize = fin.tellg()/sizeof(Book); //求图书数量
    fin.seekg(0,ios_base::beg); //文件位置指针复位

    //3.2遍历输出
    for(int i=0;i<bookSize;i++)
    {
        fin.read((char*)&book,sizeof(Book)); //提取一条记录
        book.showBook(); //输出一条记录
    }
    cout<<endl;

    //4:关闭文件
    fin.close();
}

//业务3：查找图书
void BookWork::queryBookByString(const string& findStr)
{
    //1：输出表头
    cout<<setw(10)<<left<<"图书编号"<<setw(30)<<left<<"图书名称";
    cout<<setw(20)<<left<<"图书作者"<<setw(10)<<left<<"图书价格";
    cout<<setw(20)<<left<<"出版社"<<endl;

    //2：创建输入文件流对象
    ifstream fin("book.dat",ios_base::in|ios_base::binary);
    if(!fin.is_open())
    {
        cout<<"文件打开失败！"<<endl;
        fin.close();
        return;
    }

    //3：计算图书记录数
    fin.seekg(0,ios_base::end); //文件指针位置定位到文件尾
    int bookSize = fin.tellg()/sizeof(Book); //计算图书记录数量
    fin.seekg(0,ios_base::beg);              //文件位置指针复位

    //4：循环遍历查找
    if(bookSize>0)
    {
        //文件有内容、有数据
        Book book;   //生成一本图书，用于保存提取的内容
        string bookString = (char*)""; //图书的记录信息字符串
        std::size_t found;       //字符串查找的位置
        bool foundFlag = false;  //查找标记变量

        //循环遍历每条图书记录
        for(int i=0;i<bookSize;i++)
        {
            //提取数据
            fin.read((char*)&book,sizeof(Book)); //提取一条记录
            bookString = book.getBookString();    //取得信息字符串

            //查找信息
            found = bookString.find(findStr);

            //查找判断
            if(found!=string::npos)
            {
                book.showBook();  //输出图书记录
                foundFlag = true; //更改标记变量
            }
        }
        if(foundFlag==false) cout<<endl<<"查无此书!!!"<<endl;
        else cout<<endl;
    }
    else
    {
        //文件没数据
        cout<<endl<<"文件没数据，不能查找图书！"<<endl;
    }

    //5：关闭文件
    fin.close();
}

//业务4：插入图书
bool BookWork::insertBook(Book book)
{
    //1：生成输出文件流
    ofstream fout;
    fout.open("book.dat",ios_base::app|ios_base::binary); //打开文件（以追加方式打开文件）
    if(!fout.is_open())
    {
        cout<<"打开文件失败！"<<endl;
        fout.close();
        return false;
    }

    //2：写入保存到文件
    fout.write((char*)&book,sizeof(Book)); //写入文件

    //3：关闭文件
    fout.close();
    return true;
}

//业务5：更新图书
bool BookWork::updateBook(Book book,int bookPos)
{
    //1：生成输出文件流
    fstream finout;  //不能使用ofstream对象，因为该对象打开关联文件时，会清空文件内容
    finout.open("book.dat",ios_base::in|ios_base::out|ios_base::binary); //打开文件(可读成文件流）
    if(!finout.is_open())
    {
        cout<<"打开文件失败！"<<endl;
        finout.close();
        return false;
    }

    //2：记录定位，并写入(修改)文件
    finout.seekp(bookPos*sizeof(Book),ios_base::beg);  //文件位置指针定位到目标记录
    finout.write((char*)&book,sizeof(Book));      //写入文件

    //3：关闭文件
    finout.close();
    return true;
}

//业务6：删除图书
bool BookWork::deleteBook(int bookPos)
{
    //1：生成输入输出文件流
    ofstream fout;
    fout.open("booktemp.dat",ios_base::out|ios_base::binary); //booktemp.dat：临时文件
    ifstream fin;
    fin.open("book.dat",ios_base::in|ios_base::binary); //打开文件

    if(!fout.is_open() || !fin.is_open())
    {
        cout<<"打开文件失败！"<<endl;
        fout.close();
        fin.close();
        return false;
    }

    //2：计算图书记录数
    fin.seekg(0,ios_base::end);
    int bookSize = fin.tellg()/sizeof(Book);  //图书数量
    fin.seekg(0,ios_base::beg);    //文件位置指针复位

    //3：记录定位，删除记录
    Book book; //生成图书，保存提取的内容
    for(int i=0;i<bookSize;i++)
    {
        fin.read((char*)(&book),sizeof(Book)); //提取记录
        if(i==bookPos)
        {
            continue; //要删除的记录，不拷贝
        }
        else
        {
            fout.write((char*)(&book),sizeof(Book)); //写记录
        }
    }

    //4：关闭文件
    fout.close();
    fin.close();

    //5：把临时文件的内容重新复制到正式文件
    fout.open("book.dat",ios_base::out|ios_base::binary); //打开文件
    fin.open("booktemp.dat",ios_base::in|ios_base::binary); //打开文件
    for(int i=0;i<bookSize-1;i++)
    {
        fin.read((char*)(&book),sizeof(Book)); //提取记录
        fout.write((char*)(&book),sizeof(Book)); //写记录
    }
    fout.close();
    fin.close();

    return true;
}

//业务7：图书记录定位
 int BookWork::tellBookPosition(const string& mBookid)
 {
    //1:创建输入文件流
    ifstream fin("book.dat",ios_base::in|ios_base::binary);
    if(!fin.is_open())
    {
        cout<<"文件打开失败！"<<endl;
        fin.close();
        return -1; //返回值为负：说明图书不存在
     }

    //2:统计图书记录数
    fin.seekg(0,ios_base::end);  //文件位置指针定位到文件尾
    int bookSize = fin.tellg()/sizeof(Book);  //计算图书记录数量
    fin.seekg(0,ios_base::beg);  //文件位置指针复位

    //3:循环遍历定位
    int bookPos = -1;   //图书记录位置（默认值为负，图书不存在）
    Book book;          //生成一本图书，用于保存提取的内容
    string bookString = (char*)""; //图书的记录信息字符串

    for(int i=0;i<bookSize;i++)
    {
        fin.read((char*)(&book),sizeof(Book)); //提取一条记录
        bookString = (book.getBookString()).substr(0,5); //通过图书记录信息字符串，取得图书编号
        if(bookString.compare(mBookid)==0)
        {
            //找到
            bookPos = i; //保存位置
            break;       //中止循环
        }
     }

     //4:关闭文件
     fin.close();
     return bookPos; //返回记录位置
 }



