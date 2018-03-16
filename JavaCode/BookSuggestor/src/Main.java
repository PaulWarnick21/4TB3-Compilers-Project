import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		// create a scanner so we can read the command-line input
		Scanner scanner = new Scanner(System.in);

		System.out.println("************************************************");
		System.out.println("");
		System.out.println(" Welcome to our Book Suggestor Application!");
		System.out.println("");
		System.out.println(
				" At any point in the application you may use a keyfilter and a key number to and say 'submit' to receive book suggestinos based on those keys.");
		System.out.println("");
		System.out.println(
				" At any point in the application you may use the keyword 'help' to see available filters and their corresponding key nymers. ");
		System.out.println("");
		System.out.println("************************************************");
		System.out.print(">>> ");

		// loop through as many as 200 inputs from the user
		for (int i = 0; i < 200; i++) {

			// get their input as a String
			String input = scanner.nextLine().toLowerCase();

			if (input.contains("help")) {
				// System.out.println("check");
				if (input.contains("submit")) {
					System.out.println(
							"	Submit		- no arguments - Any filters you indicated will be applied and a list of books will be returned to you");
					System.out.print(">>> ");

				} else if (input.contains("delfilter")) {

					System.out.println(
							"	DelFilter	- two arguments - Types of Filter you want to remove from your preferences");
					System.out.println("			1 - any keyfilter from the list below");
					System.out.println("			2 - any keyword from the corresponding list of the keyfilter");
					System.out.println("");
					System.out.print(">>> ");

				} else if (input.contains("addfilter")) {
					System.out
							.println("	AddFilter	- two arguments - Types of Filter you want to apply to the Books");
					System.out.println("			1 - any keyfilter from the list below");
					System.out.println("			2 - any keyword from the corresponding list of the keyfilter");
					System.out.println("");
					System.out.print(">>> ");

				} else {
					System.out.println("Commands you can use at any point in this application are: ");
					System.out.println(
							"			Help		- no arguments - Instructions for how to use this application");
					System.out.println(
							"			Submit		- no arguments - Any filters you indicated will be applied and a list of books will be returned to you");
					System.out.println(
							"			Clear		- no arguments - Any filters you indicated will be cleared from the system");
					System.out.println("			Exit		- no arguments - Exit the application");
					System.out.println(
							"			AddFilter	- two arguments - Types of Filter you want to apply to the Books");
					System.out.println("				1 - any keyfilter from the list below");
					System.out.println("				2 - any keyword from the corresponding list of the keyfilter");
					System.out.println("");
					System.out.println(
							"			DelFilter	- two arguments - Types of Filter you want to remove from your preferences");
					System.out.println("				1 - any keyfilter from the list below");
					System.out.println("				2 - any keyword from the corresponding list of the keyfilter");
					System.out.println("");
					System.out.println("Keyfilters you can use with the command 'Filter' are: ");
					System.out.println("			Genre	- 11 keyword options");
					System.out.println("				1 - Fantasy");
					System.out.println("				2 - Bildungsroman");
					System.out.println("				3 - Dystopian");
					System.out.println("				4 - Children's");
					System.out.println("				5 - Drama");
					System.out.println("				6 - Thriller");
					System.out.println("				7 - Autobiography");
					System.out.println("				8 - Mystery");
					System.out.println("				9 - Biography");
					System.out.println("				10- Educational");
					System.out.println("				11- Adventure");
					System.out.println("");
					System.out.println(
							"			Year		- This refers to year of publication, and will act as a lower bound search");
					System.out.println("");
					System.out.println("			Rating	- 4 keyword options");
					System.out.println("				1 - Everyone");
					System.out.println("				2 - Kids");
					System.out.println("				3 - Teen");
					System.out.println("				4 - Adult");
					System.out.print(">>> ");

				}
			} else if (input.contains("submit")) {
				System.out.println("	Sorry, this functionality is not available yet!");
				System.out.print(">>> ");

				// TODO
			} else if (input.contains("clear")) {
				System.out.println("	Sorry, this functionality is not available yet!");
				System.out.print(">>> ");

				// TODO
			} else if (input.contains("exit")) {
				System.out.println("	Goodbye!");
				break;
			} else {
				System.out.println("Sorry, I don't recognize that command! Try 'Help' to see a full list of commands!");
				System.out.print(">>> ");

			}

			// String filter = null;
			// String keyword = filter.split(" ")[0];
			// String keynumber = filter.split(" ")[1];

			// prompt for their age
			// System.out.println("Enter your age: ");

			// get the age as an int
			// int age = scanner.nextInt();

			// System.out.println(String.format("%s, your age is %d", "kk", age));
		}

		scanner.close();

	}

}
