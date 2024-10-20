<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Simple Calculator Results</title>
</head>
<body>
  

    <h2>Simple Calculator Operation Result</h2>
    <%
        String Ipnum1 = request.getParameter("num1");
        String Ipnum2 = request.getParameter("num2");
        String  ops = request.getParameter("btn");

            if (ops != null || Ipnum1 != null || Ipnum2 != null) {
            	int num1 = Integer.parseInt(Ipnum1);
            	int num2 = Integer.parseInt(Ipnum2);
            	
                if (ops.equals("add")) {   %>
                
                    <p>Sum of <%= num1 %> and <%= num2 %> : <%= num1 + num2 %></p>
                    
    <%		} else if (ops.equals("sub")) {  %>
    
                    <p>Difference of <%= num1 %> and <%= num2 %> : <%= num1 - num2 %></p>
                    
    <%		} else if (ops.equals("mul")) {   %>
    
                    <p>Product of <%= num1 %> and <%= num2 %> : <%= num1 * num2 %></p>
                    
    <%		} else if (ops.equals("div")) { 
                    if (num2 != 0) {
                        double result = (double) num1 / num2;  %>
                        
                        <p>Quotient of <%= num1 %> and <%= num2 %> : <%= result %></p>
                        
    <%		} else { 	%>
    
                      <p>Error: Division by zero is not allowed.</p>
    <%		}
                } else { 	%>
                
                    <p>Error: Invalid operation.</p>
                    
    <%		}
            	} else {  	%>
            	
                <p>Error: Invalid Input.</p>
                
    <%		}	%>
</body>
</html>