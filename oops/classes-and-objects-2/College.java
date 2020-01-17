public class College extends Address
{
    // Member variables
    String name;
    Address addr;

    // Constructors
    public College()
    {
        this.name = "None";
        this.addr = null;
    }

    public College(String name, Address addr)
    {
        this.name = name;
        this.addr = addr;
    }

    // Member functions
    public void display(College col_obj)
    {
        System.out.println("College name: "+col_obj.name);
        col_obj.displayAddress(col_obj.addr);
    }
}
