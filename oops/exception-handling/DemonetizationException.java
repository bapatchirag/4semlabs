public class DemonetizationException extends Exception
{
    private double amt;
    DemonetizationException(double amt)
    {
        this.amt = amt;
    }

    public String exMessage()
    {
        return ("Deposit of Old currency of Rs. " + amt + " crosses Rs. 5,000 and cannot be Deposited");
    }
}