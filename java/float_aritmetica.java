/*
 * Compile assim: javac float_aritmetica.java -target 1.2 -source 1.2
 */

/*Testar os valores extremos*/
public class float_aritmetica{
	public static void main(String args[]){
		float a=100.4f;
		float b=20.3f;
		System.out.println(a+b);	//120.7
		System.out.println(a-b);	//80.1
		System.out.println(a*b);	//2038.12
		System.out.println(a/b);	//4.945812807881773
		System.out.println(-a);		//-100.4
		System.out.println(a%b);	//
	}
}