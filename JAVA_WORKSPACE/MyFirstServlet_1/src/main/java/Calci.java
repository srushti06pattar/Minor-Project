

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class Calci
 */
@WebServlet("/Calci")
public class Calci extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public Calci() {
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
		
		out.println("Operation Of simple calculator");
		int num1=Integer.parseInt(request.getParameter("num1"));
		int num2=Integer.parseInt(request.getParameter("num2"));
		String ops=request.getParameter("btn");
		
		if(!ops.equals(null)) {
			if(ops.equals("add")) {
				out.println("<p>Sum of "+num1+" and "+num2+" :"+(num1+num2)+"</p>");
			}else if(ops.equals("sub")) {
				out.println("<p>Difference of "+num1+" and "+num2+" :"+(num1-num2)+"</p>");
			}else if(ops.equals("mul") ) {
				out.println("<p>product of "+num1+" and "+num2+" :"+(num1*num2)+"</p>");
			}else if(ops.equals("div")) {
				if(num2 != 0) {
					double result = (double)(num1/num2);
					out.println("<p>Quotient of "+num1+" and "+num2+" :"+result+"</p>");
				}else {
					out.println("<h1>Inavlid Input of the Numbers</h1>");
				}
			}
		}else {
			out.println("<h1>Error!! Invalid Input!!Operations</h1>");
		}
	}
	

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
