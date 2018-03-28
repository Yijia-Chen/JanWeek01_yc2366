/*Use the steepest descent method with line search to solve the nonlinear optimization function V 
 * by making x(0) = (0, 0) and the local analysis by xi = 10-4xi perturbation.
 V = (3x12 + x2 – 4)2 + (x12 – 3x2 + 2)2
 */
import static java.lang.Math.abs;
import static java.lang.Math.pow;
import static java.lang.Math.sqrt;


public class HP5 {
	static double tlr = pow(10,-7); 
	
	public static double V(double x1, double x2) {
		return pow( 3*pow(x1,2) + x2 - 4,2) + pow( pow(x1,2) - 3*x2 + 2,2);	
	}
	
	public static double dV(double x1, double x2) {
	//change to numerical method??
		return 40*pow(x1,3) - 40*x1 + 20*x2 - 20;
	}

	public static double deltax(double x1, double x2, double t, double dx) {  // change delta x into steepest descent
		if (abs(dx) < pow(10, -7)) return 0;
		return -t*(V(x1+dx,x2+dx)-V(x1,x2))/dx;
	}
	
	
	public static void newtonLineSearch(double x1, double x2) {
		int k = 0;
		double t = pow(1,1), del = pow(10,-4);	
		double normDel = abs(deltax(x1,x2,t,del));
		
		while(normDel>= tlr && abs(V(x1,x2)) >= tlr) {
			del = deltax(x1,x2,t,del);
			
			normDel = abs(deltax(x1,x2,t,del));
			//appropriate delta x			
			if(abs(V(x1+0.5*t*del, x2+0.5*t*del )) >= abs(V(x1+t*del, x2+t*del))){		
				x1 = x1 + t*del;
				x2 = x2 + t*del;
				k++;
				t = 1;
				System.out.println(k +", " +" ("+x1 + ", "+ x2 + ") , " + del + "," 
						+t + ", " + V(x1,x2));
			}
			//delta is too big, use line search
			else {
				while(abs(V(x1+0.5*t*del, x2+0.5*t*del )) < abs(V(x1+t*del, x2+t*del))) {
				t = 0.5*t;
				}
			}
			
		}
		
		System.out.println("iteration times: "+ k);
	}
	
	
	public static void main(String[] args) {	
        newtonLineSearch(0,0);
	}		
}

