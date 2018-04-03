package simpleton;

/* this program returns takes in 1 argument which must be an integer 
 * and returns the absolute value of that integer. 
 */

public class abs_val {
	public static void main(String[] args) {
		
		if (args.length == 1) {
			int a = Integer.parseInt(args[0]);

			if (a < 0) {
				int b = -1;
				System.out.println( a * b);
			} else {
				System.out.println( a);
			}
		}

	}
}
