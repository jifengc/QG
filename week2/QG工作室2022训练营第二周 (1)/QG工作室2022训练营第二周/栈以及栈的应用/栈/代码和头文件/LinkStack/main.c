#include<stdio.h>
#include"../head/LinkStack.h"
#include"LinkStack.c"
#include"windows.h"
void menu();
LinkStack *s;
 int count;
 int *length;		//���泤�� 
 ElemType data;		//�������� 
 ElemType *data1;	//�������� 
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
	    		printf("��ʼ��ջ�ɹ�\n");
	    		flag=1;
	    		system("pause");
				break;
			}
			
			
			case 2: { 	isEmptyLStack(s);
			if(flag==0)
			printf("ջδ��ʼ��");
				system("pause");
				break;
			} 
			case 3:{
			getTopLStack(s,e);
			if(flag==0){
				printf("ջδ��ʼ��");
				system("pause");
				break;
			}
			
			
			printf("ջ��������%d\n",*e);
			system("pause");
				break;
			}
			
			case 4:  {
				clearLStack(s);
				if(flag==0){
				printf("ջδ��ʼ��");
				system("pause");
				break;
			}
				printf("���ջ�ɹ�\n");
				
				system("pause");
				break;
			}
			
			
			case 5: 	destroyLStack(s);
			if(flag==0){
				printf("ջδ��ʼ��");
				system("pause");
				break;
			}
				printf("����ջ�ɹ��������³�ʼ��ջ�����˳�����\n");
				flag=0;
				system("pause");
				break;
			
			case 6: LStackLength(s,length);
			if(flag==0){
				printf("ջδ��ʼ��");
				system("pause");
				break;
			}
			printf("��ջ�ĳ�����%d\n",*length); 
			system("pause");
			break;
			
			case 7: printf("������Ҫ��ջ������\n");
			         scanf("%d",&data); 
			   pushLStack(s, data);
			   if(flag==0){
				printf("ջδ��ʼ��");
				system("pause");
				break;
			}
			   printf("��ջ�ɹ�\n");
			   system("pause");
			   break;
			   
			case 8: 	popLStack(s,data1);
			if(flag==0){
				printf("ջδ��ʼ��");
				system("pause");
				break;
			}
				printf("��ջ��Ԫ����%d",*data1);
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
    	
    printf("                                          [[       |   ��ջ��ѡ��      |      ]]\n");
    	
    printf("                                          [[       |                     |      ]]\n");

    printf("                                          [[       |    ���˵�/menu��    |      ]]\n");
    	
    printf("                                          [[       |                     |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  1 ��ʼ��ջ         |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  2 �ж�ջ�Ƿ�Ϊ��   |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  3 �õ�ջ��Ԫ��     |      ]]\n");

    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  4 ���ջ           |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    
    printf("                                          [[       |  5 ����ջ           |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  6 ���ջ����       |      ]]\n");
    	 
	printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  7 ��ջ             |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  8 ��ջ             |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");
	
    printf("                                          [[       |  9 �˳�             |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");	
	printf("                                          [=====================================]");
		
	printf("                                                                                           <<������Ӧ���ֽ���ѡ��>>\n");
	printf("\n\n					���ѡ���ǣ�") ; 

}
