#include<stdio.h>
#include <stdlib.h>
#include"LinkStack.h"
#include"LinkStack.c"
LinkStack *s;
LinkStack *s2;
int compare(char a,char b);
	
int q=1;
int main()
{
	s=(LinkStack *)malloc(sizeof(LinkStack));
	s2=(LinkStack *)malloc(sizeof(LinkStack));
		ElemType *data3;
		ElemType *data4;
		//���� 
		ElemType2 *data5;
		ElemType2 *undata;
		data3=(ElemType *)malloc(sizeof(ElemType));
		data4=(ElemType *)malloc(sizeof(ElemType));
		data5=(ElemType2 *)malloc(sizeof(ElemType2));
		undata=(ElemType2 *)malloc(sizeof(ElemType2));
	initLStack(s);
	initLStack(s2);
	char a[100]={"caijiayang"};
	int i;
		double math;
  printf("------------����һ������������֧�ֶ�λ����-------------\n");
  while(1){
  printf("������Ҫ�����ʽ��\n");
  scanf("%s",a);
	 i=0;
	char k='0';
	double temp2;
	//������ 
	for(i=0;a[i]!='\0';i++)
	{
	    double temp;
	    //����⵽���� ��ֱ����ջ 
		if(a[i]>='0'&&a[i]<='9')
		{
		
			math=(double)(a[i]-'0');
			pushLStack(s,math);
			continue ;
		}
		//����⵽������ 
		if(a[i]=='(')
		{
			//����������ֱ����ջ 
			pushLStack2(s2,a[i]);
			//�������� 
			for(;a[i]!='\0';i++)
			{  
			//���Ϊ������������ 
				if(a[i]==')')
				{
					break;
				}
				if(a[i]>='0'&&a[i]<='9')
			    {
				math=(a[i]-'0');
				//������ջ 
				pushLStack(s,math);
				continue ;
		     	}
		     	//���������� 
		     	if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')
			   {
			   	//���ջ��Ϊ������ 
					if(a[i-2]=='(')
					{
						//������ջ 
						pushLStack2(s2,a[i]);
						continue ;
					}
					//�����ǰ��������ȼ�����ջ������ջ 
					if(compare(a[i],s2->top->data2)==1)
					{
						pushLStack2(s2,a[i]);
						continue;
					}
					
					//�����ǰ��������ȼ�����ջ����ջ����ջ 
					if(compare(a[i],s2->top->data2)==0)
					{
					   	popLStack2(s2,data5);
					   	//�����������������һ������ 
						k=*data5; 
						pushLStack2(s2,a[i]);
					}
					//�����ǰ��������ȼ�����ջ����ջ����ջ
					if(compare(a[i],s2->top->data2)==-1)
					{
						popLStack2(s2,data5);
						k=*data5;
						pushLStack2(s2,a[i]);
					}
			
				}
			switch(k)
		   {
		   	//��ջ�Ľڵ����2 
			case '+':{
				if(s->count>=2)
				{
					//��ջ�������ִ��� 
					popLStack(s,data3);
					popLStack(s,data4);
					//������� 
					temp2=*data3+*data4;
					pushLStack(s,temp2);
					//��ӽ����ջ 
				}
				break;
			}
			case '-':{
				if(s->count>=2)
				{
					popLStack(s,data3);
					popLStack(s,data4);
					//������� 
					temp2=*data4-*data3;
					pushLStack(s,temp2);
					
				}
				break;
			}
			case '*':{
				if(s->count>=2)
				{
					popLStack(s,data3);
					popLStack(s,data4);
					//��� 
					temp2=(*data3)*(*data4);
					pushLStack(s,temp2);
					
				}
				break;
			}
			case '/':{
					if(s->count>=2)
				{
					popLStack(s,data3);
					popLStack(s,data4);
					//��� 
					temp2=(*data4)/(*data3);
					pushLStack(s,temp2);
					
				}
				break;
			}
			default:
				break;
		}
	     	
			}
			//��ջ���������� 
			while(s2->top->data2!='(')
	{
		//ջ��������ջ 
		popLStack2(s2,data5);
		k=*data5; 
			switch(k)
		{
			case '+':{
				if(s->count>=2)
				{
					popLStack(s,data3);
					popLStack(s,data4);
					temp2=(*data3)+(*data4);
					pushLStack(s,temp2);
					
				}
				break;
			}
			case '-':{
				if(s->count>=2)
				{
					popLStack(s,data3);
					popLStack(s,data4);
					temp2=(*data4)-(*data3);
					pushLStack(s,temp2);
					
				}
				break;
			}
			case '*':{
				if(s->count>=2)
				{
					popLStack(s,data3);
					popLStack(s,data4);
					temp2=(*data3)*(*data4);
					pushLStack(s,temp2);
					
				}
				break;
			}
			case '/':{
					if(s->count>=2)
				{
					popLStack(s,data3);
					popLStack(s,data4);
					temp2=(*data4)/(*data3);
					pushLStack(s,temp2);
					
				}
				break;
			}
			default:
				break;
		}	
		}
		//ջ����ջ��ֱ���������� 
		popLStack2(s2,undata);
		continue;
	}
		if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')
		{
			if(s2->count==0)
			{
				
				pushLStack2(s2,a[i]);
				continue ;
			}
			//�����ȼ���ջ���� ����ջ 
			if(compare(a[i],s2->top->data2)==1)
			{
				pushLStack2(s2,a[i]);
				continue;
			}
			//�����ȼ�����ջ����ջ����ջ 
			if(compare(a[i],s2->top->data2)==0)
			{
			   	popLStack2(s2,data5);
			   	//��������� ������һ������ 
				k=*data5;
				pushLStack2(s2,a[i]);
			}
			//�����ȼ�С��ջ����ջ����ջ 
			if(compare(a[i],s2->top->data2)==-1)
			{
				popLStack2(s2,data5);
				//��������� ������һ������
				k=*data5;
				pushLStack2(s2,a[i]);
			}
			
		}
		//�Դ���������������һ������
		switch(k)
		{
			case '+':{
				if(s->count>=2)
				{
					popLStack(s,data3);
					popLStack(s,data4);
					temp2=*data3+*data4;
					pushLStack(s,temp2);
					
				}
				break;
			}
			case '-':{
				if(s->count>=2)
				{
					popLStack(s,data3);
					popLStack(s,data4);
					temp2=*data4-*data3;
					pushLStack(s,temp2);
					
				}
				break;
			}
			case '*':{
				if(s->count>=2)
				{
					popLStack(s,data3);
					popLStack(s,data4);
					temp2=(*data3)*(*data4);
					pushLStack(s,temp2);
					
				}
				break;
			}
			case '/':{
					if(s->count>=2)
				{
					popLStack(s,data3);
					popLStack(s,data4);
					temp2=(*data4)/(*data3);
					pushLStack(s,temp2);
					
				}
				break;
			}
			default:
				break;
		}
		k='0';
	}
	
	while(s2->count!=0)
	{
		popLStack2(s2,data5);
		k=*data5;
			switch(k)
		{
			case '+':{
				if(s->count>=2)
				{
					popLStack(s,data3);
					popLStack(s,data4);
					temp2=(*data3)+(*data4);
					pushLStack(s,temp2);
					
				}
				break;
			}
			case '-':{
				if(s->count>=2)
				{
					popLStack(s,data3);
					popLStack(s,data4);
					temp2=(*data4)-(*data3);
					pushLStack(s,temp2);
					
				}
				break;
			}
			case '*':{
				if(s->count>=2)
				{
					popLStack(s,data3);
					popLStack(s,data4);
					temp2=(*data3)*(*data4);
					pushLStack(s,temp2);
					
				}
				break;
			}
			case '/':{
					if(s->count>=2)
				{
					popLStack(s,data3);
					popLStack(s,data4);
					temp2=(*data4)/(*data3);
					pushLStack(s,temp2);
					
				}
				break;
			}
			default:
				break;
		}
	k='0';
		
		
		
	} 

  	double finalmath;
	ElemType *final1;
	final1=(ElemType *)malloc(sizeof(ElemType));
	popLStack(s,final1);		//���ս����ջ 
	finalmath=*final1;			
	printf("��������%f\n",finalmath);
	q=0;
	printf("����1���ٴν��м���\n");
	printf("����0�˳�\n");
	scanf("%d",&q);
	if(q==0)
	{
		break;
	}
	
}

return 0;	
}

int compare(char a,char b)		//�Ա����ȼ� 
{
	if((a=='*'||a=='/')&&(b=='*'||b=='/'))
	{
		return 0;
	}
		if((a=='+'||a=='-')&&(b=='+'||b=='-'))
	{
		return 0;
	}
		if((a=='*'||a=='/')&&(b=='-'||b=='+'))
	{
		return 1;
	}
		if((a=='-'||a=='+')&&(b=='*'||b=='/'))
	{
		return -1;
	}
	
}
