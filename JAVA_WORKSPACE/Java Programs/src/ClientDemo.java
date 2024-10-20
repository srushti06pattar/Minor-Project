import java.io.*;
import java.net.*;

public class ClientDemo {
    public static void main(String[] args) {
        String hostname = "localhost"; // Change if server is on a different machine
        int port = 12345;

        //Create a Socket Object to connect to the Server(host name, port)
        try (Socket socket = new Socket(hostname, port)) {
        	System.out.println("Client: Connected to the Server");
        	
        	//Input and Output Stream established with the Server
            InputStream input = socket.getInputStream();
            BufferedReader reader = new BufferedReader(new InputStreamReader(input));

            OutputStream output = socket.getOutputStream();
            PrintWriter writer = new PrintWriter(output, true);
            
            //To read data from the from the Client Console
            BufferedReader consoleReader = new BufferedReader(new InputStreamReader(System.in));

           //1.' Reads the Server prompt and Displays
            String serverMessage = reader.readLine();
            System.out.println("Server: " + serverMessage);

            //2.' Reads the String the client console and sends it to the Server
            String userInput = consoleReader.readLine();
            writer.println(userInput);

            // Clients receives the reversed String and its length from the server	
            String reversedString = reader.readLine();
            String lengthOfString = reader.readLine();

            //Display it on the Client console
            System.out.println(reversedString);
            System.out.println(lengthOfString);

        } catch (UnknownHostException ex) {
        	ex.printStackTrace();
        } catch (IOException ex) {
        	ex.printStackTrace();
        }
    }
}