import java.io.IOException;

// Main class
public class TestIt
{
    public static void main(String[] args) throws IOException
    {
        Cylinder c1 = new Cylinder();
        Cylinder c2 = new Cylinder();

        // Enter specifications of both cylinders
        System.out.println("Enter specs of cylinder 1: ");
        c1 = c1.getCylinder();
        System.out.println("\nEnter specs of cylinder 2: ");
        c2 = c2.getCylinder();
        System.out.println("");

        if(c1.colour.equals(c2.colour) && c1.getArea() == c2.getArea() && c1.getVolume() == c2.getVolume())
        {
            System.out.println("Similar cylinders");
        }
        else
        {
            System.out.println("Dissimilar cylinders");
        }
    }
}