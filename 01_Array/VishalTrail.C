#include<stdio.h>
#include<conio.h>
void merge(int a[],int low,int mid,int high);
void mSort(int arr[],int low,int high){
    int mid;
    if(low<high){
        mid=(high+low)/2;
        mSort(arr,low,mid);
        mSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

void merge(int a[],int low,int mid,int high){
int i,j,k,h,b[10];
h=low;i=low;j=mid+1;
while(h<=mid&&j<=high){
    if(a[h]<=a[j]){
        b[i]=a[h];
        h++;
        i++;
    }
    else{
        b[i]=a[j];
        j++;
        i++;
    }
    if(h>mid){
        while(k<=high){
            b[i]=a[k];
            k++;
            i++;
        }
    }
    if(j>high){
        while(k<=mid){
            b[i]=a[k];
            i++;
            k++;
        }
    }
    for(i=low;i<=high;i++){
        a[i]=b[i];
    }
}


}
int main(){
int i,j,arr[10],n;
printf("enter size");
scanf("%d",&n);
for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
mSort(arr,0,n-1);
for(i=0;i<n;i++){
    printf("%d ",arr[i]);
}
return 0;
}
