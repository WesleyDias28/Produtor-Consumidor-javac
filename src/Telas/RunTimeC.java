/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Telas;

import java.io.IOException;

/**
 *
 * @author Wesley
 */
public class RunTimeC {
        Runtime processoExecutor = Runtime.getRuntime();
	String linhaComando = new String("cmd.exe /C start C:/Users/Wesley/Documents/NetBeansProjects/ProjetoAED3/src/Usuarios/Comparador1.exe");

	public RunTimeC()
	{	
        try
        {
           Runtime.getRuntime().exec(linhaComando);
        }
        catch(IOException erro)
        {
           erro.printStackTrace();
        }	
	}
	
	public static void main(String argumentos[])		                  	
	{
		RunTime aplicacao = new RunTime();		
	}
}
