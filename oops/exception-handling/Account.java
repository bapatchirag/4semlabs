public class Account
{
    private double bal;

    Account()
    {
        this.bal = 500.0;
    }

    Account(double bal)
    {
        this.bal = bal;
    }

    public void deposit(double amount, String currencyType) throws DemonetizationException
    {
        if(currencyType.equals("OLD") && amount > 5000)
        {
            throw new DemonetizationException(amount);
        }
        else
        {
            bal += amount;
            System.out.println("Balance updated");
        }
    }

    public double currBalance()
    {
        return bal;
    }

    public void withdraw(double amount)
    {
        if(bal - amount >= 500)
        {
            bal -= amount;
            System.out.println("Balance updated");
        }
        else
        {
            System.out.println("Sorry, minimum balance cannot be breached");
        }
    }
}