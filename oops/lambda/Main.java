import java.io.*;

interface PerformOperation {
    boolean operation(int num);
}

public class Main {
    static PerformOperation checkEvenOdd  = (int x) -> {
      return (x % 2 == 0);
    };

    static PerformOperation checkPrime = (int x) -> {
      for(int i = 2; i < Math.sqrt(x); i++)
          if(x % i == 0)
              return false;

      return true;
    };

    static PerformOperation checkPalindrome = (int x) -> {
      int temp = x, rev = 0;
      while(temp != 0) {
          int last_digit = temp % 10;
          rev = (rev * 10) + last_digit;
          temp /= 10;
      }

      return (rev == x);
    };

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("MENU:");
        System.out.println("1. Check even or odd");
        System.out.println("2. Check if number is prime or not");
        System.out.println("3. Check if number is palindrome or not");
        System.out.print("Enter choice: ");
        int ch = Integer.parseInt(br.readLine());

        System.out.print("Enter number to be tested: ");
        int num = Integer.parseInt(br.readLine());
        if(ch == 1)
            System.out.println(num + " is even? Ans: " + checkEvenOdd.operation(num));
        else if(ch == 2)
            System.out.println(num + " is prime? Ans: " + checkPrime.operation(num));
        else if(ch == 3)
            System.out.println(num + " is a palindrome? Ans: " + checkPalindrome.operation(num));
        else
            System.out.println("Wrong option chosen");
    }
}
