public class Student extends Address
{
    // Member variables
    String USN;
    String name;
    Address addr;

    // Constructors
    public Student()
    {
        this.USN = "None";
        this.name = "None";
        this.addr = null;
    }

    public Student(String USN, String name, Address addr)
    {
        this.USN = USN;
        this.name = name;
        this.addr = addr;
    }

    // Member functions
    public void display(Student st_obj)
    {
        System.out.println("Student name: "+st_obj.name);
        System.out.println("Student USN: "+st_obj.USN);
        st_obj.displayAddress(st_obj.addr);
    }
}
