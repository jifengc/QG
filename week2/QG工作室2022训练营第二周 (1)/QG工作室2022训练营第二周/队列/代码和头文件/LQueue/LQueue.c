
#include<stdio.h>
#include<stdlib.h>
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
	Q->front=(Node *)malloc(sizeof(Node));
	Q->front->next=(Node *)malloc(sizeof(Node));
	Q->front->data=(void*)malloc(21);
	Q->front->next=NULL;
	if(Q->front!=NULL)
	{
		Q->rear=Q->front;
		Q->rear->next=NULL;
	}
	Q->length=0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
	if(Q->front == NULL)
	{
		printf("队列未初始化\n");
	}
	else{
	
	ClearLQueue(Q);
	free(Q->front);
	}
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	if(Q->front==NULL)
	{
		printf("队列未初始化\n");
		return FALSE;
	}
	if(Q->length==0)
	{
		return TRUE;
	}
	
	
	printf("队列不为空\n");
	return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e){
	if(Q->front==NULL)
	{
		printf("队列未初始化\n");
		return FALSE;
	}
	if(IsEmptyLQueue(Q)==TRUE)
	{
		printf("这是一个空队列\n");
		return FALSE;
	}
	stringcopy(e,Q->front->data,21);
	LPrint(Q->front->data,Q->front->type);
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	if(Q->front==NULL)
	{
		printf("队列未初始化\n");
		return FALSE;
	}
	return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data){
	if(Q->front==NULL)
	{
		printf("队列未初始化\n");
		return FALSE;
	}
	Node *p;
	p=(Node *)malloc(sizeof(Node));
	p->data=(void*)malloc(21);
	stringcopy(p->data,data,21);
	p->next=NULL;
	if(Q->length==0)
	{
		Q->front=p;
	}else {
		Q->rear->next=p;
	}
	Q->rear=p;
	Q->length++;
	printf("入队成功\n");
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	if(Q->front==NULL)
	{
		printf("队列未初始化\n");
		return FALSE;
	}
	if(IsEmptyLQueue(Q)==TRUE)
	{
		printf("这是一个空队列\n");
		return FALSE;
	}
	Q->front=Q->front->next;
	Q->length--;
	printf("出队成功\n");
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	if(Q->front==NULL)
	{
		printf("队列未初始化\n");
	}
	Q->front=Q->rear;
	Q->length=0;
	printf("清空队列成功\n");
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
	if(Q->front==NULL)
	{
		printf("队列未初始化\n");
		return FALSE;
	}
	if(IsEmptyLQueue(Q)==TRUE)
	{
		printf("这是一个空队列\n");
		return FALSE;
	}
   	Node *p=NULL;
	p=(Node *)malloc(sizeof(Node));
	p->data=(void*)malloc(21);
	p=Q->front;
	while(p->next!=NULL)
	{
		foo(p->data);
		p=p->next;
	}
	foo(p->data);
	return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 
 *  @notice      : None
 */
void LPrint(void *q){
	{
		
        if(type == 'a')
            printf("--> %.2lf", *(double*)q);
        if(type == 'b')
            printf("--> %c", *(char*)q);
        if(type == 'c')
            printf("--> %d ", *(int*)q);
        if(type == 'd')
            printf("--> %s ", (char*)q);
    }
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
 


