//import java.util.concurrent.CompletionException;

public class Complex
{
    // Member variables
    double real;
    double imaginary;

    // Constructors
    public Complex()
    {
        this.real = 0.0;
        this.imaginary = 0.0;
    }

    public Complex(double real, double imaginary)
    {
        this.real = real;
        this.imaginary = imaginary;
    }

    // Member functions
    public Complex add(Complex z1, Complex z2)
    {
        Complex z_sum = new Complex();
        z_sum.real = z1.real + z2.real;
        z_sum.imaginary = z1.imaginary + z2.imaginary;
        return z_sum;
    }

    public Complex sub(Complex z1, Complex z2)
    {
        Complex z_diff = new Complex();
        z_diff.real = z1.real - z2.real;
        z_diff.imaginary = z1.imaginary - z2.imaginary;
        return z_diff;
    }

    public void display(Complex z_ans)
    {
        System.out.println(String.valueOf(z_ans.real) + "+" + String.valueOf(z_ans.imaginary) + "i");
    }

    // Main function
    public static void main(String[] args)
    {
        Complex z1 = new Complex(3.0, 4.0); // Change to whatever required
        Complex z2 = new Complex(1.0, 2.0); // Change to whatever required

        Complex z_sum = z1.add(z1, z2);
        System.out.print("z1+z2 = ");
        z_sum.display(z_sum);

        Complex z_diff = z1.sub(z1, z2);
        System.out.print("z1-z2 = ");
        z_diff.display(z_diff);
    }
}
