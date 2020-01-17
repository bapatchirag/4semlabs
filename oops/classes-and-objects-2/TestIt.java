import java.io.*;

// Main class
public class TestIt extends Address
{
   public static void main(String[] args) throws IOException
    {
        String name, USN, empid;
        TestIt entity = new TestIt();

        // Student details
        System.out.println("Enter student details: ");
        System.out.print("Enter student name: ");
        name = br.readLine();
        System.out.print("Enter student USN: ");
        USN = br.readLine();
        Student st = new Student(USN, name, entity.getAddress());
        System.out.println("\n\n");

        // College details
        System.out.println("Enter college details: ");
        System.out.print("Enter college name: ");
        name = br.readLine();
        College co = new College(name, entity.getAddress());
        System.out.println("\n\n");

        // Employee details
        System.out.println("Enter employee details: ");
        System.out.print("Enter employee ID: ");
        empid = br.readLine();
        System.out.print("Enter employee name: ");
        name = br.readLine();
        Employee emp = new Employee(empid, name, entity.getAddress());
        System.out.println("\n\n");

        // Print addresses of student, college and employee
        System.out.println("Student address: ");
        st.displayAddress(st.addr);
        System.out.println("\n");
        System.out.println("College address: ");
        co.displayAddress(co.addr);
        System.out.println("\n");
        System.out.println("Employee address: ");
        emp.displayAddress(emp.addr);
        System.out.println("\n");
    }
}
