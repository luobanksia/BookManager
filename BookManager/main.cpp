#include <iostream>
#include <BookController.h>

using namespace std;

int main()
{

    char choice;
    while(choice!='0')
    {
        toMainMenu();//显示主菜单
        cout<<"请选择菜单：";
        cin>>choice; //输入值
        cout<<endl;

        switch(choice)
        {
        case '1':
            toQueryAllBook(); break;      //显示全部图书
        case '2':
            toQueryBookByString(); break;  //查找图书
        case '3':
            toInsertBook(); break;         //插入图书
        case '4':
            toUpdateBook(); break;         //更新图书
        case '5':
            toDeleteBook(); break;         //删除图书
        case '6':
            toInitialBook(); break;        //初始化全部图书
        case '7':
            toInitialBook(1); break;       //初始化部分图书
        case '0':
            cout<<"谢谢使用，Bye-Bye!"<<endl; break; //退出系统
        default:
            cout<<"选择错误，重新选择..."<<endl;
        }
        system("pause");
    }
    cout<<endl;

    return 0;
}
