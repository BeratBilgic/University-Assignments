package com.company;

public class Main {

    public static void main(String[] args) {
        Teacher t1 = new Teacher(1, Branch.MATH);
        Teacher t2 = new Teacher(1, Branch.PHYSICS);
        Teacher t3 = new Teacher(1, Branch.CS);
        Teacher t4 = new Teacher(1, Branch.ENG);

        Teacher[] teachers = {t1, t2, t3, t4};

        for (int i = 0; i < teachers.length; i++) {
            System.out.println(teachers[i].getBranch() + " - " +teachers[i].getBranch().getDescription());
        }
/*
        //using a foreach loop.
        for (Teacher t: teachers) {
            System.out.println(t.getBranch());
        }
*/
    }
}

/*
Lab Exercise-2: Enum types

Create Branch Enum type will contain following branches
- MATH(“information regarding math”)
- PHYSICS(“information regarding physics”)
- CS(“information regarding cs”)
- ENG(“information regarding eng”)
Create a Teacher Class which contains id (int), and branch (Enum) attributes. The class must have a constructor with these two parameters.
Create four teacher objects; each has different branch.
Put them all in an array, and print their branches using for loop.
 */
