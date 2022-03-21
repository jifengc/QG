#include<stdio.h>
#include"linkedList.h"
#include <stdlib.h>
#include<windows.h>
LinkedList creat(); 
void creat1();
void menu1();
void menu2();
int i;
int k=10;
int num=0;
LinkedList p1,head,*head1;
void visit(ElemType e);
LinkedList getNode(LinkedList h,int n);									//获取对应节点
LinkedList createNode();												//创建一个节点
ElemType *e;
int main()
{  
	e=(ElemType)malloc(sizeof(ElemType));								//返回一个int类型指针，用来储存找到了的节点数据
    menu1();
    if(i==1)															//如果输出1，可储存链表数据
    {  
        system("cls");
    	head=(LinkedList)creat();							//创建一个头结点
    	p1=head;						
    	head1=&head;												
    	system("cls");
       TraverseList(head,visit);										//遍历，输出输入的
    menu2();
	}
	else {
	printf("输入错误，请重新输入") ;
	menu1();
	} 
	 
    while(k!=0){
    	menu2();
    	scanf("%d",&k);
    	
		if(k>9&&k<1){
		printf("输入错误"); continue;	
		} 
	   	switch(k)
		{
			case 1: {
				system("cls");  
				DestroyList(head1); 
				printf("链表删除成功\n"); 
				printf("按1重新构建链表，按2退出系统");
				int i=0;
				scanf("%d",&i);
				switch(i)
				{
				 case 1:creat();
				 case 2:printf("感谢您的支持"); 
				} 
					getchar();
					getchar();
				break;
			}
			case 2:   {
				system("cls");
			
				
			      LinkedList p2,p3;
		          int a=0,b=0,j;
			      p3 = (LinkedList)malloc(sizeof(LNode));
			       
				printf("请输入在哪个节点的后面添加节点\n");
				scanf("%d",&a);
				for( j=0;j<a-1;j++)						//指针移动到要插入的节点
				{
					p1=p1->next;
				}
				printf("请输入要添加的值\n");
				scanf("%d",&b);
				p3->data=b;
			if(InsertList(p1, p3)==SUCCESS){			//进行插入节点操作
			
				printf("操作结果显示\n");
				TraverseList(head,visit);} 				//遍历并输出链表
				getchar();
				getchar();
				break;
		}
		case 3:{
		system("cls");
		
			printf("你想删除第几个节点之后的节点：");
	                scanf("%d",&num);								//储存位置
	                if(DeleteList(getNode(head,num),e)==SUCCESS)	//获取该位置的地址，进行删除
	                	printf("删除成功,被删除的节点数据为%d\n",*e);
	                else	
						printf("删除失败\n");
				getchar();
				getchar();
	                break;
		}
		case 4:{
			system("cls");
			TraverseList(head,visit);								//遍历链表,传入函数到函数指针中 
			getchar();
			getchar();
			break;
		}
		case 5:{
		system("cls");
		ElemType a=0;
		LinkedList p2;
		p2=p1;
		printf("请输入你要找的数据");
			scanf("%d",&a); 
		 	SearchList(p2, a);									//传入数据，寻找该节点
		 	int i=1;
		 	while(p1->data!=a)
		 	{
		 		i++;
		 		p1=p1->next;
			 }
		 	printf("找到了是第%d个节点的数据",i);
			getchar();
			getchar();
			break;
		}
		case 6:{
		system("cls");
			LinkedList *L;
			L=&p1;
		if(	ReverseList(L)==SUCCESS)								//传入头结点，进行反转 
		{   
			printf("反转完成"); 
		}
			
				getchar();
				getchar();
				break;
		}
		case 7:{
			system("cls");
			if(IsLoopList(p1)==SUCCESS)
			{
				printf("该链表成环");
			}else printf("该链表不成环");
				getchar();
				getchar();
				break;
		}
		case 8:{
			system("cls");
			 TraverseList(ReverseEvenList(head1),visit);
			 	getchar();
			 	getchar();
			 	break;
		}
		case 9:{
		system("cls");
		    LinkedList p1=FindMidNode(head1);
		    printf("已找到中间节点的指针\n");
		    printf("中间位置指针所指的值为=%d",p1->next->data);
		  	getchar();
		  	getchar();
		  	break;
		}
		case 0:exit(0);
		}
	}  

	return 0;
}

LinkedList creat()				//在链表中储存数据 
{
	LinkedList head;
	LinkedList p1, p2;
	int i;
	int n = 0;
	printf("请输入需要创建的节点个数:\n");
	scanf("%d",&i);
	printf("\n请输入第1个数据："); 
	p1 = p2 = (LinkedList)malloc(sizeof(LNode));
	scanf("%d", &p1->data);
	printf("\n");
	head = NULL;
	while (n<i-1)
	{
		n = n+1;
		if (n == 1)
		{
			head = p1;
		}
		else p2->next = p1;
		p2 = p1;
		p1 = (LinkedList)malloc(sizeof(LNode));
		printf("\n");
		printf("请输入第%d个数据: ",n+1);
		
		scanf("%d", &p1->data);

	}

	p2->next = p1;
	p1->next=NULL;
	return head;
}

void menu1()
{
	printf("\n\n\n\n\n\n\n\n\n                             请先创建一个链表\n\n");
	printf("                         输入1创建头结点并开始存储数据");
	scanf("%d",&i);
}
void menu2()
{
	

    system("cls"); 
    system("color 06");
	printf("\n\n                                          [=====================================]\n");
    printf("                                          [[------------------------------------]]\n");
    	
    printf("                                          [[       |                     |      ]]\n");
    	
    printf("                                          [[       |   【链表选择】      |      ]]\n");
    	
    printf("                                          [[       |                     |      ]]\n");

    printf("                                          [[       |    【菜单/menu】    |      ]]\n");
    	
    printf("                                          [[       |                     |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  1 删除链表         |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  2 在链表中添加节点 |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  3 删除节点         |      ]]\n");

    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  4 遍历链表         |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    
    printf("                                          [[       |  5 查找节点         |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  6 将链表反向       |      ]]\n");
    	 
	printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  7 判断成环         |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  8 将奇偶节点交换   |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  9 找到中间节点     |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");
	
	printf("                                          [[       |  0 退出系统         |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");
    	
	printf("                                          [=====================================]");
		
	printf("                                                                                           <<按下相应数字进行选择>>\n");
	printf("\n\n					你的选择是：") ; 
}
LinkedList getNode(LinkedList h,int n)			//获取需要用到的节点
{
    LinkedList p = h;
 	int i;
	if(n<1) return NULL;
    for( i = 1;i < n;i++)
    {
        p = p->next;							//将指针指向要删除的那个节点 
        if(i < n-1 && p->next == NULL)			//如果遍历完仍然没有
            return NULL;
    }

    return p;
}

LinkedList createNode()							//创建一个新节点
{
    LinkedList q;
    q = (LinkedList)malloc(sizeof(LNode));
    printf("请输入你要插入的数据：");
    scanf("%d",q->data);
    return q;
}


