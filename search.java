import java.util.*;
public class search{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int[] arr = {1,2,5,6,7,8,10};
		int key = 8;
		System.out.println(bsr(arr,0,arr.length,key));
		System.out.println(bsi(arr,0,arr.length,key));
		System.out.println(lsr(arr,0,key));
		System.out.println(lsi(arr,key));
	}
	public static int bsr(int arr[],int low,int high,int key){
		while(low<= high){
			int mid = (low+high)/2;
			if(arr[mid] == key){
				return mid;
			}else if(arr[mid] > key){
				return bsr(arr,low,mid-1,key);
			}else{
				return bsr(arr,mid+1,high,key);
			}
		}
		return -1;
	}
	public static int bsi(int arr[] ,int low,int high,int key){
		while(low<= high){
			int mid = (low+high)/2;
			if(arr[mid] == key){
				return mid;
			}
			else if(arr[mid]<key){
				low = mid + 1;
			}else{
				high = mid -1;
			}
		}
		return -1;
	}
	public static int lsi(int arr[] ,int key){
		for(int i = 0;i<arr.length;i++){
			if(arr[i] == key){
				return i;
			}
		}
		return -1;
	}
	public static int lsr(int arr[] ,int iterator,int key){
		if(arr.length < iterator){
			return -1;
		}
		if(arr[iterator] == key){
			return iterator;
		} 
		
		return lsr(arr,++iterator,key);

	}
}
