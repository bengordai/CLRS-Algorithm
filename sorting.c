//快排

void Quicksort(char **A,int low,int high){
    int pivot;
    if(low<high){
        pivot=Qpartition(A,low,high);
        Quicksort(A,low,pivot-1);
        Quicksort(A,pivot+1,high);
    }
}
int Qpartition(char **A,int low,int high){
    char *pivot=A[high],*temp;
    int i,j;
    for(i=low-1,j=low;j<high;j++){
        if(strcmp(A[j],pivot)<=0){
            i++;
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }
    temp=A[i+1];
    A[i+1]=A[high];
    A[high]=temp;
    return(i+1);
}

//归并排序

void Merge(char **A,char **B,int Alength,int Blength){
    char **C;
    int i,j,k,l=Alength+Blength;
    C=(char**)malloc(l*sizeof(char*));
    i=j=k=0;
    while(i<Alength&&j<Blength){
        if(strcmp(A[i],B[j])<0){
        C[k]=A[i];
        i++;
        k++;
    }else{
        C[k]=B[j];
        j++;
        k++;
    }
    }
    if(i>=Alength){
        for(;j<Blength;j++,k++)C[k]=B[j];
    }else if(j>=Blength){
        for(;i<Alength;i++,k++)C[k]=A[i];
    }
    for(i=0;i<l;i++)
        A[i]=C[i];
    free(C);
}
void Mergesort(char **A,int length){
    char *temp;
    if(length<=1){
        return;
    }else if(length==2){
        if(strcmp(A[0],A[1])>0){
            temp=A[0];
            A[0]=A[1];
            A[1]=temp;
        }
    }else if(length%2==0){
        Mergesort(A,length/2);
        Mergesort(&(A[length/2]),length/2);
        Merge(A,&(A[length/2]),length/2,length/2);
    }else{
        Mergesort(A,length/2);
        Mergesort(&(A[length/2+1]),length/2+1);
        Merge(A,&(A[length/2+1]),length/2,length/2+1);
    }
}

//堆排序

void MaxifyHeap(char **A,int i,int length){
    int left;
    int right;
    int largest;
    char *temp;
    while(1){
        left=2*i+1;
        right=left+1;
        if(left>=length){
            break;
          }else if(strcmp(A[left],A[i])>0){
            largest=left;
          }else{
            largest=i;
          }
        if(right<length&&strcmp(A[right],A[largest])>0){
            largest=right;
          }
        if(largest!=i){
            temp=A[i];
            A[i]=A[largest];
            A[largest]=temp;
            i=largest;//make MaxifyHeap unrecursive
        }else{
            break;
        }
    }
}
void Heapsort(char **A,int length){
    char *temp;
    int i;
    for(i=length/2-1;i>=0;i--){
        MaxifyHeap(A,i,length);
    }
    for(i=length-1;i>=1;i--){
        temp=A[i];
        A[i]=A[0];
        A[0]=temp;
        length--;
        MaxifyHeap(A,0,length);
    }
}

//冒泡排序

void Bubblesort(char **A,int length){
    int i,j;
    char *temp;
    for(i=0;i<length-1;i++){
        for(j=0;j<length-1-i;j++){
            if(strcmp(A[j],A[j+1])>0){
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }//j-for
    }//i-for
}

//希尔排序

void Shellsort(char **A,int length){
    int increments[]={19,13,7,3,1};
    int i,j,k,l,increment;
    char *temp;
    for(i=0;i<5;i++){
        increment=increments[i];
        for(j=0;j<length-increment;j++){
            k=j+increment;
            if(strcmp(A[j],A[k])>0){
                temp=A[k];
                A[k]=A[j];
                for(l=k-increment;l>=0&&strcmp(A[l],temp)>0;l=l-increment){
                    A[l+increment]=A[l];
                }
                A[l+increment]=temp;
            }
        }//j-for
    }//i-for
} 

//插入排序

void Insertionsort(int *A,int length){
    int i,j;
    int temp;
    for(i=1;i<length;i++){
        if(A[i]<A[i-1]){
            temp=A[i];
            A[i]=A[i-1];
            for(j=i-2;j>=0&&A[j]>temp;j--){
                A[j+1]=A[j];
            }
            A[j+1]=temp;
        }
    }//i-for
}

//基数排序

void Radixsort(int *A,int length){//采用了counting sort的方式来对每一位的不同可能进行装载
    int i,j;
    int assist[6]={1,8,64,512,4096,32768};
    int count[8];
    int *digit=(int*)malloc(length*sizeof(int));
    int *bucket=(int*)malloc(length*sizeof(int));
    for(i=0;i<6;i++){//65536一共6个八进制位，i为第i位
        for(j=0;j<8;j++){//count用来记录这个位的数有几位
            count[j]=0;
        }
        for(j=0;j<length;j++){//digit用来记录第j个数的第i位
            digit[j]=A[j]/assist[i]%8;
            count[digit[j]]++;
        }
        for(j=1;j<8;j++){//count[j]表示第j个桶的右边界
            count[j]=count[j]+count[j-1];
        }
        for(j=length-1;j>=0;j--){//倒着装桶，倒着放
            bucket[count[digit[j]]-1]=A[j];
            count[digit[j]]--;
        }
        for(j=0;j<length;j++){//从桶里取出
            A[j]=bucket[j];
        }
    }
    free(digit);
    free(bucket);
}

//计数排序

void Countingsort(int *A,int length){
    int *B=(int*)malloc(length*sizeof(int));
    int C[65536],i;
    for(i=0;i<65536;i++)C[i]=0;
    for(i=0;i<length;i++){
        C[A[i]]++;
    }
    for(i=1;i<65536;i++){
        C[i]=C[i]+C[i-1];
    }
    for(i=length-1;i>=0;i--){
        B[C[A[i]]-1]=A[i];
        C[A[i]]--;
    }
    for(i=0;i<length;i++){
        A[i]=B[i];
    }
    free(B);
}