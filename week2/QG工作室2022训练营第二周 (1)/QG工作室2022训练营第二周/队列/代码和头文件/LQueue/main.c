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
				printf("��ʼ�����гɹ�\n");
				system("pause");
				break;
			}
			case 2:{
				DestoryLQueue(&Q);
				printf("���ٶ��гɹ�\n");
				system("pause");
				break;
			}
			case 3:{
				if(IsEmptyLQueue(&Q)==TRUE)
				{
					printf("����Ϊ��\n");
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
					printf("���г��ȣ�%d\n",LengthLQueue(&Q));
				}
				system("pause");
				break;
			}
			case 6:{
				int t;
				printf("����ʹ���������ͣ�:\n");
                printf("1. ���� 2. �ַ��� 3. ������ 4. �ַ���\n");
                scanf("%d", &t);
                printf("����������\n");
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
    	
    printf("                                          [[       |   ������ѡ��       |      ]]\n");
    	
    printf("                                          [[       |                     |      ]]\n");

    printf("                                          [[       |    ���˵�/menu��    |      ]]\n");
    	
    printf("                                          [[       |                     |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  1 ��ʼ������       |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  2 ���ٶ���         |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  3 �������Ƿ�Ϊ�� |      ]]\n");

    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  4 �鿴��ͷԪ��     |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    
    printf("                                          [[       |  5 ȷ�����г���     |      ]]\n");
    	
    printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  6 ��Ӳ���         |      ]]\n");
    	 
	printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  7 ���Ӳ���         |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");
    	
    printf("                                          [[       |  8 ��ն���         |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");
	
    printf("                                          [[       |  9 ��������         |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");
	printf("                                          [[       |  0 �˳�             |      ]]\n");
    
	printf("                                          [[       |  ----------------   |      ]]\n");	
	printf("                                          [=====================================]");
		
	printf("                                                                                           <<������Ӧ���ֽ���ѡ��>>\n");
	printf("\n\n					���ѡ���ǣ�") ; 

	scanf("%d",&choise);
	
	
}
