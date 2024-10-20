import java.sql.*;
public class JdbcDemo {
	
	final static String JDBC_Driver="com.mysql.jdbc.Driver";
	final static String DB_url="jdbc:mysql://localhost/2sd22cs108?ChracterEncoding=utf8";
	
	static final String USER="root";
	static final String password="";
	
	public static void main(String[] args) {
		Connection conn=null;
		Statement stmt=null;
		
		try {
			Class.forName(JDBC_Driver);
			
			System.out.println("Connecting to database...");
			conn = DriverManager.getConnection(DB_url,USER,password);
			System.out.println("Connected to database!!" +conn.getCatalog());
			System.out.println("creating statement:");
			stmt=conn.createStatement();
		    String sql = "SELECT * FROM student";
		    ResultSet rs=stmt.executeQuery(sql);
		    while(rs.next()) {
		    	int rollNo=rs.getInt("rollNo");
		    	String usn=rs.getString("usn");
		    	String name=rs.getString("name");	
		    	
		    	System.out.println("roll no : " + rollNo);
		    	System.out.println("usn : " + usn);
		    	System.out.println("name : " + name);
		    	
		    }rs.close();
		    stmt.close();
		    conn.close();
		}catch(SQLException se) {
			se.printStackTrace();
		}catch(Exception e) {
			e.printStackTrace();
		}
	}
}
