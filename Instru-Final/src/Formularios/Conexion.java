/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Formularios;


import static java.lang.System.out;
import java.sql.*;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.*;
import java.time.format.DateTimeFormatter;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Z420
 */
public class Conexion {
     private Connection con = null;
    private Statement st; //Sentencia
    private ResultSet rs; //Resultado
    void conectar() {
        //Se entabla Conexion SQL
            try {
                Class.forName("com.mysql.jdbc.Driver");
                try {
                    con = DriverManager.getConnection("jdbc:mysql://idev4u.com:3306/idevucom_instrumentacion", "idevucom","190997Tsukune");
                    st = con.createStatement();
                } catch (SQLException e) {
                    System.out.println(e.getMessage());
                }
            } catch (ClassNotFoundException ex) {
                System.out.println(ex.getMessage());
            }
    }
    
    void cerrar() {
        try {
            con.close();
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }


    int saveSensors(String primerString) {
        String[] parts = primerString.split(",");
        String Calor = parts[0];
        String Luz = parts[1];
        String Magnetico = parts[2];
        String sentenciaSQL = "INSERT INTO lecturas(`SensorCalor`,`DetectorLuz`,`SensorMagnetico`) VALUES ('"+Calor+"','"+Luz+"','"+Magnetico+"')";
        try {
            st.executeUpdate(sentenciaSQL); 
            return 1;
        } catch (SQLException ex) {
            System.out.println(ex.getMessage());
        }
        return 0;
    }
    
}
