public class Employee extends Address
{
    // Member variables
    String empid;
    String name;
    Address addr;

    // Constructors
    public Employee()
    {
        this.empid = "None";
        this.name = "None";
        this.addr = null;
    }

    public Employee(String empid, String name, Address addr)
    {
        this.empid = empid;
        this.name = name;
        this.addr = addr;
    }

    // Member functions
    public void display(Employee emp_obj)
    {
        System.out.println("Employee ID: "+emp_obj.empid);
        System.out.println("Employee name: "+emp_obj.name);
        emp_obj.displayAddress(emp_obj.addr);
    }
}
