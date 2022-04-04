
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a,int n)
{
	if (n < 2)
   {
       return;
   }
   int i; 
    for ( i = 0; i < n - 1; i++)
    {
        int end = i;
        int temp = a[end + 1];
        while (end >= 0 && a[end] > temp)
        {
            a[end + 1] = a[end];
            --end;
        }
        a[end + 1] = temp;
    }

}
 


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
		int i=begin;
 	int j=mid+1;
 	int t=0;
 	while(i<=mid&&j<=end)
 	{
 		if(*(a+i)<*(a+j))
 		{
 			*(temp+t)=*(a+i);
 			i++;
 			t++;
		 }else {
		 	*(temp+t)=*(a+j);
		 	t++;
		 	j++;
		 }
	 }
	 while(i<=mid)
	 {
	 	*(temp+t)=*(a+i);
	 	i++;
	 	t++;
	 }
	 while(j<=end)
	 {
	 	*(temp+t)=*(a+j);
	 	j++;
	 	t++;
	 }
	 t=0;
	 int tempLeft=begin;
	 while(tempLeft<=end)
	 {
	 	*(a+tempLeft)=*(temp+t);
	 	tempLeft++;
	 	t++;
	 }
}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a,int begin,int end,int *temp)
{
	if(begin<end)
 	{
 		int mid=(begin+end)/2;
 		MergeSort(a,begin,mid,temp);
 		MergeSort(a,mid+1,end,temp);
 		MergeArray(a,begin,mid,end,temp);
	 }
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int *a, int begin, int end)
{
	int left;
    if(begin < end){
        left = Partition(a,begin,end);
        QuickSort_Recursion(a,begin,left - 1);
        QuickSort_Recursion(a,left + 1,end);
    }else{
        return;
    }
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int *a,int size);


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int *a, int begin, int end)
{
	int left = begin;
    int right = end;
    int temp = a[left];
    while (left < right)
    {
        while ((a[right] >= temp) && (left < right))
        {
            right--;
        }
        a[left] = a[right];
        while ((a[left] <= temp) && (left < right))
        {
            left++;
        }
        a[right] = a[left];
    }
    a[left] = temp;
    return left;
}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int *a, int size , int max)
{
	int t[1024];
    int i,j = 0;
    for ( i = 0; i <= max; i++)
    {
        t[i] = 0;
    }
    for ( i = 0; i < size; i++)
    {
        t[a[i]]++;
    }
    for ( i = 0; i <= max; i++)
    {
        while ((t[i]--) > 0)
        {
            a[j++] = i;
        }
    } 
}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int *a,int size)
{
	int MAXN=1e5;
  	int b[MAXN];
  	int key=1;
  	int i;
  	for(i=0;i<size;i++)
  	{
  		while(key<*(a+i))
  		{
  		  key=key*10;
		}
	}
	int count[10];
	int k;
	for(k=1;k<=key;k*=10)
	{
		for(i=0;i<10;i++)
		{
			count[i]=0;
		}
		for(i=0;i<size;i++)
		{
			count[*(a+i)/k%10]++;
		}
		for(i=1;i<10;i++)
		{
			count[i]+=count[i-1];
		}
		for(i=size-1;i>=0;i--)
		{
			int dex=*(a+i)/k%10;
			b[count[dex]-1]=*(a+i);
			count[dex]--;
		}
		for(i=0;i<size;i++)
		{
			*(a+i)=b[i];
		}
	} 
}


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size)
{
	int red = 0,blue = size - 1,temp;
	 int i;
    for ( i = 0; i <= blue; i++)
    {
        if (a[i] == 0)
        {
            temp = a[i];
            a[i] = a[red]; 
            a[red] = temp;
            red++;
        }else if(a[i] == 2){
            temp = a[i];
            a[i] = a[blue]; 
            a[blue] = temp;
            i--;
            blue--;
        }
    }
}


/**
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */
int FindKthMin(int *a,int begin,int end,int k)
{
	 int pos;
    if (k > 0 && k <= end)
    {
        pos = Partition(a,begin,end);
        if (pos - begin == k - 1)
        {
            return a[pos];
        }
        if (pos - begin > k - 1)
        {
            return FindKthMin(a,begin,pos - 1,k);
        }
        return FindKthMin(a,pos + 1,end,k - pos + begin - 1);
    }
    return GetMax(a,end + 1);
}
 
 int GetMax(int *a,int size)
 {
    int i,max;
    max = a[0];
    for ( i = 0; i < size; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

#endif // QUEUE_H_INCLUDED
