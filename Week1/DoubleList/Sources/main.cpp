#include <iostream>
#include "DoubleList.h"
using namespace std;

//主函数
int main() {
    DuLinkedList head;
    InitList_DuL(&head);
    while (true) {
        cout << "--1.添加 2.插入 3.浏览 4.删除 5.销毁 6.退出 --" << endl;
        int choice;
        cout << "请输入选择" << endl;
        cin >> choice;
        ElemType element;
        switch (choice) {
            case (1):
                cout << "请输入要添加的元素" << endl;
                cin >> element;
                AddList_DuL(&head, element);
                break;
            case (2):
                cout << "结点插入的方法：1-在指定结点前插入 2-在指定结点后插入" << endl;
                int method, address;
                cout << "请输入结点插入的方法-" << endl;
                cin >> method;
                switch (method) {   //选择插入的方法
                    case (1):
                        cout << "请输入结点的位置："<<endl;
                        cin >> address;
                        DuLNode *point;
                        Status situation;
                        situation=FindNode(&head, address, &point);
                        if (situation == ERROR || point == NULL) {    //调用函数，判断指定结点是否存在
                            cout << "该结点不存在" << endl;
                            break;
                        } else {
                            DuLNode *q;
                            q = new DuLNode;
                            cout << "请输入新结点存放的数据-" << endl;
                            int num;
                            cin >> num;
                            q->data = num;
                            InsertBeforeList_DuL(point, q);     //在point结点前插入q结点
                            break;
                        }
                    case (2):
                        cout << "请输入结点的位置："<<endl;
                        cin >> address;
                        DuLNode *point_;
                        FindNode(&head, address, &point_);
                        if (FindNode(&head, address, &point_) == ERROR || point_ == NULL) {     //判断结点是否存在
                            cout << "该结点不存在" << endl;
                            break;
                        }
                        else {
                            DuLNode *q_;
                            q_ = new DuLNode;    //创建新结点
                            cout << "请输入新结点存放的数据-" << endl;
                            int num;
                            cin >> num;
                            q_->data = num;
                            cout << "数据已存进新结点" << endl;
                            InsertAfterList_DuL(point_, q_);     //在point结点后插入q结点
                            break;
                        }
                    default:
                        cout << "错误，请重新输入" << endl;
                        break;
                }
                break;
            case (3):
            	cout<<endl;
                void (*point)(ElemType c);
                point = visit;
                TraverseList_DuL(head, point);
                break;
            case (4):
                cout << "注意：删除的结点为指定结点的下一个结点" << endl;
                cout << "请输入指定结点的位置" << endl;
                cin >> address;
                DuLNode *p;
                FindNode(&head, address, &p);
                if (FindNode(&head, address, &p) == ERROR || p == NULL) {    //判断结点是否存在
                    cout << "该结点不存在" << endl;
                    break;
                }
                else {
                    ElemType e;
                    Status condition;
                    condition = DeleteList_DuL(p, &e);
                    if (condition == SUCCESS) {
                        cout << "删除成功" << endl;
                        cout << "所删除结点中的数据为：" << e << endl;
                    } else {
                        cout << "该结点为尾结点,后面无结点可删" << endl;
                        break;
                    }
                }
                break;
            case (5):
                cout << "确定销毁？" << endl;
                cout << "1-确定  2-取消" << endl;
                int number;
                cin >> number;
                if (number == 1) {
                    DestroyList_DuL(&head);
                    cout << "1.初始化链表 2.退出" << endl << "请选择-" << endl;   //销毁之后，要通过初始化链表之后才能进行插入等操作
                    int choice_;
                    cin >> choice_;
                    switch (choice_) {
                        case (1):
                            InitList_DuL(&head);
                            break;
                        case (2):
                            exit(0);
                        default:
                            cout << "错误，请重新输入" << endl;
                    }
                }
                break;
            case (6):
                exit(0);
            default:
                cout << "错误，请重新输入" << endl;
                break;
        }
        system("pause");
	system("cls");
    }
}
