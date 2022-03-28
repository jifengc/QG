#include"LQueue.h"
#include"LQueue.c"
#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
void createtemp();
LQueue Q;
int choise=0; 
void *e;
int i=1;
void stringcopy(void* a,void* b, int size){
	int i;
    for( i = 0 ; i < size ; i ++){
        ((char*)a)[i] = ((char*)b)[i];
    }
}


int main()
{
	e=(void *)malloc(sizeof(double));
	while(1)
	{
		createtemp();
		system("cls");
		switch(choise)
		{
			case 1:{
				InitLQueue(&Q);
				printf("初始化队列成功\n");
				system("pause");
				break;
			}
			case 2:{
				DestoryLQueue(&Q);
				printf("销毁队列成功\n");
				system("pause");
				break;
			}
			case 3:{
				if(IsEmptyLQueue(&Q)==TRUE)
				{
					printf("队列为空\n");
				}
				system("pause");
				break;
			}
			case 4:{
				GetHeadLQueue(&Q, e);
				system("pause");
				break;
			}
			case 5:{
				if(LengthLQueue(&Q)!=FALSE)
				{
					printf("队列长度：%d\n",LengthLQueue(&Q));
				}
				system("pause");
				break;
			}
			case 6:{
				int t;
				printf("你想使用哪种类型？:\n");
                printf("1. 整型 2. 字符型 3. 浮点型 4. 字符串\n");
                scanf("%d", &t);
                printf("请输入数据\n");
                switch(t)
                {
                	case 1:{
                		int a;
			            scanf("%d", &a);
			             
			            EnLQueue(&Q, &a);
			            datatype[i]='a';
			            i++;
						break;
					}
					case 2:{
						fflush(stdin);
						char b;
						scanf("%c",&b);
						EnLQueue(&Q, &b);
						datatype[i]='b';
			            i++;
						break;
					}
					case 3:{
						double c;
						scanf("%lf",&c);
						EnLQueue(&Q, &c);
						datatype[i]='c';
			            i++;
						break;
					}
					case 4:{
						fflush(stdin);
						char d[20];
						scanf("%s", d);
						EnLQueue(&Q, d);
						datatype[i]='d';
			            i++;
						break;
					}
				}
				system("pause");
				break;
			}
			case 7:{
				DeLQueue(&Q);
				system("pause");
				break;
			}
			case 8:{
				ClearLQueue(&Q);
				system("pause");
				break;
			}
			case 9:{
				TraverseLQueue(&Q,LPrint);
				system("pause");
				break;
			}
			case 0:{
				exit(0);
				break;
			}
		}
	}
	return 0;
}
 
void createtemp()
{
	system("cls"); 
    system("color 06");
	printf("\n\n                                          [=====================================]\n");
    printf("                                          [[------------------------------------]]\n");
    	
    printf("                                          [[       |                     |      ]]\n");
    	
    printf("                                          [[       |   【队列选择】       |      ]]\n");
    	
    printf("                                          [[       |                     |      ]]\n");

    printf("                                          [[       |    【菜单/menu】    |      ]]\n");
    	
    printf("                                          [[       |                     |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  1 初始化队列       |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  2 销毁队列         |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  3 检查队列是否为空 |      ]]\n");

    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  4 查看队头元素     |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    
    printf("                                          [[       |  5 确定队列长度     |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  6 入队操作         |      ]]\n");
    	 
	printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  7 出队操作         |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  8 清空队列         |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");
	
    printf("                                          [[       |  9 遍历队列         |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");
	printf("                                          [[       |  0 退出             |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");	
	printf("                                          [=====================================]");
		
	printf("                                                                                           <<按下相应数字进行选择>>\n");
	printf("\n\n					你的选择是：") ; 

	scanf("%d",&choise);
	
	
}
