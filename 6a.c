//binarysearch
#include<stdio.h>
int binarysearch(int arr[],int low,int high,int key);

int main(){
	int n,key;
	printf("Enter no of elements in the array");
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter the element to be searched");
	scanf("%d",&key);
	int result=binarysearch(arr,0,n-1,key);
	if(result == -1){
		printf("the element is not present in the array");
	}else{
		printf("The element is present in the array");
	}
}

int binarysearch(int arr[],int low,int high,int key){
	if(low<=high){
		int mid = low + (high -low)/2;
		if(arr[mid] == key)
			return mid;

		if(arr[mid]>key)
			return binarysearch(arr,low,mid-1,key);

		return binarysearch(arr,mid+1,high,key);}
	return -1;
}


