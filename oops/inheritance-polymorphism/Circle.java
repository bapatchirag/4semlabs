public class Circle
{
    // Member variables
    double radius;
    String colour;

    // Constructors
    public Circle()
    {
        this.radius = 0.0;
        this.colour = null;
    }

    public Circle(double radius)
    {
        this.radius = radius;
        this.colour = null;
    }

    public Circle(double radius, String colour)
    {
        this.radius = radius;
        this.colour = colour;
    }

    // Member functions
    public double getRadius()
    {
        return this.radius;
    }

    public double getArea()
    {
        double area = Math.PI * this.getRadius() * this.getRadius();
        return area;
    }
}