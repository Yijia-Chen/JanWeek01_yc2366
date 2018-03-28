/*Use the quasi-Newton method with line search to solve the same nonlinear equation by making x(0) = 1 
 * and the local analysis of the Jacobian matrix by 10-4 perturbation. 
							f(x) = e100x – 1 = 0
 *Report x(k), deltax(k), f(x(k)).
 */


import static java.lang.Math.*;

public class HP3 {
static double tlr = pow(10,-4); 
	
	public static double f(double x) {
		return exp(50*x)-1;		
	}
	/*quasi-Newton method*/
	public static double df(double x) {
		return (f(1.0001*x)-f(x))/0.0001*x;
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
	
	/*x is the initial guess*/
	public static void newtonLineSearch(double x) {
		int k = 0; 
		double t = 1;
		while(abs(deltax(x)) >= tlr && abs(f(x)) >= tlr) {
			//appropriate delta x
			if(abs(f(x+0.5*t*deltax(x))) > abs(f(x+t*deltax(x)))){			
				x = x + t*deltax(x);
				k++;
				t = 1;
				System.out.println(k +", " + x + ", " + deltax(x) + ", " + f(x));
			}
			//delta is too big, use line search
			else {
				t = 0.5*t;				
			}
		}
		System.out.println("iteration times: "+ k);
	}
	
	public static void main(String[] args) {		
		newtonLineSearch(1);
	}		
}