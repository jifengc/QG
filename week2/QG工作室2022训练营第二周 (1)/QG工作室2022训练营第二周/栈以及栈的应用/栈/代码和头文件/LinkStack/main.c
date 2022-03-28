#include<stdio.h>
#include"../head/LinkStack.h"
#include"LinkStack.c"
#include"windows.h"
void menu();
LinkStack *s;
 int count;
 int *length;		//储存长度 
 ElemType data;		//储存数据 
 ElemType *data1;	//储存数据 
 ElemType *e;
 int a=0;
 int flag=0;
int main()
{
	length=(int *)malloc(sizeof(int)); 
	e=(ElemType *)malloc(sizeof(ElemType));
	data1=(ElemType *)malloc(sizeof(ElemType));
	s=(LinkStack *)malloc(sizeof(LinkStack));
		while(1)
	{  	
	menu();
	scanf("%d",&a);
		switch(a)
		{
			case 1:   {
			initLStack(s);
	    		printf("初始化栈成功\n");
	    		flag=1;
	    		system("pause");
				break;
			}
			
			
			case 2: { 	isEmptyLStack(s);
			if(flag==0)
			printf("栈未初始化");
				system("pause");
				break;
			} 
			case 3:{
			getTopLStack(s,e);
			if(flag==0){
				printf("栈未初始化");
				system("pause");
				break;
			}
			
			
			printf("栈顶数据是%d\n",*e);
			system("pause");
				break;
			}
			
			case 4:  {
				clearLStack(s);
				if(flag==0){
				printf("栈未初始化");
				system("pause");
				break;
			}
				printf("清空栈成功\n");
				
				system("pause");
				break;
			}
			
			
			case 5: 	destroyLStack(s);
			if(flag==0){
				printf("栈未初始化");
				system("pause");
				break;
			}
				printf("销毁栈成功，请重新初始化栈或者退出程序\n");
				flag=0;
				system("pause");
				break;
			
			case 6: LStackLength(s,length);
			if(flag==0){
				printf("栈未初始化");
				system("pause");
				break;
			}
			printf("该栈的长度是%d\n",*length); 
			system("pause");
			break;
			
			case 7: printf("请输入要入栈是数据\n");
			         scanf("%d",&data); 
			   pushLStack(s, data);
			   if(flag==0){
				printf("栈未初始化");
				system("pause");
				break;
			}
			   printf("入栈成功\n");
			   system("pause");
			   break;
			   
			case 8: 	popLStack(s,data1);
			if(flag==0){
				printf("栈未初始化");
				system("pause");
				break;
			}
				printf("出栈的元素是%d",*data1);
				system("pause");
				break;
			        
			case 9: {
				exit(0);  
				break;
			}      
		}
		system("cls");
		
		
	}
	return 0;
}
 
 void menu()
{
	
	system("cls"); 
    system("color 06");
	printf("\n\n                                          [=====================================]\n");
    printf("                                          [[------------------------------------]]\n");
    	
    printf("                                          [[       |                     |      ]]\n");
    	
    printf("                                          [[       |   【栈链选择】      |      ]]\n");
    	
    printf("                                          [[       |                     |      ]]\n");

    printf("                                          [[       |    【菜单/menu】    |      ]]\n");
    	
    printf("                                          [[       |                     |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  1 初始化栈         |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  2 判断栈是否为空   |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  3 得到栈顶元素     |      ]]\n");

    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  4 清空栈           |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    
    printf("                                          [[       |  5 销毁栈           |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  6 检测栈长度       |      ]]\n");
    	 
	printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  7 入栈             |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  8 出栈             |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");
	
    printf("                                          [[       |  9 退出             |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");	
	printf("                                          [=====================================]");
		
	printf("                                                                                           <<按下相应数字进行选择>>\n");
	printf("\n\n					你的选择是：") ; 

}
