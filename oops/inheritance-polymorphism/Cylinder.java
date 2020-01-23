import java.io.*;

public class Cylinder extends Circle
{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    // Member variables
    double height;

    // Constructors
    public Cylinder()
    {
        this.height = 0.0;
        this.radius = 0.0;
        this.colour = null;
    }

    public Cylinder(double height, double radius)
    {
        this.height = height;
        this.radius = radius;
        this.colour = null;
    }

    public Cylinder(double height, double radius, String colour)
    {
        this.height = height;
        this.radius = radius;
        this.colour = colour;
    }

    // Member functions
    public double getHeight()
    {
        return this.height;
    }

    public double getArea()
    {
        return (super.getArea() + (2 * Math.PI * this.radius * this.height));
    }

    public double getVolume()
    {
        return (this.getArea() * this.getHeight());
    }

    public Cylinder getCylinder() throws IOException
    {
        double height, radius;
        String colour;

        System.out.print("Enter height of cylinder: ");
        height = Double.parseDouble(br.readLine());
        System.out.print("Enter radius of cylinder: ");
        radius = Double.parseDouble(br.readLine());
        System.out.print("Enter colour of cylinder: ");
        colour = br.readLine();

        Cylinder newCylinder = new Cylinder(height, radius, colour);
        return newCylinder;
    }
}
