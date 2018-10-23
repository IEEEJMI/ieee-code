// Don't place your source in a package
import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.Arrays;

// Please name your class Main
class Main {
		static void printpairs(int A[],int sum) 
	{	int arr_size=A.length;
	
	    int l, r; 
        int count=0;
        
        Arrays.sort(A); 
      
        
        l = 0; 
        r = arr_size-1;  
        while (l < r) 
        { 
            if(A[l] + A[r] == sum) 
                {
                    System.out.println(A[l]+" "+A[r]);
                    count++;
                    break;
                }
            else if(A[l] + A[r] < sum) 
                {l++;} 
            else // A[i] + A[j] > sum 
                {r--; }
                if(count==0 && l==r)
                {
                    System.out.println("!OK");
                }
                
        }  
	    
	    
	}

	// Main to test the above function 
	public static void main (String[] args)
	{
    	Scanner in = new Scanner(System.in);
    	int a = in.nextInt(); //number of cases
    		
        for(int i=0;i<a;i++)
        {
            try {
                int S=in.nextInt();//sum to be checked
                int E=in.nextInt(); //no of elements in list
                    
                int[] intArray = new int[E];  // allocating memory to array
                for(int j=0;j<E;j++)
                {
                    try {
                        //for reading array
                        intArray[j]=in.nextInt();
                    } catch (Exception e) {
                        System.out.println("!OK");
                        continue;
                    }
                }
                Arrays.sort(intArray);
                if(E==0){//1
                    System.out.println("!OK");
                }
                else if(E==1){//2
                    if(intArray[0]==S){
                        System.out.println(S);
                    }
                    else{
                        System.out.println("!OK");
                    }
                }
                else{//3
                    printpairs(intArray, S); 
                }
            } catch (Exception ex) {
                System.out.println("!OK");
                continue;
            }
        }
    }   
}