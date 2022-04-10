#include "binary_sort_tree.h"
#include <windows.h>
#include<stdio.h>
#include<stdlib.h>

BinarySortTree a;

void show();
int main()
{
	int choice=0;
	 ElemType value = 0;
    do
    {
        show();
        scanf("%d",&choice);
        system("cls");
        switch (choice)
        {
            case 1:
            {
                if(BST_init(&a)){
                    printf("����ʼ���ɹ���\n");
                    system("pause"); 
                }
                break;
            }
            case 2:
            {
                printf("������һ��������");
                scanf("%d",&value);
                if (BST_insert(&a,value))
                {
                    printf("����ɹ���\n");
                    system("pause"); 
                }else{
                    printf("����ʧ�ܣ�\n");
                    system("pause"); 
                }
                break;
            }
            case 3:
            {
               printf("������Ҫɾ��������: ");
               scanf("%d",&value);
               BST_delete(&a,value);
                break;
            }
            case 4:
            {
               printf("������Ҫ���ҵ����֣�");
               scanf("%d",&value);
               if(BST_search(&a,value)==false)
               {
               	printf("What you're looking for doesn't exist\n");
               	system("pause"); 
			   }
                break;
            }
            case 5:
            {
                printf("�ݹ�ǰ�����:");
                if (!BST_preorderR(&a,visit))
                {
                    printf("����ʧ��");
                    system("pause"); 
                }
                system("pause"); 
                break;
            }
            case 6:
            {
               printf("����ǰ�����:");
               BST_preorderI(&a,visit);
               system("pause"); 
                break;
            }
            case 7:
            {
            	printf("�ݹ��������:");
               BST_inorderR(&a,visit);
               system("pause"); 
                break;
            }
            case 8:							
            {
               printf("�����������:");
               BST_inorderI(&a,visit);
                break;
            }
            case 9:
            {
               printf("�ݹ�������:");
               BST_postorderR(&a,visit);
               system("pause"); 
                break;
            }
            case 10:
            {
            	printf("�����������:");
            	BST_postorderI(&a,visit);
            	system("pause"); 
               break;
            }
            case 11:
            {
               printf("�������:");
               BST_levelOrder(&a,visit);
               system("pause"); 
                break;
            }
            case 12:
            {
                break;
            }                                                                          
            default:
            {
                printf("��������������!(1-12)\n");
                break;
            }
        }
    } while (choice != 12);
    return 0;

}

void show(){
	system("cls"); 
    system("color 06");
	printf("\n\n                                          [=====================================]\n");
    printf("                                          [[------------------------------------]]\n");
    	
    printf("                                          [[       |                     |      ]]\n");
    	
    printf("                                          [[       |   �����������ADT�� |      ]]\n");
    	
    printf("                                          [[       |                     |      ]]\n");

    printf("                                          [[       |    ���˵�/menu��    |      ]]\n");
    	
    printf("                                          [[       |                     |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  1 ��ʼ����         |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  2 ��������         |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  3 ɾ������         |      ]]\n");

    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  4 ��������         |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    
    printf("                                          [[       |  5 �ݹ�ǰ�����     |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  6 ����ǰ�����     |      ]]\n");
    	 
	printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  7 �ݹ��������     |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  8 �����������     |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");
	
    printf("                                          [[       |  9 �ݹ�������     |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");	
	printf("                                          [[       |  10 �����������    |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");	
	printf("                                          [[       |  11�������         |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");	
	printf("                                          [[       |  12�˳�             |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");	
	printf("                                          [=====================================]");
		
	printf("                                                                                           <<������Ӧ���ֽ���ѡ��>>\n");
	printf("\n\n					���ѡ���ǣ�") ; 
}

