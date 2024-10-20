import java.io.FileReader;
import java.io.FileWriter;

public class CopyFile{
	public static void main(String[] args) {
		if(args.length!=2) {
			System.out.println("enter two file name as arguments");
		}
		try {
			FileReader fin=new FileReader(args[0]);
			FileWriter fout=new FileWriter(args[1]);
			int c;
			while((c=fin.read())!=-1) {
				out.write(c);
				
			}
			in.close();
			out.close();
		}catch(Exception e) {
			System.out.println("The file enterd are invalid or not opened");
		}
	}
}