package com.company;

public class Company {
    Employee[] employees;
    CompanyName companyName;

    public Company(Employee[] employees, CompanyName companyName) {
        this.employees = employees;
        this.companyName = companyName;
    }

    public Employee[] getEmployees() {
        return employees;
    }

    public CompanyName getCompanyName() {
        return companyName;
    }

    public void printAllEmployeesName(){
        for (Employee employee : employees) {
            System.out.println(employee.getName());
        }
    }
}
