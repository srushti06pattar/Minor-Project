
import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class VowelConst
 */
@WebServlet(description = "My First Java servlet", urlPatterns = { "/VowelConst" })
public class VowelConst extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public VowelConst() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.setContentType("text/html");
		PrintWriter out=response.getWriter();
		out.println("<h2>Number Of Vowels And Consonants</h2>");
		
		String usrInputTxt=request.getParameter("txtname");
		int vowelCount=0;
		int constCount=0;
		int spacecount=0;
		int digitcount=0;
		
		String inputTxt=usrInputTxt.toLowerCase();
		
		for(int i=0;i<inputTxt.length();i++) {
			char c=inputTxt.charAt(i);
			if(c=='a'|| c=='e'|| c=='i'|| c=='o'||c=='u' ) {
				vowelCount+=1;
			}
			else if(c==' ') {
				spacecount++;
			}
			else if(Character.isDigit(c)) {
				digitcount++;
			}
			else if(c=='1') {
				digitcount++;
			}
				
			else {
				constCount+=1;
			}
			
		}
		String Txt=new StringBuilder(inputTxt).reverse().toString();
		out.println("<p>The number reverse in text: "+Txt+"</p>");
		out.println("<p>The number Vowels in text: "+vowelCount+"</p>");
		out.println("<p>The number Consonants in text :"+constCount+"</p>");
		out.println("<p>The number space in text: "+spacecount+"</p>");
		out.println("<p>The number digits in text: "+digitcount+"</p>");

		
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
