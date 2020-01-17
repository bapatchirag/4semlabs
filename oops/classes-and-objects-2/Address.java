import java.io.*;

public class Address extends bufread
{
    //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    // Member variables
    int streetnum;
    String city;
    String state;
    String country;

    // Constructors
    public Address()
    {
        this.streetnum = 0;
        this.city = "None";
        this.state = "None";
        this.country = "None";
    }

    public Address(int streetnum, String city, String state, String country)
    {
        this.streetnum = streetnum;
        this.city = city;
        this.state = state;
        this.country = country;
    }

    // Member functions
    public Address getAddress() throws IOException
    {
        System.out.print("Enter street number: ");
        int snum = Integer.parseInt(br.readLine());
        System.out.print("Enter city name: ");
        String cname = br.readLine();
        System.out.print("Enter state name: ");
        String sname = br.readLine();
        System.out.print("Enter country name: ");
        String coname = br.readLine();

        Address addr = new Address(snum, cname, sname, coname);

        return addr;
    }

    public void displayAddress(Address addr)
    {
        System.out.println("Street number: "+String.valueOf(addr.streetnum));
        System.out.println("City name: "+addr.city);
        System.out.println("State name: "+addr.state);
        System.out.println("Country name: "+addr.country);
    }
}
