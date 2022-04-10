//
// Created by eke_l on 2021/4/21.
//


#define true 1
#define false 0
#define succeed 1
#define failed 0
#define Status int
typedef int ElemType;

typedef struct Node{
    ElemType value;
    struct Node *left, *right;
}Node, *NodePtr;

typedef struct BinarySortTree{
    NodePtr root ;
} BinarySortTree, *BinarySortTreePtr;

/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
 void visit (NodePtr p)
{
    if (p->value != 0x7fffffff)
    {
        printf(" %d ",p->value);
    }	
}
Status BST_init(BinarySortTreePtr p)
{

    if(p == NULL)
	{
		printf("这是一个空指针");
		return false;
	}
    p->root = (Node*)malloc(sizeof(Node));
    p->root->value = 0x7fffffff;
    p->root->left = NULL;
    p->root->right = NULL;
    return succeed;
} 

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */Status BST_insert(BinarySortTreePtr a, ElemType value){
   if (a->root == NULL || a == NULL)
    {
        printf("树未初始化！\n");
        return false;
    }
    NodePtr p = a->root;
    while (1)
    {
        if (a->root->value == 0x7fffffff)
        {
            a->root->value = value;
            a->root->left = (Node*)malloc(sizeof(Node));
            a->root->right = (Node*)malloc(sizeof(Node));
            a->root->left->value =a->root->right->value = 0x7fffffff;
            break;
        }else{
            if (value < a->root->value)
            {
                a->root = a->root->left;
            }else if (value == a->root->value)
            {
                printf("该值已存在于树中！\n");
                return failed;
            }else if (value > a->root->value)
            {
                a->root = a->root->right;
            }
        }
    }
    a->root = p;
    return succeed;
}

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
Status BST_delete(BinarySortTreePtr p, ElemType q)
{
		if(p==NULL)
	{
		printf("这是一个空指针\n");
		return false;
	}
	if(p->root->value==0x7fffffff)
	{
		printf("delete is false\n ");
		return false;
	}
	if(p->root->value==q)
	{
		if(p->root->left->value==0x7fffffff&&p->root->right->value==0x7fffffff)
		{
			p->root->value=0x7fffffff;
			printf("delete is successful");
			return true;
		}
		if(p->root->left->value!=0x7fffffff&&p->root->right->value==0x7fffffff)
		{
			p->root=p->root->left;
			printf("delete is successful");
			return true;
		}
		if(p->root->left->value==0x7fffffff && p->root->right->value!=0x7fffffff)
		{
			p->root=p->root->right;
			printf("delete is successful");
			return true;
		}
		if(p->root->left->value!=0x7fffffff && p->root->right->value!=0x7fffffff)
		{
			NodePtr temp=(NodePtr)malloc(sizeof(Node));
			temp=p->root->left;
			while(temp->right!=NULL)
			{
				temp=temp->right;
			}
			p->root->value=temp->value;
			temp->value=0x7fffffff;
			/*
			while(p->root->right!=NULL)
			{
				p->root=p->root->right; 
			}
			p->root=NULL; */
			printf("delete is successful");
			return true;
			
		}
	}
	if(q<p->root->value)
	{
		BinarySortTreePtr temp2;
	 	temp2=(BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	 	temp2->root=p->root->left;
		BST_delete( temp2, q);
	}
	if(q>p->root->value)
	{
		BinarySortTreePtr temp3;
	 	temp3=(BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	 	temp3->root=p->root->right;
		BST_delete( temp3, q);
	}
}

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
Status BST_search(BinarySortTreePtr p, ElemType q)
{
	if(p==NULL)
	{
		printf("这是一个空指针\n");
		return false;
	}
	if(p->root->value==q)
	{
		printf("what you search is exist\n");
		return true;
	}

	if(q>p->root->value)
	{
		BinarySortTreePtr temp;
	 	temp=(BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	 	temp->root=p->root->right;
	 	if(p->root->right->value==0x7fffffff)
	 	{
	 		return false;
		 }
		BST_search(temp,q);
	}
	if(q<p->root->value)
	{
		BinarySortTreePtr temp2;
	 	temp2=(BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	 	temp2->root=p->root->left;
	 	if(p->root->left->value==0x7fffffff)
	 	{
	 		return false;
		 }
		BST_search(temp2,q);
	}
	if(p->root->value==0x7fffffff)
	{
		return false;
	}
}

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderI(BinarySortTreePtr p, void (*visit)(NodePtr q))
{
	if(p==NULL)
 	{
 		printf("这是一个空指针\n");
		return false; 
	}
	if(p->root->value==0x7fffffff)
	{
		printf("这是一个空树\n");
		return false;
	}
	LinkStack s;
    initLStack(&s);
     pushLStack(&s,p->root);
    while (!isEmptyLStack(&s))
    {
        NodePtr node = popLStack(&s);
        visit(node);
        if (node->right->value!= 0x7fffffff)
        {
            pushLStack(&s,node->right);
        }
        if (node->left->value!= 0x7fffffff)
        {
            pushLStack(&s,node->left);
        }        
    }
    return succeed;
}

/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderR(BinarySortTreePtr p, void (*visit)(NodePtr q))
{
	if (p->root == NULL || p == NULL)
    {
        printf("树未初始化！\n");
        return failed;
    }
    if (p->root->value == 0x7fffffff)
    {
        return false;
    }
    visit(p->root);
    BinarySortTreePtr q = (BinarySortTree*)malloc(sizeof(BinarySortTree));
    q->root = p->root->left;
    BST_preorderR(q, visit);
    q->root = p->root->right;
    BST_preorderR(q, visit);
    system("pause");  
    return true;
}

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderI(BinarySortTreePtr p, void (*visit)(NodePtr q))
{
	if(p==NULL)
 	{
 		printf("这是一个空指针\n");
 		return false;
	}
	if(p->root->value==0x7fffffff)
	{
		printf("这是一个空树\n");
		return false;
	}
    NodePtr node = p->root;
    LinkStack s;
    initLStack(&s);
    pushLStack(&s,node);
    while(!isEmptyLStack(&s))
    {
    	if(node->left->value!=0x7fffffff)
    	{
    		pushLStack(&s,node->left);
    		node=node->left;
		}else{
			NodePtr temp=popLStack(&s);
			visit(temp);
			if(temp->right->value=0x7fffffff)
			{
				node=temp->right;
				pushLStack(&s,node);
			}
		}
	}
}

/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderR(BinarySortTreePtr p, void (*visit)(NodePtr q))
{
		if(p==NULL)
	{
		printf("这是一个空指针\n");
		return false;
	}
	 if (p->root->value == 0x7fffffff)
    {
        return false;
    }
	BinarySortTreePtr temp;
	temp=(BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	temp->root=p->root->left;
	BST_inorderR(temp,visit);
	visit(p->root);
	temp->root=p->root->right;
	BST_inorderR(temp,visit);
	return true;
}

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderI(BinarySortTreePtr p, void (*visit)(NodePtr q))
{
		if(p==NULL)
 	{
 		printf("这是一个空指针\n");
 		return false;
	}
	if(p->root->value==0x7fffffff)
	{
		printf("这是一个空树\n");
		return false;
	}
	  LinkStack s1;
    LinkStack s;
    initLStack(&s);
    initLStack(&s1);
    pushLStack(&s,p->root);
     while (!isEmptyLStack(&s))
    {
        NodePtr node = popLStack(&s);
        pushLStack(&s1,node);
        if (node->left->value != 0x7fffffff)
        {
            pushLStack(&s,node->left);
        }
        if (node->right->value!=0x7fffffff)
        {
            pushLStack(&s,node->right);
        }        
    }
     while (!isEmptyLStack(&s1))
    {
        NodePtr node = popLStack(&s1);
        visit(node);
    }
    return true;
}

/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderR(BinarySortTreePtr p, void (*visit)(NodePtr q))
{
	if(p==NULL)
	{
		printf("这是一个空指针\n");
		return false;
	}
	if(p->root->value==0x7fffffff)
	{
		return false;
	}
	BinarySortTreePtr temp;
	temp=(BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	temp->root=p->root->left;
 	BST_postorderR(temp,visit);
	temp->root=p->root->right;
 	BST_postorderR(temp,visit);
 	visit(p->root);
 	return true;
}

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_levelOrder(BinarySortTreePtr p, void (*visit)(NodePtr q))
{
	if(p==NULL)
	{
		printf("这是一个空指针\n");
		return false;
	}
	if(p->root->value==0x7fffffff)
	{
		printf("这是一个空树\n");
		return false;
	}
	 Node* Queue[100] = {NULL};
    Node* left = NULL;
    Node* right = NULL;
    int i = 1,j = 0;
    Queue[0] = p->root;
    while (i > j)
    {
        if (Queue[j]->value != 0x7fffffff)
        {
            visit(Queue[j]);
            left = Queue[j]->left;
            right = Queue[j]->right;
            if (left){Queue[i++] = left;}
            if (right){Queue[i++] = right;}
        }
        j++;
    }
    return succeed;
}


