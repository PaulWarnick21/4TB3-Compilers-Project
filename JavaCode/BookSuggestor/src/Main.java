import java.util.Scanner;

public class Main {
	static String[] Genres = new String[12];
	static String[] Ratings = new String[4];

	public static boolean arrayContains(String[] array, String value) {
		for (String element : array) {
			// System.out.println("checking for " + element + " in " + value);

			if (value.contains(element)) {
				return true;
			}
		}
		return false;

	}

	public static void main(String[] args) {

		Genres[0] = "fantasy";
		Genres[1] = "bildungsroman";
		Genres[2] = "dystopian";
		Genres[3] = "children";
		Genres[4] = "drama";
		Genres[5] = "thriller";
		Genres[6] = "autobiography";
		Genres[7] = "mystery";
		Genres[8] = "biography";
		Genres[9] = "educational";
		Genres[10] = "adventure";
		Genres[11] = "horror";

		Ratings[0] = "teen";
		Ratings[1] = "adult";
		Ratings[2] = "children";
		Ratings[3] = "everyone";

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
			String[] words = input.split(" ");

			String command = words[0];

			if (words.length < 1) {
				// no words from user's input
				break;
			} else if (words.length < 2) {
				// exactly one word from the user's input

				if (command.contains("help")) {

					System.out.println("Commands you can use at any point in this application are: ");
					System.out.println("	Help		- no arguments - Instructions for how to use this application");
					System.out.println(
							"	List		- 1 argument - Any filters you indicated will be applied and a list of books will be returned to you");
					System.out.println("		1 - Books");
					System.out.println("		2 - Filters");
					System.out.println(
							"	Clear		- no arguments - Any filters you indicated will be cleared from the system");
					System.out.println("	Exit		- no arguments - Exit the application");
					System.out
							.println("	AddFilter	- two arguments - Types of Filter you want to apply to the Books");
					System.out.println("		1 - any keyfilter from the list below");
					System.out.println("		2 - any keyword from the corresponding list of the keyfilter");
					System.out.println("");
					System.out.println(
							"	DelFilter	- two arguments - Types of Filter you want to remove from your preferences");
					System.out.println("		1 - any keyfilter from the list below");
					System.out.println("		2 - any keyword from the corresponding list of the keyfilter");
					System.out.println("");
					System.out.println("Keyfilters you can use with the command 'Filter' are: ");
					System.out.println("	Genre	- 11 keyword options");
					System.out.println("		1 - Fantasy");
					System.out.println("		2 - Bildungsroman");
					System.out.println("		3 - Dystopian");
					System.out.println("		4 - Children's");
					System.out.println("		5 - Drama");
					System.out.println("		6 - Thriller");
					System.out.println("		7 - Autobiography");
					System.out.println("		8 - Mystery");
					System.out.println("		9 - Biography");
					System.out.println("		10- Educational");
					System.out.println("		11- Adventure");
					System.out.println("");
					System.out.println(
							"	Year		- This refers to year of publication, and will act as a lower bound search");
					System.out.println("");
					System.out.println("	Rating	- 4 keyword options");
					System.out.println("		1 - Everyone");
					System.out.println("		2 - Kids");
					System.out.println("		3 - Teen");
					System.out.println("		4 - Adult");
					System.out.print(">>> ");

				} else if (arrayContains(Genres, input) || arrayContains(Ratings, input) || input.contains("year")
						|| input.contains("filter") || input.contains("rating")) {
					showVaguePrompt();
				} else if (input.contains("clear")) {
					System.out.println("	Sorry, this functionality is not available yet!");
					System.out.print(">>> ");

					// TODO clear all filters of year, genre and rating provided
				} else if (input.contains("exit")) {
					System.out.println("Goodbye!");
					break;
				} else {
					showVaguePrompt();

				}
			} else {
				// more than one word from the user's input

				String argument1 = words[1];

				if (words.length < 3) {

					// exactly two words from the user's input

					if (argument1.contains("delfilter")) {

						System.out.println(
								"	DelFilter	- two arguments - Types of Filter you want to remove from your preferences");
						System.out.println("			1 - any keyfilter from the list below");
						System.out.println("			2 - any keyword from the corresponding list of the keyfilter");
						System.out.println("");
						System.out.print(">>> ");

					} else if (argument1.contains("addfilter")) {
						System.out.println(
								"	AddFilter	- two arguments - Types of Filter you want to apply to the Books");
						System.out.println("			1 - any keyfilter from the list below");
						System.out.println("			2 - any keyword from the corresponding list of the keyfilter");
						System.out.println("");
						System.out.print(">>> ");

					} else if (argument1.contains("list")) {
						System.out.println(
								"	List		- 1 argument - Any filters you indicated will be applied and a list of books will be returned to you");
						System.out.println("		1 - Books");
						System.out.println("		2 - Filters");
						System.out.print(">>> ");

					} else if (command.contains("list") && argument1.contains("book")) {
						// TODO list the books after being filtered
						System.out.println(" Sorry, this functionality is not available yet!");
						System.out.print(">>> ");

					} else if (command.contains("list") && argument1.contains("filter")) {
						// TODO list the filters

						System.out.println(" Sorry, this functionality is not available yet!");
						System.out.print(">>> ");

					} else {
						showVaguePrompt();
					}
				} else {
					// more than two words from the user's input

					String argument2 = words[2];

					if (argument1.contains("genre")) {
						if (arrayContains(Genres, argument2)) {
							// TODO Filter by genre provided
							System.out.println(
									"Succesffully applied this genre filter to your list of books: " + argument2);
							System.out.println(
									"You can continue to apply more filters or type 'List Books' to receive your customized list of books. Type 'List Filters' to see the filters you have applied so far. ");
							System.out.print(">>> ");
						} else {
							System.out.println(
									"Sorry, that genre is not in our system. Here is a full list of genres we have:");
							System.out.println("		1 - Fantasy");
							System.out.println("		2 - Bildungsroman");
							System.out.println("		3 - Dystopian");
							System.out.println("		4 - Children's");
							System.out.println("		5 - Drama");
							System.out.println("		6 - Thriller");
							System.out.println("		7 - Autobiography");
							System.out.println("		8 - Mystery");
							System.out.println("		9 - Biography");
							System.out.println("		10- Educational");
							System.out.println("		11- Adventure");
							System.out.print(">>> ");
						}
					} else if (argument1.contains("rating")) {
						if (arrayContains(Ratings, argument2)) {
							// TODO Filter by genre provided
							System.out.println(
									"Succesffully aplied this rating filter to your list of books: " + argument2);
							System.out.println(
									"You can continue to apply more filters or type 'Submit' to receive your customized list of books");
							System.out.print(">>> ");
						} else {
							System.out.println(
									"Sorry, that rating is not in our system. Here is a full list of ratings we have:");
							System.out.println("		1 - Everyone");
							System.out.println("		2 - Kids");
							System.out.println("		3 - Teen");
							System.out.println("		4 - Adult");
							System.out.print(">>> ");
						}

					} else if (argument1.contains("year")) {

						// check if a second year has been provided
						if (words.length >= 4) {
							String argument3 = words[3];

							// TODO Filter by genre provided

							System.out.println(
									"Succesffully aplied this date filter to your list of books. Only books published from "
											+ argument2 + " to " + argument3
											+ " will be shown. You can continue to apply more filters or type 'Submit' to receive your customized list of books");
							System.out.print(">>> ");

						} else {
							showVaguePrompt();
						}
					} else {
						showVaguePrompt();

					}

				}
			}

		}

		scanner.close();

	}

	private static void showVaguePrompt() {
		System.out.println(" Your input seems to be a little vague. Try one of the following formats: ");
		System.out.println("");
		System.out.println("		\"AddFilter Genre Horror \" ");
		System.out.println("		\"DelFilter Rating Teen \" ");
		System.out.println("		\"AddFilter Year 2013 2015 \" ");

		System.out.println("");
		System.out.println(" For a more extensive list use the command 'Help'");
		System.out.println("");

		System.out.print(">>> ");
	}

}
