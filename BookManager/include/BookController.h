#ifndef BOOKCONTROLLER_H_INCLUDED
#define BOOKCONTROLLER_H_INCLUDED

//控制层：业务流程控制函数的定义

void toInitialBook(int=0);         //实现业务1：初始化数据
void toQueryAllBook();        //实现业务2：显示所有图书
void toQueryBookByString();   //实现业务3：查找图书
void toInsertBook();          //实现业务4：插入图书
void toUpdateBook();          //实现业务5：更新图书
void toDeleteBook();          //实现业务6：删除图书
void toMainMenu();            //主菜单

#endif // BOOKCONTROLLER_H_INCLUDED
