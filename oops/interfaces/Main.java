public class Main
{
    public static void main(String[] args)
    {
        Lion l = new Lion();
        Snake s = new Snake();

        System.out.println("Information about lion:");
        l.printColour(l);
        l.eat();
        l.sound();
        l.printTired(l);

        System.out.println("\nInformation about snakes:");
        s.printColour(s);
        s.eat();
        s.sound();
        s.printTired(s);
    }
}