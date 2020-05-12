import java.util.ArrayList;
import java.util.Scanner;

class Market {
    ArrayList<String> fruits = new ArrayList<>();
    int fruitsNumber;

    // Constructor that initialises fruitNumber
    public Market(int fruitsNumber) {
        if (fruitsNumber > 0) {
            this.fruitsNumber = fruitsNumber;
            System.out.println("Market can hold " + fruitsNumber + " fruits");
        } else {
            throw new IllegalArgumentException("Negative value for fruitsNumber");
        }
    }

    // check if their is no place or its full //
    private synchronized boolean isFull() {
        boolean b = fruits.size() == this.fruitsNumber;
        System.out.println(b);
        return b;
    }

    // check if the market is empty
    private synchronized boolean isEmpty() {
        return fruits.isEmpty();
    }

    // farmer method which attempts to produce the fruit
    public synchronized void farmer() {
        while(true) {
            if (isFull()) {
                System.out.println("We cannot accept more fruits at the moment !!");
                try {
                    wait();
                } catch (InterruptedException e) {
                    System.out.println("Interruption");
                }
            } else
                System.out.println("Enter the fruit to be added");
            Scanner sc = new Scanner(System.in);
            String fruit = sc.next();
            fruits.add(fruit);
            System.out.printf("Fruit : %s is added !!!%n", fruit);
            notify();
        }
    }

    // consumer method which attempts to buy or consume the goods
    public synchronized void consumer() {
        while(true) {
            if (isEmpty()) {
                System.out.println("We don't have any goods yet");
                try {
                    wait();
                } catch (InterruptedException e) {
                    System.out.println("interruption occured !!!");
                }
            }
            String currentFruitRecusted = fruits.remove(0);
            System.out.println(" " + currentFruitRecusted);
            notifyAll();
        }
    }
}

// Farmer class which is used as a thread
class Farmer extends Thread
{
    Market m;
    Farmer (Market m)
    {
        this.m = m;
    }
    public void run()
    {
        m.farmer();
    }
}

// Consumer class which is used as a thread
class Customer extends Thread
{
    Market m;
    Customer (Market m)
    {
        this.m = m;

    }
    public void run()
    {
        m.consumer();
    }
}

// the main function that actually uses these thread classes on the market
public class Main {
    public static void main(String[] args)
    {
        Market superMarket = new Market(10);
        Farmer f  = new Farmer(superMarket);
        Customer c = new Customer(superMarket);
        f.start();
        c.start();
    }
}
