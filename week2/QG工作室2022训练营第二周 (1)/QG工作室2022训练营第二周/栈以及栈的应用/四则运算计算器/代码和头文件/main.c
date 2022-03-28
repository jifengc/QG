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
		//符号 
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
  printf("------------这是一个计算器（不支持多位数）-------------\n");
  while(1){
  printf("请输入要计算的式子\n");
  scanf("%s",a);
	 i=0;
	char k='0';
	double temp2;
	//从左到右 
	for(i=0;a[i]!='\0';i++)
	{
	    double temp;
	    //若检测到数字 ，直接入栈 
		if(a[i]>='0'&&a[i]<='9')
		{
		
			math=(double)(a[i]-'0');
			pushLStack(s,math);
			continue ;
		}
		//若检测到左括号 
		if(a[i]=='(')
		{
			//输入左括号直接入栈 
			pushLStack2(s2,a[i]);
			//继续遍历 
			for(;a[i]!='\0';i++)
			{  
			//如果为右括号则跳过 
				if(a[i]==')')
				{
					break;
				}
				if(a[i]>='0'&&a[i]<='9')
			    {
				math=(a[i]-'0');
				//数字入栈 
				pushLStack(s,math);
				continue ;
		     	}
		     	//如果输入符号 
		     	if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')
			   {
			   	//如果栈顶为左括号 
					if(a[i-2]=='(')
					{
						//符号入栈 
						pushLStack2(s2,a[i]);
						continue ;
					}
					//如果当前运算符优先级大于栈顶，入栈 
					if(compare(a[i],s2->top->data2)==1)
					{
						pushLStack2(s2,a[i]);
						continue;
					}
					
					//如果当前运算符优先级等于栈顶，栈顶出栈 
					if(compare(a[i],s2->top->data2)==0)
					{
					   	popLStack2(s2,data5);
					   	//储存运算符，进行下一步操作 
						k=*data5; 
						pushLStack2(s2,a[i]);
					}
					//如果当前运算符优先级等于栈顶，栈顶出栈
					if(compare(a[i],s2->top->data2)==-1)
					{
						popLStack2(s2,data5);
						k=*data5;
						pushLStack2(s2,a[i]);
					}
			
				}
			switch(k)
		   {
		   	//若栈的节点大于2 
			case '+':{
				if(s->count>=2)
				{
					//出栈，将数字储存 
					popLStack(s,data3);
					popLStack(s,data4);
					//进行相加 
					temp2=*data3+*data4;
					pushLStack(s,temp2);
					//相加结果入栈 
				}
				break;
			}
			case '-':{
				if(s->count>=2)
				{
					popLStack(s,data3);
					popLStack(s,data4);
					//进行相减 
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
					//相乘 
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
					//相除 
					temp2=(*data4)/(*data3);
					pushLStack(s,temp2);
					
				}
				break;
			}
			default:
				break;
		}
	     	
			}
			//若栈顶无右括号 
			while(s2->top->data2!='(')
	{
		//栈顶继续出栈 
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
		//栈顶出栈，直到有右括号 
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
			//若优先级比栈顶大 ，入栈 
			if(compare(a[i],s2->top->data2)==1)
			{
				pushLStack2(s2,a[i]);
				continue;
			}
			//若优先级等于栈顶，栈顶出栈 
			if(compare(a[i],s2->top->data2)==0)
			{
			   	popLStack2(s2,data5);
			   	//储存运算符 进行下一步操作 
				k=*data5;
				pushLStack2(s2,a[i]);
			}
			//若优先级小于栈顶，栈顶出栈 
			if(compare(a[i],s2->top->data2)==-1)
			{
				popLStack2(s2,data5);
				//储存运算符 进行下一步操作
				k=*data5;
				pushLStack2(s2,a[i]);
			}
			
		}
		//对储存的运算符进行下一步操作
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
	popLStack(s,final1);		//最终结果出栈 
	finalmath=*final1;			
	printf("计算结果是%f\n",finalmath);
	q=0;
	printf("输入1可再次进行计算\n");
	printf("输入0退出\n");
	scanf("%d",&q);
	if(q==0)
	{
		break;
	}
	
}

return 0;	
}

int compare(char a,char b)		//对比优先级 
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
