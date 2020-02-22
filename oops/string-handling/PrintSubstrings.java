import java.io.*;

public class PrintSubstrings
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Enter the sentence: ");
        String sentence = br.readLine();
        System.out.print("Enter the delimiter: ");
        String delimiter = br.readLine();

        String[] substrings = sentence.split(delimiter);
        System.out.println("The substrings are: ");
        for(String str: substrings)
        {
            System.out.println(str);
        }
    }
}