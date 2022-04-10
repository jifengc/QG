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
                    printf("树初始化成功！\n");
                    system("pause"); 
                }
                break;
            }
            case 2:
            {
                printf("请输入一个整数：");
                scanf("%d",&value);
                if (BST_insert(&a,value))
                {
                    printf("插入成功！\n");
                    system("pause"); 
                }else{
                    printf("插入失败！\n");
                    system("pause"); 
                }
                break;
            }
            case 3:
            {
               printf("请输入要删除的数字: ");
               scanf("%d",&value);
               BST_delete(&a,value);
                break;
            }
            case 4:
            {
               printf("请输入要查找的数字：");
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
                printf("递归前序遍历:");
                if (!BST_preorderR(&a,visit))
                {
                    printf("遍历失败");
                    system("pause"); 
                }
                system("pause"); 
                break;
            }
            case 6:
            {
               printf("迭代前序遍历:");
               BST_preorderI(&a,visit);
               system("pause"); 
                break;
            }
            case 7:
            {
            	printf("递归中序遍历:");
               BST_inorderR(&a,visit);
               system("pause"); 
                break;
            }
            case 8:							
            {
               printf("迭代中序遍历:");
               BST_inorderI(&a,visit);
                break;
            }
            case 9:
            {
               printf("递归后序遍历:");
               BST_postorderR(&a,visit);
               system("pause"); 
                break;
            }
            case 10:
            {
            	printf("迭代后序遍历:");
            	BST_postorderI(&a,visit);
            	system("pause"); 
               break;
            }
            case 11:
            {
               printf("层序遍历:");
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
                printf("请重新输入数字!(1-12)\n");
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
    	
    printf("                                          [[       |   【二叉查找树ADT】 |      ]]\n");
    	
    printf("                                          [[       |                     |      ]]\n");

    printf("                                          [[       |    【菜单/menu】    |      ]]\n");
    	
    printf("                                          [[       |                     |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  1 初始化树         |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  2 插入数字         |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  3 删除数字         |      ]]\n");

    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  4 查找数字         |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    
    printf("                                          [[       |  5 递归前序遍历     |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  6 迭代前序遍历     |      ]]\n");
    	 
	printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  7 递归中序遍历     |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  8 迭代中序遍历     |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");
	
    printf("                                          [[       |  9 递归后序遍历     |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");	
	printf("                                          [[       |  10 迭代后序遍历    |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");	
	printf("                                          [[       |  11层序遍历         |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");	
	printf("                                          [[       |  12退出             |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");	
	printf("                                          [=====================================]");
		
	printf("                                                                                           <<按下相应数字进行选择>>\n");
	printf("\n\n					你的选择是：") ; 
}

