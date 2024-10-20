import java.sql.*;
public class JdbcDemo {
	static final String JDBC_DRIVER="com.mysql.jdbc.Driver";
	static final String DB_url="jdbc:mysql://localhost/2sd22cs108?ChracterEncoding=utf8";
	
	static final String USER="root";
	static final String PASSWD="";
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Connection conn=null;
		Statement stmt=null;
		
		try {
			Class.forName(JDBC_DRIVER);
			
			System.out.println("Connection to Server");
			conn=DriverManager.getConnection(DB_url,USER,PASSWD);
			System.out.println("Connected to server" +conn.getCatalog());
			
			stmt=conn.createStatement();
			
			String sql="select * from students";
			
			ResultSet rs=stmt.executeQuery(sql);
			
			while(rs.next()) {
				int RollNo=rs.getInt("rollNo");
				String Name=rs.getString("name");
				String USN= rs.getString("usn");
				String Divison= rs.getString("divison");
				
				System.out.println("Roll no: "+RollNo);
				System.out.println("Name: "+Name);
				System.out.println("USN: "+USN);
				System.out.println("Divison: "+Divison);
			}
			rs.close();
			conn.close();
			stmt.close();
		}catch(SQLException se) {
			se.printStackTrace();
		}catch(Exception e) {
			e.printStackTrace();
		}

	

}
}
