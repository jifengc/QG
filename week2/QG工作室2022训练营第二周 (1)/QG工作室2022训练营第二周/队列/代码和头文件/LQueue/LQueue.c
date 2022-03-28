
#include<stdio.h>
#include<stdlib.h>
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
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
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
	if(Q->front == NULL)
	{
		printf("����δ��ʼ��\n");
	}
	else{
	
	ClearLQueue(Q);
	free(Q->front);
	}
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	if(Q->front==NULL)
	{
		printf("����δ��ʼ��\n");
		return FALSE;
	}
	if(Q->length==0)
	{
		return TRUE;
	}
	
	
	printf("���в�Ϊ��\n");
	return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void *e){
	if(Q->front==NULL)
	{
		printf("����δ��ʼ��\n");
		return FALSE;
	}
	if(IsEmptyLQueue(Q)==TRUE)
	{
		printf("����һ���ն���\n");
		return FALSE;
	}
	stringcopy(e,Q->front->data,21);
	LPrint(Q->front->data,Q->front->type);
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	if(Q->front==NULL)
	{
		printf("����δ��ʼ��\n");
		return FALSE;
	}
	return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data){
	if(Q->front==NULL)
	{
		printf("����δ��ʼ��\n");
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
	printf("��ӳɹ�\n");
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	if(Q->front==NULL)
	{
		printf("����δ��ʼ��\n");
		return FALSE;
	}
	if(IsEmptyLQueue(Q)==TRUE)
	{
		printf("����һ���ն���\n");
		return FALSE;
	}
	Q->front=Q->front->next;
	Q->length--;
	printf("���ӳɹ�\n");
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	if(Q->front==NULL)
	{
		printf("����δ��ʼ��\n");
	}
	Q->front=Q->rear;
	Q->length=0;
	printf("��ն��гɹ�\n");
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
	if(Q->front==NULL)
	{
		printf("����δ��ʼ��\n");
		return FALSE;
	}
	if(IsEmptyLQueue(Q)==TRUE)
	{
		printf("����һ���ն���\n");
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
 *    @description : ��������
 *    @param         q ָ��q
 
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
 


