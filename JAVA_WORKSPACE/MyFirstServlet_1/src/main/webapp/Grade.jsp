<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
	<h2>Your Grades are as follows</h2>
	
	<%	
		String grade;
		String inputMarks = request.getParameter("txtGrade");
		if(inputMarks != null && inputMarks.matches("\\d+")) {
			int marks = Integer.parseInt(inputMarks);
			if(marks > 100 || marks < 0 ) {
				out.println("Marks Out of range");
			}else {
				if (marks >= 90 && marks <= 100) {
		            grade = "O";
		        } else if (marks >= 80 && marks <= 89) {
		            grade = "A+";
		        } else if (marks >= 70 && marks <= 79) {
		            grade = "A";
		        } else if (marks >= 60 && marks <= 69) {
		            grade = "B+";
		        } else if (marks >= 50 && marks <= 59) {
		            grade = "B";
		        } else if (marks >= 45 && marks <= 49) {
		            grade = "C";
		        } else if (marks >= 40 && marks <= 44) {
		            grade = "P";
		        } else if (marks >= 0 && marks <= 39) {
		            grade = "F";
		        } else {
		            grade = "Invalid marks";
		        }
		%>
				<p>Your marks: <%= marks %></p>
				<p>Your Grades: <%= grade %></p>	
		<% 
			}
		} else {
			out.println("Invalid input. Please enter a valid number.");
		}
	%>
</body>
</html>