import java.io.*;

public class SwapSubstrings
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Enter sentence: ");
        String sentence = br.readLine();

        String[] words = sentence.split(" ");
        for(int i = 0; i < words.length; i++)
        {
            if(words[i].equals("python"))
                words[i] = "java";
            else if(words[i].equals("java"))
                words[i] = "python";
        }

        String newSentence = String.join(" ", words);
        System.out.println("The revised sentence is: " + newSentence);
    }
}