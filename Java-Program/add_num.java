package simpleton;

/* this program returns takes in 2 arguments 
 * which must be integers and returns the sum of them. 
 */

public class add_num {

	public static void main(String[] args) {
		if (args.length == 2) {
			int a = Integer.parseInt(args[0]);
			int b = Integer.parseInt(args[1]);

			System.out.println(a + b); 
		}

	}

}