import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class binaryTranslator {
	
	public binaryTranslator () {
		System.out.println("Please enter \"file\" to enter a file or \"input\" to use the console.");//initial user interaction
		Scanner scanner = new Scanner(System.in);
		String input = scanner.nextLine(); //this input is either "file" or "input"
		String convNum = "";
		
		if (input.equals("file")) { //input from a file
			try {
			System.out.println("What is your file name?");
			input = scanner.nextLine();
			Scanner fileScanner = new Scanner(new File((input)));
			convNum = fileScanner.nextLine();
			} catch (IOException ex) {
				System.out.println("File is not found");
				scanner.close();
				System.exit(1);
			}
		} // if closes here
		
		else { //input in console
			convNum = scanner.nextLine();
		}//else closes here
		System.out.println("Hit \"dtb\" if you want to convert decimal to binary. Hit \"btd\" if you want to convert binary to decimal");
			input = scanner.nextLine();
			
			
			if(input.equals("dtb")) {
				String answer = "";
				//convert decimal to binary HERE
				int number = Integer.parseInt(convNum); //converts read number to a real number
				while (number > 0) {
					if (number % 2 ==1) {
						answer = "1" + answer;
					}
					else {
						answer = "0"+answer;
					}
					number = number / 2;               // actually divides and spits back into the if statement
			        System.out.println(answer);
				} // if dtb closes here
			}
			else {
				//convert a binary to decimal
				int answer = 0;
				for (int a = convNum.length()- 1; a >=0;a--) {
					if (input.charAt (a) == '1') { 
						answer = answer + (int)(Math.pow(2, a));
						
					}
				}
			}
		
	}

	public static void main(String[] args) {
		new binaryTranslator();

	}

}
