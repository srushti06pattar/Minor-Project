//Write a java program to read the contents from a file named "input.txt" and write all the contents into a file named "output.txt"
import java.io.FileReader;
import java.io.FileWriter;

public class CopyDemo{    
    public static void main(String[] args) {
        try {
            FileReader in = new FileReader("input.txt");
            FileWriter out = new FileWriter("output.txt");
            int c;
            while((c = in.read()) != -1){
                out.write(c);
            }
            in.close();
            out.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}



