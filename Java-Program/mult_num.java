package simpleton;

/* this program returns takes in 2 arguments 
 * which must be integers and returns the product of them. 
 */

public class mult_num {

	public static void main(String[] args) {
		
		if (args.length == 2) {
			int a = Integer.parseInt(args[0]);
			int b = Integer.parseInt(args[1]);

			int product = 0;
			for (int i=0; i < a; i++) {
				product += b;
			}
			System.out.println(product); 
		}

	}

}
