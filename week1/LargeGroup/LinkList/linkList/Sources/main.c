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
LinkedList getNode(LinkedList h,int n);									//��ȡ��Ӧ�ڵ�
LinkedList createNode();												//����һ���ڵ�
ElemType *e;
int main()
{  
	e=(ElemType)malloc(sizeof(ElemType));								//����һ��int����ָ�룬���������ҵ��˵Ľڵ�����
    menu1();
    if(i==1)															//������1���ɴ�����������
    {  
        system("cls");
    	head=(LinkedList)creat();							//����һ��ͷ���
    	p1=head;						
    	head1=&head;												
    	system("cls");
       TraverseList(head,visit);										//��������������
    menu2();
	}
	else {
	printf("�����������������") ;
	menu1();
	} 
	 
    while(k!=0){
    	menu2();
    	scanf("%d",&k);
    	
		if(k>9&&k<1){
		printf("�������"); continue;	
		} 
	   	switch(k)
		{
			case 1: {
				system("cls");  
				DestroyList(head1); 
				printf("����ɾ���ɹ�\n"); 
				printf("��1���¹���������2�˳�ϵͳ");
				int i=0;
				scanf("%d",&i);
				switch(i)
				{
				 case 1:creat();
				 case 2:printf("��л����֧��"); 
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
			       
				printf("���������ĸ��ڵ�ĺ�����ӽڵ�\n");
				scanf("%d",&a);
				for( j=0;j<a-1;j++)						//ָ���ƶ���Ҫ����Ľڵ�
				{
					p1=p1->next;
				}
				printf("������Ҫ��ӵ�ֵ\n");
				scanf("%d",&b);
				p3->data=b;
			if(InsertList(p1, p3)==SUCCESS){			//���в���ڵ����
			
				printf("���������ʾ\n");
				TraverseList(head,visit);} 				//�������������
				getchar();
				getchar();
				break;
		}
		case 3:{
		system("cls");
		
			printf("����ɾ���ڼ����ڵ�֮��Ľڵ㣺");
	                scanf("%d",&num);								//����λ��
	                if(DeleteList(getNode(head,num),e)==SUCCESS)	//��ȡ��λ�õĵ�ַ������ɾ��
	                	printf("ɾ���ɹ�,��ɾ���Ľڵ�����Ϊ%d\n",*e);
	                else	
						printf("ɾ��ʧ��\n");
				getchar();
				getchar();
	                break;
		}
		case 4:{
			system("cls");
			TraverseList(head,visit);								//��������,���뺯��������ָ���� 
			getchar();
			getchar();
			break;
		}
		case 5:{
		system("cls");
		ElemType a=0;
		LinkedList p2;
		p2=p1;
		printf("��������Ҫ�ҵ�����");
			scanf("%d",&a); 
		 	SearchList(p2, a);									//�������ݣ�Ѱ�Ҹýڵ�
		 	int i=1;
		 	while(p1->data!=a)
		 	{
		 		i++;
		 		p1=p1->next;
			 }
		 	printf("�ҵ����ǵ�%d���ڵ������",i);
			getchar();
			getchar();
			break;
		}
		case 6:{
		system("cls");
			LinkedList *L;
			L=&p1;
		if(	ReverseList(L)==SUCCESS)								//����ͷ��㣬���з�ת 
		{   
			printf("��ת���"); 
		}
			
				getchar();
				getchar();
				break;
		}
		case 7:{
			system("cls");
			if(IsLoopList(p1)==SUCCESS)
			{
				printf("������ɻ�");
			}else printf("�������ɻ�");
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
		    printf("���ҵ��м�ڵ��ָ��\n");
		    printf("�м�λ��ָ����ָ��ֵΪ=%d",p1->next->data);
		  	getchar();
		  	getchar();
		  	break;
		}
		case 0:exit(0);
		}
	}  

	return 0;
}

LinkedList creat()				//�������д������� 
{
	LinkedList head;
	LinkedList p1, p2;
	int i;
	int n = 0;
	printf("��������Ҫ�����Ľڵ����:\n");
	scanf("%d",&i);
	printf("\n�������1�����ݣ�"); 
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
		printf("�������%d������: ",n+1);
		
		scanf("%d", &p1->data);

	}

	p2->next = p1;
	p1->next=NULL;
	return head;
}

void menu1()
{
	printf("\n\n\n\n\n\n\n\n\n                             ���ȴ���һ������\n\n");
	printf("                         ����1����ͷ��㲢��ʼ�洢����");
	scanf("%d",&i);
}
void menu2()
{
	

    system("cls"); 
    system("color 06");
	printf("\n\n                                          [=====================================]\n");
    printf("                                          [[------------------------------------]]\n");
    	
    printf("                                          [[       |                     |      ]]\n");
    	
    printf("                                          [[       |   ������ѡ��      |      ]]\n");
    	
    printf("                                          [[       |                     |      ]]\n");

    printf("                                          [[       |    ���˵�/menu��    |      ]]\n");
    	
    printf("                                          [[       |                     |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  1 ɾ������         |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  2 ����������ӽڵ� |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  3 ɾ���ڵ�         |      ]]\n");

    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  4 ��������         |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    
    printf("                                          [[       |  5 ���ҽڵ�         |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  6 ��������       |      ]]\n");
    	 
	printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  7 �жϳɻ�         |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  8 ����ż�ڵ㽻��   |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  9 �ҵ��м�ڵ�     |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");
	
	printf("                                          [[       |  0 �˳�ϵͳ         |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");
    	
	printf("                                          [=====================================]");
		
	printf("                                                                                           <<������Ӧ���ֽ���ѡ��>>\n");
	printf("\n\n					���ѡ���ǣ�") ; 
}
LinkedList getNode(LinkedList h,int n)			//��ȡ��Ҫ�õ��Ľڵ�
{
    LinkedList p = h;
 	int i;
	if(n<1) return NULL;
    for( i = 1;i < n;i++)
    {
        p = p->next;							//��ָ��ָ��Ҫɾ�����Ǹ��ڵ� 
        if(i < n-1 && p->next == NULL)			//�����������Ȼû��
            return NULL;
    }

    return p;
}

LinkedList createNode()							//����һ���½ڵ�
{
    LinkedList q;
    q = (LinkedList)malloc(sizeof(LNode));
    printf("��������Ҫ��������ݣ�");
    scanf("%d",q->data);
    return q;
}


