//liste
import java.util.ArrayList;
import java.util.Scanner;
//boh
import java.security.*;

public class learnJava{
    public static void main(String[] args) {
        // IO

        System.out.println("IO");
        System.out.println("si può " + "usare  il " + '+' + "\n" + 
        "int: " + 10 + "\ndouble: " + 12.5 + "\nboolean: " + true);

        // out.print -> senza new line
        // out.printf -> formattazione tipo C

        //creo uno scanner (apparentemente)
        Scanner scanner = new Scanner(System.in);

        String str = scanner.next();

        System.out.println(str);

        scanner.close();
    }
}