/*Use the Newton method to solve the following nonlinear equation:
	f(x) = e50x – 1 = 0
	Report x(k), x(k), f(x(k)).
*/

import static java.lang.Math.*;

public class HP1 {
	static double tlr = pow(10,-7); 
	
	public static double f(double x) {
		return exp(50*x)-1;		
	}
	
	public static double df(double x) {
		return 50*exp(50*x);
	}

	public static double deltax(double x) {
		return -f(x)/df(x);
	}
	
	/*x is the initial guess*/
	public static void newton1D(double x) {
		int k = 0;
		while(abs(deltax(x)) >= tlr && abs(f(x)) >= tlr) {
			System.out.println(k +", " + x + ", " + deltax(x) + ", " + f(x));
			x = x + deltax(x);
			k++;
		}
		System.out.println("iteration times: "+ k);
	}
	
	public static void main(String[] args) {		
        newton1D(1);
        newton1D(10);
	}		
}
