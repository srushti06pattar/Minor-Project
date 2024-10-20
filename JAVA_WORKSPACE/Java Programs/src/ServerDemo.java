import java.io.*;
import java.net.*;

public class ServerDemo {
	public static void main(String[] args) {
		int port = 12345; //Port Number

		//Create a ServerSocket to LISTEN to the client on the PORT
		try (ServerSocket serverSocket = new ServerSocket(port)) {
			System.out.println("Server is listening on port " + port);

			//The Server waits(blocks) until Client Connects
			try (Socket socket = serverSocket.accept()) {
				System.out.println("Server: client connected");

				//Input and Output Stream established with Client
				InputStream input = socket.getInputStream();
				BufferedReader reader = new BufferedReader(new InputStreamReader(input));

				OutputStream output = socket.getOutputStream();
				PrintWriter writer = new PrintWriter(output, true);

				//1. Server Prompts the Client : Sending a message
				writer.println("Enter a string:");

				//2. Server waits for the Client to send the String wand reads it
				String receivedString = reader.readLine();
				
				//Reverse the String 
				if (receivedString != null) {
					String reversedString = new StringBuilder(receivedString).reverse().toString();
					int length = receivedString.length();
					//Display it on the Server Console
					System.out.println("Servers: " + reversedString);
					System.out.println("Servers Length: " + length);

					//Sending the reversed String and its length back to Client
					writer.println("Reversed String: " + reversedString);
					writer.println("Length of String: " + length);
				}

			} catch (IOException ex) {

				ex.printStackTrace();
			}

		} catch (IOException ex) {

			ex.printStackTrace();
		}
	}
}