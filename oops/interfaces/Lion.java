public class Lion implements TiredAnimal
{
    // Member variables
    String colour;

    // Constructors
    public Lion()
    {
        this.colour = "Golden";
    }

    public Lion(String colour)
    {
        this.colour = colour;
    }

    // Member methods
    public void printColour(Lion l)
    {
        System.out.println("The lion is "+l.colour+" in colour");
    }

    public void printTired(Lion l)
    {
        System.out.println("Is the lion tired? "+l.isTired());
    }

    public void eat()
    {
        System.out.println("The lion is a carnivore, and it eats deer");
    }

    public void sound()
    {
        System.out.println("The lion roars");
    }

    public boolean isTired()
    {
        return tired;
    }
}
