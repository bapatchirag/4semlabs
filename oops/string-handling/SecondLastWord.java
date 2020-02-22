import java.io.*;

public class SecondLastWord
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Enter sentence: ");
        String sentence = br.readLine();
        String[] words = sentence.split(" ");
        System.out.println("The second last word of this sentence is: " + words[words.length - 2]);
    }
}