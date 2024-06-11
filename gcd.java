import java.util.*;
public class gcd{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the first no: "+" ");
		int m = sc.nextInt();
		System.out.print("Enter the second no: "+" ");
		int n = sc.nextInt();
		System.out.println("Gcd by iteration"+ euclidrec(m,n));
		System.out.println(eucliditerative(m,n));
		System.out.println(consecutive(m,n));
		System.out.println(middleschool(m,n));
	}
	public static int  euclidrec(int m,int n){
		if (n == 0) {
			return m;
		}
		return euclidrec(n,m%n);
	}
	public static int eucliditerative(int m,int n){
		int rem = 0;
		while(n!=0){
			rem = m%n;
			m = n;
			n = rem;
		}
		return m;
	}
	public static int consecutive(int m,int n){
		int t = (m>n)?n:m;
		while(m%t != 0 || n%t != 0){
			t--;
		}
		return t;
	}
	public static ArrayList<Integer> primefact(int n){
		ArrayList<Integer> factors = new ArrayList<>();
		int i = 2;
		while(i<n){
			while(n%i == 0){
				factors.add(i);
				n = n/i;
			}
			i++;
		}
		if(n>2){
			factors.add(n);
		}
		return factors;
	}
	public static int middleschool(int m,int n){
		int gcd = 1;
		ArrayList<Integer> factorsofm = primefact(m);
		ArrayList<Integer> factorsofn = primefact(n);

		int i = 0;
		int j = 0;
		while(i<factorsofm.size() && j<factorsofn.size()){
			if(factorsofm.get(i) == factorsofn.get(j)){
				gcd = gcd * factorsofm.get(i);
				i++;
				j++;
			}
			else if(factorsofm.get(i) <factorsofn.get(j)){
				i++;
			}else{
				j++;
			}


		}
		return gcd;
	}


}
