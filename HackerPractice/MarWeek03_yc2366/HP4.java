/*Use the quasi-Newton method with line search to solve the nonlinear optimization function V
 *  by making x(0) = (0, 0) and the local analysis of the Hessian matrix by 10-4 perturbation. 

V = (3x12 + x2 – 4)2 + (x12 – 3x2 + 2)2


Report ||x(k)||2, ||x(k)||2, t, V(x(k)).

 **/

import static java.lang.Math.*;


public class HP4 {
	static double tlr = pow(10,-7); 
	
	public static double V(double x1, double x2) {
		return pow( 3*pow(x1,2) + x2 - 4,2) + pow( pow(x1,2) - 3*x2 + 2,2);	
	}
	
	public static double dV(double x1, double x2) {
	//change to numerical method??
		return 40*pow(x1,3) - 40*x1 + 20*x2 - 20;
	}

	public static double[] deltax(double x1, double x2) {  // how to compute delta!!!!!!
		double delta[] = new double[2];
		delta[0] = (40*pow(x1,3)-40*x1)/(120*pow(x1,2)-40);
		delta[1] = x2-1;
		return delta;
	}
	
	
	public static void newtonLineSearch(double x1, double x2) {
		int k = 0, m = 0; 
		double t = 1;
		double [] del = deltax(x1,x2);
		double normDel = sqrt(pow(del[0],2)+pow(del[1],2));
		
		while(normDel>= tlr && abs(V(x1,x2)) >= tlr) {
			del = deltax(x1,x2);
			normDel = sqrt(pow(del[0],2)+pow(del[1],2));
			//appropriate delta x

			if(abs(V(x1+0.5*t*del[0], x2+0.5*t*del[1] )) >= abs(V(x1+t*del[0], x2+t*del[1]))){	
		
				x1 = x1 + t*del[0];
				x2 = x2 + t*del[1];
				k++;
				t = 1;
				System.out.println(k +", " +" ("+x1 + ", "+ x2 + ") , " + " ("+del[0] + ", "+ del[1] + ") , " 
						+t + ", " + V(x1,x2));
			}
			//delta is too big, use line search
			else {
				t = 0.5*t;
				m++;
				if(m>10000) break; // t keeps update, means there's no convergence
			}		
		}		
		System.out.println("iteration times: "+ k);
	}
		
	public static void main(String[] args) {	
        newtonLineSearch(0,0);
	}		
}

