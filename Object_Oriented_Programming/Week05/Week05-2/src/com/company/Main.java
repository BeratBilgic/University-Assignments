package com.company;

public class Main {

    public static void main(String[] args) {
	    Employee e1 = new Employee(1 , "employee1", 1000.0);
        Employee e2 = new Employee(2 , "employee2", 2000.0);
        Employee e3 = new Employee(3 , "employee3", 3000.0);
        Employee e4 = new Employee(4 , "employee4", 4000.0);

        Employee[] employees = {e1, e2, e3, e4};

        Company company = new Company(employees, CompanyName.APPLE);

        System.out.println(company.getCompanyName() + " Employee Names");
        company.printAllEmployeesName();
    }
}
