#include <iostream>
#include <iomanip>
#include <cstring>
#include <BookWork.h>

using namespace std;

//控制层：流程控制函数的具体实现

//实现业务1：初始化数据
void toInitialBook(int n)
{
    BookWork bw;      //生成业务对象
    bw.initialBook(n); //调用业务方法，实现业务
}

//实现业务2：显示所有图书
void toQueryAllBook()
{
    BookWork bw; //生成业务对象
    bw.queryAllBook(); //调用业务方法，实现业务
}

//实现业务3：查找图书
void toQueryBookByString()
{
    string findStr = ""; //信息字符串
    cout<<"请输入查找的图书信息：";
    cin>>findStr;  //输入

    BookWork bw;  //生成业务对象
    bw.queryBookByString(findStr); //调用业务方法，实现业务
}

//实现业务4：插入图书
void toInsertBook()
{
    //1:定义字符串
    string titleStr[5]={"图书编号：","图书名称：","图书作者：","图书价格：","出版社名："}; //字段信息
    string valueStr[5]={"","","","",""}; //字段值
    char mBookid[50],mBookname[50],mAuthor[50],mPublish[50]; //字段变量
    double mPrice;

    //2:输入字段值
    cout<<"请输入图书的信息："<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<titleStr[i];
        cin>>setw(50)>>valueStr[i];
    }

    //3:处理字段值，将输入值保存到字段变量
    strcpy(mBookid,valueStr[0].c_str());  //string要转char*
    strcpy(mBookname,valueStr[1].c_str());
    strcpy(mAuthor,valueStr[2].c_str());
    strcpy(mPublish,valueStr[4].c_str());
    mPrice = atof(valueStr[3].c_str());   //string转double

    //4:创建并实例化对象
    Book book(mBookid,mBookname,mAuthor,mPrice,mPublish); //实例化对象

    //5:生成业务对象，并调用业务方法
    BookWork bw;
    bool insertFlag = bw.insertBook(book);
    if (insertFlag==true)
        cout<<endl<<"插入图书成功!"<<endl;
    else
        cout<<endl<<"插入图书失败!"<<endl;
}

//实现业务5：更新图书
void toUpdateBook()
{
    //1:输入要修改的图书编号
    string findBookid = "";
    cout<<"请输入要修改的图书编号：";
    cin>>findBookid;

    //2:定位图书
    BookWork bw;  //生成业务对象
    int bookPos  = bw.tellBookPosition(findBookid); //调用业务方法，实现业务

    //3:修改记录
    if(bookPos>=0)
    {
        //找到记录
        //3.1:输入图书信息
        char mBookid[50],mBookname[50],mAuthor[50],mPublish[50]; //字段变量
        double mPrice;
        cout<<"输入新的图书信息"<<endl;
        cout<<"图书编号：";
        cin>>setw(50)>>mBookid;
        cout<<"图书名称：";
        cin>>setw(50)>>mBookname;
        cout<<"图书作者：";
        cin>>setw(50)>>mAuthor;
        cout<<"图书价格：";
        cin>>setw(50)>>mPrice;
        cout<<"出版社名：";
        cin>>setw(50)>>mPublish;

        //3.2:创建并实例化对象
        Book book(mBookid,mBookname,mAuthor,mPrice,mPublish); //实例化对象

        //3.3:调用业务方法，实现修改
        bool updateFlag = bw.updateBook(book,bookPos);
        if(updateFlag==true)
        {
            cout<<endl<<"图书修改成功！";
        }
        else
        {
            cout<<endl<<"图书修改失败!";
        }
    }
    else
    {
        //没找到记录
        cout<<endl<<"图书不存在，修改失败！"<<endl;
    }
}

//实现业务6：删除图书
void toDeleteBook()
{
    //1:输入要删除的图书编号
    string findBookid = "";
    cout<<"请输入要删除的图书编号：";
    cin>>findBookid;

    //2:定位图书
    BookWork bw;  //生成业务对象
    int bookPos  = bw.tellBookPosition(findBookid); //调用业务方法，实现业务

    //3:删除图书
    if(bookPos>=0)
    {
        //找到记录
        bool deleteFlag = bw.deleteBook(bookPos); //调用业务方法，实现业务
        if(deleteFlag==true)
        {
            cout<<endl<<"图书删除成功！"<<endl;
        }
        else
        {
            cout<<endl<<"图书删除失败！"<<endl;
        }
    }
    else
    {
        //没找到记录
        cout<<endl<<"图书不存在，删除失败！"<<endl;
    }
}

//显示主菜单
void toMainMenu()
{
    system("cls");   //清除屏幕
    cout<<endl;
    cout<<"**************************************"<<endl;
    cout<<"*        欢迎使用图书管理系统        *"<<endl;
    cout<<"*             版本：2021             *"<<endl;
    cout<<"**************************************"<<endl;
    cout<<endl;
    cout<<"      [1] 显示全部图书"<<endl;
    cout<<"      [2] 查找图书"<<endl;
    cout<<"      [3] 插入图书"<<endl;
    cout<<"      [4] 更新图书"<<endl;
    cout<<"      [5] 删除图书"<<endl;
    cout<<"      [6] 初始化全部图书"<<endl;
    cout<<"      [7] 初始化部分图书"<<endl;
    cout<<"      [0] 退出系统"<<endl;
    cout<<endl;
}



