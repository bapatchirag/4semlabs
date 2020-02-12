public class Snake implements TiredAnimal
{
    // Member variables
    String colour;

    // Constructors
    public Snake()
    {
        this.colour = "Green";
    }

    public Snake(String colour)
    {
        this.colour = colour;
    }

    // Member methods
    public void printColour(Snake s)
    {
        System.out.println("The snake is "+s.colour+" in colour");
    }

    public void printTired(Snake s)
    {
        System.out.println("Is the snake tired? "+s.isTired());
    }

    public void eat()
    {
        System.out.println("The snake is a carnivore, and it eats rats");
    }

    public void sound()
    {
        System.out.println("The snake hisses");
    }

    public boolean isTired()
    {
        return tired;
    }
}