import java.sql.*;


public class JDBCUtils {


        public static Connection getConnection() throws ClassNotFoundException {

            try {
                Class.forName("com.mysql.jdbc.Driver");
                return DriverManager.getConnection("jdbc:mysql://localhost:3306/cai_event?useUnicode=true&characterEncoding=utf-8","root","root");
            } catch (SQLException e) {
                e.printStackTrace();
            }

            return null;
        }
    public static void close (PreparedStatement preparedStatement, Connection conn) {
        if (preparedStatement != null) {
            try {
                preparedStatement.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        if (conn != null) {
            try {
                conn.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }



    }