import java.util.*;
import java.io.*;

public class ArrayListOper
{
    public static void printMenu()
    {
        System.out.println("MENU:");
        System.out.println("1. Show menu");
        System.out.println("2. Add colour");
        System.out.println("3. Convert ArrayList to Array");
        System.out.println("4. Reverse ArrayList");
        System.out.println("5. Get sublist of ArrayList");
        System.out.println("6. Sort ArrayList");
        System.out.println("7. Clone ArrayList");
        System.out.println("8. Exit");
    }

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<String> list = new ArrayList<String>();

        printMenu();

        while(true)
        {
            System.out.print(": ");
            int ch = Integer.parseInt(br.readLine());

            if(ch == 1)
            {
                printMenu();
            }
            else if(ch == 2)
            {
                System.out.print("Enter colour to be added: ");
                String colour = br.readLine();
                list.add(colour);
                System.out.println(colour + " is added to the list");
                System.out.println("List is now: " + list);
            }
            else if(ch == 3)
            {
                String[] newarr = new String[list.size()];
                newarr = list.toArray(newarr);

                System.out.print("The converted ArrayList is: {" + newarr[0]);
                for(int i = 1; i < newarr.length; i++)
                {
                    System.out.print(", " + newarr[i]);
                }
                System.out.println("}");
            }
            else if(ch == 4)
            {
                ArrayList<String> revlist = new ArrayList<String>();
                for(int i = list.size() - 1; i >= 0; i--)
                {
                    revlist.add(list.get(i));
                }
                System.out.println("The reversed list is: " + revlist);
            }
            else if(ch == 5)
            {
                System.out.print("Enter start index: ");
                int sIndex = Integer.parseInt(br.readLine());
                System.out.print("Enter end index: ");
                int eIndex = Integer.parseInt(br.readLine());
                System.out.print("Sublist is: ");
                System.out.println(list.subList(sIndex, eIndex + 1));
            }
            else if(ch == 6)
            {
                System.out.println("Unsorted list: " + list);
                Collections.sort(list);
                System.out.println("After sorting: " + list);
            }
            else if(ch == 7)
            {
                ArrayList<String> cloned = (ArrayList<String>) list.clone();
                System.out.println("Clone is: " + cloned);
            }
            else if(ch == 8)
            {
                System.out.println("Goodbye!");
                break;
            }
            else
            {
                System.out.println("Wrong option, try again");
            }
            System.out.println("");
        }
    }
}
