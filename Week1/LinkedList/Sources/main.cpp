#include <iostream>
using namespace std;
#include "LinkedList.h"

//主函数
int main() {
    LinkedList head;
    InitList(&head);
    while(true){
        cout<<"---1.添加 2.插入 3.浏览 4.删除 5.查找 6.判断空链表 7.销毁 8.退出---"<<endl;
        int choice;
        cout<<"请输入选择-"<<endl;
        cin>>choice;
        int locate,element;
        switch(choice){
            case(1):
                cout<<"请输入要添加的元素（注意：头插法）-"<<endl;
                cin>>element;
                AddList(&head,element);
                break;
            case(2):
                cout<<"注意：插入的位置为指定结点的后面"<<endl;
                cout<<"请输入要插入的结点位置-"<<endl;
                cin>>locate;
                LNode *p;
                Status situation;
                situation = FindNode(&head, locate, &p);
                if (situation == ERROR || p == NULL) {     //判断结点是否存在
                    cout << "该结点不存在" << endl;
                    break;
                }
                else {
                    LNode *q;
                    q = new LNode;
                    cout << "请输入新结点存放的数据-" << endl;
                    int num;
                    cin >> num;
                    q->data = num;
                    cout << "数据已存进新结点" << endl;
                    InsertList(p, q);
                    break;
                }
            case(3):
                void (*point)(ElemType c);
                point=visit;
                TraverseList(head,point);
                break;
            case(4):
                cout << "注意：删除的结点为指定结点的下一个结点" << endl;
                cout<<"请输入指定结点位置-"<<endl;
                cin>>locate;
                LNode *point_;
                FindNode(&head, locate, &point_);
                if (FindNode(&head, locate, &point_) == ERROR || p == NULL) {    //判断结点是否存在
                    cout << "该结点不存在" << endl;
                    break;
                }
                else {
                    ElemType e;
                    Status condition;
                    condition = DeleteList(p, &e);
                    if (condition == SUCCESS) {
                        cout << "删除成功" << endl;
                        cout << "所删除结点中的数据为：" << e << endl;
                    }
                    else {
                        cout << "该结点为尾结点,后面无结点可删" << endl;
                        break;
                    }
                }
                break;
            case(5):
                cout<<"请输入要查找的数据-"<<endl;
                cin>>element;
                SearchList(head,element);
                break;
            case(6):
                EmptyList(head);
                break;
            case(7):
                cout<<"确定销毁？"<<endl;
                cout<<"1-确定  2-取消"<<endl;
                int number;
                cin>>number;
                if(number==1) {
                    DestroyList(&head);
                    cout<<"1.初始化链表 2.退出"<<endl<<"请选择-"<<endl;
                    int choice_;
                    cin>>choice_;
                    switch(choice_){
                        case(1):
                            InitList(&head);
                            break;
                        case(2):
                            exit(0);
                    }
                }
                break;
            case(8):
                exit(0);
            default:
                cout<<"错误，请重新输入"<<endl;
        }
        system("pause");
        system("cls");
    }
}
